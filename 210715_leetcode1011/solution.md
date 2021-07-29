# 1011. Capacity To Ship Packages Within D Days

**Medium**
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

화물을 무조건 weights 배열의 순서대로 보낸다고 했을때 기한을 맞추는 최소한의 배 적재 무게를 구하여라.

Example 1:
```
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
```

Example 2:
```
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
```

Example 3:
```
Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
```

Constraints:
- 1 <= days <= weights.length <= 5 * 104
- 1 <= weights[i] <= 500

# 풀이과정
이분탐색을 이용해서 구한다. 이때 검사하는 방식은 직접 다 적재해보면서 검사하는 방식으로 했고, 최소값인 left는 한번에 한 개를 보내는 방법이므로 배열에서 최댓값의 무게가 left값이고, 최댓값 right는 한번에 모든것을 보내는 것이므로 배열의 합을 right로 설정해서 이분탐색을 진행하면된다.