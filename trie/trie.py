class Node:
    def __init__(self, flag=False):
        self.flag = flag
        self.children = [None] * 26

    def isEnd(self) -> bool:
        return self.flag

    def setEnd(self) -> None:
        self.flag = True

    def containsKey(self, ch: str):
        return self.children[ord(ch) - ord("a")] != None

    def putKey(self, ch: str, node):
        self.children[ord(ch) - ord("a")] = node

    def getKey(self, ch):
        return self.children[ord(ch) - ord("a")]


class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word: str):
        temp = self.root
        for ch in word:
            if temp is not None:
                if temp.containsKey(ch) == False:
                    temp.putKey(ch, Node())
                temp = temp.getKey(ch)
        assert temp is not None
        temp.setEnd()

    def search(self, word: str):
        temp = self.root
        for ch in word:
            if temp is not None:
                if not temp.containsKey(ch):
                    return False
                temp = temp.getKey(ch)
        assert temp is not None
        return temp.isEnd()

    def startsWith(self, word: str):
        temp = self.root

        for ch in word:
            if temp is not None:
                if not temp.containsKey(ch):
                    return False
                temp = temp.getKey(ch)
        return True
