//
// Created by eyeboy on 2018/6/26.
//

#ifndef LEETCODE_CONTAINER_WITH_MOST_WATER_HPP
#define LEETCODE_CONTAINER_WITH_MOST_WATER_HPP

#include <vector>

/**
 * Given n non-negative integers a1, a2, ..., an,
 * where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container,
 * such that the container contains the most water.
   Note: You may not slant the container and n is at least 2.
 */

 using namespace std;

 namespace container_with_most_water {
     // brute force (Time Limit Exceeded)
     // O(n!), O(1)
     int solution_1(vector<int> &height) {
         int result = 0;

         int len = height.size();
         for(int i=0; i<len; ++i) {
             for(int j=i+1; j <len; ++j) {
                 int valI = height[i];
                 int valJ = height[j];
                 int val = (valI < valJ ? valI : valJ) * (j - i);
                 if(val > result)
                     result = val;
             }
         }
         return result;
     }

     int solution_2(vector<int> &height) {
         int len = height.size();

         int i = 0, j = len - 1;
         int leftH = height[i];
         int rightH = height[j];
         int result = (leftH < rightH ? leftH : rightH) * (j - i);
         while(i < j) {
            if(leftH < rightH) {
                while((++i) < j && leftH > height[i]);

                if(i >= j)
                    return result;

                leftH = height[i];
            } else {
                while((--j) > i && rightH > height[j]);

                if(j <= i)
                    return result;

                rightH = height[j];
            }

            int val = (leftH < rightH ? leftH : rightH) * (j - i);
            if(result < val)
                result = val;
         }

         return result;
     }
 }

#endif //LEETCODE_CONTAINER_WITH_MOST_WATER_HPP
