# 1611. Minimum One Bit Operations to Make Integers Zero

**Hard**
Given an integer `n`, you must transform it into `0` using the following operations any number of times:

- Change the rightmost (`0`^th^) bit in the binary representation of `n`.
- Change the `i`^th^ bit in the binary representation of n if the `(i-1)`^th^ bit is set to `1` and the `(i-2)`^th^ through `0`^th^ bits are set to `0`.

Return the _minimum number of operations to transform_ `n` into `0`.

어떠한 주어진 수 n을 이진수로 표현하였을때 아래의 규칙 둘 중 하나를 적용시켜서 최소 몇번의 연산이 진행되어야 0이 만들어질 것인가?

- 최하위 비트(0번비트)를 뒤집는다.
- `i-1`번째 비트가 1이고, `i-2`부터 `0`번째 비트까지 0이라면 `i`번째 비트를 뒤집는다.

Example 1:

```
Input: n = 0
Output: 0
```

Example 2:

```
Input: n = 3
Output: 2
Explanation: The binary representation of 3 is "11".
"11" -> "01" with the 2nd operation since the 0th bit is 1.
"01" -> "00" with the 1st operation.
```

Example 3:

```
Input: n = 6
Output: 4
Explanation: The binary representation of 6 is "110".
"110" -> "010" with the 2nd operation since the 1st bit is 1 and 0th through 0th bits are 0.
"010" -> "011" with the 1st operation.
"011" -> "001" with the 2nd operation since the 0th bit is 1.
"001" -> "000" with the 1st operation.
```

Example 4:

```
Input: n = 9
Output: 14
```

Example 5:

```
Input: n = 333
Output: 393
```

Constraints:

- `0 <= n <= 10^9`

# 풀이과정

## 규칙 찾기

규칙을 먼저 찾아야하는데, 처음에는 규칙이 매우 불규칙해 보인다. 따라서 이진수인만큼 처음의 접근은 2의 n승들을 본다.

0의 경우는 이진수로도 0이므로
총 0회가 소모된다.

1=2^0의 경우 이진수로도 `1`이므로
1번규칙에 의해 뒤집어서 `0`.
총 1회가 소모된다.

2=2^1의 경우 이진수로 `10`이므로
1번규칙에 의해 `11`
2번규칙에 의해 `01` // 바로 아랫비트가 1이고, 나머지는 없으므로 무시
1번규칙에 의해 `00`
총 3회가 소모된다.

4=2^2의 경우 이진수로 `100`이므로
1번규칙에 의해 `101`
2번규칙에 의해 `111`
1번규칙에 의해 `110`
2번규칙에 의해 `010`
1번규칙에 의해 `011`
2번규칙에 의해 `001`
1번규칙에 의해 `000`
총 7회가 소모된다.

8=2^3의 경우 이진수로 `1000`이므로
1번규칙에 의해 `1001`
2번규칙에 의해 `1011`
1번규칙에 의해 `1010`
2번규칙에 의해 `1110`
1번규칙에 의해 `1111`
2번규칙에 의해 `1101`
1번규칙에 의해 `1100`
2번규칙에 의해 `0100`
여기서 패턴을 본다면, 마지막 숫자 `0100`은 4이다. 그러므로 뒷부분은 4의 부분을 그대로 반복하게 된다.
그러므로 8+7 = 총 15회가 소모된다.

지금까지 본다면 2^n 숫자들은 2^(n+1)-1번이 최소횟수가 된다.

다음은 나머지 숫자들인데, 각각의 숫자를 2^n들의 합이라고 생각한다면, 2^n에서 2^(n+1)사이의 숫자는 2^n 비트패턴보다 적은 횟수가 들고, 거기에 도달하는게 걸리는 횟수가 그 차감되는 양이다.
즉, `1010`을 예로 든다면,
`1010`은 `10`이 `00`이 되는데 걸리는 횟수만큼 적게든다.
왜냐하면 우리가 `1000`에서 `0000`으로 만드는 과정에 `1000`을 `1010`으로 만들기때문에, 그대로 역과정이 걸리는 횟수가 `10`이 `00`으로 바뀌는 과정이기 때문이다.
즉 `1000`의 횟수 15회 - `10`의 횟수 3회 = 12회가 걸리게 되고, 확인해보면 실제로 3회가 적게든다.

이제 복잡한 예시를 보자.
`1110`을 본다면 같은 법칙에 의해서 최소 횟수는
`1000`의 횟수 - `110`의 횟수가 된다.
재귀적으로 본다면, 또 `110`의 횟수는
`100`의 횟수 - `10`의 횟수가 되므로
최종적으로
`1000`의 횟수 - (`100`의 횟수 - `10`의 횟수)이므로
플마가 반복되는 `1000`횟수 - `100`횟수 + `10`횟수의 방식을 띄게 된다.

여기까지 약 40분이 걸렸다....

## 코딩

이제는 이것을 코딩해야하는데, 처음엔 반복문을 이용해서 하려했는데, 누가봐도 오래걸릴것같다.
최상위비트부터 보면서 그것에 맞는 2^n^을 더하고 빼주면서 내려가야하는데, 이중반복문이되고, O(n^2^) 시간복잡도가 나오게되서, 이진수에 걸맞게 비트마스킹을 이용하기로 했다.

int타입으로 숫자를 받으니까, 최상위 부호비트를 제외하고 31번째비트부터 검사를 해도되고, 숫자 범위인 10^9^을 변환해보니 30번째비트까지만 사용하길래 30번째비트부터 검사했다.

방식은 단순하게 `00100000 00000000 00000000 00000000`부터 시작해서 AND 비트연산을 이용해서 0이 나오면 그 자리에 숫자가 없는 것이니, 2를 나눠가면서 일일이 해보면 O(n)으로 연산을 줄일수 있다.
또한 해당 자리가 0이 아니라면 위의 공식에 의해서 `2^(n+1) - 1`을 구해야하는데, 바로 윗자리이므로 그냥 2를 곱해서 1만 빼주면되어서 매우 간결해진다.

```
mask = 0x20 00 00 00;
sign = 1; // 이것으로 덧셈뺄셈을 왔다갔다하게 구현
totalOps = 0;
WHILE mask > 0 :
    IF (mask & n) != 0 :
        totalOps = totalOps + sign*(mask*2-1)
        sign = sign * -1
    mask = mask / 2
```