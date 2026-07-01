# Two Sum

**Difficulty:** Easy | **Language:** C++ | **Topics:** Array, Hash Table

## Problem Statement
Given an array of integers `nums` and an integer `target`, the task is to return the indices of two numbers in the array that sum up to `target`. It is guaranteed that there is exactly one solution, and the same element cannot be used twice. The order of the returned indices does not matter.

## Approach
The problem can be efficiently solved using a hash map (unordered_map in C++). We iterate through the array once. For each number `nums[i]`, we calculate the `complement` needed to reach the `target` (i.e., `target - nums[i]`). Before adding the current number to the hash map, we check if its `complement` already exists in the map.

If the `complement` is found in the hash map, it means we have identified the two numbers that sum to `target`. We then return the index associated with the `complement` (retrieved from the map) and the current index `i`. If the `complement` is not found, we add the current number `nums[i]` and its index `i` to the hash map for potential future lookups. This approach allows us to find the pair in a single pass.

## Code with comments for intermediate to recall the code easily

## Algorithm Walkthrough
Let's trace the algorithm with `nums = [2, 7, 11, 15]` and `target = 9`.

1.  Initialize an empty hash map `mp`.
2.  **Iteration 1 (i = 0, nums[0] = 2):**
    *   Calculate `complement = target - nums[0] = 9 - 2 = 7`.
    *   Check if `7` exists in `mp`. It does not.
    *   Add `(2, 0)` to `mp`. `mp` is now `{2: 0}`.
3.  **Iteration 2 (i = 1, nums[1] = 7):**
    *   Calculate `complement = target - nums[1] = 9 - 7 = 2`.
    *   Check if `2` exists in `mp`. Yes, `mp[2]` is `0`.
    *   Since the `complement` (2) is found, we have our pair. Return `[mp[2], i]`, which is `[0, 1]`.
    *   The algorithm terminates.

## Complexity Analysis
| | Complexity |
|---|---|
| Time | O(n) |
| Space | O(n) |

## Solution with Comments
```cpp
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
```

## Key Takeaways
-   Hash maps provide an efficient way to store and retrieve data, enabling O(1) average time complexity for lookups, insertions, and deletions.
-   This problem demonstrates a common pattern where a hash map can optimize a brute-force O(n^2) search (checking all pairs) into an O(n) single-pass solution by storing previously seen elements and their required complements.