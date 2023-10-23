class Solution(object):
    def isPowerOfFour(self, n):
        from numpy import log as ln
        if n <= 0 :
            return False
        if n == 1:
            return True
        return pow(4, int(ln(n) / ln(4))) == n
        