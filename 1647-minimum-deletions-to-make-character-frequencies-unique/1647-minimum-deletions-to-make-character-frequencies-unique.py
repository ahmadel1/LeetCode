class Solution(object):
    def minDeletions(self, s):
        ls = [0]*27
        for i in range(len(s)):
            ls[ord(s[i]) - 97] += 1
        sorted_ls = sorted(ls, reverse = True)
        counter = 0
        i = 0
        while i < 26 or sorted_ls[i] != 0:
            if sorted_ls[i] == sorted_ls[i+1] and sorted_ls[i+1] != 0:
                print(sorted_ls[i])
                sorted_ls[i+1] = sorted_ls[i+1] - 1
                counter += 1
                sorted_ls = sorted(sorted_ls, reverse = True)
                continue
            i += 1 
        return counter

        