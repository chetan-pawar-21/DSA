class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() <= 0){
            return true;
        }
        string ns = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] >= 65 && s[i] <= 90){
                ns += (s[i]+32);
            }else if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)){
                ns += s[i];
            }
        }

        for(int i=0, j=ns.length()-1; i<j; i++, j--){
            if(ns[i] != ns[j]){
                return false;
            }
        }

        return true;
    }
};