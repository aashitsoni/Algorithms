/*
Add Binary

Solution
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

*/



char * addBinary(char * a, char * b)
{
    int a_size = strlen(a)-1;
    int b_size = strlen(b)-1;
    int sum = 0;
    int i = ((a_size>b_size)?a_size:b_size)+1;
    char* str = (char*)malloc(i+2); // one extra for last carry and one extra for the null termination
  
    str[i+1] = '\0';
    
    while(a_size >=0 || b_size >=0 || sum)
    {
        
   
        if(a_size >=0)
            sum+=a[a_size--]-0x30;
        if(b_size >=0)
            sum+= b[b_size--]-0x30;

        str[i--] = sum % 2 + 0x30;
        sum = sum/2;
    }
    return str+i+1;
}