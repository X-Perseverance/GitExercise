#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int singleNumber(int* nums, int numsSize)
{
	assert(nums);
	int tmp = 0;
	for (int i = 0; i<numsSize; i++)
	{
		tmp ^= nums[i];
	}
	return tmp;
}

int main()
{
	int nums[] = { 1, 1, 2, 2, 3, 4, 4 };
	int size = sizeof(nums) / sizeof(nums[0]);
	int num = singleNumber(nums, size);
	printf("singleNumber£º%d\n", num);
	system("pause");
	return 0;
}