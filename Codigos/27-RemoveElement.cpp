//Fonte:https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//Autor:Bruno Harlis
//Data: 22/06/2020

/*****************************************************************************************
* PROBLEM:
* Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
* The relative order of the elements may be changed.
*
* Since it is impossible to change the length of the array in some languages, you must instead have the
* result be placed in the first part of the array nums. More formally, if there are k elements after
* removing the duplicates, then the first k elements of nums should hold the final result. It does not
* matter what you leave beyond the first k elements.
*
* Return k after placing the final result in the first k slots of nums.
*
* Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*
* Exemple 1:
* Input: nums = [0,1,2,2,3,0,4,2], val = 2
* Output: 5, nums = [0,1,4,0,3,_,_,_]
* Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
* Note that the five elements can be returned in any order.
* It does not matter what you leave beyond the returned k (hence they are underscores).
* 
* EFFICIENCY TEST:
* Runtime: 4 ms
* Memory Usage: 8.8 MB
*****************************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
    for (unsigned i{ 0 }; i < nums.size(); ++i)
    {
        while (nums[i] == val)
        {
            nums.erase(nums.begin() + i);
            if (i == nums.size()) break;
        }
    }

    return nums.size();
}
    
     

int main()
{
    vector<int> x{ 3,2,2,3 };
    int val{ 2 };
    
    cout << removeElement(x, val) << endl;

    return 0;
}