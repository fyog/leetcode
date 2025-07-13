#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:

    // iterator approach
    int maxArea(vector<int> &height) {

        vector<int>::iterator left = height.begin();
        vector<int>::iterator right = height.end() - 1;
        vector<int> areas;
        int i = 1;
        int j = height.size();


        while (i < j) {
            areas.push_back((min(*left, *right)  *  (j - i)));
            
            // move to the next possible container and increment accordingly
            if (*left < *right) { left++; i++; }
            else { right--; j--; }
        }
        
        // find the max area from the list of areas
        auto max_area = max_element(areas.begin(), areas.end());
        return *max_area;
    }
}; 