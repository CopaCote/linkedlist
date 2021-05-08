# 1106. Parsing A Boolean Expression

**Hard**
Return the result of evaluating a given boolean `expression`, represented as a string.

An expression can either be:

- `"t"`, evaluating to `True`;
- `"f"`, evaluating to `False`;
- `"!(expr)"`, evaluating to the logical NOT of the inner expression `expr`;
- `"&(expr1,expr2,...)"`, evaluating to the logical AND of 2 or more inner expressions `expr1, expr2, ...`
- `"|(expr1,expr2,...)"`, evaluating to the logical OR of 2 or more inner expressions `expr1, expr2, ...`

String으로 주어진 논리식을 풀어서 답을 true, false로 반환하라.
이때 문제에서는 AND와 OR가 2개 혹은 그 이상의 expression을 연산하는 거라고 적혀있지만, test case에서는 실제로 1개도 수행한다.

Example 1:

```
Input: expression = "!(f)"
Output: true
```

Example 2:

```
Input: expression = "|(f,t)"
Output: true
```

Example 3:

```
Input: expression = "&(t,f)"
Output: false
```

Example 4:

```
Input: expression = "|(&(t,f,t),!(t))"
Output: false
```

Constraints:

- `1 <= expression.length <= 20000`
- `expression[i]` consists of characters in `{'(', ')', '&', '|', '!', 't', 'f', ','}`.
- `expression` is a valid expression representing a boolean, as given in the description.

# 풀이과정 1

처음풀이는 단순하지만 매우 느린 풀이를 하였다.
인덱스 두개를 저장해놓고, '('가 나오면 begin의 인덱스를 기록, ')'가 나오면 begin과의 사이 부분을 구한뒤에 string을 치환해주고 처음부터 다시 시작하는 방식을 사용했다.
이렇게 하면 '('가 나올때마다 인덱스가 바뀌므로 가장 안쪽에 있는 식들부터 하나씩 처리해나갈 수 있기때문에 하였다.

```
for(int i=0;i<expression.length();i++){
  if(expression[i] == '(')
      begin = i;
  else if(expression[i] == ')'){
      end = i;
      string ans;
      switch(expression[begin-1]){
          case '!':
              ans = parseNot(expression.substr(begin-1,end-begin+2));
              break;
          case '|':
              ans = parseOr(expression.substr(begin-1,end-begin+2));
              break;
          case '&':
              ans = parseAnd(expression.substr(begin-1,end-begin+2));
              break;
      }
      expression.replace(begin-1,end-begin+2, ans);
      break;
  }
}
```

# 풀이과정 2

처음의 풀이가 당연하게도 너무 느리게 나와서 스택을 일반 계산식에 쓰이는 것인 스택으로 구현을 해보았다. 스택을 한 개 쓰는 것보다 두 개 쓰는 것이 연산에 편해서 두 개를 채택했다.
'(', 't', 'f'가 나오면 스택에 집어넣고, ')'가 나오면 '('가 나올때까지 모두 pop해서 연산하는 방식이다. 이때 연산 부호가 같은 스택에 있으면 귀찮아지므로 아예 op라는 스택을 따로 만들어서 ')'가 나오면 op를 하나 pop해서 그 연산으로 진행했다.

```
for(int i=0;i<expression.length();i++){
    switch(expression[i]){
        case '(':
        case 't':
        case 'f':
            s.push(expression[i]);
            break;
        case '!':
        case '&':
        case '|':
            op.push(expression[i]);
            break;
        case ')':
            evaluate(s,op.top());
            op.pop();
            //함수호출
    }
}
```
