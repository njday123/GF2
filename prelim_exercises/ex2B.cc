#include <iostream>
using namespace std;

//Tested successfully.

int main(){
	int i = 7;
	int *ipointer = &i;
	int &ireference = i;
	cout << "Pointer: " << *ipointer << endl;
	cout << "Reference: " << ireference << endl;
}