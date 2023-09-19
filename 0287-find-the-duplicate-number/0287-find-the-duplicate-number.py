class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dic = {}
        for i in range(len(nums)):
            if dic.get(nums[i], 0) == 0:
                dic[nums[i]] =1
            else:
                return nums[i]