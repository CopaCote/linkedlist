class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        while (expression.length() > 1)
        {
            int begin = 0;
            int end = 0;
            for (int i = 0; i < expression.length(); i++)
            {
                if (expression[i] == '(')
                    begin = i;
                else if (expression[i] == ')')
                {
                    end = i;
                    string ans;
                    switch (expression[begin - 1])
                    {
                    case '!':
                        ans = parseNot(expression.substr(begin - 1, end - begin + 2));
                        break;
                    case '|':
                        ans = parseOr(expression.substr(begin - 1, end - begin + 2));
                        break;
                    case '&':
                        ans = parseAnd(expression.substr(begin - 1, end - begin + 2));
                        break;
                    }
                    expression.replace(begin - 1, end - begin + 2, ans);
                    break;
                }
            }
        }
        return expression[0] == 't' ? true : false;
    }
    string parseNot(string expression)
    {
        if (expression[2] == 't')
            return "f";
        else
            return "t";
    }
    string parseOr(string expression)
    {
        bool ans = expression[2] == 't' ? true : false;
        for (int i = 4; i < expression.length(); i += 2)
        {
            if (expression[i] == 't')
                ans |= true;
            else
                ans |= false;
        }
        return ans ? "t" : "f";
    }
    string parseAnd(string expression)
    {
        bool ans = expression[2] == 't' ? true : false;
        for (int i = 4; i < expression.length(); i += 2)
        {
            if (expression[i] == 't')
                ans &= true;
            else
                ans &= false;
        }
        return ans ? "t" : "f";
    }
};