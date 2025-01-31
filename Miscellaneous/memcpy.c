#include <stdlib.h>
#include <stdio.h>

void mymemcpy(void *dst, void *src, int len)
{
    int inc = 1;
    int offset = 0;
    if( dst  > src ) {
        inc = -1;
        offset = len;
    } 
    
    for(int i = 0; len > 0 ; i+=inc, len-- )
        *((unsigned char*)dst+offset+i) = *((unsigned char*)src+offset+i);

    /* write code here */
    //if( dst > src ) {
    //    for( int i = len-1; i >=0 ; i--)
    //        *((unsigned char*)dst+i) = *((unsigned char*)src+i);
    //} else if ( dst < src ){
    //    for( int i = 0; i <len ; i++)
    //        *((unsigned char*)dst+i) = *((unsigned char*)src+i);
    //}
        
}

int main()
{
    char mem[80];
    int s, d, l;
    
    for (int i=0; i<80; i++) {
        mem[i] = '0' + (i%10);
    }
    printf("dst, src, len:");
    scanf("%d %d %d", &d, &s, &l);
    printf("\n");
    for (int i=0; i<80; i++) {
        printf("%c", mem[i]);
    }
    for (int i=s; i<s+l; i++) {
        mem[i] = 'A' + ((i-s)%26);
    }
    printf("\n");
    for (int i=0; i<80; i++) {
        printf("%c", mem[i]);
    }
    mymemcpy(mem+d, mem+s, l);
    printf("\n");
    for (int i=0; i<80; i++) {
        printf("%c", mem[i]);
    }
}
