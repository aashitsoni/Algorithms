/*
Multiply Strings
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.

*/



char * multiply(char * num1, char * num2){
    
    int len_big = strlen(num1);
    int len_small = strlen(num2);
    int len_res;
    char *char_sum;
    char *big = num1;
    char *small = num2;
    int zero = 0;
    
    int i,j,carry,piv,pos,sum;
    
    if(len_big < len_small)// swap only if len_big < len_small
    {
        len_res = len_big;
        len_big = len_small;
        len_small = len_res;
        big = num2;
        small = num1;
        
    }
    len_res = len_big+len_small;
    
    
    char_sum = (char*)calloc(len_res+1,sizeof(char));
    
    if(NULL == char_sum)
        return NULL;
    
    pos = len_res;
    for(i = len_small-1; i >= 0;i--)
    {
        piv = --pos;
        
        int mul = small[i] - 0x30; // convert it to integer
        carry = 0;
        if(mul == 0)
            continue;
      
        zero = 1;
        
        for(j = len_big-1; j >= 0;j--)
        {
            int dig = big[j] - 0x30;
            
            sum = dig*mul+carry+char_sum[piv];
            
            carry = sum/10;
            sum = sum%10;
            char_sum[piv] = sum;
            piv--;
        }
        
        // manage the carry with inline-addition
        if(carry )
        {
            sum = char_sum[piv]+carry;
            carry = sum/10;
            sum = sum%10;
            char_sum[piv] = sum;
        }    
    }
    
    if(zero == 0)
    {
        char_sum[0] = '0';
        char_sum[1] = NULL;
        return char_sum;
    }
    if(char_sum[0] == 0)
    {
        for(i = 1; i <= len_res-1; i++)
            char_sum[i-1] = char_sum[i] + 0x30;
        char_sum[i-1] = '\0'; // set the null
    }
    else
    {
        for(i = 0; i < len_res; i++)
            char_sum[i] = char_sum[i] + 0x30;
    }
        
    
    
    return char_sum;
        

}