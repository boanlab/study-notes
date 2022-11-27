class SingleLinkedList:
    class _Node:
        def __init__(self, value=None, link=None):    # 노드 생성자
            self._value = value             # 저장된 데이터           
            self._next = link               # 다음 노드 래퍼런스
        
        def __str__(self):
            return str(self._value)
    
    def __init__(self):
        self._head = None                   # 첫 생성 시 내부에 노드가 없음
    
    # 삽입 - 첫번째
    def addFirst(self, value):
        self._head = self._Node(value, self._head)
    
    # 삽입 - node가 가리키는 노드 다음에 새 노드 삽입
    def addAfter(self, value, node):
        node._next = SingleLinkedList._Node(value, node._next)

    