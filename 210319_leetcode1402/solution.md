# 1402. Reducing Dishes

**Hard**
A chef has collected data on the `satisfaction` level of his `n` dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. `time[i]*satisfaction[i]`

Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in **any** order and the chef can discard some dishes to get this maximum value.

n개의 음식들에 대해서 각각의 만족도 수치가 나와있다.
셰프는 1 시간단위에 1개의 음식만 조리할 수 있다.
Like-time coefficient는 나오는데 걸리는시간 \* 만족도 수치로 계산이 가능한데, 음식의 목록 중 원하는 숫자만큼 아무렇게나 만들어도 된다고할때(아예 안만드는 것도 가능) 최대로 뽑을 수 있는 Like-time Coefficient는 얼마인가?

Example 1:

```
Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). Each dish is prepared in one unit of time.
```

Example 2:

```
Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
```

Example 3:

```
Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People don't like the dishes. No dish is prepared.
```

Example 4:

```
Input: satisfaction = [-2,5,-1,0,3,-3]
Output: 35
```

Constraints:

- `n == satisfaction.length`
- `1 <= n <= 500`
- `-10^3 <= satisfaction[i] <= 10^3`

# 풀이과정

공식에 의해서 배열의 뒤쪽에 높은 만족도들이 오는 것이 곱셈에서 더욱 더 이득을 취할 수 있기 때문에 당연하게도 오름차순으로 정렬을 해놓는 것이 필요하다.
`std::sort(satisfaction.begin(), satisfaction.end())`

이제 다음문제는 어떤 음식들을 버리는지가 관건인데, 단순히 생각해보면 음수들을 버리는 것이 더 이득이라고 생각할 수도 있다. 하지만 아래의 예를 생각해보자.
`Input : satisfaction = [-1,2]`
이 경우에서는 -1을 버리게 되면 수치는 2x1로써 2가 나오게 되지만, 음수를 안버리게 되면 오히려 2가 2로 곱해짐으로써 최종적으로 3의 수치가 나오게 된다.

따라서 사실상 모든 경우의 수를 도는 것이 가장 간단한 해결책이다.

이중 반복문을 돌면서 최대치를 찾는 것밖에 방법이 보이질 않는다.
대신에 음식을 버릴때는 가장 작은수부터 하나씩 버려가는 방향으로 가야 항상 n개를 버린다고 했을때의 최대 수치가 나오게 된다.

```
for (int i = 0; i <= satisfaction.size(); i++)
    {
        int tempSat = 0;
        for (int j = i; j < satisfaction.size(); j++)
        {
            tempSat += (j - i + 1) * satisfaction[j];
    }
        if (tempSat > maxNum)
            maxNum = tempSat;
    }
```

그나마 조심한 점은 vector 자료형은 요소를 지우게 되면, 앞을 지우면 전부 당겨주는 작업이 자동으로 호출되고, 뒤를 지워도 크기의 변화로 인해 메모리 재할당이 일어날 수 있으니 가급적이면 index만 이용해서 vector자체는 삭제를 하지 않는 방향으로 코딩을 해줘야 속도가 나온다.
