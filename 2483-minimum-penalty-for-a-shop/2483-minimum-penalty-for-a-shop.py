
class Solution(object):
    def bestClosingTime(self, customers):
        n = len(customers)
        Nprev = [0] * (n+1)
        Yprev = [0] * (n+1)
        for i in range(n):
            if customers[i] == 'Y': 
                Yprev[i] = 1
            if customers[i] == 'N': 
                Nprev[i+1] = 1
        for i in range(n-1, -1, -1):
            Yprev[i] += Yprev[i+1]
        
        for i in range(1, n+1):
            Nprev[i] += Nprev[i-1]

        result, mn = 0, 9999999999
        for i in range(n+1):
            if Yprev[i] + Nprev[i] < mn:
                mn = Yprev[i] + Nprev[i]
                result = i
        return result