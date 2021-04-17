# 338. Counting Bits

**Medium**
Given an integer `num`, return an array of the number of `1`'s in the binary representation of every number in the range `[0, num]`.

0 ~ num 사이의 숫자를 모두 이진수로 표현했을때 각각의 1의 갯수를 모두 담아서 반환하라.

Example 1:

```
Input: num = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
```

Example 2:

```
Input: num = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
```

Constraints:

- `0 <= num <= 10^5`

Follow up:

- It is very easy to come up with a solution with run time `O(32n)`. Can you do it in linear time `O(n)` and possibly in a single pass?
- Could you solve it in `O(n)` space complexity?
- Can you do it without using any built-in function (i.e., like `__builtin_popcount` in C++)?

# 풀이과정

다이나믹 프로그래밍으로 해결  
이진수를 2^n단위로 짤라서 보면 앞부분의 패턴이 반복한다.

예를 들어서 [4,7], 즉 [2^2, 2^3-1] 까지를 보자  
4 = 100 = 1 + dp[0]  
5 = 101 = 1 + dp[1]  
6 = 110 = 1 + dp[2]  
7 = 111 = 1 + dp[3]  
앞의 1은 고정적으로 추가되고, 나머지 뒷비트는 0~3까지의 패턴이 반복된다.  
그래서 식을 세우자면

```
for(2^n <= i < 2^(n+1)):
    dp[i] = 1 + dp[i-2^n]
```

으로 깔끔하게 나온다.
