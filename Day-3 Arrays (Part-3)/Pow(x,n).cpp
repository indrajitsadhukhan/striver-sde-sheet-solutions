class Solution {
public:
    double myPow(double x, long long int n) {
        if(n<0)
         { 
         x=1.00000000/x;
            n=-n;
        }
        if(n==0) return 1;
        if(n%2) return x*myPow(x,n-1);
        double ans=myPow(x,n/2);
        return ans*ans;
    }
};