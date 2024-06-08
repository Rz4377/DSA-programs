#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    
    bool isPossible(int i, int j,vector<vector<int>> &m,vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=m.size() || j>=m.size()){
            return false;
        }
        else if(visited[i][j] == true || m[i][j] == 0){
            return false;
        }
        return true;
    }
    
    void solve(int i, int j,string output,vector<string>&ans,vector<vector<bool>> &visited,
    vector<vector<int>> &m, int n){
        // base condn
        if(i == n-1 && j == n-1){
            ans.push_back(output);
            return ;
        }
        int arr1[] = {i,i,i-1,i+1};
        int arr2[] = {j-1,j+1,j,j};
        char arr[] = {'L','R','U','D'};
        
        for(int k=0 ; k<4 ; ++k){
            int posx = arr1[k];
            int posy = arr2[k];
            
            bool p = isPossible(posx,posy,m,visited);
            if(p){
                visited[posx][posy] = true;
                output.push_back(arr[k]);
                solve(posx, posy ,output,ans,visited,m,n);
                output.pop_back();
                visited[posx][posy] = false;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        // 0, 0 par 1 na ho 
        if(m[0][0]!=1){
            return ans;
        }
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        int i = 0;
        int j = 0;
        
        visited[0][0] = true;
        
        int dest[2] = {n-1,n-1};
        string output = "";
        
        solve(i,j,output,ans,visited,m,n);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}