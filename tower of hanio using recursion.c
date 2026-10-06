#include <stdio.h>
#include <stdlib.h>
void TowerofHanoi(int n,char source,char dest,char temp)
{
    if(n>1){
        TowerofHanoi(n-1,source,temp,dest);
        printf("\n Move %d disc from %c to %c",n,source,dest);
        TowerofHanoi(n-1,temp,dest,source);
    }
    else
        printf("\n Move %d disc from %c to %c",n,source,dest);
}
int main()
{
    int n;
    printf("\n Read no. of discs:");
    scanf("%d",&n);
    TowerofHanoi(n,'S','D','T');
    return 0;
}



