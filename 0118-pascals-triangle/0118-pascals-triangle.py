class Solution(object):
    def generate(self, numRows):
       pascal = []
       for i in range(1, numRows+1):
           pascal.append([1]*i)
       for i in range(2, numRows):
           for k in range(1, len(pascal[i])-1):
               pascal[i][k] = pascal[i-1][k-1] + pascal[i-1][k] 
       return pascal
        