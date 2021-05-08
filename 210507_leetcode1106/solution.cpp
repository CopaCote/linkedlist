class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        stack<char> s;
        stack<char> op;
        for (int i = 0; i < expression.length(); i++)
        {
            switch (expression[i])
            {
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
                evaluate(s, op.top());
                op.pop();
                //함수호출
            }
        }
        return s.top() == 't' ? true : false;
    }
    void evaluate(stack<char> &s, char op)
    {
        if (op == '!')
        {
            char n = s.top();
            s.pop(); // pop 't' or 'f'
            s.pop(); // pop '('
            if (n == 't')
                s.push('f');
            else
                s.push('t');
        }
        else if (op == '|')
        {
            bool ans = s.top() == 't' ? true : false;
            s.pop();
            while (s.top() != '(')
            {
                ans |= s.top() == 't' ? true : false;
                s.pop();
            }
            s.pop();
            s.push(ans ? 't' : 'f');
        }
        else if (op == '&')
        {
            bool ans = s.top() == 't' ? true : false;
            s.pop();
            while (s.top() != '(')
            {
                ans &= s.top() == 't' ? true : false;
                s.pop();
            }
            s.pop();
            s.push(ans ? 't' : 'f');
        }
    }
};