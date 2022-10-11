#include "sort.h"

int power(int num, size_t index)
{
    if (index == 0)
        return 1;
    else if (index == 1)
        return num;
    else
        return num * power(num, index - 1);

}

void shell_sort(int *array, size_t size)
{
    int interval;
    size_t index, i;
    index = 0;

    interval = 1;

    while (interval < size)
    {
        for (i = )
    }


}