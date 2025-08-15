#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> resultStack;
        string currString = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                counts.push(num);
                resultStack.push(currString);
                num = 0;
                currString = "";
            }
            else if (c == ']') {
                int repeatTimes = counts.top(); counts.pop();
                string prevString = resultStack.top(); resultStack.pop();
                string repeated = "";
                for (int i = 0; i < repeatTimes; i++) {
                    repeated += currString;
                }
                currString = prevString + repeated;
            }
            else {
                currString += c;
            }
        }
        return currString;
    }
};
