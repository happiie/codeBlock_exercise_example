#include <iostream>
#include <fstream>

using namespace std;

void quickSort(ofstream &myfile, int a[], int lf, int rg) {
	int pos = (lf + rg) / 2;
	int pivot = a[pos];

    myfile << "QuickSort [(lf=x)" << lf << ", " << rg << "(rg-y)] Pivot: " << pivot << "[" << pos << "] ";
	myfile << "( ";
	for (int i=lf; i<=rg; i++)
		myfile << a[i] << " ";
	myfile << ") --> ";

	int x = lf, y = rg, tmp;
	while (x <= y) {
		while (a[x] < pivot) {
			x++;
	myfile << "( ";
	for (int i=lf; i<=rg; i++)
		myfile << a[i] << " ";
	myfile << ") x = " << x << " y = " << y << "\n";

		}
		while (a[y] > pivot) {
			y--;
	myfile << "( ";
	for (int i=lf; i<=rg; i++)
		myfile << a[i] << " ";
	myfile << ") x = " << x << " y = " << y << "\n";

		}
		if (x <= y) {
			tmp = a[x];
			a[x] = a[y];
			a[y] = tmp;
			x++;
			y--;
	myfile << "( ";
	for (int i=lf; i<=rg; i++)
		myfile << a[i] << " ";
	myfile << ") x = " << x << " y = " << y << "\n";

		}
	}

	myfile << "( ";
	for (int i=lf; i<=rg; i++)
		myfile << a[i] << " ";
	myfile << ") x = " << x << " y = " << y << "\n";

	if (lf < y) {
        myfile << "(Front): ";
		quickSort(myfile, a, lf, y);
	}
	if (x < rg) {
        myfile << "(End): ";
		quickSort(myfile, a, x, rg);
	}
};

int main()
{
    ofstream myfile;
    myfile.open ("QuickSort_out.txt");

	int a[10] = { 12, 14, 25, 8, 35, 89, 56, 85, 16, 15 };
    int n = 10;

//	int a[6] = { 2, 5, 7, 1, 9, 3};
//    int n = 6;

	myfile << "***Quick Sort***\nBefore:{ ";
	for (int i=0; i<n; i++)
		myfile << a[i] << " ";
	myfile << "}" << endl;

    quickSort(myfile, a, 0, n-1);

	myfile << "After:{ ";
	for (int i=0; i<n; i++)
		myfile << a[i] << " ";
	myfile << "}" << endl;

    myfile.close();
    return 0;
}
