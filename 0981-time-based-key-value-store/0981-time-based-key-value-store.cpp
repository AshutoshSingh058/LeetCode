class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // vector<pair<int,string>> v = mp[key];
        auto & v = mp[key];
        // sort(v.begin(), v.end());
        int n = v.size(), l=0, r = n-1, m =0;
        string k = "";
        // while(l<=r){
        //     m = (l+r)/2;
        //     if(v[m].first <= timestamp) {
        //         k = v[m].second;
        //         l = m+1;
        //     }
        //     else {
        //         r = m-1;
        //     }
        // }
        auto it = upper_bound(v.begin(), v.end(), make_pair(timestamp, string(1, char(127))));
    
    if(it == v.begin()) return "";  // all timestamps > given
    --it;  // step back to get <= timestamp
    return it->second;
        // for(int i=0;i<n;i++){
        //     if(v[i].first <= timestamp) k = v[i].second;
        //     // else break;
        // }
        return k;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */