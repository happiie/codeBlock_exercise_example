#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream myfile;
    myfile.open ("BubbleSort_out.txt");

	int a[10] = { 12, 14 ,25, 8, 35, 89, 56, 85, 16, 15 };
    int n = 10;

	myfile << "***Bubble Sort***\ni0: ( ";
	for (int i=0; i<n; i++)
		myfile << a[i] << " ";
	myfile << ")" << endl;

	int temp;
	for (int i=0; i<n-1; i++) {
		for (int j = 0; j<n-1-i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
        myfile << "\ti" << i+1 << j << ": ( ";
        for (int i=0; i<n; i++)
            myfile << a[i] << " ";
            myfile << ")" << endl;
		}

		myfile << "i" << i+1 << ": ( ";
		for (int i = 0; i < n; i++)
			myfile << a[i] << " ";
		myfile << ")" << endl;
	}

    myfile.close();
    return 0;
}
