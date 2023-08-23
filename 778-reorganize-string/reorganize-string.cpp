class Solution {
public:
    string reorganizeString(string S) {
        int N = S.size();
        unordered_map<char, int> counter;
        
        for(char c : S){
            counter[c]++;
        }
        
        auto comp = [](const pair<char, int>& a, const pair<char, int>& b){
            return (a.second == b.second) ? (a.first > b.first) : a.second < b.second;};
        
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);
        
        for(auto it = counter.begin(); it != counter.end(); it++){
            
            if(it->second > (N+1)/2) return "";
            pq.push(make_pair(it->first, it->second));
        }
        
        string ans = "";
        
        while(pq.size() >= 2){
            
            pair<char, int> cur = pq.top(); pq.pop();
            pair<char, int> next = pq.top(); pq.pop();
            
            
            ans += cur.first;
            
            
            ans += next.first;
            
           
            if(--cur.second > 0) pq.push(cur);
            if(--next.second > 0) pq.push(next);
        }
        
        
        if(!pq.empty()) ans += pq.top().first;
        
        return ans;
    }
};