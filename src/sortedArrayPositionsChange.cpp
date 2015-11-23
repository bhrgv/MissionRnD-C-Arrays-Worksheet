/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len < 0)
		return NULL;
	int i, temp, j;
	int flag = 0;
	int c;
	for (i = 0; i<len - 1; i++)
	{
		if (Arr[i] <= Arr[i + 1])
		{
		}
		else
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		j = i;
		temp = j;
		while (j<len)
		{
			if ((Arr[i - 1] <= Arr[j]) && (Arr[j]<Arr[i + 1]))
				break;
			j++;
		}
		c = Arr[temp];
		Arr[temp] = Arr[j];
		Arr[j] = c;
	}
}