#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

struct Student {

	char* m_name;
	int stNo;
	char grade;
};

void setStudent(FILE* ft, Student& SR) {
	char name[80];
	fscanf(ft, "%[^,],", name);
	int i = strlen(name);
	SR.m_name = new char[i + 1];
	//SR.m_name = new char[strlen(name) + 1];
	strcpy(SR.m_name, name);
	
	fscanf(ft,"%d,",&SR.stNo);

	fscanf(ft, "%c\n", &SR.grade);

}

void dispStudent(const Student& SR) {
	cout << SR.m_name << "," << SR.stNo << "," << SR.grade << endl;

}
int main() {

	FILE* fptr;
	fptr = fopen("DMA.txt", "r");

	int ch;
	fscanf(fptr, "%d\n", &ch);

	Student* S = nullptr;
	S = new Student[ch];

	for (int i = 0; i < ch; i++) {

		setStudent(fptr, S[i]);
	}

	for (int i = 0; i < ch; i++) {

		dispStudent(S[i]);
		cout << endl;
	}

	for (int i = 0; i < ch; i++) {

		delete[] S[i].m_name;
	}

	delete[] S;
	S = nullptr;
	return 0;
}