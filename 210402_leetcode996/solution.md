# 996. Number of Squareful Arrays

**Hard**
Given an array `A` of non-negative integers, the array is squareful if for every pair of adjacent elements, their sum is a perfect square.

Return the number of permutations of A that are squareful. Two permutations `A1` and `A2` differ if and only if there is some index `i` such that `A1[i] != A2[i]`.

숫자들을 잘 배열해서 서로 인접하는 수의 덧셈이 모두 제곱수가 되도록 하는 경우의 수를 모두 계산하여라. 이때 중복은 세지 않는다.

Example 1:

```
Input: [1,17,8]
Output: 2
Explanation:
[1,8,17] and [17,8,1] are the valid permutations.
```

Example 2:

```
Input: [2,2,2]
Output: 1
```

Note:

1. `1 <= A.length <= 12`
2. `0 <= A[i] <= 1e9`

# 풀이과정

기본 베이스는 dfs이므로,
visited표시를 해주면서 조건에 맞으면 들어가고, 재귀를 탈출할때 visited를 다시 false로 바꿔주면서 결과값들을 새어주었다.

처음엔 단순히 제곱수만 보면서 dfs를 한 후에 결과들의 중복값들을 없애주려니까 당연하게도 시간이 넘어갔다.
ex) 시간오버된 예시가... `[2,2,2,2,2,2,2,2,2,2]` 같은것..

중복 조합들을 없애기 위해서 열심히 고민해 본 결과, 두개의 같은 수를 이용할때 모든 경우가 2배씩 적용되었다.
그렇기 때문에 이 숫자가 두번째 이용되는 숫자면 반대경우를 적용시키지 않도록 해야하는데, 그것을 편하게 하기 위해서 sort를 해주고, 바로 앞번째 숫자와 비교하여서, 앞번째 visited가 false이면 어차피 같은 수순을 밟게 될 것이므로 continue를 해주는 것이 핵심이었다.

```
if(i>0 && (A[i] == A[i-1]) && visited[i-1]==false)
	continue;
```
