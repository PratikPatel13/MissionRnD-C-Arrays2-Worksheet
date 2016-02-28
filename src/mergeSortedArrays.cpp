/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
int compare(char *s1, char *s2);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0, j = 0, k = 0;
	struct transaction *mergeRes = NULL;
	if (A == NULL || B == NULL)
		return NULL;
	mergeRes = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	while (k < ALen + BLen)
	{
		if (compare(A[i].date, B[j].date) == 1)
		{
			mergeRes[k] = B[j];
			k++;
			j++;
		}
		else
		{
			mergeRes[k] = A[i];
			k++;
			i++;
		}
		if (i == ALen)
		{
			while (j < BLen)
			{
				mergeRes[k] = B[j];
				k++;
				j++;
			}
		}
		if (j == BLen)
		{
			while (i < ALen)
			{
				mergeRes[k] = A[i];
				k++;
				i++;
			}
		}
	}
	return mergeRes;
}

//return 0 if both are same, 1 if date1 is greater , -1 if date2 is greater
int compare(char *date1, char *date2)
{
	int d1, d2, m1, m2, y1, y2;
	sscanf(date1, "%d-%d-%d", &d1, &m1, &y1);
	sscanf(date2, "%d-%d-%d", &d2, &m2, &y2);
	if (y1 > y2)
		return 1;
	else if (y1 < y2)
		return -1;
	else
	{
		if (m1 > m2)
		{
			return 1;
		}
		else if (m1 < m2)
			return -1;
		else
		{
			if (d1 > d2)
				return 1;
			else if (d1 < d2)
				return -1;
			else
				return 0;
		}
	}
}