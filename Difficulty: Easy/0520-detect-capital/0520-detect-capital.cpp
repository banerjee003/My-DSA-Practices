class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() <= 1) return true;

        bool iscap;

        if((word[0] >= 'A' && word[0] <= 'Z') && (word[1] >= 'A' && word[1] <= 'Z'))
            iscap = true;
        else
            iscap = false;

        for(int i = 1; i < word.size(); i++){
            if(iscap){
                if(word[i] >= 'a' && word[i] <= 'z')
                    return false;
            }
            else{
                if(word[i] >= 'A' && word[i] <= 'Z')
                    return false;
            }
        }

        return true;
    }
};
