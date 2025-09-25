#Validate serailized string?
#Slot count method: if #: slot -=1
#                   else: slot -=1 then slot +=2
# At the end check if slots == 0

# N stores 2 bytes, # only 1, so choose #

class Codec:
    
    # Encodes a tree to a single string

    def serialize(self, root: Optional[TreeNode]) -> str:
        vals = []

        def dfs(root):
            if not root:
                vals.append("#")
                return
            vals.append(str(root.val))
            dfs(root.left)
            dfs(root.right)

        dfs(root)
        return " ".join(vals)

        
    # Decodes your encoded data to tree.

    def deserialize(self, data: str) -> Optional[TreeNode]:
        nodes = data.split("#")
        
        self.i = 0

        def dfs(nodes):
            if nodes[self.i] == "#":
                self.i +=1
                return None
            node = TreeNode(int(nodes[self.i]))
            self.i+=1
            node.left = dfs(nodes)
            node.right = dfs(nodes)

            return node
        return dfs(nodes)
        




