# 173. Binary Search Tree Iterator

**Medium**
Implement the `BSTIterator` class that represents an iterator over the **in-order traversal** of a binary search tree (BST):

- `BSTIterator(TreeNode root)` Initializes an object of the `BSTIterator` class. The `root` of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
- `boolean hasNext()` Returns `true` if there exists a number in the traversal to the right of the pointer, otherwise returns `false`.
- `int next()` Moves the pointer to the right, then returns the number at the pointer.

Notice that by initializing the pointer to a non-existent smallest number, the first call to `next()` will return the smallest element in the BST.

You may assume that `next()` calls will always be valid. That is, there will be at least a next number in the in-order traversal when `next()` is called.

중위순회 결과를 한개씩 출력해주는 유사 반복자를 구현해라.
next()로 다음결과가 나오고, hasNext()로 다음 출력할 것이 있는지 bool로 표현해라.

Example 1:

![ex1](ex1.png)

```
Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
```

Constraints:

- The number of nodes in the tree is in the range `[1, 10^5]`.
- `0 <= Node.val <= 10^6`
- At most `10^5` calls will be made to `hasNext`, and `next`.

Follow up:

- Could you implement `next()` and `hasNext()` to run in average `O(1)` time and use `O(h)` memory, where `h` is the height of the tree?

# 풀이과정

Tree의 기본에 충실하게 단순한 재귀호출과 스택을 이용해서 반복자를 구현해주었다.

중위순회는 왼쪽자식, 본인, 오른쪽자식으로 순회를 도니까, 출력을 그렇게 뽑으려면 스택에는 역순인 오른쪽자식, 본인, 왼쪽자식순으로 넣어준다.

단순히 next에서는 pop()을 해주고, hasNext에서는 empty()를 불러서 검사만 해준다.

다른사람보다는 비교적으로 오래걸렸지만 순회를 재귀적으로 하고싶었으므로 이런 결과가 나왔다.
