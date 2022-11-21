//
// Created by ori on 11/15/22.
//
#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPalindrome(int num)
{
    if (num == rev(num,0)) return 1;
    return 0;
}

int isArmstrong(int num)
{
    if(num == 0)return 1;
    if(num == isArm(num, digCount(num)))return 1;
    return 0;
}


int digCount(int x)
{
    if(x == 0)return 0;
    return 1+ digCount(x/10);
}


int isArm(int num, int digs)
{
    if(num == 0)return 0;
    return isArm(num/10,digs)+ (isPow(num%10,digs));

}




int rev(int n, int temp)
{
    if (n == 0)
        return temp;

    // stores the reverse of a number
    temp = (temp * 10) + (n % 10);

    return rev(n / 10, temp);
}
