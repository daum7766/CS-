from linked_list import LinkedList

linked_list = LinkedList()

linked_list.append(1)
linked_list.append(2)
linked_list.append(3)
print(linked_list)

print('리스트의 처음값은 {}입니다.'.format(linked_list.getFirst()))
print('리스트의 마지막값은 {}입니다.'.format(linked_list.getLast()))
print('{}번째 인덱스에 있는값은 {}입니다.'.format(1, linked_list.get(1)))

linked_list.insert(0, 0)
print('0번째에 0을 넣으면 아래와 같습니다.')
print(linked_list)

print('제일 마지막 데이터를 빼면 아래와 같습니다.')
linked_list.pop()
print(linked_list)

print('여기에 1번 인덱스 데이터를 빼면 아래와 같습니다.')
linked_list.pop(1)
print(linked_list)

print('0번 인덱스 데이터를 1로 바꾸면 아래와 같습니다.')
linked_list.change(0, 1)
print(linked_list)