#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Leetcode 2656. Maximum Sum With Exactly K Elements 
 */

int maximizeSum(int* nums, int numsSize, int k) {
    int max = 0;
    int sum = (k * (k - 1) / 2);

    for (int i = 0; i < numsSize; i++) {
        if(nums[i] > max) {
            max = nums[i];
        }
    }

    sum += max * k;

    return sum;
}

void test1(){
    int nums[] = {1,2,3,4,5};
    int k = 3;
    int result = maximizeSum(nums, 5, k);
    printf("1: %d\n", result);
    assert(result == 18);
}

void test2(){
    int nums[] = {5,5,5};
    int k = 2;
    int result = maximizeSum(nums, 3, k);
    printf("2: %d\n", result);
    assert(result == 11);
}

void test3(){
    int nums[] = {9,9,9};
    int k = 4;
    int result = maximizeSum(nums, 3, k);
    printf("3: %d\n", result);
    assert(result == 42);
}

void test4(){
    int nums[] = {99,99,99};
    int k = 4;
    int result = maximizeSum(nums, 3, k);
    printf("4: %d\n", result);
    assert(result == 402);
}

void test5(){
    int nums[] = {100,100,100};
    int k = 100;
    int result = maximizeSum(nums, 3, k);
    printf("5: %d\n", result);
    assert(result == 14950);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}