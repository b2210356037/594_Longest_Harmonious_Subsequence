#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int findLHS(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        unordered_map<int, int> u_map;
        int res = 0;
        for(auto& i : nums){
            u_map[i]++;
        }

        for(auto& item : u_map){
            if(u_map.find(item.first -1) != u_map.end()) {
                res = max(res, u_map[item.first] + u_map[item.first-1]);
            }
            if(u_map.find(item.first + 1) != u_map.end()) {
                res = max(res, u_map[item.first] + u_map[item.first+1]);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4,6,5,-5,10,-1,-2,5,4,4,-1,7};
    cout << s.findLHS(nums) << endl;
    return 0;
}
