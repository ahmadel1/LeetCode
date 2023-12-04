class Solution(object):
    def largestGoodInteger(self, num):
        """
        :type num: str
        :rtype: str
        """

        for i in range(9, -1, -1):
            n = str(i) * 3
            if n in num:
                return n

        return ""
        