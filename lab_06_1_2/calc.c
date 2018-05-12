int calc(int* const begin, int* const end)
{
    int *i = begin, *j = end;
    int sum = 0;

    while (i <= end && j >= begin)
    {
        if (*i >= 0)
            i++;

        if (*j < 0)
            j--;

        if (*i < 0 && *j >= 0)
            sum += (*(i++)) * (*(j--));
    }

    return sum;
}

