# 1340. Jump Game V

**Hard**
Given an array of integers `arr` and an integer `d`. In one step you can jump from index `i` to `index`:

- `i + x` where: `i + x < arr.length` and `0 < x <= d`.
- `i - x` where: `i - x >= 0` and `0 < x <= d`.

In addition, you can only jump from index `i` to index `j` if `arr[i] > arr[j]` and `arr[i] > arr[k]` for all indices `k` between `i` and `j` (More formally `min(i, j) < k < max(i, j)`).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.

배열내의 아무 기둥에서 시작해서, 최대 d의 거리만큼 멀리 떨어진 기둥으로 뛸 수 있다. 이때 뛸 수 있는 기둥은 사이에 더 큰 기둥이 없어야 한다. 최대로 많이 뛸 수 있는 경우는 몇개의 기둥을 지나갈 수 있는가?

Example 1:

![ex1](ex1.jpeg)

```
Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
Output: 4
Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as shown.
Note that if you start at index 6 you can only jump to index 7. You cannot jump to index 5 because 13 > 9. You cannot jump to index 4 because index 5 is between index 4 and 6 and 13 > 9.
Similarly You cannot jump from index 3 to index 2 or index 1.
```

Example 2:

```
Input: arr = [3,3,3,3,3], d = 3
Output: 1
Explanation: You can start at any index. You always cannot jump to any index.
```

Example 3:

```
Input: arr = [7,6,5,4,3,2,1], d = 1
Output: 7
Explanation: Start at index 0. You can visit all the indicies.
```

Example 4:

```
Input: arr = [7,1,7,1,7,1], d = 2
Output: 2
```

Example 5:

```
Input: arr = [66], d = 1
Output: 1
```

Constraints:

- `1 <= arr.length <= 1000`
- `1 <= arr[i] <= 10^5`
- `1 <= d <= arr.length`

# 풀이과정

다이나믹 프로그래밍으로 해결
Bottom-Up방식으로 작은숫자부터 최대 점프 수를 센다.

가장 작은 숫자부터 하나씩 꺼내서 해당 인덱스의 좌우로 뛸 수 있는 인덱스들을 찾는다.
사이에 더 큰 것이 있으면 점프하지 못하므로, 그때까지만 검사한다.
dp[k]는 k번째에서 가장 많이 방문할수있는 인덱스의 수이므로, max(dp[k]+1)이 dp[j]가 된다.

처음 풀이의 문제점.

1. 숫자들을 1부터 하나씩올려서 검사했다.
   숫자들이 커질수록 의미없는 반복이 늘었다.

해결. vector를 하나 더 만들어서 모든 숫자를 sort하고, 그 해당하는 숫자들만 찾았다.

2. 해당하는 인덱스를 찾기위해서 0인덱스부터 계속 뒤졌다.

해결. set과 pair를 활용해서 1번의 해결책에 더해서 인덱스도 바로 줌으로써 의미없는 반복이 매우 줄었다.
pair를 비교할때는 기본적으로 pair.first를 기준으로 비교가 되기 때문에 추가적인 비교함수를 만들 필요가 없어서 매우 편하다.

Runtime 변화 : Limit Exceeded(300ms+) -> 44ms

배운점.
C++을 사용할거면 적극적으로 STL을 활용하자.
