class Solution(object):
    def minTimeToVisitAllPoints(self, points):
        result = 0
        for i in range(len(points)-1):
            distx = abs(points[i][0] - points[i+1][0]) 
            disty = abs(points[i][1] - points[i+1][1]) 
            result += max(distx, disty)
        return result
                    