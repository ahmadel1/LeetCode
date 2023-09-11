class Solution(object):
    def checkPalindrome(self, s):
        i, j = 0, len(s) - 1
        while i<=j :
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True
    
    def toBase(self, n, base):
        res = ""
        while n > 0:
            res = str(n % base) + res
            n //= base
        return self.checkPalindrome(res)
        
    def isStrictlyPalindromic(self, n):
        for i in range(2, n-1):
            if not self.toBase(n, i):
                return False
        return True
        