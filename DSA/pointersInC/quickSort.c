#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateRandom(int *a, int s)
{
    for (int i = 0; i < s; i++)
    {
        *(a + i) = rand() % s + 1;
    }
}

void swap(void *a, int i, int j, int sz)
{

    char *temp = malloc(sz);

    char *t1 = (char *)a + i * sz;
    char *t2 = (char *)a + j * sz;

    memcpy(temp, t1, sz);
    memcpy(t1, t2, sz);
    memcpy(t2, temp, sz);

    free(temp);
}

void quick_sort(void *a, int L, int R,
                int (*cmp)(void *, void *), int sz)
{

    if (L >= R)
        return;

    int p = L;
    int x = L;

    for (int i = L + 1; i <= R; i++)
    {
        if (cmp((char *)a + i * sz,
                (char *)a + p * sz) < 0)
        {
            swap(a, i, ++x, sz);
        }
    }

    swap(a, x, p, sz);

    quick_sort(a, L, x - 1, cmp, sz);
    quick_sort(a, x + 1, R, cmp, sz);
}

void print(int *a, int s)
{

    for (int i = 0; i < s; i++)
    {
        printf("%d ", *(a + i));
    }

    printf("\n");
}

struct student
{
    int id;
    float cgpa;
    char *name;
};

int intCmparator(void *i, void *j)
{
    int x = *(int *)i;
    int y = *(int *)j;

    if (x == y)
        return 0;

    if (x < y)
        return -1;

    return 1;
}

int floatCmparator(void *i, void *j)
{
    float x = *(float *)i;
    float y = *(float *)j;

    if (x == y)
        return 0;

    if (x < y)
        return -1;

    return 1;
}

int studentIdCmp(void *i, void *j)
{
    struct student *x = (struct student *)i;
    struct student *y = (struct student *)j;

    return x->id - y->id;
}

int main()
{

    int size = 8;
    int a[size];

    generateRandom(a, size);
    print(a, size);

    quick_sort(a, 0, size - 1,
               intCmparator,
               sizeof(int));

    print(a, size);



    float f[6] = {1.2, 3.4, .7, .8, .4, .3};

    quick_sort(f, 0, 5,
               floatCmparator,
               sizeof(float));

    for (int i = 0; i < 6; i++)
    {
        printf("%f ", f[i]);
    }

    printf("\n");



    int n = 7;

    struct student *d =
        malloc(sizeof(struct student) * n);

    float cgpa[] =
        {1.2f, 2.2f, 1.3f, .7f, 5.4f, 2.3f, .9f};

    char *names[] =
        {"ram", "tina", "tom", "sam",
         "tom", "david", "harry"};

    for (int i = 0; i < n; i++)
    {
        d[i].id = rand() % 100;
        d[i].cgpa = cgpa[i];
        d[i].name = names[i];
    }

    // Before sorting

    for (int i = 0; i < n; i++)
    {
        printf("%d:%s:%.2f, ",
               d[i].id,
               d[i].name,
               d[i].cgpa);
    }

    printf("\n");



    quick_sort(d, 0, n - 1,
               studentIdCmp,
               sizeof(struct student));



    for (int i = 0; i < n; i++)
    {
        printf("%d:%s:%.2f, ",
               d[i].id,
               d[i].name,
               d[i].cgpa);
    }

    printf("\n");

    free(d);

    return 0;
}