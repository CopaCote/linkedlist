# 778. Swim in Rising Water

**Hard**
On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

(0,0)에서 (N-1, N-1)로 길을 이어주려면 최소한의 time t는 얼마인가?

Example 1:

```
Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
```

Example 2:

```
Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
```

Note:

- 2 <= N <= 50
- grid[i][j] is a permutation of [0, ..., N*N - 1]

# 풀이과정

단순하게 DFS를 이용해서 상하좌우 다 조사하고, 진행할 수 있는지 bool값으로 return하여 해결하였다.
처음에 실수한 것으로는 경로를 출력할 때처럼 재귀의 끝에 visited = false를 달아 주었었는데, 생각해보니 경로가 존재한다는 것만 확인하면 되어서, 굳이 그렇게 하지 않아도 되었다. (이것때문에 time exceed에서 엄청해맸다.)

시간을 줄이기 위해서 할 수 있던것은 크게 2가지이다.

1. 시작하는 time 값 결정을 잘하기.
   무조건 (0,0)과 (N-1,N-1)을 지나기 때문에, 둘중에 MAX값을 취해서 이 숫자부터 탐색해주어야 한다.
2. 이분탐색 활용
   Related Topics에 이분탐색이 있었지만 어떻게 해야하는지 몰라서 처음에 활용은 안했고, 당연하게도 time을 하나씩 증가시켜서 찾아보는 것보다는 효율적인데, 사용하고 안하고의 차이는 12ms -> 8ms 정도였다. 이분탐색은 해본적이 없어서 어쩔 수 없이 다른 사람 코드를 찾아보다가 이해하고 내 코드에 적어놓았다.
