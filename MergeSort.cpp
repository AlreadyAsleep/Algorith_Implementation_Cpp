#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> merge(vector<int> arr1, vector<int> arr2)
{
	vector<int> arr(arr1.size() + arr2.size());
	vector<int> count(3);
	while(count[1] < arr1.size() && count[2] < arr2.size())//both arrays are full
	{
		if(arr1[count[1]] > arr2[count[2]])
		{
			arr[count[0]] = arr2[count[2]];
			count[2]++;
		}
		else
		{
			arr[count[0]] = arr1[count[1]];
			count[1]++;
		}
		count[0]++;
	}//end while

	while(count[1] < arr1.size())
	{
		arr[count[0]] = arr1[count[1]];
		count[1]++;
		count[0]++;
	}// end while

	while(count[2] < arr2.size())
	{
		arr[count[0]] = arr2[count[2]];
		count[2]++;
		count[0]++;
	}//end while
	return arr;
}

vector<int> mergeSort(vector<int> arr)
{
	if(arr.size() < 2)
		return arr;
	bool even = (arr.size() % 2) == 0;
	vector<int> arr1(arr.size() / 2);
	vector<int> arr2(arr.size() - arr.size() / 2);
	for(int i = 0; i < arr.size() / 2; i++)
	{
		arr1[i] = arr[i];
		arr2[i] = arr[i + arr.size() / 2];
	}//end for
	if(!even)
		arr2[arr2.size() - 1] = arr[arr.size() - 1];
	arr1 = mergeSort(arr1);
	arr2 = mergeSort(arr2);

	return merge(arr1, arr2);
}



int main(int argc, char* argv[])
{
	vector<int> arr(argc - 1);
	for(int i = 0; i < arr.size(); i++)
	{
		arr[i] = atoi(argv[i+1]);
	}
	arr = mergeSort(arr);
	for(int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}