/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int comp_dates(char *date1, char* date2){
	int i = 0;
	while (date1[i++] != '\0')
	if (date1[i] != date2[i])
		return 0;
	return 1;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL||B==NULL)
		return NULL;
	struct transaction * commonEles = (struct transaction *)malloc(sizeof(struct transaction)*((ALen<BLen)?ALen:BLen));
	int comTren = 0;
	for (int TranA = 0; TranA < ALen; TranA++){
		for (int TranB = 0; TranB < BLen; TranB++){
			if (comp_dates(A[TranA].date, B[TranB].date)==1){
				commonEles[comTren] = A[TranA];
				comTren++;
			}
		}
	}
	if (comTren == 0)
		return NULL;
	return commonEles;
}