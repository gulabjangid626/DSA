class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered map to store numbers and their indices.
        // The key will be the number, and the value will be its index in the 'nums' array.
        unordered_map<int, int> mp; 

        // Iterate through the input array 'nums' using an index 'i'.
        for (int i = 0; i < nums.size(); i++) {
            // For the current number nums[i], calculate the 'complement'
            // needed to reach the 'target'.
            int complement = target - nums[i];

            // Check if this 'complement' already exists as a key in our map.
            // If it does, it means we have found the two numbers that sum up to 'target'.
            if (mp.find(complement) != mp.end()) {
                // Return the index of the complement (retrieved from the map)
                // and the current index 'i'.
                return {mp[complement], i};
            }

            // If the complement was not found, add the current number nums[i]
            // and its index 'i' to the map. This makes it available for future
            // numbers to find as their complement.
            mp[nums[i]] = i;
        }

        // According to the problem constraints, there will always be exactly one solution.
        // Therefore, this line should theoretically not be reached.
        return {}; 
    }
};