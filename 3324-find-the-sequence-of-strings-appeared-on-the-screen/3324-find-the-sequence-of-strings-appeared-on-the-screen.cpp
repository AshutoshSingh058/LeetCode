class Solution {
public:
    vector<string> stringSequence(string target) {
        int n = target.size();
        //brute
        vector<string> vec;
        for(int i=0; i<n; i++){
            string st = "";
            if(i!=0) st=target.substr(0,i) ;
            // cout<< i<<" "<<st<<"\n";
            char ch = 'a';
            // vec.push_back()
            while(true){
                vec.push_back((st + ch));
                if(target[i] == ch) break;
                ch++;

            }
        }
        return vec;
    }
};