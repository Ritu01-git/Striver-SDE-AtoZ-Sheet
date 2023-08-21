#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //using map
    map<int, int> mpp;

    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        cout << it.first << "=> " << it.second << endl;
    }

    //using unorderd map
    unordered_map<int, int> ans;
    for(int i = 0; i < n; i++){
        ans[arr[i]]++;
    }
    for(auto it: ans){
        cout << it.first << "=> " << it.second << endl;
    }
    
    return 0;
}