//
// Created by ori on 11/15/22.
//
#include <stdio.h>
#include "NumClass.h"

int isPrime(int num)
{
    if (num == 1 || num == 2)  return 1;

    for (int i=2; i<num;i++)
    {
        if (num % i == 0)   return 0;
    }
    return 1;
}

int isStrong(int num)
{
    int sum = 0;
    int originalNumber = num;
    while (originalNumber > 0)
    {
        int div = (originalNumber%10);
        sum = sum + factorialVal(div);
        originalNumber = originalNumber / 10;
    }
    if (num==sum) return 1;
    return 0;
}

int factorialVal(int num)
{
    int sum = 1;
    for (int i = 1; i<= num; i++)
    {sum = i * sum;}
    return sum;
}

int isPow(int a , int b)
{
    int result=1;
    for(int i=0; i<b; i++)
        {result = result*a;}
    return result;
}

