#include <iostream>
#include <fstream>

using namespace std;

void shellSort(ofstream &myfile, int a[], int n) {
  int j;
  int counter1 = 0, counter2=0;

  myfile << "***Shell Sort***\ni0:( ";
  for (int i=0; i<n; i++)
	myfile << a[i] << " ";
  myfile << ")" << endl;

  for (int gap = n/2; gap>0; gap/=2) {
    counter2=0;

    for (int i=gap; i<n; ++i) {
      int temp = a[i];

      for (j=i; j>=gap && temp<a[j-gap]; j-=gap)
         a[j] = a[j-gap];

      a[j] = temp;
      counter2++;
      myfile << "\ti" << counter1 << counter2 << "[gap=" << gap << ", i=" << i << ", j=" << j <<"]:( ";
      for (int i=0; i<n; i++)
	    myfile << a[i] << " ";
      myfile << ")" << endl;
    }

    counter1++;
    myfile << "i" << counter1 << ":( ";
    for (int i=0; i<n; i++)
	   myfile << a[i] << " ";
    myfile << ")" << endl;
  }

};

int main()
{
    ofstream myfile;
    myfile.open ("ShellSort_out.txt");

	int a[10] = { 12, 14 ,25, 8, 35, 89, 56, 85, 16, 15 };
    int n = 10;

    shellSort(myfile, a, n);

    myfile.close();
    return 0;
}
