# 1665. Minimum Initial Energy to Finish Tasks

**Hard**
You are given an array `tasks` where `tasks[i] = [actual i, minimum i]`:

- actual~i~ is the actual amount of energy you **spend to finish** the `i`^th^ task.
- minimum~i~ is the minimum amount of energy you **require to begin** the `i`^th^ task.
  For example, if the task is `[10, 12]` and your current energy is `11`, you cannot start this task. However, if your current energy is `13`, you can complete this task, and your energy will be `3` after finishing it.

You can finish the tasks in **any order** you like.

Return the **_minimum_** initial amount of energy you will need to finish all the tasks.

task 배열의 각 요소는 actual과 minimum의 값이 있는데, minimum이 시작하기 위해서 필요한 최소 에너지, actual은 실제로 소모되는 에너지이다. 순서는 임의로 할 수 있다고 할 때 가장 최소한으로 필요한 에너지는 얼마인가.

Example 1:

```
Input: tasks = [[1,2],[2,4],[4,8]]
Output: 8
Explanation:
Starting with 8 energy, we finish the tasks in the following order:
    - 3rd task. Now energy = 8 - 4 = 4.
    - 2nd task. Now energy = 4 - 2 = 2.
    - 1st task. Now energy = 2 - 1 = 1.
Notice that even though we have leftover energy, starting with 7 energy does not work because we cannot do the 3rd task.
```

Example 2:

```
Input: tasks = [[1,3],[2,4],[10,11],[10,12],[8,9]]
Output: 32
Explanation:
Starting with 32 energy, we finish the tasks in the following order:
    - 1st task. Now energy = 32 - 1 = 31.
    - 2nd task. Now energy = 31 - 2 = 29.
    - 3rd task. Now energy = 29 - 10 = 19.
    - 4th task. Now energy = 19 - 10 = 9.
    - 5th task. Now energy = 9 - 8 = 1.
```

Example 3:

```
Input: tasks = [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]
Output: 27
Explanation:
Starting with 27 energy, we finish the tasks in the following order:
    - 5th task. Now energy = 27 - 5 = 22.
    - 2nd task. Now energy = 22 - 2 = 20.
    - 3rd task. Now energy = 20 - 3 = 17.
    - 1st task. Now energy = 17 - 1 = 16.
    - 4th task. Now energy = 16 - 4 = 12.
    - 6th task. Now energy = 12 - 6 = 6.
```

Constraints:

- `1 <= tasks.length <= 10^5`
- `1 <= actual​ i <= minimum i <= 10^4`

# 풀이과정

생각을 해보면, 같은 에너지 차이(actual과 minimum의 차이)가 있는 task끼리는 순서를 바꿔도, 항상 에너지가 `minimum - actual`만큼 남게되있다. 어차피 최소 수치를 맞춰주기 위해서 에너지를 더 주입해주고, 그다음 actual만큼 깎게 되면 `minimum - actual`로 맞춰지기 때문이다.

그러면 다른 에너지 차이를 가진 task끼리는 운이 좋으면 같은 결과가 나올수도 있겠지만, 최적화된 순서는 차이가 점점 줄어드는 형태일 것이다. 그렇게 되어야만 더 큰 차이를 가진 task에서 남은 에너지들이 더 작은 차이를 가진 task에서 사용될 수 있기 때문이다.

따라서 문제는 단순한 Sorting 문제로 간략화 되고, 에너지 차이에 따른 소팅만 해주면된다.

```
bool Compare(vector<int>& p, vector<int>& q){
    return p[1]-[0] > q[1]-q[0];
}
```

이 함수를 만들어서 std::sort에 집어넣으려 했으나, 사이트에선 작동을 하지않았다...
그래서 그냥 람다식으로 만들어서 집어넣어보니 되긴했다.
`sort(tasks.begin(),tasks.end(),[](vector<int>& p, vector<int>& q){return p[1]-p[0] > q[1]-q[0];});`

그 외에 다른것은 실제로 에너지가 사용되고, minimum에 맞추기위해서 에너지를 추가해주는 것을 실제로 해주기만 하면된다. 이미 소팅에 따라서 최적화는 되었으니 진행하면된다.
