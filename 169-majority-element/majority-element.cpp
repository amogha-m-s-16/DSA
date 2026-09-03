class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, cnt1 = 0, el;

        for(int i = 0; i < nums.size(); i++) {

            if(cnt == 0){
                el = nums[i];
                cnt = 1;
            }

            else if (el == nums[i]) cnt++;
            else cnt--;
        }

        int mini = (nums.size() /2) + 1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == el) cnt1++;
        }

        if(cnt1 >= mini) 
            return el;

        return -1;        
    }
};