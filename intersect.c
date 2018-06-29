#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

void InsertSort(int *nums, int numsSize)
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

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
	assert(nums1&&nums2);
	if (nums1Size == 0 || nums2Size == 0)
	{
		return NULL;
	}
	InsertSort(nums1, nums1Size);
	InsertSort(nums2, nums2Size);

	int i = 0;
	int j = 0;
	while (i<nums1Size && j<nums2Size)
	{
		if (nums1[i]>nums2[j])
		{
			j++;
		}
		else if (nums1[i]<nums2[j])
		{
			i++;
		}
		else
		{
			(*returnSize)++;
			i++;
			j++;
		}
	}

	int *ret = (int*)malloc((*returnSize)*sizeof(int));

	i = 0;
	j = 0;
	int index = 0;
	while (i<nums1Size && j<nums2Size)
	{
		if (nums1[i]>nums2[j])
		{
			j++;
		}
		else if (nums1[i]<nums2[j])
		{
			i++;
		}
		else
		{
			ret[index++] = nums1[i];
			i++;
			j++;
		}
	}

	return ret;
}

int main()
{
	int nums1[] = { 1, 2, 3, 4 };
	int nums2[] = { 1, 3 };
	int size1 = sizeof(nums1) / sizeof(nums1[0]);
	int size2 = sizeof(nums2) / sizeof(nums2[0]);
	int returnsize = 0;

	int *tmp = intersect(nums1, size1, nums2, size2, &returnsize);
	for (int i = 0; i < returnsize; i++)
	{
		printf("%d ", tmp[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}