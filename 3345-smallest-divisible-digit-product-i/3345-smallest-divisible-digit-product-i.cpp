class Solution {
public:
    int product(int n){
        // base condition
        if(n == 0)  return 1;

        int rem = n%10;
        int div = n/10;

        return rem * product(div);
    }
    int smallestNumber(int n, int t) {
        for(int i=n; i<=100; i++){
            int res = product(i);
            if(res%t == 0)  return i;
        }
        return 0;
    }
};