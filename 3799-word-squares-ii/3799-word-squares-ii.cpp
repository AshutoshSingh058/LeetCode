class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& word) {
        int n = word.size();
        string top = "", left = "", right = "", bottom = "";

        set<vector<string>> s;
        vector<vector<string>> v;

        for(int i=0; i < n; i++){
            top = word[i];
            for(int j=0; j <n; j++ ){
                if(j!=i)left = word[j];
                else continue;
                for(int k =0; k <n; k++){
                    if(k!= i && k!=j)right =word[k];
                    else continue;
                    for(int l =0; l <n; l++){
                        if(l!=i && l!=j && l!=k) {
                            bottom = word[l];
                        
                            if(top[0]== left[0] && top[3] == right[0] && 
                                bottom[0] == left[3] && bottom[3] == right[3])
                                s.insert({top, left, right, bottom});
                        
                        }
                        else continue;
                        
                    }   
                }
            }
        }
        int k= 0;
        for(auto i:s){
            v.push_back(i);
        }

        return v;
    }
};