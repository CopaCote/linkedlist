#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 올바른 괄호 확인
bool checkCorrect(string s){
    stack<char> st;
    
    for(auto c : s){
        if(c == '(')
            st.push(c);
        else{
            if(st.empty())
                return false;
            st.pop();
        }
    }
    return true;
}

string makeCorrect(string w){
    if(w == "")
        return "";

    int left=0;
    int right=0;
    if(w[0] == '(')
        left++;
    else
        right++;

    int i = 1;
    while(left != right){
        if(w[i] == '(')
            left++;
        else
            right++;
        i++;
    }
    string u = w.substr(0,i);
    string v = w.substr(i,w.size()-i);

    if(checkCorrect(u)){
        return u + makeCorrect(v);
    }else{
        string s = "(" + makeCorrect(v) + ")";
        u = u.substr(1,u.size()-2);
        for(int i=0;i<u.size();i++)
            u[i] = u[i] == '(' ? ')' : '(';
        return s + u;
    }
}

string solution(string p) {
    string answer = makeCorrect(p);
    return answer;
}