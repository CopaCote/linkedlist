# 810. Chalkboard XOR Game

**Hard**
We are given non-negative integers nums[i] which are written on a chalkboard. Alice and Bob take turns erasing exactly one number from the chalkboard, with Alice starting first. If erasing a number causes the bitwise XOR of all the elements of the chalkboard to become 0, then that player loses. (Also, we'll say the bitwise XOR of one element is that element itself, and the bitwise XOR of no elements is 0.)

Also, if any player starts their turn with the bitwise XOR of all the elements of the chalkboard equal to 0, then that player wins.

Return True if and only if Alice wins the game, assuming both players play optimally.

Alice�� Bob�� XOR������ �Ѵ�. ������ ������ �̷��� �ȴ�.  
1. Alice�� �迭���� ���� �ϳ��� �����.  
2. ���� �迭�� ������ XOR�� 0�̵Ǹ� Alice�� ����.  
3. Bob�� �Ȱ��� �Ѵ�.  
4. �������������� XOR���� 0�̶�� Alice�� �¸��̴�.  
5. ���� �÷��̾�� ���� optimal�ϰ� �ൿ�Ѵ�.  
(�ƹ��͵� ���� �迭�� XOR���� 0�̴�. ���� �ϳ��� XOR�� �ڱ��ڽ��̴�.)  

Example:

```
Input: nums = [1, 1, 2]
Output: false
Explanation: 
Alice has two choices: erase 1 or erase 2. 
If she erases 1, the nums array becomes [1, 2]. The bitwise XOR of all the elements of the chalkboard is 1 XOR 2 = 3. Now Bob can remove any element he wants, because Alice will be the one to erase the last element and she will lose. 
If Alice erases 2 first, now nums becomes [1, 1]. The bitwise XOR of all the elements of the chalkboard is 1 XOR 1 = 0. Alice will lose.
```

Notes:
- `1 <= N <= 1000`
- `0 <= nums[i] <= 2^16`

# Ǯ�̰���

���� ��ü������ ��Ģ�� ã�� �� �����Ƿ�, ���� ��� ��츦 ���������Ѵ�. ��� n,m,k�� 0�� �ƴ� ���̴�.

N=1�϶�,  
[0]�̸� Alice�� �¸�  
[n]�̸� Bob�� �¸�(Alice�� �ϳ��� �̾���)  

N=2�϶�,  
[0,0]�̸� Alice�� �¸�  
[n,m]�̰� n^m==0�̸� Alice�� �¸�  
[n,m]�̰� n^m!=0�̸� Alice�� ��� �̾Ƶ� 0�� ���� �����Ƿ�, Alice�� �̱��.  
[n,0]�̸� Alice�� 0�� ������ �ǹǷ�, Alice�� �̱��.  

N=3�϶�,  
[0,0,0]�̸� Alice�� �¸�  
[0,0,n]�̸� Alice�� 0�� �����, Bob�� 0�� �����, Alice�� n�� ����Ƿ� Alice�� �й�  
[0,n,m]�̸� Alice�� m�� �����, Bob�� 0�� �����, Alice�� n�� ����Ƿ� Alice�� �й�  
���ܷ� n^m == 0�̸� Alice�� �¸�  
[n,m,k]�̸� Alice�� XOR�� 0�� �����ʵ��� ���� �Ѱ� �����(n�̶�� ����), Bob�� �ƹ��ų� �Ѱ��� ����. Alice�� ������ ���ڸ� ����Ƿ� Alice�� �й�  


N=4�϶�,
[0,0,0,0]�̸� Alice�� �¸�  
[0,0,0,n]�̸� ���� 0�� ����ٰ� �������� Bob�� n�� ����� Alice�� �¸�
[0,0,n,m]�̸� Alice�� 0�� �����, Bob�� 0�� �����, Alice�� n�� �����, Bob�� m�� ������ Alice �¸�  
���ܷ� n^m==0�̸� Alice�� �¸�  
[0,m,n,k]�̸� Alice�� 0�� �����, ���� ����ٰ� Alice�� �¸�.  
��ΰ� 0�� �ƴѰ����� �غ��Ƶ� �Ȱ��� ���� optimal�ϰ� ���⶧���� Alice�� �¸��ϰ� �ȴ�.  

��������� �����ν� Alice�� N�� ¦���϶� ��� ����� ������ �¸��ϰ� �ǰ�, Ȧ���϶��� ���ۺ��� ��� �迭���� ������ XOR�� 0�� �ɶ� �¸��ϰ�, �� ���� ����쿡�� �й��Ѵ�.  
�� ��� ��츦 �غ��� ������ ������ �Ȱ��� �� ���Ƽ� ���⼭ ������ �ڵ��� �غ��Ұ�, ���� N�ϳ��� ���а� �����Ǿ���ȴ�.  