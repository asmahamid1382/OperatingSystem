#include <stdio.h>
#include <string.h>

typedef struct students
{
    char Name[20];
    int Age;
    int Score;
} Students;

typedef struct pair
{
    Students S1;
    Students S2;
    int Average;
} Pair;

void sort_pairs(Pair arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].Average < arr[j + 1].Average)
            {
                Pair temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Delete_Least_Scored_Student(Students student[], int n)
{
    int i;
    int min = __INT_MAX__;
    int index;
    for (i = 0; i < n; i++)
    {
        if (student[i].Score < min)
        {
            index = i;
            min = student[i].Score;
        }
    }
    if (index != n - 1)
    {
        for (i = index; i < n - 1; i++)
        {
            student[i] = student[i + 1];
        }
    }
}

int main()
{

    int n;
    scanf("%d", &n);
    Students student[n];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%s %d %d", student[i].Name, &student[i].Age, &student[i].Score);
    }
    if (n % 2 == 1)
    {
        Delete_Least_Scored_Student(student, n);
        n = n - 1;
    }
    Pair new_pair[n / 2];
    for (i = 0; i < n / 2; i++)
    {
        new_pair[i].S1 = student[i];
        new_pair[i].S2 = student[n - 1 - i];
        new_pair[i].Average = (new_pair[i].S1.Score + new_pair[i].S2.Score);
    }

    sort_pairs(new_pair, n / 2);

    for (i = 0; i < n / 2; i++)
    {
        printf("%s %d %d, %s %d %d\n", new_pair[i].S1.Name, new_pair[i].S1.Age, new_pair[i].S1.Score, new_pair[i].S2.Name, new_pair[i].S2.Age, new_pair[i].S2.Score);
    }
}