# 138. Copy List with Random Pointer 

**Medium**
A linked list of length `n` is given such that each node contains an additional random pointer, which could point to any node in the list, or `null`.

Construct a **deep copy** of the list. The deep copy should consist of exactly `n` **brand new nodes**, where each new node has its value set to the value of its corresponding original node. Both the `next` and `random` pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. **None of the pointers in the new list should point to nodes in the original list.**

For example, if there are two nodes `X` and `Y` in the original list, where `X.random --> Y`, then for the corresponding two nodes `x` and `y` in the copied list, `x.random --> y`.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of `n` nodes. Each node is represented as a pair of `[val, random_index]` where:

- `val`: an integer representing `Node.val`
- `random_index`: the index of the node (range from `0` to `n-1`) that the `random` pointer points to, or `null` if it does not point to any node.
Your code will **only** be given the `head` of the original linked list.

링크드 리스트를 복사해라. 이때 next포인터만 있는게 아니라, 어디든 갈 수 있는 random 포인터도 노드에 하나씩 존재한다. 이것까지 deep copy를 잘 실행해라.

Example 1:
![ex1](e1.png)

```
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
```

Example 2:
![ex2](e2.png)

```
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
```

Example 3:
![ex3](e3.png)

```
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
```

Example 4:
```
Input: head = []
Output: []
Explanation: The given linked list is empty (null pointer), so return null.
```

Constraints:

- 0 <= n <= 1000
- -10000 <= Node.val <= 10000
- Node.random is null or is pointing to some node in the linked list.

# 풀이과정
처음 한바퀴를 돌면서 노드의 element와 next들을 모두 copy하여 연결한다. 이때 map도 하나 생성해서 n번째 노드의 원본과 copy를 각각 key와 value로 묶어준다. 
두번째 바퀴를 돌면서 원본의 각 random 포인터를 map을 참고하면서 copy에다가 연결해준다.