#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int Inputs[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &Inputs[i][j]);
        }
    }

    if (Inputs[0][0] == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", Inputs[i][j]);
            }
            printf("\n");
        }
    }
    if (Inputs[0][n - 1] == 0)
    {

        for (int j = n - 1; j >= 0; j--)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%d ", Inputs[i][j]);
            }

            printf("\n");
        }
    }
    if (Inputs[n - 1][0] == 0)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                printf("%d ", Inputs[i][j]);
            }

            printf("\n");
        }
    }

    if (Inputs[n - 1][n - 1] == 0)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                printf("%d ", Inputs[i][j]);
            }

            printf("\n");
        }
    }
}