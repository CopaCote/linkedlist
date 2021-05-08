# 1106. Parsing A Boolean Expression

**Hard**
Return the result of evaluating a given boolean `expression`, represented as a string.

An expression can either be:

- `"t"`, evaluating to `True`;
- `"f"`, evaluating to `False`;
- `"!(expr)"`, evaluating to the logical NOT of the inner expression `expr`;
- `"&(expr1,expr2,...)"`, evaluating to the logical AND of 2 or more inner expressions `expr1, expr2, ...`
- `"|(expr1,expr2,...)"`, evaluating to the logical OR of 2 or more inner expressions `expr1, expr2, ...`

String���� �־��� ������ Ǯ� ���� true, false�� ��ȯ�϶�.
�̶� ���������� AND�� OR�� 2�� Ȥ�� �� �̻��� expression�� �����ϴ� �Ŷ�� ����������, test case������ ������ 1���� �����Ѵ�.

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

# Ǯ�̰��� 1

ó��Ǯ�̴� �ܼ������� �ſ� ���� Ǯ�̸� �Ͽ���.
�ε��� �ΰ��� �����س���, '('�� ������ begin�� �ε����� ���, ')'�� ������ begin���� ���� �κ��� ���ѵڿ� string�� ġȯ���ְ� ó������ �ٽ� �����ϴ� ����� ����ߴ�.
�̷��� �ϸ� '('�� ���ö����� �ε����� �ٲ�Ƿ� ���� ���ʿ� �ִ� �ĵ���� �ϳ��� ó���س��� �� �ֱ⶧���� �Ͽ���.

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

# Ǯ�̰��� 2

ó���� Ǯ�̰� �翬�ϰԵ� �ʹ� ������ ���ͼ� ������ �Ϲ� ���Ŀ� ���̴� ���� �������� ������ �غ��Ҵ�. ������ �� �� ���� �ͺ��� �� �� ���� ���� ���꿡 ���ؼ� �� ���� ä���ߴ�.
'(', 't', 'f'�� ������ ���ÿ� ����ְ�, ')'�� ������ '('�� ���ö����� ��� pop�ؼ� �����ϴ� ����̴�. �̶� ���� ��ȣ�� ���� ���ÿ� ������ ���������Ƿ� �ƿ� op��� ������ ���� ���� ')'�� ������ op�� �ϳ� pop�ؼ� �� �������� �����ߴ�.

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
            //�Լ�ȣ��
    }
}
```
