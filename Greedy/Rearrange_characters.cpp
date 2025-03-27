#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    string reorganizeString(string str) {
        int n = str.length();
        vector<int> freq(26, 0);
        for(char c : str) {
            freq[c - 'a']++;
        }
        
        int maxFreq = 0;
        char maxChar = 'a';
        for(int i = 0; i < 26; i++) {
            if(freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = i + 'a';
            }
        }
        
        if(maxFreq > (n + 1) / 2) {
            return "";
        }
        
        string result(n, ' ');
        int idx = 0;
        while(freq[maxChar - 'a'] > 0) {
            result[idx] = maxChar;
            idx += 2;
            freq[maxChar - 'a']--;
        }
        
        for(int i = 0; i < 26; i++) {
            while(freq[i] > 0) {
                if(idx >= n) {
                    idx = 1;
                }
                result[idx] = i + 'a';
                idx += 2;
                freq[i]--;
            }
        }
        
        for(int i = 1; i < n; i++) {
            if(result[i] == result[i-1]) return "";
        }
        
        return result;
    }
};

