class Solution(object):
    def isSubsequence(self, s, t):
        if len(s) == 0:
            return True
        idx = 0
        st = ""
        for i in t:
            if s[idx] == i:
                st += i
                idx += 1
                if idx == len(s):
                   break
        if st == s:
            return True
        return False
            