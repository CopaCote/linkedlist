# 23. Merge k Sorted Lists

**Hard**
You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

여러개의 링크드리스트를 엮어서 오름차순 1개짜리 링크드리스트로 만들어라

Example 1:

```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```

Example 2:

```
Input: lists = []
Output: []
```

Example 3:

```
Input: lists = [[]]
Output: []
```

Constraints:

- `k == lists.length`
- `0 <= k <= 10^4`
- `0 <= lists[i].length <= 500`
- `-10^4 <= lists[i][j] <= 10^4`
- `lists[i]` is sorted in **ascending order.**
- The sum of `lists[i].length` won't exceed `10^4`.

# 풀이과정

MergeSort를 LinkedList를 가지고 한다고 생각하고, Merge단계의 알고리즘만 딱 빼서 사용했습니다.
두개의 List를 Merge해주는 함수를 만들고, Queue를 사용해서 앞에부터 두개씩 빼면서 Merge하고 뒤에 넣는 방식사용.
이때 예외처리로 빈 배열을 준다고도 되어있는데, 이는 확인해보니 nullptr로 주는거라서 아예 큐에 넣을때 nullptr는 그냥 무시하고 진행.
