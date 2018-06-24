#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void InsertSort(int *nums, int numsSize) //插入排序
{
	for (int i = 0; i < numsSize - 1; i++)
	{
		int end = i;
		int key = nums[end + 1];
		while (end >= 0 && key < nums[end])
		{
			nums[end + 1] = nums[end];
			end--;
		}
		nums[end + 1] = key;
	}
}

int containsDuplicate(int* nums, int numsSize)
{
	assert(nums);
	if (numsSize == 0 || numsSize == 1)
	{
		return 0;
	}
	InsertSort(nums, numsSize);
	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i] == nums[i - 1])
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int nums[] = { 1, 2, 3, 4, 5, 5 };
	int size = sizeof(nums) / sizeof(nums[0]);
	int ret = containsDuplicate(nums, size);
	printf("是否存在重复：%d\n", ret);
	system("pause");
	return 0;
}