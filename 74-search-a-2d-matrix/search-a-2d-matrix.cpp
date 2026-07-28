class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //using binary search
        int r= matrix.size();
        int c=matrix[0].size();
        int i= 0;
        int j=r*c-1;
        while(i<=j){
            int m=i+(j-i)/2;
            int col=m%c;
            int row=m/c;
                        if(target==matrix[row][col]){
                return true;
            }
            else if(target>matrix[row][col]) i=m+1;
            else j=m-1;
        }
        return false;
    }
};