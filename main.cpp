#include <iostream>

#include "CListOriginal.h"

int main()
{
    CList<int> list;

    for (int i = 0; i < 4; ++i)
    {
        list.push_back(i);
    }

    for (int i = 0; i < 2; ++i)
    {
        list.push_front(i);
    }

    return 0;
}