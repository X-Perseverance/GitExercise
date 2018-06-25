#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	int k = 1; //��ʼ��λֵ  
	for (int i = digitsSize - 1; i >= 0; i--)
	{
		digits[i] += k; //ÿһλ���Ͻ�λ��ֵ
		k = digits[i] / 10; //������һ����λֵ
		digits[i] %= 10; //���¸�λ��ֵ       
		if (k == 0) //��û�н�λ��ֱ���˳�ѭ��
		{
			*returnSize = digitsSize;
			break;
		}
	}

	if (k > 0) //������н�λ  
	{
		*returnSize = digitsSize + 1;
		int *tmp = (int*)malloc((*returnSize)*sizeof(int));
		tmp[0] = k;
		for (int i = 0; i < digitsSize; i++)
		{
			tmp[i + 1] = digits[i];
		}
		return tmp;
	}

	return digits;
}

int main()
{
	int digits[] = { 9, 9, 9 };
	int size = sizeof(digits) / sizeof(digits[0]);
	int returnSize = 0;
	int *ret = plusOne(digits, size, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", ret[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}