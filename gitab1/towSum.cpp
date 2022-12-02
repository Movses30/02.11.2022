#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;                  
        unordered_map<int,int>my_map;
        
        for(int i=0;i<nums.size();i++)    
        {
            int val = target-nums[i];
            if(my_map.find(val)!=my_map.end()) 
            {
                ans.push_back(my_map.find(val)->second);
                ans.push_back(i);
                break;
            }
            my_map.insert(pair<int,int>(nums[i],i)); 
        }
        return ans;
    }
};
    

int main()
{
  vector <int> v;
  v= {1,22,34,4};
  int target = 5;
  Solution obj;
  auto ok = obj.twoSum(v,target);
  for (int i =0; i < ok.size();i++ )
  cout << ok[i]<<"\t";
  cout <<endl;
}


//version 2
/*
#include <iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    
      vector<int> twoSum(vector<int>& nums, int target) {
                map<int,int> mymap;
                vector<int> v;
                int n= nums.size();
                for(int i=0;i<n;i++)
                {
                    
                        int diff = target - nums[i]; 
                        if(mymap.find(diff) != mymap.end())
                        {
                        auto p = mymap.find(diff)->second;        
                        v.push_back(p);
                        v.push_back(i);
                        }
                        mymap.insert(make_pair(nums[i],i));
                }
          
                return v;
}
};
int main(){
    Solution obj ;
    vector<int> v;
     v={1,6,3,2,5};
     vector<int> result= obj.twoSum (v, 11);
     for(int i: result)
     {
          cout<<i<<endl;
     }
     return 0;

}*/