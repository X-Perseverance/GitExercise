#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void Reverse(int* nums, int begin, int end) //����
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
	Reverse(nums, 0, numsSize - k - 1); //������ǰn-k��
	Reverse(nums, numsSize - k, numsSize - 1); //�����ú�k��
	Reverse(nums, 0, numsSize - 1); //�������������
}

int main()
{
	int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(nums) / sizeof(nums[0]);
	int k = 8;

	printf("��תǰ��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");

	rotate(nums, size, k);
	printf("��ת��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}