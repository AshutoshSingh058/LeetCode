class Solution {
public:
    int minTimeToType(string word) {
        int sol=0;
        char current = 'a';
        for(char c  : word){
            int direct_distance = abs( c- current);
            int anit_distance  = 26-direct_distance;
            sol += min(direct_distance, anit_distance) + 1; //type + move
            current = c;
        }
        return sol;
            
    }
};