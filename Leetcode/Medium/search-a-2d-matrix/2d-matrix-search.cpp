#include <vector>
#include <iostream>

using namespace std;

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // first instinct is nested binary searches: one for array selection, one within each array
            // i.e, find the middle array, then find its middle value
                // if this value is equal to target, return true
                // if this value is greater than target, set right bounds to this value
                // else if this value is less than target, set left bounds to this value
        
        // the trouble: how do we know when to switch between arrays?
            // take example 1: we can find the middle array via the size of vector by using outerMid = outerLow + (outerHigh - outerLow)/2
            // that gives us our array targeting, but we then need separate pointers for searching within an array. 
            // problem suggests o(log(m*n)) complexity. bsearch averages o(log n), so i think this is actually the intended solution
        
        // Initial values
        int outerLow = 0, outerHigh = matrix.size()-1, outerMid;
        int innerLow, innerHigh, innerMid; 

        while (outerLow <= outerHigh){
            outerMid = outerLow + (outerHigh - outerLow)/2;
            innerHigh = matrix[outerMid].size()-1; // Reset inner pointers before looping again
            innerLow = 0; 
            while (innerLow <= innerHigh){
                innerMid = innerLow + (innerHigh - innerLow)/2;
                if (matrix[outerMid][innerMid] == target){
                    return true;
                } else if (matrix[outerMid][innerMid] > target) {
                    innerHigh = innerMid-1;
                } else {
                    innerLow = innerMid+1;
                }
            }
            if (matrix[outerMid][innerMid] > target){ // Use where inner left off to adjust outer
                outerHigh = outerMid-1;
            } else {
                outerLow = outerMid+1;
            }
            
        }
        return false;
    }

int main(){
    vector<vector<int>> matrix = {
        {1,5,7,10},
        {12, 16, 19, 22},
        {25, 27, 32, 38}
    };
    cout << "Test 1, expecting true/1: " << searchMatrix(matrix, 32) << endl;
    cout << "Test 2, expecting false/0: " << searchMatrix(matrix, 99) << endl;
}
