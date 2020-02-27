"""
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

"""

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        indeksi = []
        for i in range(len(nums)):
        	for j in range(len(nums)):
        		if (i != j) and (nums[i]+nums[j] == target):
        			indeksi.append(i)
        			indeksi.append(j)
        			return indeksi




        
        return indeksi

if __name__ == "__main__":
    # execute only if run as a script
    s = Solution()
    nums = [2, 7, 11, 15]
    target = 9
    
    print(s.twoSum(nums,target))