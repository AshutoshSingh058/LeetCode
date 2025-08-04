class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(),[](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
        }

        int cnt=0, lastEndTime = arr[0][1];
        for(int i=1; i<arr.size(); i++){
            if(lastEndTime>arr[i][0]){
                cnt++;
            }
            else lastEndTime = arr[i][1];
        }
        return cnt;
    }
};