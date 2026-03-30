'''
I could use an array with 1_000_000 entries
That would take too much space

I could shrink the array to 10_000 cells
and each cell could have 100 entries
It reduces the space used

But I lose the unique association between the key and its value
Or each cell in the array should store pairs of key & its value?

SO first declare an array with 10_000 cells
'''
class TreeNode:
    def __init__(self, key = 0, val= 0):
        self.node = (key, val)
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = TreeNode()
    
    def insert(self, cur, key, val):
        # recursively check and insert into left or right subtree
        pass
    
    def remove(self, key):
        # recursively check and delete
        pass
    
    def search(self, key):
        # search via iteration
        pass


class MyHashMap:
    def __init__(self):
        self.hm = [BST() for _ in range(10_000)]
    
    def findPos(self, key):
        return key % 10_000
        

    def put(self, key: int, value: int) -> None:
        pos = self.findPos(key)
        cur = self.hm[pos]
        cur.insert(key, value)

        
    def get(self, key: int) -> int:
        pos = self.findPos(key)
        cur = self.hm[pos]
        return cur.search(key)
        

    def remove(self, key: int) -> None:
        pos = self.findPos(key)
        cur = self.hm[pos]
        cur.remove(key)
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
