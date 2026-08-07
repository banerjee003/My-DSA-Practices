from functools import lru_cache

class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        # 1. Factorize t for valid prime factors (2, 3, 5, 7)
        temp = t
        req = [0, 0, 0, 0]  # Counts for prime factors: 2, 3, 5, 7
        primes = [2, 3, 5, 7]
        for i, p in enumerate(primes):
            while temp % p == 0:
                req[i] += 1
                temp //= p
                
        # If there's any remaining factor > 7, it's impossible
        if temp > 1:
            return "-1"
            
        # 2. Make num zero-free. 
        if '0' in num:
            idx = num.index('0')
            num = num[:idx] + '1' * (len(num) - idx)
            
        n = len(num)
        
        # Prime factor contributions for digits 1-9 (counts of 2, 3, 5, 7)
        contrib = {
            1: (0, 0, 0, 0), 2: (1, 0, 0, 0), 3: (0, 1, 0, 0),
            4: (2, 0, 0, 0), 5: (0, 0, 1, 0), 6: (1, 1, 0, 0),
            7: (0, 0, 0, 1), 8: (3, 0, 0, 0), 9: (0, 2, 0, 0)
        }
        
        # DP to find the minimum number of digits to cover the remaining factors
        @lru_cache(None)
        def get_min_len(r2, r3, r5, r7):
            if r2 == 0 and r3 == 0 and r5 == 0 and r7 == 0:
                return 0
            res = float('inf')
            # Check digits 2-9 (1 doesn't contribute factors, thus wouldn't minimize length)
            for d in range(2, 10):
                c2, c3, c5, c7 = contrib[d]
                nr2 = max(0, r2 - c2)
                nr3 = max(0, r3 - c3)
                nr5 = max(0, r5 - c5)
                nr7 = max(0, r7 - c7)
                
                # Prevent infinite recursion if the digit contributes nothing useful
                if (nr2, nr3, nr5, nr7) != (r2, r3, r5, r7):
                    res = min(res, 1 + get_min_len(nr2, nr3, nr5, nr7))
            return res

        # Pre-calculate accumulated prefix factors for O(1) retrieval
        pref = [[0, 0, 0, 0] for _ in range(n + 1)]
        for i in range(n):
            d = int(num[i])
            for j in range(4):
                pref[i+1][j] = pref[i][j] + contrib[d][j]
                
        # 3. Check if the zero-free 'num' already satisfies the condition
        rem = [max(0, req[j] - pref[n][j]) for j in range(4)]
        if sum(rem) == 0:
            return num
            
        # 4. Try to find a valid suffix by keeping a prefix of length i
        for i in range(n - 1, -1, -1):
            start_d = int(num[i]) + 1
            for d in range(start_d, 10):
                # Calculate remaining factors needed after appending digit 'd'
                rem = [max(0, req[j] - (pref[i][j] + contrib[d][j])) for j in range(4)]
                rem_len = n - 1 - i
                
                # If the remaining factors can fit inside the remaining suffix length
                if get_min_len(*rem) <= rem_len:
                    ans = num[:i] + str(d)
                    curr_rem = rem
                    # Greedily construct the remaining suffix left-to-right
                    for step in range(rem_len):
                        for nxt_d in range(1, 10):
                            next_rem = [max(0, curr_rem[j] - contrib[nxt_d][j]) for j in range(4)]
                            if get_min_len(*next_rem) <= rem_len - 1 - step:
                                ans += str(nxt_d)
                                curr_rem = next_rem
                                break
                    return ans
                    
        # 5. If no valid sequence of length `n` exists, it must be longer.
        ans = ""
        curr_rem = req
        rem_len = max(n + 1, get_min_len(*req))
        
        for step in range(rem_len):
            for nxt_d in range(1, 10):
                next_rem = [max(0, curr_rem[j] - contrib[nxt_d][j]) for j in range(4)]
                if get_min_len(*next_rem) <= rem_len - 1 - step:
                    ans += str(nxt_d)
                    curr_rem = next_rem
                    break
                    
        return ans