#include <algorithm>
#include <vector>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> elems;
        for(int i = 0; i <nums.size(); i++){
            elems[nums[i]]++;
        }
        using Pair = pair<int, int>; // {frequency, number}
        priority_queue<Pair, vector<Pair>, greater<Pair>> minHeap;

        for (pair<int,int> p: elems) {
            minHeap.push({p.second, p.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        std::vector<int> sol;
        while(!minHeap.empty()){  
            sol.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return sol;
    }
};
