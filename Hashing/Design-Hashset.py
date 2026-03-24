'''
Create an array of 10,000 entries
Each entry is a BST
Values are taken and a hash is computed 
and inserted into the BST

add -> Find its key, Insert into BST
remove -> Find the key, Remove from BST
contains -> Check if it exists
'''
class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None
    
    def insert(self, root, key):
        if not root:
            return TreeNode(key)

        if key < root.key:
            root.left = self.insert(root.left, key)
        elif key > root.key:
            root.right = self.insert(root.right, key)
        return root
    
    def delete(self, root, key):
        if not root:
            return None
        if key < root.key:
            root.left = self.delete(root.left, key)
        elif key > root.key:
            root.right = self.delete(root.right, key)
        else:
            # Left doesn't exist
            # replace root with its right child
            if not root.left:
                return root.right
            # Right doesn't exist
            # replace root with its left child
            elif not root.right:
                return root.left
            
            # Find inorder suceesor
            # THe smallest node from right sub-tree
            # replace it with that, as that is the next 
            # root in line
            temp = self.minValue(root.right)
            # Copy its value
            root.key = temp.key
            root.right = self.delete(root.right, temp.key)
        
        def minValue(self, root):
            while root.left:
                root = root.left
            return root

    
    def search(self, root, key):
        while root:
            if root.key == key:
                return True
            elif root.key < key:
                root = root.right
            else:
                root = root.left
        
        return False

    def add(self, key):
        self.root = self.insert(self.root, key)
    
    def remove(self, key):
        self.root = self.delete(self.root, key)
    
    def contains(self, key):
        return self.search(self.root, key)

        
class MyHashSet:

    def __init__(self):
        self.size = 10000
        self.buckets = [BST() for _ in range(self.size)]
    
    def _hash(self, key):
        return key % self.size

        
    def add(self, key: int) -> None:
        idx = self._hash(key)
        if not self.contains(key):
            self.buckets[idx].add(key)
        

    def remove(self, key: int) -> None:
        idx = self._hash(key)
        self.buckets[idx].remove(key)
        

    def contains(self, key: int) -> bool:
        idx = self._hash(key)
        return self.buckets[idx].contains(key)
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
