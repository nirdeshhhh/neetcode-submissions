class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        string cleaned = "";
        

        for(char c: s){
            if(isalnum(c)){
                cleaned += tolower(c);
            }
        }

        int left = 0;
        int right = cleaned.size() -1;

        while(left < right){
            if(cleaned[right] != cleaned[left]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
