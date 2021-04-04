//Merge Sort
#include <iostream>
#include <fstream>

using namespace std;


void display(ofstream &myfile, int a[], int x, int y) {
	myfile << "( ";
	for (int i = x; i <=y; i++)
		myfile << a[i] << " ";
	myfile << ")";
};

void Merge(ofstream &myfile, int a[], int left, int mid1, int mid2, int right) {
	int leftIndex = left;
	int rightIndex = mid2;
	int workingIndex = left;
	int working[10];

	myfile << "Merge: ";
	display(myfile, a, left, mid1);
	myfile << " + ";
	display(myfile, a, mid2, right);
	myfile << "--> " ;

	while (leftIndex <= mid1 && rightIndex <= right) {
		if (a[leftIndex] <= a[rightIndex])
			working[workingIndex++]=a[leftIndex++];
		else
			working[workingIndex++] = a[rightIndex++];
	}

	if (leftIndex == mid2) {
		while (rightIndex <= right)
			working[workingIndex++] = a[rightIndex++];
	}
	else {
		while (leftIndex <= mid1)
			working[workingIndex++] = a[leftIndex++];
	}

	for (int i = left; i < right + 1; i++)
		a[i] = working[i];

	display(myfile, a, left, right);
	myfile << endl;
};

void mergeSort(ofstream &myfile, int a[], int low, int high) {
	if ((high - low) >= 1) {
		int mid1 = (low + high) / 2;
		int mid2 = mid1 + 1;
		myfile << "Split [mid1=" << mid1 << ", mid2=" << mid2 << "]" ;
		display(myfile, a, low, high);
		myfile << " --> ";
		display(myfile, a, low, mid1);
		myfile << "  ";
		display(myfile, a, mid2, high);
		myfile << endl;
		mergeSort(myfile, a, low, mid1);
		mergeSort(myfile, a, mid2, high);
		Merge(myfile, a, low, mid1, mid2, high);
	}
};

int main()
{
    ofstream myfile;
    myfile.open ("MergeSort_out.txt");

	int a[10] = { 12, 14 ,25, 8, 35, 89, 56, 85, 16, 15 };
    int n = 10;

	myfile << "***Merge Sort***\nBefore:( ";
	for (int i=0; i<n; i++)
		myfile << a[i] << " ";
	myfile << ")" << endl;

    mergeSort(myfile, a, 0, n-1);

	myfile << "After:( ";
	for (int i=0; i<n; i++)
		myfile << a[i] << " ";
	myfile << ")" << endl;

    myfile.close();
    return 0;
}
