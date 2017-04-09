#include <iostream>
#include <vector>
#include <utility>

// The Problem is taken from codefights.com, section 'DP Basic', the name is 'houseRobber' .
//
// You are planning to rob houses on a specific street, and you know that every house on the street has a certain amount of money hidden.
// The only thing stopping you from robbing all of them in one night is that adjacent houses on the street have a connected security system.
// The system will automatically trigger an alarm if two adjacent houses are broken into on the same night.
//
// Given a list of non-negative integers nums representing the amount of money hidden in each house, determine the maximum amount of money you can rob in one night without triggering an alarm.
//
// Example
//
// For nums = [1, 1, 1], the output should be
// houseRobber(nums) = 2.
//
// The optimal way to get the most money in one night is to rob the first and the third houses for a total of 2.
//
int houseRobber(std::vector<int> nums) {
    
    if (nums.empty())
        return 0;
    if(nums.size() == 1)
        return nums[0];
    if(nums.size() == 2)
        return std::max(nums[0], nums[1]);
    
    std::vector<int>::size_type nums_count = nums.size();
    std::pair<int,int> m1 = std::make_pair(0, 0);
    std::pair<int,int> m2 = std::make_pair(0, 0);
    std::vector<std::pair<bool,bool> > v(nums_count, std::make_pair(false, false));
    m1.first = 0;
    m1.second = nums[0];
    m2.first = 0;
    m2.second = nums[1];
    v[0].first = true;
    v[0].second = false;
    v[1].first = false;
    v[1].second = true;
    for(int i = 2; i < nums_count; ++i) {
        if(nums[i] == 0) {
            
            continue;
        }
        if(v[i-1].first == false) {
            m1.first = m1.second;
            m1.second += nums[i];
            v[i].first = true;
        } else {
            int condidate = m1.first + nums[i];
            if (condidate > m1.second) {
                m1.first = m1.second;
                m1.second = condidate;
                v[i].first = true;
            }
        }
        
        if(v[i-1].second == false) {
            m2.first = m2.second;
            m2.second += nums[i];
            v[i].second = true;
        } else {
            int condidate = m2.first + nums[i];
            if (condidate > m2.second) {
                m2.first = m2.second;
                m2.second = condidate;
                v[i].second = true;
            }
        }
        
    }
        
    return std::max(m1.second, m2.second);
}

int main()
{
    std::vector<int> houses(3, 1);
    std::cout << "Revenue = " << houseRobber(houses) << std::endl;

    return 0;
}
