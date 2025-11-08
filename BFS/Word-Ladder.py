class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # Check if the endWord is in the list
        if endWord not in wordList:
            return 0
        
        # Adjacency list
        adj = collections.defaultdict(list)

        # Since beginWord may not be in the list, add it
        wordList.append(beginWord)

        # Go through every word
        # Replace every character of the word with a wildcard
        # Push the word into the pattern it matches
        # Because it means there's 1 character difference
        for w in wordList:
            for j in range(len(w)):
                pat = w[:j] + "*" + w[j+1:]
                adj[pat].append(w)
        
        vis = set([beginWord])
        res = 1

        q = deque([beginWord])
        while q:
            for i in range(len(q)):
                w = q.popleft()
                # If the word is the endWord, return res
                if w == endWord:
                    return res
                
                # Otherwise do a bfs
                # This step explores all the neighbors
                # The set prevents revisting neighbors again
                for j in range(len(w)):
                    pat = w[:j] + "*" + w[j+1:]
                    for word in adj[pat]:
                        if word not in vis:
                            vis.add(word)
                            q.append(word)
            # After exploring a level increment res by 1
            res+=1
        # If no word was found, return 0
        return 0


        
        
