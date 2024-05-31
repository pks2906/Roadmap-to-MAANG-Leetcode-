class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
       
        long long total_xor = 0;
        for (int num : nums) {
            total_xor ^= num;
        }
      
        
        int last_bit = total_xor & -total_xor;
      
        int num1 = 0;
        for (int num : nums) {
            
            if (num & last_bit) {
                num1 ^= num;
            }
        }
      
        
        int num2 = total_xor ^ num1;
      
        
        return {num1, num2};
    }
};

//solved by Pratik