class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st1;
        // queue<int>  st2;
        // queue<char> q;
        // vector<int> arr;
        
        
        int n= s.length(), a=0;
        for(int i=0; i<n;i++){
            if(s[i]=='(')st1.push(i);
            else if(s[i]==')'){
                a= st1.top(); st1.pop();
                reverse(s.begin()+a, s.begin()+i);
            }
            
        }


        cout<<s<<endl;

        // int x=0, y=0;
        // while(!st1.empty()){
        //     x= st1.top(); st1.pop();
        //     y= st2.front(); st2.pop();
        //     cout<<x<<" "<<y<<" ; ";
        //     reverse(ans.begin()+x, ans.begin()+y );
        // }
        string ans ="";
        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]==')');
            else ans+=s[i];
        }
        cout<<ans;

        return ans;
    }
};



// int i=0, n = s.length(), c=0 ;
        // bool flag =0;

        // while(i<n){
        //     if(s[i]==')'|| s[i]=='('){
        //         flag= !flag;
        //         arr.push_back(c);
        //         c=0;
        //     }
        //     else if( flag==1){
        //         st.push(s[i]);
        //         c++;
        //     }
        //     else{
        //         q.push(s[i]);
        //         c++;
        //     } 
        //     i++;
        // }
        // arr.push_back(c);c=0;
        // // if(arr.size()%2!=0)arr.push_back(0);
        // // int cnt = 0;
        // // for(int x =0; i<s.length(); i++){
        // //     if(s[i]=='(')cnt++;
        // // }
        // // cnt=cnt%2;

        // for(int j =0; j< arr.size(); j++){
        //     if((cnt+ j)%2==0 ){
        //         while(arr[j] > 0){
        //             arr[j]--;
        //             ans+=q.front();
        //             q.pop();
        //         }
        //     }
        //     else{
        //         while(arr[j] > 0){
        //             arr[j]--;
        //             ans+=st.top();
        //             st.pop();
        //         }
        //     }
        // }
        

        // // while(!st.empty()){
        // //     cout<<st.top()<<" "; 
        // //     // ans+=st.top();
        // //     st.pop();
        // // }
        // // cout<<endl;
        // // while(!q.empty()){
        // //     cout<<q.front()<<" "; q.pop();
        // // }
        // // cout<<ans<<endl;