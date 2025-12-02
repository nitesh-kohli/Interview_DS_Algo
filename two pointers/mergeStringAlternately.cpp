class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int n1 = word1.length(), n2 = word2.length();
        string str = "";

        while(i < min(n1, n2)){
            str += word1[i];
            str += word2[i];
            i++;
        }

        while(i < n1){
            str += word1[i];
            i++;
        }

        while(i < n2){
            str += word2[i];
            i++;
        }
        return str;
    }
};