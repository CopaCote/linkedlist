# 1289. Minimum Falling Path Sum II

**Hard**
Given a square grid of integers `arr`, a falling path with non-zero shifts is a choice of exactly one element from each row of `arr`, such that no two elements chosen in adjacent rows are in the same column.

Return the minimum sum of a falling path with non-zero shifts.

Row마다 숫자를 하나씩 골라서, 최솟값을 만들면된다. 이때 인접하는 Row들은 서로 같은 Column번호를 사용하면 안된다.

Example 1:

```
Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation:
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.
```

Constraints:

- `1 <= arr.length == arr[i].length <= 200`
- `-99 <= arr[i][j] <= 99`

# 풀이과정

다이나믹 프로그래밍
위에서부터 차근차근 최솟값들을 저장해가면서 진행하였다.
윗줄에서 같은 Column을 제외한 나머지 숫자들 중에서 가장 작은 수와 현재값을 더하면 dp[i][j] 즉 현재 자리까지 오는 최소 값이 된다.

3중 반복문을 사용하였지만, 속도가 너무 느리게 나와서, 알고리즘을 찾아보니까 min_element 함수를 대신 적용시켜보니 훨씬 빠르게 나왔다.
범위를 다르게 잡아주고 싶었는데, 어떻게 할줄 몰라서 3범위로 나누어서 일일이 계산해주었다.

Runtime 변화 : 272ms -> 76ms
