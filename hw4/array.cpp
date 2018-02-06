#include<iostream>
#include<string>
#include<cassert>
using namespace std;

int locateMinimum(const string array[], int n);
int findLastOccurrence(const string array[], int n, string target);
int flipAround(string array[], int n);
bool hasNoDuplicates(const string array[], int  n);
void unionWithNoDuplicates(const string array1[], int n1, const string array2[], int n2, string resultingString[], int& resultingSize);
int shiftRight(string array[], int n, int amount, string   placeholderToFillEmpties);
bool isInIncreasingOrder(const string array[], int  n);



int locateMinimum(const string array[], int n)
{
	if (n <= 0)
		return -1;
	string min = array[0];
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] < min)     //if the first one is the minimum, it will still return 0
		{
			min = array[i];
			index = i;
		}
	}
	return index;
}

int findLastOccurrence(const string array[], int n, string target)
{
	if (n <= 0)
		return -1;
	int index = -1;
	for (int i = 0; i < n; i++)
	{
		if (array[i] == target)
		{
			index = i;  //at last, index will automatically be the last occurance
		}
	}
	return index;        //if target doesn't occur , it will return -1 at last
}

int flipAround(string array[], int n)
{
	int count = 0	;
	string temp;
	for (int i = 0; i < n / 2; i++)  //if n is even, then it's ok. if odd, it should omit the central one
	{
		temp = array[n - i - 1];
		array[n - i - 1] = array[i];
		array[i] = temp;
		count++;
	}
	return count;
}
	
bool hasNoDuplicates(const string array[], int  n)
{
	if (n < 0)
		return false;
	for (int i = 0; i < n; i++) {
		for (int s = i + 1; s < n; s++) {    //compare array[i] to all the ones after it
			if (array[i] == array[s])
				return false;
		}
	}
	return true;
}

void unionWithNoDuplicates(const string array1[], int n1, const string array2[], int n2, string resultingString[], int & resultingSize)
{
	resultingSize = 0;
	bool duplicate = true;
	for (int i = 0; i < n1; i++) {
		duplicate = true;                     //assign true every time or if previous time is false, then  even if it true, duplicate will be false;          
		for (int s = i + 1; s < n1; s++) {
			if (array1[i] == array1[s])
				duplicate = false;
		}
		if (duplicate) {
			resultingString[resultingSize] = array1[i];
			resultingSize++;       //resultingSize++ after assigning value !! 
		}
	}
	for (int i = 0; i < n2; i++) {
		duplicate = true;
		for (int a = 0; a < n1; a++){
		if (array2[i] == array1[a])
			duplicate = false;               //first check if it is in array[1] already
		}
		for (int s = i + 1; s < n2; s++) {
			if (array2[i] == array2[s])
				duplicate = false;                //check if there is duplicate in the array2
		}                     
		if (duplicate) {
			resultingString[resultingSize] = array2[i];
			resultingSize++;
		}
	}
}

int shiftRight(string array[], int n, int amount, string   placeholderToFillEmpties)
{
	int count = 0;
	if (amount > n || amount < 0)
		return -1;
	for (int i = 0; i <n-amount; i++) {
		array[i + amount] = array[i];
		count++;
	}
	for (int s = 0; s < amount; s++) {
		array[s] = placeholderToFillEmpties;
	}
	return count;
}

bool isInIncreasingOrder(const string array[], int  n)
{
	if (n < 0)       
		return false;
	for (int i = 0; i < n-1; i++) {     // the result of n=0 here is different if use size_t instead of int
		if (array[i] >= array[i + 1])    
			return false;
	}
	return true;
}

int main()
{
	string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };

	string b[6] = { "delta", "gamma", "beta", "alpha", "beta", "alpha" };
	string h[7] = { "samwell", "jon", "margaery", "daenerys", "", "tyrion", "margaery" };
	int answer;


	string output[6] = { " ", " ", " ", " ", " ", " " };
	int outputSize = 6;

	assert(locateMinimum(a, 3) == 0);
	assert(locateMinimum(b, 3) == 2);

	assert(findLastOccurrence(a, 5, "beta") == 4);
	assert(findLastOccurrence(b, 3, "beta") == 2);

	assert(hasNoDuplicates(a, 3) == true);
	assert(hasNoDuplicates(a, 6) == false);

	assert(isInIncreasingOrder(a, 3) == true);
	assert(isInIncreasingOrder(a, 6) == false);

	unionWithNoDuplicates(a, 6, b, 2, output, outputSize);
	assert(outputSize == 4);
	assert(output[0] == "alpha");

	answer = shiftRight(h, 6, 1, "foobar");
	assert(answer == 5);
	assert(h[0] == "foobar");

	assert(flipAround(b, 3) == 1);
	assert(flipAround(b, 4) == 2);

	cout
		<< "All tests succeeded" << endl; return(0);
}