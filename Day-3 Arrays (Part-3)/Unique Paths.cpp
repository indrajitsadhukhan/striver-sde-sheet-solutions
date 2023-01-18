class Solution {
public:
    int uniquePaths(int m, int n) {
        m--,n--;
        if(m>n)
            swap(m,n);
       long long int ans=1,j=1;
        for(int i=m+1;i<=m+n;i++,j++)
        {
            ans*=i;
            ans/=j;
        }
        return (int)ans;
    }
};