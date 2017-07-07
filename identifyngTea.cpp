#include <stdio.h>
int main()
{
    int n, m , i, cnt=0;
    scanf("%d", &n);
    for(i=0; i<5; i++)
    {
        scanf("%d", &m);
        if(m==n) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}