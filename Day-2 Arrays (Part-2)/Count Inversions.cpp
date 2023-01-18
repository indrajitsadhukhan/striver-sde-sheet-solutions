long long int merge(long long int arr[],int l,int m,int r)
{
    int i=0,j=0,k=l,n1=m-l+1,n2=r-m;
   long long  int cnt=0;
    int L[n1],R[n2];
        j=m+1;
    for(int i=l;i<=m;i++)
    {
        while(j<=r && arr[i]>arr[j])
           j++;
       cnt+=(0ll+j-m-1);
    }
    for(int i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(int i=0;i<n2;i++)
        R[i]=arr[m+1+i];
    i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else{
//             1 7 8         2 3
//             cnt+=(m-i-l+1);
            arr[k++]=R[j++];
        }
    }
    while(i<n1)
        arr[k++]=L[i++];
    while(j<n2)
        arr[k++]=R[j++];
    return cnt;
}
long long int mergesort(long long int arr[],int l,int r)
{
    if(l>=r) return 0;
    int mid = (0ll+l+r)/2;
 long long  int cnt= mergesort(arr,l,mid);
    cnt+=mergesort(arr,mid+1,r);
  cnt+=merge(arr,l,mid,r);
    return cnt;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
  return mergesort(arr,0,n-1);
}
