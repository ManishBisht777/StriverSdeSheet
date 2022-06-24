bool ispossible(vector<int> &arr, int k , int mid)
{
    int cnt=1;
    int temp=arr[0];
    
    for(int i=1; i<arr.size();i++)
    {
        
        if(arr[i]-temp>=mid)
        {
            cnt++;
            if(cnt>=k) return true;
            temp=arr[i];
        }
    }
    
    return false;
}

int aggressiveCows(vector<int> &arr, int k)
{
    //    Write your code here.
    sort(arr.begin(),arr.end());
    
    
    int st=0;
    int end=arr[arr.size()-1];
    int ans=-1;
    
    while(st<=end)
    {
        int mid=st+(end-st)/2;
        
        if(ispossible(arr,k,mid))
        {
            st=mid+1;
            ans=mid;
        }
            
        else end=mid-1;        
    }
    
    
    return ans;
    
}