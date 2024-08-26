//有序数组都要考虑左右指针

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int sum;
        int left = 0;
        int right = numbers.size()-1;
        while(left < right){
            sum = numbers[left]+numbers[right];
            if (sum == target){
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};