class Solution(object):
    def countBits(self, n):
        ls = [0]
        for i in range(1, n+1):
            if i <= 2:
                ls.append(1)
                continue
            elif math.log(i, 2) == round(math.log(i, 2)):
                ls.append(1)
            else:
                power = floor(math.log(i, 2))
                ls.append(1 + ls[int(i - 2**power)])
        return ls        
        