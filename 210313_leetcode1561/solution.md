# 1561. Maximum Number of Coins You Can Get

**Medium**
There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:

- In each step, you will choose any 3 piles of coins (not necessarily consecutive).
- Of your choice, Alice will pick the pile with the maximum number of coins.
- You will pick the next pile with maximum number of coins.
- Your friend Bob will pick the last pile.
- Repeat until there are no more piles of coins.
  Given an array of integers piles where piles[i] is the number of coins in the ith pile.

Return the maximum number of coins which you can have.

3n개의 동전뭉치가 있다.
나, Alice, Bob은 세명이서 각각 동전뭉치를 하나씩 가져가기로하였다.
많은 뭉치들중에서 3개씩 선정해서 그 3 뭉치중에서 가장 동전이 많은 것을 Alice가, 그 다음으로 많은 것을 내가, 마지막으로 남은 뭉치를 Bob이 가져가기로 하였다.
내가 최대한 많이 가져갈 수 있는 동전의 수는 몇개인가?

Example 1:

```
Input: piles = [2,4,1,2,7,8]
Output: 9
Explanation: Choose the triplet (2, 7, 8), Alice Pick the pile with 8 coins, you the pile with 7 coins and Bob the last one.
Choose the triplet (1, 2, 4), Alice Pick the pile with 4 coins, you the pile with 2 coins and Bob the last one.
The maximum number of coins which you can have are: 7 + 2 = 9.
On the other hand if we choose this arrangement (1, 2, 8), (2, 4, 7) you only get 2 + 4 = 6 coins which is not optimal.
```

Example 2:

```
Input: piles = [2,4,5]
Output: 4
```

Example 3:

```
Input: piles = [9,8,7,6,5,1,2,3,4]
Output: 18
```

Constraints:

- `3 <= piles.length <= 10^5`
- `piles.length % 3 == 0`
- `1 <= piles[i] <= 10^4`

# 풀이과정

내가 가장 많은 동전을 가져가는 경우의 수는 결국에 Alice와 Bob이 각각 제일 각 순서마다 가장 높은 갯수와 가장 적은 갯수를 하나씩 없애주는 경우가 이상적이다.

가장 큰 것과 작은 것을 찾기 위해서는 당연하게도 정렬을 해놓고 시작하는 것이 빠르다.
`std::sort(piles.begin(), piles.end());`

이후는 간단하게 반복문으로 처리할 수 있는데, C++을 사용하는만큼 반복자를 연습하기 위해서 반복자로써 표현해보았다.

```
        vector<int>::iterator bob = piles.begin();
        vector<int>::iterator alice = --piles.end();

        while (1)
        {
            alice--;
            bob++;
            answer += *alice;
            if (alice == bob)
                break;
            alice--;
        }
```

`piles.end()`는 vector의 마지막 요소 바로 뒤를 가르키니까 실제 마지막 요소부터 시작하기 위해서 Alice는 `--pile.end()`로 시작한다.
Alice가 하나 가져가서 `alice--`, Bob이 하나 가져가서 `bob++`, 그다음 나는 큰 숫자를 가져가는 것이 이상적이므로 answer를 더해주고, 만약 뭉치가 더 이상 없다면 둘의 반복자는 같은 위치를 가리키고 있을것이다.
뭉치가 더 있다면 다음 뭉치를 보기위해서 Alice 반복자를 한칸 더 땡겨주고 다시 시작한다.
