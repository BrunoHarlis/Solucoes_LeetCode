//fonte: https://leetcode.com/problems/container-with-most-water/
//Autor: Bruno Harlis
//Date: 25/04/2020

/******************************************************************************************
* PROPOSED PROBLEM
* Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
* n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0).
* Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
*
* Exemple 1:
* Input: height = [1,8,6,2,5,4,8,3,7]
* Output: 49
* Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, 
* the max area of water (blue section) the container can contain is 49.
* 
* Exemple 2:
* Input: height = [4,3,2,1,4]
* Output: 16
* 
* EFFICIENCY TEST
* Brute force.
* 
*****************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    int maxArea(std::vector<int>& height) 
    {
        int area{ 0 };
        for (int x{ 0 }; x < height.size(); ++x)
        {
            for (int y{ x + 1 }; y < height.size(); ++y)
            {
                int tempArea = std::min(height[x], height[y]) * (y - x);
                area = std::max(tempArea, area);
            }
        }

        return area;
    }
};

int main()
{
    std::vector<int> x{ 1,8,6,2,5,4,8,3,7 };

    Solution s;
    std::cout << s.maxArea( x );
}

/******************************************************************************************
* Autor: Bruno Harlis
* Date: 26/04/2020
*
* DYNAMIC SOLUTION
*
* EFFICIENCY TEST
* Runtime: 68 ms
* Memory Usage: 59.1 MB
*****************************************************************************************/

class Solution 
{
public:
    int maxArea(std::vector<int>& height) 
    {
        int area{ 0 };
        int i{ 0 };
        int j = height.size() - 1;
        while (i != j)
        {
            int tempArea = std::min(height[i], height[j]) * (j - i);
            area = std::max(tempArea, area);
            (height[i] > height[j])? --j : ++i;
        }

        return area;
    }
};