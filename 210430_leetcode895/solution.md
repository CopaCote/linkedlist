# 895. Maximum Frequency Stack

**Hard**
Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the `FreqStack` class:

- `FreqStack()` constructs an empty frequency stack.
- `void push(int val)` pushes an integer `val` onto the top of the stack.
- `int pop()` removes and returns the most frequent element in the stack.
- If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

가장 많은 횟수가 push된 숫자를 pop해주는 stack을 구현한다. 이때 freqency가 같으면 둘 중 더 top에 가까운 숫자를 뽑는다.

Example 1:

```
Input
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]

Explanation
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
```

Notes:
- 0 <= val <= 10^9
- At most 2 * 10^4 calls will be made to push and pop.
- It is guaranteed that there will be at least one element in the stack before calling pop.

# 풀이과정

처음에는 int,vector의 map으로 특정 숫자의 인덱스 번호들을 담아놓고, int,int의 map으로 해당 숫자의 freq수치를 담아두려고 했으나, 2시간동안 붙잡은 결과 top 부분에 대한 처리가 점점 쌓이는 것에 대해서는 추적이 되는데, pop을 하면서 추적이 불가능해져서 이 시점에서 문제를 포기했다.  

// 다른 사람의 풀이법
map두개의 방식을 바꾸어서, 둘다 특정 숫자를 key값으로 가지는게 아니라 한개는 (숫자, frequency)를 가지고, 한개는 (frequency, Stack)을 해서, 문제이름 그대로 각각의 Frequency Stack을 만드는 것이다.  

숫자가 여러번 나오게 되면 해당 숫자가 각 frequency별로 한번씩 삽입되는 방식이다.  

push단계에서는 그러면 해야하는 것은 해당 숫자에 대한 frequency를 1증가 시키고, 올라간 frequency의 stack에 push해주면된다.  

pop단계에서는 제일 큰 frequency의 stack에서 하나 빼오고, 나온 숫자에 대해서 frequency를 하나 줄여주면된다.  