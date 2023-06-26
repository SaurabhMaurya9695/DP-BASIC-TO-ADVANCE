class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     int n=numRows;
     vector<vector<int>>p(n);
     for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i){
                p[i].push_back(1);
            }else{
                p[i].push_back(p[i-1][j-1] + p[i-1][j]); // making ans from here
            }
        }
     }   
     return p;
    }
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pt = generate(34);
        return pt[rowIndex];
    }
};