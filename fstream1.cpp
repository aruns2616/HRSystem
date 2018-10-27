#include <fstream>
#include <iostream>

using namespace std;

class customer {
	int custId;
	char name[20];
};

int main(int argc, char** argv) {
	customer c;
	cout << sizeof(customer)<<endl;
	cout << sizeof (c)<<endl;
	ifstream f1;
	
	f1.open("ab.dat",ios::trunc|ios::out|ios::in);
	
	if (!f1){
		cout << "Error while opening the file"<<endl;
		return -1;
	}
	
	f1.close();
}


