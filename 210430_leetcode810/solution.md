# 810. Chalkboard XOR Game

**Hard**
We are given non-negative integers nums[i] which are written on a chalkboard. Alice and Bob take turns erasing exactly one number from the chalkboard, with Alice starting first. If erasing a number causes the bitwise XOR of all the elements of the chalkboard to become 0, then that player loses. (Also, we'll say the bitwise XOR of one element is that element itself, and the bitwise XOR of no elements is 0.)

Also, if any player starts their turn with the bitwise XOR of all the elements of the chalkboard equal to 0, then that player wins.

Return True if and only if Alice wins the game, assuming both players play optimally.

Alice와 Bob은 XOR게임을 한다. 게임의 진행은 이렇게 된다.  
1. Alice가 배열에서 숫자 하나를 지운다.  
2. 남은 배열의 숫자의 XOR가 0이되면 Alice가 진다.  
3. Bob도 똑같이 한다.  
4. 시작했을때부터 XOR값이 0이라면 Alice의 승리이다.  
5. 각자 플레이어는 가장 optimal하게 행동한다.  
(아무것도 없는 배열의 XOR값은 0이다. 숫자 하나의 XOR는 자기자신이다.)  

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

# 풀이과정

문제 자체에서는 규칙을 찾을 수 없으므로, 직접 모든 경우를 따져봐야한다. 모든 n,m,k는 0이 아닌 수이다.

N=1일때,  
[0]이면 Alice의 승리  
[n]이면 Bob의 승리(Alice가 하나를 뽑아함)  

N=2일때,  
[0,0]이면 Alice의 승리  
[n,m]이고 n^m==0이면 Alice의 승리  
[n,m]이고 n^m!=0이면 Alice가 어떤걸 뽑아도 0이 되지 않으므로, Alice가 이긴다.  
[n,0]이면 Alice가 0을 뽑으면 되므로, Alice가 이긴다.  

N=3일때,  
[0,0,0]이면 Alice의 승리  
[0,0,n]이면 Alice가 0을 지우고, Bob이 0을 지우고, Alice가 n을 지우므로 Alice의 패배  
[0,n,m]이면 Alice가 m을 지우고, Bob이 0을 지우고, Alice가 n을 지우므로 Alice의 패배  
예외로 n^m == 0이면 Alice의 승리  
[n,m,k]이면 Alice가 XOR가 0이 되지않도록 숫자 한개 지우고(n이라고 가정), Bob은 아무거나 한개를 지움. Alice가 마지막 숫자를 지우므로 Alice의 패배  


N=4일때,
[0,0,0,0]이면 Alice의 승리  
[0,0,0,n]이면 서로 0을 지우다가 마지막에 Bob이 n을 지우고 Alice의 승리
[0,0,n,m]이면 Alice가 0을 지우고, Bob도 0을 지우고, Alice가 n을 지우고, Bob이 m을 지워서 Alice 승리  
예외로 n^m==0이면 Alice의 승리  
[0,m,n,k]이면 Alice가 0을 지우고, 서로 지우다가 Alice의 승리.  
모두가 0이 아닌경우까지 해보아도 똑같이 서로 optimal하게 빼기때문에 Alice가 승리하게 된다.  

여기까지의 관찰로써 Alice는 N이 짝수일때 모든 경우의 수에서 승리하게 되고, 홀수일때는 시작부터 모든 배열내의 숫자의 XOR가 0이 될때 승리하고, 그 외의 모든경우에서 패배한다.  
더 길게 경우를 해보려 했지만 느낌상 똑같을 것 같아서 여기서 예상대로 코딩을 해보았고, 고작 N하나로 승패가 결정되어버렸다.  