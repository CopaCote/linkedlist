# 419. Battleships in a Board

**Medium**
Given an 2D board, count how many battleships are in it. The battleships are represented with `'X'`s, empty slots are represented with `'.'`s. You may assume the following rules:

- You receive a valid board, made of only battleships or empty slots.
- Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
- At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.

배틀쉽 보드가 주어지는데, 배의 갯수를 세어라. 두개 이상의 배들은 절대로 붙어있지 않다.

Example:

```
X..X
...X
...X
```

In the above board there are 2 battleships.
Invalid Example:

```
...X
XXXX
...X
```

This is an invalid board that you will not receive - as battleships will always have a cell separating between them.

Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?

# 풀이과정

쉬운걸 풀려고 고른것은 맞지만, one-pass로 검사하는 것도 금방할 수 있기에, 아래에 적혀있는 O(1) 공간복잡도를 가지도록 알고리즘을 만들었다.

핵심은, 검사를 좌에서 우로, 위에서 아래로 하기 때문에 위나 왼쪽에 X가 또 있다면 배가 연결되어있다는 뜻이므로 굳이 숫자를 카운트 하지않고 처음에 시작하는 X만 카운트하는 방식이다.

```
if(i > 0 && board[i-1][j] == 'X') continue;
if(j > 0 && board[i][j-1] == 'X') continue;
```
