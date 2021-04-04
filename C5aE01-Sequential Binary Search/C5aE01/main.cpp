#include <iostream>

using namespace std;

void sortArr( int a[]) {
	int i, j, minIndex, tmp;
	for (i = 0; i < 10; i++) {
		minIndex = i;
		for (j = i + 1; j < 10; j++)
			if (a[j] < a[minIndex])
				minIndex = j;
			if (minIndex != i) {
				tmp = a[i];
				a[i] = a[minIndex];
				a[minIndex] = tmp;
			}
	}
};

void display(int a[]) {
    for (int i=0; i<10; i++)
        cout << a[i] << " ";
    cout << endl;
};

void sequentialSearch(int a[], int key) {
    int counter = 1;
    for (int i=0; i<10; i++) {
        if(a[i]==key) {
            cout << key << " found at " << i << " (#" << counter << ")\n";
            return;
        }
        counter++;
    }
    cout << key << " not found (#" << counter << ")\n";
};

void binarySearch(int a[], int key) {

	int first = 0, last = 9, mid;
	int counter = 0;
	bool found = false, repeat = false;

	while (first <= last && !found) {
		++counter;
		mid = (last + first) / 2;
		cout << "\t#" << counter << " First: " << first << " Last: " << last << " Mid: " << mid << endl;

		if (a[mid] == key) {
			cout << key << " found at " << mid << " (#" << counter << ")\n";
			found = true;
			break;
		}
		else if (a[mid] > key)
			last = mid - 1;
		else
			first = mid + 1;

		if (first==last && a[mid]!=key && repeat)
			break;

		if (first == last && repeat == false)
			repeat == true;
	}

	if(!found)
      cout << key << " not found (#" << counter << ")\n";
};

int main() {

	int data[10] ={12, 14, 8, 7, 2, 3, 17, 5, 1, 6}, data1[10];

	for (int i=0; i<10; i++)
        data1[i]=data[i];
    sortArr(data1);

    cout << "***Sequential Search***\n";
   	cout << "Original List: ";
   	display(data);
    for (int i=0; i<20; i++)
        sequentialSearch(data, i);

    cout << "***Binary Search***\n";
   	cout << "Sorted List: ";
   	display(data1);
    for (int i=0; i<20; i++)
        binarySearch(data1, i);

    return 0;
}
