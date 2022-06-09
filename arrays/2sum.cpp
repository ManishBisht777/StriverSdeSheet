vector<int> twoSum(vector<int>& arr, int target) {
        
        int n=arr.size();
        
        int st=0,end=n-1;
        vector<int> ans;
        
        while(st<=end)
        {
            int sum=arr[st]+arr[end];
            if(sum==target) 
            {
                ans.push_back(st+1);
                ans.push_back(end+1);
                break;
            }
            else if(sum<target) st++;
            else end--;
        }
        return ans;
    }