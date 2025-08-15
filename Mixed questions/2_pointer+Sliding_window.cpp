#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==" ") return 1;
        if(s=="") return 0;
        unordered_map<char,int> mp;
        int left = 0;
        int right = 1;
        mp[s[left]]=1;
        int maxlen = 1;
        int len = 1;
        while(right<s.length()){
            char ch = s[right];
            if(mp[ch]==0){
                right++;
                len++;
                mp[ch]++;
            }
            else{
                while(mp[ch]>0){
                    mp[s[left]]--;
                    left++;
                    len--;    
                }
                mp[ch]++;
                right++;
                len++;
            }
            maxlen = max(maxlen,len);
        }
        return maxlen;
    }
};