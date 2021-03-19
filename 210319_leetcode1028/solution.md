# 1028. Recover a Tree From Preorder Traversal

**Hard**
We run a preorder depth-first search (DFS) on the `root` of a binary tree.

At each node in this traversal, we output `D` dashes (where `D` is the depth of this node), then we output the value of this node. If the depth of a node is `D`, the depth of its immediate child is `D + 1`. The depth of the `root` node is `0`.

If a node has only one child, that child is guaranteed to be **the left child**.

Given the output `S` of this traversal, recover the tree and return its `root`.

입력값으로는 string타입으로 트리의 DFS결과가들어오고, 답으로는 TreeNode들을 직접연결해서 root를 반환하면 된다.

Example 1:
![ex1](ex1.png)

```
Input: S = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
```

Example 2:
![ex2](ex2.png)

```
Input: S = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
```

Example 3:
![ex3](ex3.png)

```
Input: S = "1-401--349---90--88"
Output: [1,401,null,349,88,90]
```

Constraints:

- The number of nodes in the original tree is in the range `[1, 1000]`.
- `1 <= Node.val <= 10^9`

# 풀이과정

기본적인 과정은 이렇다.

1. root는 이미 들어있다고 가정한다. (S에서 첫 숫자는 일단 무시). 현재 깊이 수치 depth를 0으로 둔다.
2. 바로뒤의 -의 갯수를 본다.
   2-1. 현재 depth보다 높다면 자식으로 달리게 된다.
   이때 깊이우선 탐색이므로, 무조건적으로 늘어나면 자식일 수 밖에 없다.
   2-2. 현재 depth보다 작거나 같다면 부모를 계속 타고 올라가서, -의 갯수보다 1개 작은 depth의 부모를 찾아서 자식으로 달아준다.
   이후 현재 depth값을 -의 갯수로 바꿔준다.
3. 2의 과정을 S가 끝날때까지 반복한다.

다른 부분은 다 할만했는데, 주어진 조건의 node가 부모정보를 포함하고 있지 않았기 때문에, 부모를 타고 올라가는 방식이 처음에 재귀호출밖에 생각나지를 않아서 망한 풀이부터 소개한다.

## 망한 풀이

재귀호출을 할 함수를 만들었다.
전역으로 string변수를 만들었으면 좀더 편하게 했을텐데, 풀던 당시에는 생각나지 않았다
`string addChild(TreeNode* parent, int depth, string S)`
이 함수에서는 현재의 depth값을 주고, 자식으로 달 수 있는 parent node를 다음 depth 값이 현재 depth 보다 높다면 달 수 있도록 주었다.

```
int d = 0;
size_t p = 0;
while(S[d] == '-')
    d++;
if(d > depth){
    S = S.substr(d);
    parent->left = new TreeNode(stoi(S,&p));
    S = S.substr(p);
    S = addChild(parent->left,depth+1,S);
}else
    return S;
```

S로 하는것은 -부분의 갯수를 세서 짜르고, 첫 숫자를 변환 시킨 다음에, 짜르고 반환하는 일이다.
좌우 자식이 모두 있을 수 있으니 위의 과정을 좌우 모두 한번씩 해준다.
자식으로 달지않고 return할때 -부분을 짜르지 않는 이유는 바깥으로 타고타고 나가면서 다시 세야하기 때문이다.

재귀함수를 만들어 준 이후에는, root부분의 코딩만 따로 해주어서 재귀함수를 시작 시켜주었다.

## 문제점

당연하게도 재귀함수는 노드의 갯수가 많아지면 미친듯이 메모리 소모량이 올라간다.
Runtime: 44 ms
Memory Usage: 284.4 MB
그래프를 보니 런타임은 그렇다쳐도, 메모리 사용량 등수가 무려 밑에서 15%였다.

## 재구상

제출 이후에 다시 생각해보니, 애초에 재귀함수가 스택구조를 이용하므로, 애초부터 스택을 반복문에 넣고 돌리면 함수호출이 없어져서 매우 빨라질 것이라고 생각했다.

재귀함수의 return과정이 pop이고, 새로운 함수호출을 하는 것을 push로 수정하면 매우 간결해지게 된다.

```
int currDepth = 0;
while(S != string()){
    int nextDepth = 0;
    p = 0;
    while(S[nextDepth] == '-')
        nextDepth++;
    for(int i=0;i<=currDepth-nextDepth;i++)
        myStack.pop();
    S = S.substr(nextDepth);
    TreeNode* child = new TreeNode(stoi(S,&p));
    S = S.substr(p);
    addChild(myStack.top(),child);
    myStack.push(child);
    currDepth = nextDepth;
}
```

Runtime: 32 ms
Memory Usage: 192 MB

함수호출을 없앴을뿐인데 메모리가 90mb나 줄었다. 이제는 런타임을 줄일 차례다.

코드를 살펴보니, vector타입에서는 요소를 지우지 않도록 주의하는데, string에서는 그것을 간과하고 자꾸 substr 함수로 string을 자꾸 바꿔버린다.

그래서 마지막으로는 substr으로 짜르는 부분들과 stoi를 이용하는 것을 전부 인덱스를 활용해서 구현해주었다. 애초부터 짜르는 이유가 stoi를 편하게 호출하기 위함이였는데, 여러자리 숫자를 인덱스만 가지고 찾아낼수 있도록 수정했다.

```
while(index < S.size() && S[index] != '-'){
    val = val*10 + (S[index]-'0'); index++;
}
```

최종적으로 나온 결과는
Runtime: 12ms
Memory Usage: 19.4 MB
처음에 만든 결과보다 메모리 사용량이 10배가량 줄었다...
