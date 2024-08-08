class Solution {
public:
    int passThePillow(int n, int t)  {
           
        int N = 2*n-2;   // total no of dintinct passes for n friends
        int T = t % N;    // # of pass(# of seconds) 
        return 1 + ((T<n)? T:N-T) ;    // Forward pass T+1  // Reverse Pass N-T+1     N-T+1;

    }

};