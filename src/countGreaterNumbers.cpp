/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
int isDateEqual(char *d1, char *d2);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i, count = 0;
	for (i = 0; i < len; i++)
	{
		if (isDateEqual(Arr[i].date, date))
		{
			if (i == len - 1)
				break;
			if (isDateEqual(Arr[i + 1].date, date))
			{
				continue;
			}
			count = len - i - 1;
			break;
		}
	}
	return count;
}
int isDateEqual(char *date1, char *date2)
{
	int d1, d2, m1, m2, y1, y2;
	sscanf(date1, "%d-%d-%d", &d1, &m1, &y1);
	sscanf(date2, "%d-%d-%d", &d2, &m2, &y2);
	if (y1 == y2 && d1 == d2 && m1 == m2)
		return 1;
	else
		return 0;
}

