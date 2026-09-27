class Solution:
    def reverseWords(self, s: str) -> str:
        words = list(s.strip().split(" "))
        words.reverse()
        ans = ""
        
        for word in words:
            if word != "":
                ans = ans + word + " "
        
        return ans.strip()
