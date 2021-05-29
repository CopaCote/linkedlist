# 1739. Building Boxes

**Hard**
You have a cubic storeroom where the width, length, and height of the room are all equal to n units. You are asked to place n boxes in this room where each box is a cube of unit side length. There are however some rules to placing the boxes:

- You can place the boxes anywhere on the floor.
- If box x is placed on top of the box y, then each side of the four vertical sides of the box y must either be adjacent to another box or to a wall.
  Given an integer n, return the minimum possible number of boxes touching the floor.

n���� �ڽ��� n X n X n ������ �ִ´�.
Ư�� �ڽ� x�� y���� �÷����� ���ؼ��� y�� �����¿�� ���� ���̸�ŭ �ڽ��� �־���Ѵ�. Ȥ�� ������ �����־�� �Ѵ�.
�ٴڿ� ��� �ڽ��� �ּ� ���� ���ϴ� ����.

Example 1:
![ex1](1.png)

```
Input: n = 3
Output: 3
Explanation: The figure above is for the placement of the three boxes.
These boxes are placed in the corner of the room, where the corner is on the left side.
```

Example 2:
![ex2](2.png)

```
Input: n = 4
Output: 3
Explanation: The figure above is for the placement of the four boxes.
These boxes are placed in the corner of the room, where the corner is on the left side.
```

Example 3:
![ex3](3.png)

```
Input: n = 10
Output: 6
Explanation: The figure above is for the placement of the ten boxes.
These boxes are placed in the corner of the room, where the corner is on the back side.
```

Constraints:

- 1 <= n <= 109

# Ǯ�̰���

�⺻�������� ���� ���� ���� �ٴڿ� ��� ���ؼ��� ���� ���� �׾ƾ��ϰ�, �������� ���� �˰ڵ���, ������ ���Ƽ� �ִ� ���� ���� �ִ��� Ȱ���ؼ� �ٴڿ� ��Ƴ����ϴ� ������ ��������. 

�ڽ� 1���� ��쿡�� 1���� �ڽ��� 1�� �򸰴�. 
�ڽ� 4���� ��쿡�� 1������ �ڽ��� 3��, 2������ 1���� �򸰴�. 
�ڽ� 10���� ��쿡�� 1������ �ڽ��� 6��, 2������ 3��, 3���� 1���� �򸰴�. 
�ִ��� �ڽ� �������� k���� �ڽ��� �״´ٸ� ���� �ٴڸ��� �ڽ� ������ �ñ׸�(n) = (n) X (n+1) / 2�� �ȴ�. 
���� �� �ڽ��� ������ �ñ׸�(�ñ׸�(n)) = (n) X (n+1) X (n+2) / 6�� �ȴ�. 

�̸� �̿��ؼ� ������ �ڽ� ���� �� ������ ���� �� �ֳ� ���� ã�� �ܰ谡 �ְ�, ���� �ű⼭ ���������� ��� �ڽ��� �� ��ġ�ؾ��ϳ��� ���ؼ� ã���� �ȴ�. 
�� ���� ���� �� �ִ� ���� �̺�Ž���� ����ϱ⵵ �߰�, ����Ž���� ����غôµ�, �̺�Ž���� ����ϸ� ���ڰ� �ʹ� Ŀ���鼭 ������. 
(n) X (n+1) X (n+2) / 6�� ���ϴ� �������� ������ �Ǿ��µ�, ����Ž���� �ϸ� �� ������ ������� �ʰ� ��� ���ذ��Ƿ� ������ ���� �� ����. 

�ִ��� ���� ���ϰ� �� �ڿ��� ���� �ڽ����� �ϳ��� ���༭ ������ ��������Ѵ�.
�ٴ��� ���̴°� �����̹Ƿ�, �ٴ��� �ڽ��� �ϳ� ���ԵǸ�, ������ ������ �ȸ¾����鼭 ���������� ������ ������ �ȴ�. 
���� 3������ �ٴ��� �ϳ� ���ָ�, �� 3���� �ڽ��� �������. ���Ŀ� �ٴ��� �ϳ� �� ���ָ� 2���� ������, ������ �Ѱ��� ���� �ȴ�. �Ʒ��� ������ �����ϸ� ������ �� ���̴�. 
![example](example.png)

```
while(maxBox-height >= n){
  bottomBox--;
  maxBox -= height;
  height--;
}
```