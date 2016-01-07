/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

int findSingleOccurenceNumber(int *A, int len) {
	if (A == nullptr)
		return -1;
	for (int curr1 = 0; curr1 < len; curr1++){
		int count = 1;
		for (int curr2 = 0; curr2 < len; curr2++){
			if (A[curr1] == A[curr2])
				count++;
		}
		if (count == 2)
			return A[curr1];
	}
}