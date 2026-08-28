class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;

        for(int i = 0; i < nums.size(); i++) {
            int moreNeeded = target - nums[i];

            if(hashMap.find(moreNeeded) != hashMap.end()) return {hashMap[moreNeeded], i};

            hashMap[nums[i]] = i;
        }

        return {-1, -1};
    }
};