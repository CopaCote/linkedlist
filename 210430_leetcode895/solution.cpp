class FreqStack
{
public:
    unordered_map<int, stack<int>> fs;
    unordered_map<int, int> freq;
    int maxFreq = 0;
    FreqStack()
    {
    }

    void push(int val)
    {
        freq[val]++;
        fs[freq[val]].push(val);
        maxFreq = maxFreq < freq[val] ? freq[val] : maxFreq;
    }

    int pop()
    {
        int top = fs[maxFreq].top();
        fs[maxFreq].pop();
        freq[top]--;
        if (fs[maxFreq].empty())
            maxFreq--;
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */