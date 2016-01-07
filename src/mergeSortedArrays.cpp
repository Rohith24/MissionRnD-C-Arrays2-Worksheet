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

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int com_dates(char *date1, char* date2){
	int yy1 = ((date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0'));
	int yy2 = ((date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0'));
	return yy1 - yy2;
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL||B==NULL)
		return NULL;
	struct transaction * mergeTrans = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	int currA = 0, currB = 0,currRes=0;
	while (currA<ALen&&currB<BLen)
	{
		int cmp=com_dates(A[currA].date, B[currB].date);
		if (cmp<0){
			mergeTrans[currRes] = A[currA];
			currA++;
			currRes++;
		}
		else if (cmp>0){
			mergeTrans[currRes] = B[currB];
			currB++;
			currRes++;
		}
		else
		{
			mergeTrans[currRes] = A[currA];
			currA++;
			currRes++;
			mergeTrans[currRes] = B[currB];
			currB++;
			currRes++;
		}
	}
	while (currA < ALen)
	{
		mergeTrans[currRes] = A[currA];
		currA++;
		currRes++;
	}
	while (currB<BLen)
	{
		mergeTrans[currRes] = B[currB];
		currB++;
		currRes++;
	}
	return mergeTrans;
}