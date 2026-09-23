class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        fst = {}
        lst = {}
        
        # Step 1: Find first and last occurrences of each character
        for i, ch in enumerate(s):
            if ch not in fst:
                fst[ch] = i
            lst[ch] = i
            
        valid_intervals = []
        
        # Step 2: Expand ranges for each unique character
        for ch in fst:
            left = fst[ch]
            right = lst[ch]
            
            i = left
            is_valid = True
            
            while i <= right:
                c = s[i]
                # If character appears before our left boundary, this left index is invalid
                if fst[c] < left:
                    is_valid = False
                    break
                right = max(right, lst[c])
                i += 1
                
            if is_valid:
                valid_intervals.append((left, right))
                
        # Step 3: Sort by end index and greedily select non-overlapping intervals
        valid_intervals.sort(key=lambda x: x[1])
        
        res = []
        last_end = -1
        
        for left, right in valid_intervals:
            if left > last_end:
                res.append(s[left:right + 1])
                last_end = right
                
        return res