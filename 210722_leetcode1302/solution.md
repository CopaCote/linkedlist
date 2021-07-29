# 1302. Deepest Leaves Sum

**Medium**
Given the root of a binary tree, return the sum of values of its deepest leaves.

가장 깊은 Leaf들의 값을 더해서 반환해라

Example 1:
![ex1](1483_ex1.png)
```
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
```

Example 2:
```
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
```

Constraints:
- The number of nodes in the tree is in the range [1, 104].
- 1 <= Node.val <= 100

# 풀이과정
트리의 dfs 탐색으로 leaf들을 깊이값과 함께 배열에 pair로 넣어주고 탐색이 끝난 뒤에 깊이순으로 정렬하여 가장 높은 깊이값들만 더해서 반환하였다.