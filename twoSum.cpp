/*	https://leetcode.com/problems/two-sum/	*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> intMap;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) intMap[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++) {
            if (intMap.find(target-nums[i]) != intMap.end() && intMap[target-nums[i]] != i) {
                res.push_back(i+1);
                res.push_back(intMap[target-nums[i]]+1);
                break;
            }
        }
        return res;
    }
};
