# 841. Keys and Rooms 

**Medium**
There are `N` rooms and you start in room `0`.  Each room has a distinct number in `0, 1, 2, ..., N-1`, and each room may have some keys to access the next room. 

Formally, each room `i` has a list of keys `rooms[i]`, and each key `rooms[i][j]` is an integer in `[0, 1, ..., N-1]` where `N = rooms.length`.  A key `rooms[i][j] = v` opens the room with number `v`.

Initially, all the rooms start locked (except for room 0). 

You can walk back and forth between rooms freely.

Return `true` if and only if you can enter every room.

각각의 rooms[i]에는 열쇠의 배열이 있다. 열쇠 k는 k번째 방을 열수 있다는 뜻이다. 방은 자유롭게 들락날락할 수 있으며, 모든 방을 열 수 있다면 true를, 없다면 false를 반환하면 된다.

Example 1:
```
Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.
```

Example 2:
```
Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.
```

Note:

1. 1 <= rooms.length <= 1000
2. 0 <= rooms[i].length <= 1000
3. The number of keys in all rooms combined is at most 3000.

# 풀이과정
자유롭게 들락날락할 수 있으니, opened 배열을 만들어서 각각 문연것을 확인해주고, BFS를 이용해서 각각의 key를 queue에 넣어서 일일이 확인해준다.