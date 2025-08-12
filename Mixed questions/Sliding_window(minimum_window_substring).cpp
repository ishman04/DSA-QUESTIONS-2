#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";
        unordered_map<char,int> t_freq;
        unordered_map<char,int> s_freq;
        for(int i = 0;i<t.length();i++){
            t_freq[t[i]]++;
        }
        int req = t_freq.size();
        int right = 0;
        int left = 0;
        int formed = 0;
        int minLen = INT_MAX;
        int min_left = 0;
        
        while(right<s.size()){
            char new_char = s[right];
            s_freq[new_char]++;

            if(t_freq[new_char] && t_freq[new_char] == s_freq[new_char]) formed++;

            while(left<=right && formed == req){
                if(right-left+1<minLen){
                    minLen = right -left + 1;
                    min_left = left;
                }
                char left_char = s[left];
                s_freq[left_char]--;

                if(t_freq[left_char] && s_freq[left_char] < t_freq[left_char]) formed--;

                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(min_left,minLen);
    }
};