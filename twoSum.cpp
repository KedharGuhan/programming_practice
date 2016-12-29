#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {

        int targetNum;

        for (int i = 0; i < nums.size(); i++ ) {

            targetNum = target - nums.at(i);

            twoSum.at(0) = i;

            for( int j = i+1; j < nums.size(); j++ ){

                if( nums.at(j) == targetNum ){

                    twoSum.at(1) = j;

                    break;

                }

            }

        }

        return twoSum;

 }

