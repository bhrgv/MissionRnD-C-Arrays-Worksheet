/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL || len < 0)
		return NULL;
	int i=0;
	int flen = len;
	while(i<len)
	{
		int j;
		j = i+1;
		while (j < len)
		{
			if (Arr[i] == Arr[j])
			{
				int k = j + 1;
				while (k < len)
				{
					Arr[k - 1] = Arr[k];
					k++;
				}
			}
			j++;
		}
		i++;
	}
}