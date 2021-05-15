# 1192. Critical Connections in a Network

**Hard**
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

EdgeList���� ���Եȴٸ� Fully Connected�� �������� �Ǵ� Edge�� ��ȯ�ϱ�

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

# Ǯ�̰���

ó������ ũ�� �������� �ʰ�, �׳� DFS�� �Ἥ ȥ�� ���������� ��尡 ����� ������ ����ϰ� �ߴµ�, �ٸ� Test Case�� ���� �ƿ� �߸� �����ߴٴ� ���� ���޾Ƽ� Ÿ�� �˰��� ���ؼ� �˻��ؼ� ���� �����غ����� ����� �ߴ�.
�ٸ� ���� �ֻ��� �θ� ã�Ƽ� �и������ִ� ���� �����µ�, �ΰ��� �ٸ� �θ� �׷쿡 ���ؼ� ����� ������ ��½�Ű�� �������� ������ ���ܼ� �ذ��� ������ ���ߴ�...
Ÿ�� �˰��� ���� ��쿡�� �Ʒ��� ��α׸� ���� ���� �����ؼ� �����ߴ�.
https://taesung1993.tistory.com/53
