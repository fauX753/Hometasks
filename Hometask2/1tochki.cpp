#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
 
using namespace std;
 
bool comp(vector<int>&f,vector<int>&s){
    
    if(f[0] == s[0])return (f[1] < s[1]);
    else return (f[0] < s[0]);
    
}
 
int main() 
{
    int n;
    cin >> n;
    
    vector<vector<int>>v(n,vector<int>(2));
    
    for(int i = 0;i<n;++i)cin >> v[i][0] >> v[i][1];
    
    vector<vector<int>>temp;
    
    for(int i = 0;i<n;++i){
        temp.push_back({v[i][0],0,i});
        temp.push_back({v[i][1],1,i});
    }
    
    sort(temp.begin(),temp.end(),comp);
    
    vector<int>ok(n);
    vector<int>ans;
    
    vector<int>nul(n);
    
    for(int i = 0;i<temp.size();++i){
        
        int f = temp[i][0];
        int s = temp[i][1];
        int t = temp[i][2];
        
        //cout << f << ' ' << s  << ' ' << ok[t] << "\n";
        
        if(s == 0)ok[t] = 1;
        else {
            
            if(ok[t]){
                
                ok = nul;
                
                ans.push_back(f);
                
            }
            
        }
        
        
        
    }
    
    cout << ans.size() << "\n";
    
    for(int i = 0;i<ans.size();++i)cout << ans[i] << ' ';
    
    
    
    return 0;
}