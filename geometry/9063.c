#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int x, y;
    int lowestX = 100000, lowestY = 100000, highestX = -100000, highestY = -100000;
    for (int i = 1 ; i <= n ; i++)
    {
        scanf("%d %d", &x, &y);
        lowestX = x < lowestX ? x : lowestX;
        lowestY = y < lowestY ? y : lowestY;
        highestX = x > highestX ? x : highestX;
        highestY = y > highestY ? y : highestY;
    }
    if (n == 1) {
        printf("0");
    }   
    else {
        printf("%d", (highestX - lowestX) * (highestY - lowestY));
    }
}