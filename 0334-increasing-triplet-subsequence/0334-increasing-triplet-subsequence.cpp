class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
         int i,n=a.size(),one=INT_MAX,two=INT_MAX;
        if(n<3)
            return 0;

        for(i=0;i<n;i++)
        {
            if(a[i]<=one)
                one = a[i];
            else if(a[i]<=two)
                two = a[i];
            else
                return 1;
        }
        return 0;
    }
};