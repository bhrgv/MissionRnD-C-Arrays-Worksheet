/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	if (students == NULL || K <= 0)
		return NULL;
	struct student** result = (student**)malloc(K*sizeof(student));
	if (K >= len)
	{
		int i;
		for (i = 0; i < len; i++)
			result[i] = students + i;
		return result;
	}
	int* flag = (int*)malloc(len*sizeof(int));
	int kt;
	for (kt = 0; kt < len; kt++)
		flag[kt] = 0;
	for (kt = 0; kt < K; kt++)
	{

		int index = 0;
		while (flag[index] == 1)
			index++;
		int val = students[index].score;
		int i;
		for (i = 0; i < len; i++)
		{
			if (val < students[i].score && flag[i] == 0)
			{
				index = i;
				val = students[i].score;
			}
		}
		flag[index] = 1;
		result[kt] = students + index;
	}
	free(flag);
	return result;
}