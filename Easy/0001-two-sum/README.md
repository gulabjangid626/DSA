# Two Sum

**Difficulty:** Easy | **Language:** C++ | **Topics:** Hash Table, Array

## Problem Statement
Given an array of integers `nums` and an integer `target`, the task is to return the indices of two numbers in the array such that their sum equals `target`. It is guaranteed that there is exactly one solution, and the same element cannot be used twice. The order of the returned indices does not matter.

## Approach
A straightforward approach using nested loops to check every possible pair would result in O(n^2) time complexity. To achieve a more efficient solution, we can leverage a hash map (specifically `unordered_map` in C++).

The optimized approach involves iterating through the array once. For each number `nums[i]`, we calculate the `complement` needed to reach the `target` (i.e., `target - nums[i]`). We then check if this `complement` already exists as a key in our hash map. If it does, we have found the two numbers that sum up to `target`, and we can immediately return the index associated with the `complement` from the hash map and the current index `i`.

If the `complement` is not found in the hash map, it means the current number `nums[i]` has not yet found its pair. In this case, we add `nums[i]` and its corresponding index `i` to the hash map. This allows subsequent numbers in the array to efficiently check if `nums[i]` is their complement. This method ensures that each number is processed once, and hash map operations (insertion and lookup) take O(1) time on average, leading to an overall O(n) time complexity.

## code with comments for intermiadate to recall the code easily 

## Algorithm Walkthrough
Let's trace the algorithm with `nums = [2,7,11,15]` and `target = 9`.

1.  Initialize an empty hash map `mp` (stores `value -> index`).
2.  **Iteration 1 (i = 0, nums[0] = 2):**
    *   Calculate `complement = target - nums[0] = 9 - 2 = 7`.
    *   Check if `7` exists in `mp`. It does not.