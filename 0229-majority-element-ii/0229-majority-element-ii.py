class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        hashMap = {}
        res = set()
        n = len(nums)/3
        for num in nums:
            if num in hashMap:
                hashMap[num] += 1
            else:
                hashMap[num] = 1
            
            if hashMap[num] > n:
                res.add(num)

        return res