/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
struct student {
	char name[10];
	int score;
};
void studentSwap(struct student* student1, struct student* student2)
{
	int c = student1->score;
	student1->score = student2->score;
	student2->score = c;
	int i = 0;
	int flag = 0;
	while (1)
	{
		if (student1->name[i] == '\0')
			flag++;
		if (student2->name[i] == '\0')
			flag++;
		if (flag == 2)
			break;
		char ch = student1->name[i];
		student1->name[i] = student2->name[i];
		student2->name[i] = ch;
		i++;
	}
}
void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len < 0)
		return NULL;
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (students[j].score < students[j + 1].score)
				studentSwap(students + j, students + j + 1);
		}
	}
}