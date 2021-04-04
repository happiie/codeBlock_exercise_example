#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream myfile;
    myfile.open ("InsertionSort_out.txt");

	int a[10] = { 12, 14 ,25, 8, 35, 89, 56, 85, 16, 15 };
    int n = 10;

	myfile << "***Insertion Sort***\ni0: ( ";
	for (int i=0; i<n; i++)
		myfile << a[i] << " ";
	myfile << ")" << endl;

	int j, temp;
	for (int i=1; i<n; i++) {
		j = i;
		while (j>0 && a[j]<a[j-1]){
			  temp = a[j];
			  a[j] = a[j-1];
			  a[j-1] = temp;
			  j--;
		}

		myfile << "i" << i << ": ( ";
		for (int i = 0; i < n; i++)
			myfile << a[i] << " ";
        myfile << ")" << endl;
	}

    myfile.close();
    return 0;
}
