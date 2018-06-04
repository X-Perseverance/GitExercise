#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int removeDuplicates(int* nums, int numsSize)
{
	assert(nums);
	if (numsSize == 0)
	{
		return 0;
	}
	int j = 0;
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] > nums[j])
		{
			nums[++j] = nums[i];
		}
	}
	return j + 1;
}

int main()
{
	int nums[] = { 1, 1, 2, 3, 3, 3, 4, 5, 5 };
	int size = sizeof(nums) / sizeof(nums[0]);
	int newsize = removeDuplicates(nums, size);
	for (int i = 0; i < newsize; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}