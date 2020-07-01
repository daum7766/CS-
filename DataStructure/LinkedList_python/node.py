#연결리스트에 사용될 노드
class Node:
    # 생성자
    def __init__(self, item):
        self.back_link = None
        self.item = item
        self.next_link = None