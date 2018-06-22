#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void Reverse(int* nums, int begin, int end) //逆置
{
	while (begin < end)
	{
		int tmp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = tmp;
		begin++;
		end--;
	}
}

void rotate(int* nums, int numsSize, int k)
{
	assert(nums);
	if (numsSize == 0 || numsSize == 1)
	{
		return;
	}
	k = k%numsSize;
	Reverse(nums, 0, numsSize - k - 1); //先逆置前n-k个
	Reverse(nums, numsSize - k, numsSize - 1); //再逆置后k个
	Reverse(nums, 0, numsSize - 1); //最后再整体逆置
}

int main()
{
	int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(nums) / sizeof(nums[0]);
	int k = 8;

	printf("旋转前：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");

	rotate(nums, size, k);
	printf("旋转后：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}