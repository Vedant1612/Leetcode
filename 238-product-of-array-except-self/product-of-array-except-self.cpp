class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>Product(n,0);

        Product[0] = 1;
        for(int i=1; i<n; i++){
            Product[i] = Product[i-1] * nums[i-1];
        }
        int rightProduct = 1;

        for(int i=n-1; i>=0; i--){
            Product[i] = Product[i] * rightProduct;
            rightProduct *= nums[i];
        }

        return Product;
    }
};