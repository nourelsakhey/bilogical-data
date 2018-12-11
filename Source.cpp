#include<iostream>
#include"sequence.h"
#include"DNA.h"
#include"Protein.h"
#include"Condonstable.h"
#include"RNA.h"
using namespace std;

int main() {
	int choise;
	cout << "welcome to the biological data program" << endl;
	cout << "what type of biological data you want to entre" << endl << "1-DNA  2-RNA  3-Protein  0-end" << endl;
		cin >> choise;
		while (choise != 0) {
		if (choise == 1) {

			int x;
			cout << "enter the size of the sequence";
			cin >> x;
			cout << endl;
			char*ARR;
			ARR = new char[x];
			for (int i = 0;i < x;i++) {
				cin >> ARR[i];
			}
			cout << "enter the type of DNA" << endl;
			DNA d1(ARR, promoter, x);
			cout << d1;
			cout << "what operation you want to do" << endl << "1-print the strand   2-built the complement strand   3-convert to RNA" << endl;
			int y;
			cin >> y;
			if (y == 1) {
				d1.print();
				cout << endl;
			}
			else if (y == 2) {
				d1.build_complemantary_strand();
				cout << endl;
			}
			else if (y == 3) {
				d1.convert_to_RNA();
				cout << endl;
			}
		}
		else if (choise == 2) {

			int x;
			cout << "enter the size of the sequence";
			cin >> x;
			cout << endl;
			char*ARR;
			ARR = new char[x];
			for (int i = 0;i < x;i++) {
				cin >> ARR[i];
			}
			//cout << "enter the type of DNA" << endl;
			RNA r1(ARR, mRNA, x);
			cout << r1;
			cout << "what operation you want to do" << endl << "1-print the strand   2-convert to DNA   3-convert to Protein" << endl;
			int y;
			cin >> y;
			if (y == 1) {
				r1.print();
				cout << endl;
			}
			else if (y == 2) {
				r1.convert_to_DNA();
				cout << endl;
			}
			else if (y == 3) {
				Codonstable c1;
				r1.convert_to_Protien(c1);
				cout << endl;
			}
		}
		else if (choise == 3) {


			int x;
			cout << "enter the size of the sequence";
			cin >> x;
			cout << endl;
			char*ARR;
			ARR = new char[x];
			for (int i = 0;i < x;i++) {
				cin >> ARR[i];
			}
			//cout << "enter the type of DNA" << endl;
			Protein p1(ARR, enzyme, x);
			p1.print();
			cout << "what operation you want to do" << endl << "1-print the strand    2-convert to RNA" << endl;
			int y;
			cin >> y;
			if (y == 1) {
				p1.print();
				cout << endl;
			}

		}
		cin >> choise;

	}
		cout << endl;
	int sizee;
	cout << "enter the size of the sequence";
	cin >> sizee;
	char*ARR;
	ARR = new char[sizee];
	char*arr;
	arr = new char[6];
	char ARR1[] = { 'A', 'C', 'G', 'G', 'G', 'T' };
	arr = ARR1;
	for (int i = 0;i < sizee;i++) {
		cin >> ARR[i];
	}
	DNA d2(ARR, promoter,sizee);
	d2.print();
	cout << endl << endl;
	DNA d3(ARR, promoter, sizee);
	d3.print();
	cout << endl << endl;
	DNA d4(ARR1,promoter,sizee);
	d4.print();
	cout << endl << endl;
	bool check;
	
	check = (d3 == d2);
	cout <<check<<endl<<endl;
	
	check=(d2 != d3);
	cout <<check<< endl << endl;
	check = (d2 != d4);
	cout<<check<<endl <<endl;
	check = (d2 == d4);
	cout << check << endl << endl;


	cin >> sizee;




	return 0;
}
