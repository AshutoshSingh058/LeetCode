class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> ds;
    int K;

    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i=0; i<nums.size(); i++)add(nums[i]);
    }
    
    int add(int val) {
        ds.push(val);
        if(ds.size() > K) ds.pop();
        return ds.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */