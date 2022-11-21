//
// Created by ori on 11/15/22.
//

#include <stdio.h>
#include "NumClass.h"

int isPalindrome(int num)
{
    int originalNumber = num;
    int temp = 0;
    int reversed = 0;

    // reversed integer is stored in reversed variable
    while (num != 0)
    {
        temp = num % 10;
        reversed = reversed * 10 + temp;
        num /= 10;
    }

    if (originalNumber == reversed) return 1;
    return 0;
}

int isArmstrong(int num)
{
    int originalNUmber = num;
    int digCOunt = 0;

    while (num != 0) {
        digCOunt++;
        num /= 10;
    }

    num = originalNUmber;
    int sum = 0;

    while (num != 0) {
        sum += (isPow((num % 10),  digCOunt));
        num /=10;
    }


    if ((int) sum == originalNUmber) return 1;
    return 0;
}

