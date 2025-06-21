#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
  public:
    int characterReplacement(string& s, int k) {
        vector<int> chars(26,0);
        int mx = 0;
        int n = s.size();
        int maxlen=0;
        int left = 0;
        for(int i=0;i<n;i++){
            chars[s[i]-'A']++;
            mx = max(mx,chars[s[i]-'A']);
            if(i-left+1 -mx > k){
                chars[s[left]-'A']--;
                left++;
            }
            maxlen = max(maxlen,i-left+1);
        }
        return maxlen;
    }
};