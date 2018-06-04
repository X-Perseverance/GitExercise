#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int maxProfit(int* prices, int pricesSize)
{
	assert(prices);
	if (pricesSize == 0)
	{
		return 0;
	}
	int sum = 0;
	int sub = 0;
	for (int i = 1; i<pricesSize; i++)
	{
		sub = prices[i] - prices[i - 1];
		if (sub > 0)
		{
			sum += sub;
		}
	}
	return sum;
}

int main()
{
	int prices[] = { 7, 1, 5, 3, 6, 4 };
	int size = sizeof(prices) / sizeof(prices[0]);
	int profit = maxProfit(prices, size);
	printf("Profit£º%d\n", profit);
	system("pause");
	return 0;
}