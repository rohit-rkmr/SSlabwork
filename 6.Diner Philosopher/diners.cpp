#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ps 5
bool AllDone(bool p[])// checks if everyone s done eating
{
    for (int i = 0; i < ps; i++)
        if (!p[i])
            return false;
    return true;
}

void FreeChops(bool chops[])//puts all the chopticks to table
{
    for (int i = 0; i < ps; i++)
        chops[i] = true;
}

int main()
{

    bool c[ps];
    bool p[ps];
    FreeChops(c);

    bool f = true;
    while (f)
    {
        
        FreeChops(c);
        f = false;
        for (int i = 0; i < ps; i++)
        {
            if (!p[i])
            {
                if (c[i] && c[(i + 1) % 5])
                {
                    c[i] = false;
                    c[(i + 1) % 5] = false;
                    printf("P %d is eating\n", i+1);
                    p[i] = true;
                    f= true;
                }
                else
                    printf("P %d is thinking\n", i+1);
            }
            else
                printf("P %d has  eaten\n", i+1);
        }
        if (AllDone(p))
        {
            printf("Done.exiting...\n");
            exit(0);
        }
        printf("\nGoing Again:\n");
        
    }
    printf("Deadlock\n");
    return 0;
}

