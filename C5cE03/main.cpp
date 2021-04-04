#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream myfile;
    myfile.open ("SelectionSort_out.txt");

	int a[10] = { 12, 14 ,25, 8, 35, 89, 56, 85, 16, 15 };
    int n = 10;

	myfile << "***Selection Sort***\ni0: ( ";
	for (int i=0; i<n; i++)
		myfile << a[i] << " ";
	myfile << ")" << endl;

	int pos, temp;
	for (int i=0; i<n-1; i++) {
        pos=i;
        for (int j=i+1; j < n; j++) {
            if (a[j] < a[pos])
                   pos=j;
		}
		if (pos != i) {
            temp = a[i];
            a[i] = a[pos];
            a[pos] = temp;
        }

		myfile << "i" << i+1 << ": ( ";
		for (int i = 0; i < n; i++)
			myfile << a[i] << " ";
        myfile << ")" << endl;
	}

    myfile.close();
    return 0;
}
