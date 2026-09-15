class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n > m) return false;

        vector<int> freqs1(26, 0);
        vector<int> freqs2(26, 0);

        for(auto x: s1){
            freqs1[x - 'a']++;
        }

        int i=0;
        int j=0;

        while(j < m){
            freqs2[s2[j] - 'a']++;

            if(j-i+1 > n){ // time to shrink window
                freqs2[s2[i] - 'a']--;
                i++;
            }

            if(freqs1 == freqs2) return true;

            j++;
        }

        return false;


    }
};