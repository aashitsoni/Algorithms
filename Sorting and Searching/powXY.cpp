/*
Pow(x, n)

Solution
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104
*/

double myPow(double x, int n)
{
    int neg_pow = 1;
    double result=1;
    if(n > 0)
    {
        neg_pow = 0;
        n = -n; // make -t positive
    }
    else if(n == 0)
        return 1;
    
    if(x == 0 || x == 1)
        return x;
    else  if(x == -1)
    {
        if(n % 2 == 0)
            return 1;
        else
            return -1;
    }
    
    
    while(n<0)
    {
        int power = -1;
        double value = x;
        while(power+power > n)
        {
            value*=value;
            power+=power;
            
        }
        result*=value;
        
        n-=power;
    }
    if(neg_pow)
        result = 1/result;
    
        
    return result;
    
}
