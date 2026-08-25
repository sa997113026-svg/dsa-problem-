class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
                vector<int> ans;
                unordered_set< int > s;
                int n=grid.size();
                int actualsum=0;
                int expectedsum=0;
                int a,b;
                
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        actualsum+= grid[i][j];


                      if(s.find(grid[i][j])!=s.end()){
                      a=grid[i][j];
                      ans.push_back(a);
                }
                s.insert(grid[i][j]);

            }

        }

                
        // Count occurrences of each value
        b=n*n*(n*n+1)/2-actualsum+a;;
        ans.push_back(b);
        return ans;
    }
};        

