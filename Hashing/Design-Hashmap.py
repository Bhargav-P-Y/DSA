'''
I could use an array with 1_000_000 entries
That would take too much space

I could shrink the array to 10_000 cells
and each cell could have 100 entries
It reduces the space used

But I lose the unique association between the key and its value
So each cell in the array should store pairs of key & its value?

SO first declare an array with 10_000 cells

Don't forget to return root, this is recursion!
'''
class TreeNode:
    def __init__(self, key = 0, val= 0):
        self.node = [key, val]
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None
    
    def insert(self, cur, key, val):
        # recursively check and insert into left or right subtree

        # Base case
        if not cur:
            return TreeNode(key, val)

        # Already exists then update & return
        if cur.node[0] == key:
            cur.node[1] = val
            return cur
        
        if cur.node[0] > key:
            # recurse with left subtree
            cur.left = self.insert(cur.left, key, val)
        else:
            # otherwise the right subtree
            cur.right = self.insert(cur.right, key, val)
        
        return cur


    def minValueNode(self, cur):
        while cur.left:
            cur = cur.left
        return cur

    def delete(self, root, key):
        '''
        Three cases
        Both children exist
        Only left exists
        Only right exists
        Nothing exists
        '''
        # Base case
        if not root:
            return None
        
        if root.node[0] < key:
            root.right = self.delete(root.right, key)
        
        elif root.node[0] > key:
            root.left = self.delete(root.left, key)
        
        else:
            # Left doesn't exist
            # return right child
            if not root.left:
                return root.right
            # Right doesn't exist
            # return left child
            elif not root.right:
                return root.left
            else:
                # find inorder successor
                tmp = self.minValueNode(root.right)
                root.node = tmp.node

                root.right = self.delete(root.right, tmp.node[0])
        
        return root
                

    def search(self, cur, key):
        while cur:
            if cur.node[0] == key:
                return cur.node[1]
            elif cur.node[0] > key:
                cur = cur.left
            else:
                cur = cur.right

        return -1


    def add(self, key, value):
        self.root = self.insert(self.root, key, value)
    
    def remove(self, key):
        self.root = self.delete(self.root, key)
    
    def contains(self, key):
        return self.search(self.root, key)


class MyHashMap:
    def __init__(self):
        self.hm = [BST() for _ in range(10_000)]
    
    def findPos(self, key):
        return key % 10_000
        

    def put(self, key: int, value: int) -> None:
        pos = self.findPos(key)
        cur = self.hm[pos]
        cur.add(key, value)

        
    def get(self, key: int) -> int:
        pos = self.findPos(key)
        cur = self.hm[pos]
        return cur.contains(key)
        

    def remove(self, key: int) -> None:
        pos = self.findPos(key)
        cur = self.hm[pos]
        cur.remove(key)
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
