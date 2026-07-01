# Two Sum

**Difficulty:** Easy | **Language:** C++ | **Topics:** Array, Hash Table

## Problem Statement
Given an array of integers `nums` and an integer `target`, the task is to find the indices of two numbers in the array such that their sum equals `target`. It is guaranteed that exactly one solution exists, and the same element cannot be used twice. The indices can be returned in any order.

## Approach
A straightforward, brute-force approach would involve iterating through the array with two nested loops, checking every possible pair of numbers. This would result in an O(N^2) time complexity, which is inefficient for larger inputs, as hinted by the problem's follow-up.

To achieve a more optimal solution, we can leverage a hash map (or `unordered_map` in C++). The core idea is to iterate through the array once. For each number `nums[i]`, we determine what "complement" value would be needed to reach the `target` (i.e., `complement = target - nums[i]`). We then check if this `complement` already exists in our hash map. If it does, we have found our pair, and we can return the index of the `complement` (stored in the map) and the current index `i`. If the `complement` is not found, we add the current number `