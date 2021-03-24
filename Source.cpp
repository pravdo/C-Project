#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>


using namespace std;
struct disciplin
{

	int value = 0;
};
struct student
{

	string Specialnost;
	string f_number;
	string name;// Name na student
	int y;//godina na rajdane
	int m;//mesec;
	double sreden_uspeh = 0;
	string group;
	disciplin dis[5];
};

const int N = 30;
void menu(int& q, struct student stud[]);

void validation(int& choice, int vali1, int vali2);
void m_menu();
void function_for_decide_group(struct student stud[], int q, int num1, int num2, string group);
void decide_group(struct student stud[], int q);
void sit_(struct student stud[], int q);
void add_stud(struct student stud[], int& q);
void addaSTU(struct student stud[], int& q);//prototipi na funkciq
void listofSTU(struct student stud[], int& q);
void show(struct student stud[], int i);
void data(struct student stud[], int q);
void serach_algorithm(struct student stud[], int q, string search, int& n);
void swap(struct student stud[], int q);
void delete_action(struct student stud[], int t, int q);
void delete_student(struct student stud[], int q);
void sort1(struct student stud[], int q);
void sort2(struct student stud[], int q);
void search1(struct student stud[], int q);
void search2(struct student stud[], int q);
void fileSave(struct student stud[], int count);
int fileRead(struct student stud[], int count);

int main()
{
	student stud[N];// masiv na struktura
	int q = 0;//broqch
	menu(q, stud);

	return 0;
}
void validation(int& choice, int vali1, int vali2)//& adres na kletkata
{
	cin >> choice;
	while (cin.good() == false)// ako ne e vyvden pravilin cin
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n'); 
		cout << "You have entered a letter." << endl;
		validation(choice, vali1, vali2);
	}
	while (choice < vali1 || choice>vali2) {
		cout << u8"Wrong number" << endl;
		cout << u8"Write a number between " << vali1 << " and " << vali2 << endl;;
		validation(choice, vali1, vali2);
	}
	system("cls");
}

void menu(int& q, struct student stud[])
{
	int choice;
	cout << "------------------------------MENU--------------------------" << endl;
	cout << "1.  Adding a student" << endl;
	cout << "2. Adding a list of students" << endl;
	cout << "3. Cout the data" << endl;
	cout << "4. Swap student's group by faculty number" << endl;
	cout << "5. Deleting a student by faculty number" << endl;
	cout << "6. List of averge student's grades" << endl;
	cout << "7. List of student's age" << endl;
	cout << "8. List of student's highest average grades(CSE and SIT)" << endl;
	cout << "9. List of students with average grades over 5,50" << endl;
	cout << "10. Text File Save" << endl;
	cout << "11. Text file Read" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "Enter your choice between 1-11" << endl;

	validation(choice, 1, 11);

	switch (choice)
	{
	case 1: addaSTU(stud, q);
		break;
	case 2: listofSTU(stud, q);
		break;
	case 3: data(stud, q);
		break;
	case 4:swap(stud, q);
		break;
	case 5: delete_student(stud, q);
		break;
	case 6: sort1(stud, q);
		break;
	case 7: sort2(stud, q);
		break;
	case 8: search1(stud, q);
		break;
	case 9: search2(stud, q);
		break;
	case 10: fileSave(stud, 30);
		break;
	case 11: fileRead(stud, 30);
	default:cout << endl << "END!" << endl;
		break;
		system("cls");
	}
}

void m_menu() {
	cout << "----------------------------------" << endl;
	cout << "1.SIT" << endl;
	cout << "2.CSE" << endl;
}
void function_for_decide_group(struct student stud[], int q, int num1, int num2, string group) {
	for (int i = num1; i < num2; i++) {
		stud[i].group = group;
	}
}
void decide_group(struct student stud[], int q) {
	string group1 = "1"; string group2 = "2"; string group3 = "3"; string group4 = "4"; string group5 = "5"; string group6 = "6";
	if (q == 0) {
		stud[q].group = "1";
	}
	else if (q == 1) {
		stud[q - 1].group = "1";
		stud[q].group = "1";
	}
	else if (q == 2) {
		stud[q - 2].group = "1";
		stud[q - 1].group = "1";
		stud[q].group = "1";
	}
	else if (q == 3) {
		function_for_decide_group(stud, q, 0, 4, group1);
	}
	else if (q == 4) {
		stud[q].group = "2";
		function_for_decide_group(stud, q, 0, 4, group1);
	}
	else if (q == 5) {
		stud[q - 1].group = "2";
		stud[q].group = "2";
		function_for_decide_group(stud, q, 0, 4, group1);
	}
	else if (q == 6) {
		function_for_decide_group(stud, q, 0, 4, group1);
		stud[4].group = "2";
		stud[5].group = "2";
		stud[q].group = "2";
	}
	else if (q == 7) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
	}
	else if (q == 8) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		stud[q].group = "1";
	}
	else if (q == 9) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		stud[q - 1].group = "1";
		stud[q].group = "2";
	}
	else if (q == 10) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 11, group3);
	}
	else if (q == 11) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);
	}
	else if (q == 12) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);
		stud[q].group = "1";
	}
	else if (q == 13) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);
		stud[q - 1].group = "1";
		stud[q].group = "2";
	}
	else if (q == 14) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);
		stud[q - 2].group = "1";
		stud[q - 1].group = "2";
		stud[q].group = "3";
	}
	else if (q == 15) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);   function_for_decide_group(stud, q, 12, 16, group4);
	}
	else if (q == 16) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);   function_for_decide_group(stud, q, 12, 16, group4);
		stud[q].group = "1";
	}
	else if (q == 17) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);   function_for_decide_group(stud, q, 12, 16, group4);
		stud[q - 1].group = "1";
		stud[q].group = "2";
	}
	else if (q == 18) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);   function_for_decide_group(stud, q, 12, 16, group4);
		stud[q - 2].group = "1";
		stud[q - 1].group = "2";
		stud[q].group = "3";
	}
	else if (q == 19) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);   function_for_decide_group(stud, q, 12, 16, group4);
		stud[q - 3].group = "1";
		stud[q - 2].group = "2";
		stud[q - 1].group = "3";
		stud[q].group = "4";
	}
	else if (q == 20) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);   function_for_decide_group(stud, q, 12, 16, group4);
		function_for_decide_group(stud, q, 16, 20, group5);
		stud[q].group = "1";
	}
	else if (q == 21) {
		function_for_decide_group(stud, q, 0, 4, group1);     function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);
		function_for_decide_group(stud, q, 12, 16, group4);
		function_for_decide_group(stud, q, 16, 20, group5);
		stud[q - 1].group = "1";
		stud[q].group = "2";
	}
	else if (q == 22) {
		function_for_decide_group(stud, q, 0, 4, group1);     function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);    function_for_decide_group(stud, q, 12, 16, group4);
		function_for_decide_group(stud, q, 16, 20, group5);
		stud[q - 2].group = "1";
		stud[q - 1].group = "2";
		stud[q].group = "3";
	}
	else if (q == 23) {
		function_for_decide_group(stud, q, 0, 4, group1);     function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);    function_for_decide_group(stud, q, 12, 16, group4);
		function_for_decide_group(stud, q, 16, 20, group5);
		stud[q - 3].group = "1";
		stud[q - 2].group = "2";
		stud[q - 1].group = "3";
		stud[q].group = "4";
	}
	else if (q == 24) {
		function_for_decide_group(stud, q, 0, 4, group1);     function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);    function_for_decide_group(stud, q, 12, 16, group4);
		function_for_decide_group(stud, q, 16, 20, group5);
		stud[q - 4].group = "1";
		stud[q - 3].group = "2";
		stud[q - 2].group = "3";
		stud[q - 1].group = "4";
		stud[q].group = "5";
	}
	else if (q == 25) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);   function_for_decide_group(stud, q, 12, 16, group4);
		function_for_decide_group(stud, q, 16, 20, group5);  function_for_decide_group(stud, q, 20, 24, group6);
		stud[q - 1].group = "1";
		stud[q].group = "2";
	}
	else if (q == 26) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);   function_for_decide_group(stud, q, 12, 16, group4);
		function_for_decide_group(stud, q, 16, 20, group5);  function_for_decide_group(stud, q, 20, 24, group6);
		stud[q - 2].group = "1";
		stud[q - 1].group = "2";
		stud[q].group = "3";
	}
	else if (q == 27) {
		function_for_decide_group(stud, q, 0, 4, group1);    function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);   function_for_decide_group(stud, q, 12, 16, group4);
		function_for_decide_group(stud, q, 16, 20, group5);  function_for_decide_group(stud, q, 20, 24, group6);
		stud[q - 3].group = "1";
		stud[q - 2].group = "2";
		stud[q - 1].group = "3";
		stud[q].group = "4";
	}
	else if (q == 28) {
		function_for_decide_group(stud, q, 0, 4, group1);     function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);    function_for_decide_group(stud, q, 12, 16, group4);
		function_for_decide_group(stud, q, 16, 20, group5);   function_for_decide_group(stud, q, 20, 24, group6);
		stud[q - 4].group = "1";
		stud[q - 3].group = "2";
		stud[q - 2].group = "3";
		stud[q - 1].group = "4";
		stud[q].group = "5";
	}
	else if (q == 29) {
		function_for_decide_group(stud, q, 0, 4, group1);     function_for_decide_group(stud, q, 4, 8, group2);
		function_for_decide_group(stud, q, 8, 12, group3);    function_for_decide_group(stud, q, 12, 16, group4);
		function_for_decide_group(stud, q, 16, 20, group5);   function_for_decide_group(stud, q, 20, 24, group6);
		stud[q - 5].group = "1";
		stud[q - 4].group = "2";
		stud[q - 3].group = "3";
		stud[q - 2].group = "4";
		stud[q - 1].group = "5";
		stud[q].group = "6";
	}

}
void sit_(struct student stud[], int q)
{
	int t;
	cin.ignore(1, '\n');// propuska pyrviq sp 
	do {
		cout << "Enter a name " << endl;
		getline(cin, stud[q].name);
	} while (stud[q].name == "");// vyrti dokato e raven na prazen string
	do {
		cout << "Enter a faculty number " << endl;
		getline(cin, stud[q].f_number);
	} while (stud[q].f_number == "");
	cout << "Enter a month of birth ";
	validation(t, 1, 12);
	stud[q].m = t;
	cout << "Enter a year of birth ";
	validation(t, 1900, 2019);
	stud[q].y = t;
	cout << "Enter grades: " << endl;
	cout << "Math: ";
	validation(t, 2, 6);
	stud[q].dis[0].value = t;
	cout << "Computer programming: ";
	validation(t, 2, 6);
	stud[q].dis[1].value = t;
	cout << "Web Design: ";
	validation(t, 2, 6);
	stud[q].dis[2].value = t;
	cout << "English: ";
	validation(t, 2, 6);
	stud[q].dis[3].value = t;
	cout << "Computer Electronics: ";
	validation(t, 2, 6);
	stud[q].dis[4].value = t;

}
void add_stud(struct student stud[], int& q) {
	if (q > 29) {
		cout << "There is no left space";
		system("pause");
		system("cls");
		menu(q, stud);
	}
	m_menu();
	int choice;
	validation(choice, 1, 2);// dopuska ot 1vata do posl opciq
	if (choice == 1) {
		stud[q].Specialnost = "SIT";
		sit_(stud, q);
	}
	else {
		stud[q].Specialnost = "CSE";
		int t;
		cin.ignore(1, '\n');
		do {
			cout << "Enter a name: " << endl;
			getline(cin, stud[q].name);
		} while (stud[q].name == "");

		do {
			cout << "Enter a faculty number: " << endl;
			getline(cin, stud[q].f_number);
		} while (stud[q].f_number == "");
		cout << "Enter a month of birth: ";
		validation(t, 1, 12);
		stud[q].m = t;
		cout << "Enter a year of birth: ";
		validation(t, 1900, 2019);
		stud[q].y = t;
		cout << "Enter grades: " << endl;
		cout << "Math: ";
		validation(t, 2, 6);
		stud[q].dis[0].value = t;
		cout << "Computer programming: ";
		validation(t, 2, 6);
		stud[q].dis[1].value = t;
		cout << "OKS: ";
		validation(t, 2, 6);
		stud[q].dis[2].value = t;
		cout << "English: ";
		validation(t, 2, 6);
		stud[q].dis[3].value = t;
		cout << "ET: ";
		validation(t, 2, 6);
		stud[q].dis[4].value = t;


	}

	for (int i = 0; i < 5; i++) {
		stud[q].sreden_uspeh = stud[q].dis[i].value + stud[q].sreden_uspeh;
	}

	stud[q].sreden_uspeh = stud[q].sreden_uspeh / 5;

	system("pause");

}
void addaSTU(struct student stud[], int& q)
{
	add_stud(stud, q);
	decide_group(stud, q);
	q++;

	system("cls");
	menu(q, stud);

}

void listofSTU(struct student stud[], int& q)
{

	cout << "How many students do you want to add? " << endl;
	int n = 0;
	validation(n, 1, 29);// vyvejdane na n studenti
	n = n + q;
	for (q; q < n; q++) {
		add_stud(stud, q);
		decide_group(stud, q);
	}
	system("cls");
	menu(q, stud);
}
void show(struct student stud[], int i) {

	if (stud[i].Specialnost == "CSE") {
		cout << "Stecialnost  " << stud[i].Specialnost << "  group  " << stud[i].group << "   Average grades  " << stud[i].sreden_uspeh;
		cout << "Name: " << stud[i].name << "      Fnumber  " << stud[i].f_number <<  "   Month of birth:  " << stud[i].m << "      Year of birth  " << stud[i].y << endl;
		cout << "Math " << stud[i].dis[0].value << endl;
		cout << "Computer programming  " << stud[i].dis[1].value << endl;
		cout << "OKS   " << stud[i].dis[2].value << endl;
		cout << "English   " << stud[i].dis[3].value << endl;
		cout << "ET " << stud[i].dis[4].value << endl << endl << endl;
	}
	else {

		cout << "Stecialnost  " << stud[i].Specialnost << "  group  " << stud[i].group << "   Average grades  " << stud[i].sreden_uspeh;
		cout << "Name: " << stud[i].name << "      Fnumber  " << stud[i].f_number << "   Month of birth:  " << stud[i].m << "      Year of birth  " << stud[i].y << endl;
		cout << "Math " << stud[i].dis[0].value << endl;
		cout << "Computer programming  " << stud[i].dis[1].value << endl;
		cout << "Web Design  " << stud[i].dis[2].value << endl;
		cout << "English   " << stud[i].dis[3].value << endl;
		cout << "Computer Electronics " << stud[i].dis[4].value << endl << endl << endl;
	}


}
void data(struct student stud[], int q)
{
	for (int i = 0; i < q; i++) {
		show(stud, i);

	}
	system("pause");
	menu(q, stud);
}
void serach_algorithm(struct student stud[], int q, string search, int& n) {
	int br = 0;
	for (int i = 0; i < q; i++) { // namirane na mqstoto na studenta v masiva
		if (search == stud[i].f_number) {
			n = i;// priema na koe mqsto e v masiva sys syotvetniq fn
			i = q;// za krai na cikula
			br++;
		}


	}
	if (br == 0) {
		cout << "error" << endl;
		system("pause");
		system("cls");
		menu(q, stud);
	}
}
void swap(struct student stud[], int q)
{
	student temp;
	int num1 = -1, num2 = -1;// az reshih da vyveda -1 tyi kato nqma kak da se poluchi tova; poziciq na studenta
	string search1, search2;// fn na studenta
	cin.ignore(1, '/n');// propuska edin enter
	cout << "Enter fist student's faculty number " << endl;
	getline(cin, search1);
	cout << "Enter second student's faculty number " << endl;
	getline(cin, search2);
	serach_algorithm(stud, q, search1, num1);

	serach_algorithm(stud, q, search2, num2);

	temp.group = stud[num1].group;
	stud[num1].group = stud[num2].group;
	stud[num2].group = temp.group;
	cout << "Changed groups" << endl;
	system("pause");
	system("cls");
	menu(q, stud);
}
void delete_action(struct student stud[], int t, int q) {
	student temp;// promenliva, za zapazvane na info za opredeleno vreme


	for (t; t < q - 1; t++) {// premestvame dannite na vyprosniq student do posledno mqsto v masiva
		temp = stud[t];// student s adres na masiva t
		stud[t] = stud[t + 1];
		stud[t + 1] = temp;
	}
	q--;// namalqva broikata

	decide_group(stud, q);// novo opredelqne na grupi
	stud[q].group = "";// zanulqva grupata na studenta
	q++;
	system("pause");
	system("cls");
	menu(q, stud);
}
void delete_student(struct student stud[], int q) {
	string search;
	int t = -1; int ans;
	cin.ignore(1, '/n');
	do {
		cout << "Enter a faculty number to delete a student" << endl;
		getline(cin, search);
	} while (search == "");// cikylyt vyrti dokato fn e prazen


	for (int i = 0; i < q; i++) {
		if (search == stud[i].f_number) {
			t = i;
			i = q;
		}
	}

	if (t == -1) {
		cout << "No students found" << endl;
		system("pause");
		system("cls");
		menu(q, stud);
	}

	show(stud, t);
	system("pause");
	system("cls");
	cout << "1.Delete the student" << endl;
	cout << "2.Back to MENU" << endl;
	validation(ans, 1, 2);
	if (ans == 1) {
		delete_action(stud, t, q);// t mqsto na studenta v samiq masiv
	}
	else {
		menu(q, stud);
	}

}
void sort1(struct student stud[], int q)// sortirane s bubble po golemina
{
	student temp;
	for (int i = 0; i < q - 1; i++)
	{
		for (int k = 0; k < q - 1; k++)
		{
			temp = stud[k + 1];
			if (stud[k].sreden_uspeh < stud[k + 1].sreden_uspeh)
			{
				stud[k + 1] = stud[k];

				stud[k] = temp;
			}
		}
	}

	cout << " The students are sorted by their average grades. ";
	system("pause");
	menu(q, stud);

}
void sort2(struct student stud[], int q)
{
	student temp;
	for (int i = 0; i < q - 1; i++)
	{
		for (int k = 0; k < q - 1; k++)
		{
			temp = stud[k + 1];
			if (stud[k].m > stud[k + 1].m)
			{
				stud[k + 1] = stud[k];

				stud[k] = temp;
			}
		}
	}
	cout << " The students are sorted by months(age)";
	system("pause");
	menu(q, stud);
}
void search1(struct student stud[], int q)
{
	if (stud[0].f_number == "") {// proverqva dali ima syzdaden student
		cout << "No information found" << endl;
		system("pause");
		system("cls");
		menu(q, stud);
	}
	int test = -1;
	double max = -1; int d = -1;
	for (int i = 0; i < q; i++) {
		if (stud[i].Specialnost == "SIT") {

			max = stud[i].sreden_uspeh;// na pyrviq nameren student ot sit
			d = i;// adres na studenta v masiva
			i = q;

		}
	}
	test = d;
	if (d != -1) {
		for (d; d < q; d++) {
			if ((max < stud[d].sreden_uspeh) && (stud[d].Specialnost == "SIT")) {
				max = stud[d].sreden_uspeh;
				test = d;
			}
		}
		show(stud, test);
	}


	test = -1;
	max = -1; d = -1;
	for (int i = 0; i < q; i++) {
		if (stud[i].Specialnost == "CSE") {

			max = stud[i].sreden_uspeh;
			d = i;
			i = q;
		}
	}
	test = d;

	if (d != -1) {
		for (d; d < q; d++) {
			if ((max < stud[d].sreden_uspeh) && (stud[d].Specialnost == "CSE")) {
				test = d;
				max = stud[d].sreden_uspeh;
			}
		}
		show(stud, test);
	}
	system("pause");
	system("cls");
	menu(q, stud);
}
void search2(struct student stud[], int q)
{
	if (stud[0].f_number == "") {
		cout << "No information found" << endl;
		system("pause");
		system("cls");
		menu(q, stud);
	}

	int t[30]{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, -1,-1, -1,-1, -1,-1,-1,-1,-1,-1, -1,-1, -1,-1, -1,-1 };// za da ne sa sluchaini chisla
	int br = 0;// cqlo chislo
	double p = 5.5;// realno chislo
	for (int i = 0; i < q; i++) {
		if (stud[i].sreden_uspeh > p) {
			t[br] = i;
			br++;
		}
	}

	for (int i = 0; i < br; i++) {
		if (t[i] != -1) {

			if (stud[i].Specialnost == "CSE") {
				cout << "Stecialnost  " << stud[t[i]].Specialnost << "  group  " << stud[t[i]].group << "   Average grades  " << stud[t[i]].sreden_uspeh;
				cout << "Name: " << stud[t[i]].name << "      Fnumber  " << stud[t[i]].f_number << endl;
				cout << "Math " << stud[t[i]].dis[0].value << endl;
				cout << "Computer programming  " << stud[t[i]].dis[1].value << endl;
				cout << "OKS   " << stud[t[i]].dis[2].value << endl;
				cout << "English   " << stud[t[i]].dis[3].value << endl;
				cout << "ET " << stud[t[i]].dis[4].value << endl << endl << endl;
			}
			else {
				cout << "Stecialnost  " << stud[t[i]].Specialnost << "  group  " << stud[t[i]].group << "   Average grades  " << stud[t[i]].sreden_uspeh;
				cout << "Name: " << stud[t[i]].name << "      Fnumber  " << stud[t[i]].f_number << endl;
				cout << "Math " << stud[t[i]].dis[0].value << endl;
				cout << "Computer programming  " << stud[t[i]].dis[1].value << endl;
				cout << "Web Design  " << stud[t[i]].dis[2].value << endl;
				cout << "English   " << stud[t[i]].dis[3].value << endl;
				cout << "Computer Electronics " << stud[t[i]].dis[4].value << endl << endl << endl;
			}
		}
	}


	if (t[0] == -1) {
		cout << " No students with average grades over 5.50 found." << endl;
	}

	system("pause");
	system("cls");
	menu(q, stud); 
}
void fileSave(struct student stud[], int count)
{
	cout << "Text File Save" << endl;
	fstream file("student.txt", ios::binary | ios::out);
	for (int i = 0; i < count; i++)
	{
		file << stud[i].Specialnost << endl;
		file << stud[i].f_number << endl;
		file << stud[i].name << endl;
		file << stud[i].y << endl;
	   file << stud[i].m << endl;
	}
	file.close();
}
int fileRead(struct student stud[], int count)
{
	cout << "Text file read" << endl;
	ifstream file;
	file.open("student.txt", ios::binary | ios::in);
	for(int i=0; i<count;i++)
	{
		file.ignore();
		getline(file,stud[count].Specialnost);
		getline(file,stud[count].name);
		file >> stud[count].f_number;
		file >> stud[count].y;
		file >> stud[count].m;
		count++;
		
	}
	cout << stud[count].Specialnost << endl;
	cout << stud[count].name << endl;
	cout << stud[count].f_number << endl;
	cout << stud[count].y << endl;
	cout << stud[count].m << endl;

	file.close();
	return count;
}