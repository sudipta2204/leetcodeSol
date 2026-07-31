/*
 * Problem #74: Search a 2D Matrix
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * You are given an m x n integer matrix matrix with the following two properties:
 * 
 * 
 * 	Each row is sorted in non-decreasing order.
 * 	The first integer of each row is greater than the last integer of the previous row.
 * 
 * 
 * Given an integer target, return true if target is in matrix or false otherwise.
 * 
 * You must write a solution in O(log(m * n)) time complexity.
 * 
 *  
 * Example 1:
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * Output: false
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	m == matrix.length
 * 	n == matrix[i].length
 * 	1 <= m, n <= 100
 * 	-104 <= matrix[i][j], target <= 104
 *
 * ----- Solution -----
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        int n= matrix[0].size();
        int start= 0, end= m-1;
        while(start<=end){
        int mid= start + (end-start)/2;
        if(target>= matrix[mid][0] && target<= matrix[mid][n-1]){
            int s= 0;
            int e= n-1;
            while(s<=e){
            int middle= s+(e-s)/2;
                if(target==matrix[mid][middle]){
                    return true;
                }else if(target>matrix[mid][middle]){
                    s=middle+1;
                }else{
                    e=middle-1;
                }
            }
                return false;
        }else if(target>matrix[mid][n-1]){
            start=mid+1;
        }else{
            end=mid-1;
        }
        }
        return false;
    }
};