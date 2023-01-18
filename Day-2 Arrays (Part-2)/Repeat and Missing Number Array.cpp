vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int x=0;
    int n= A.size();
    for(int i=0;i<n;i++)
    {
        x^=A[i];
        x^=i+1;
    }
    int pos=-1;
    for(int i=0;i<32;i++)
    {
       if(x&(1<<i))
       {
           pos=i;
           break;
       }
    }
    vector<int> bas1,bas2;
    for(int i=0;i<n;i++)
    {
        if(A[i]&(1<<pos))
        bas1.push_back(A[i]);
        else
        bas2.push_back(A[i]);

        if((i+1)&(1<<pos))
        bas1.push_back(i+1);
         else
        bas2.push_back(i+1);
    }
    int ans1=0,ans2=0;
    for(int i=0;i<bas1.size();i++)
    {
        ans1^=bas1[i];
    }
    for(int i=0;i<bas2.size();i++)
    ans2^=bas2[i];

int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==ans1) cnt++;
    }
    if(cnt==2)
    return {ans1,ans2};
    else
    return {ans2,ans1};

}
