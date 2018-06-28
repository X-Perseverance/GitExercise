#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void Swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void moveZeroes(int* nums, int numsSize)
{
	assert(nums);
	int index = 0;
	int prev = -1;
	while (index < numsSize)
	{
		if (nums[index] != 0 && ++prev != index)
		{
			Swap(&nums[index], &nums[prev]);
		}
		index++;
	}
}

int main()
{
	int nums[] = { 0, 1, 0, 3, 4 };
	int size = sizeof(nums) / sizeof(nums[0]);
	moveZeroes(nums, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}