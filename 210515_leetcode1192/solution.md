# 1192. Critical Connections in a Network

**Hard**
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

EdgeList에서 끊게된다면 Fully Connected가 무너지게 되는 Edge들 반환하기

Example 1:
![ex1](1537_ex1_2.png)

```
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
```

Constraints:

- 2 <= n <= 10^5
- n - 1 <= connections.length <= 10^5
- 0 <= ai, bi <= n - 1
- ai != bi
- There are no repeated connections.

# 풀이과정

처음에는 크게 생각하지 않고, 그냥 DFS를 써서 혼자 동떨어지는 노드가 생기면 엣지를 기록하게 했는데, 다른 Test Case를 보니 아예 잘못 생각했다는 것을 깨달아서 타잔 알고리즘에 대해서 검색해서 나름 구현해보려고 노력은 했다.
다만 서로 최상위 부모를 찾아서 분리시켜주는 일은 끝났는데, 두개의 다른 부모 그룹에 대해서 연결된 간선을 출력시키는 과정에서 문제가 생겨서 해결을 끝내지 못했다...
타잔 알고리즘 같은 경우에는 아래의 블로그를 보고 대충 이해해서 구현했다.
https://taesung1993.tistory.com/53
