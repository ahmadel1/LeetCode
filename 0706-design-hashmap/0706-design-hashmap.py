class MyHashMap(object):

    def __init__(self):
        self.keys = []
        self.values = []
        
    def put(self, key, value):
        if key not in self.keys:
            self.keys.append(key)
            self.values.append(value)
        else:
            self.values[self.keys.index(key)] = value
        
        
    def get(self, key):
        if key in self.keys:
            return self.values[self.keys.index(key)]
        else:
            return -1

        

    def remove(self, key):
        if key in self.keys:
            idx = self.keys.index(key)
            del self.keys[idx]
            del self.values[idx]
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)