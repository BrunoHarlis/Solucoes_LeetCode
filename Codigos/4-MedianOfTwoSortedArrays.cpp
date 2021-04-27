#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        for (const auto& x : nums2)
            nums1.push_back(x);

        std::sort(nums1.begin(), nums1.end());

        if (nums1.size() % 2 == 0) // tamanho par
        {
            int meio = static_cast<int>(nums1.size()) / 2;
            return static_cast<double>(nums1[meio] + nums1[meio - 1]) / 2;
        }
        else //Tamanho impar
        {
            double meio = static_cast<double>(nums1.size()) / 2;
            meio -= std::fmod(meio, 1);
            return nums1[meio];
        }
    }
};

int main()
{
    std::vector<int> nums1{ 1, 2 };
    std::vector<int> nums2{ 3, 4, 5 };
    Solution x;

    std::cout << x.findMedianSortedArrays(nums1, nums2);
}