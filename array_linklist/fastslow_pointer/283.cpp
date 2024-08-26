class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==0){
            return;
        }
        int slow = 0;
        int fast = 0;
        while(fast < nums.size()){
            if (nums[fast] != 0){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        for (int i = slow;i<nums.size();i++){
            nums[i] = 0;
        }
        return;
    }
};