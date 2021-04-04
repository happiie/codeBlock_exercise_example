#include <iostream>
#include <fstream>

using namespace std;

void display(ofstream &myfile, int a[], int lf, int rg) {
	myfile << "( ";
	for (int i=lf; i<rg; i++)
		myfile << a[i] << " ";
	myfile << ")" << endl;
}

void heapify(ofstream &myfile, int a[], int n, int x) {
    int largest = x;
    int l = 2*x + 1;
    int r = 2*x + 2;

    if (l<n && a[l]>a[largest])
        largest = l;

    if (r<n && a[r]>a[largest])
        largest = r;

    if (largest != x) {
        int temp = a[x];
        a[x]=a[largest];
        a[largest] = temp;
        heapify(myfile, a, n, largest);
    }
};

void heapSort(ofstream &myfile, int a[], int n) {
	myfile << "Before: ";
    display(myfile, a, 0, n);

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(myfile, a, n, i);

	myfile << "Heapify (P): ";
    display(myfile, a, 0, n);

    int temp;
    for (int i=n-1; i>=0; i--) {
        temp = a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(myfile, a, i, 0);
        myfile << "Heapify (" << i << "): ";
        display(myfile, a, 0, n);
    }

	myfile << "After: ";
    display(myfile, a, 0, n);
};

int main()
{
    ofstream myfile;
    myfile.open ("HeapSort_out.txt");

	int a[10] = { 12, 14 ,25, 8, 35, 89, 56, 85, 16, 15 };
    int n = 10;

    heapSort(myfile, a, n);

    myfile.close();
    return 0;
}
