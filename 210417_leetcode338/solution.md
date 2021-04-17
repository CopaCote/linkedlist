# 338. Counting Bits

**Medium**
Given an integer `num`, return an array of the number of `1`'s in the binary representation of every number in the range `[0, num]`.

0 ~ num ������ ���ڸ� ��� �������� ǥ�������� ������ 1�� ������ ��� ��Ƽ� ��ȯ�϶�.

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

# Ǯ�̰���

���̳��� ���α׷������� �ذ�  
�������� 2^n������ ©�� ���� �պκ��� ������ �ݺ��Ѵ�.

���� �� [4,7], �� [2^2, 2^3-1] ������ ����  
4 = 100 = 1 + dp[0]  
5 = 101 = 1 + dp[1]  
6 = 110 = 1 + dp[2]  
7 = 111 = 1 + dp[3]  
���� 1�� ���������� �߰��ǰ�, ������ �޺�Ʈ�� 0~3������ ������ �ݺ��ȴ�.  
�׷��� ���� �����ڸ�

```
for(2^n <= i < 2^(n+1)):
    dp[i] = 1 + dp[i-2^n]
```

���� ����ϰ� ���´�.
