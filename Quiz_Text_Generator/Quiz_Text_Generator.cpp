// Quiz_Text_Generator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "applet_tools.h"
//Small app for Generating Quiz texts for the game/device
applet_tools data_app;

void start_display() {
	cout << "\t\t\t\t\tWELCOME\n";
	cout << "OPTIONS:\n";
	cout << "1: ADD\n";
	cout << "2: WRITE TO FILE\n";
	cout << "3: READ FROM FILE\n";
	cout << "4: EXIT\n";
}

void display_1() {
	int num;
	cout << "\t\t\tADDING QUESTIONS" << endl;
	cout << "Enter number of questions:"<<endl;
	cin >> num;
	if (cin.peek() == '\n')
		cin.ignore();
	fflush(stdin);
	for (int j = 0; j < num; j++) {
		cout << " Enter Question: " << j+1 <<endl;
		Data temp;
;
		getline(cin, temp.Question);
		cout << " Enter Num of Options for Question: " << j + 1 << endl;
		cin >> temp.num_options;
		
		fflush(stdin);
		for (int s = 0; s < temp.num_options; s++) {
			cout << " Enter all Option "<<s<<"for Question : " << j + 1 << endl;
			string temp2;
			if (cin.peek() == '\n')
				cin.ignore();
			getline(cin, temp2);

			temp.options.push_back(temp2);
		}
		fflush(stdin);
		cout << "Enter the correct answer for Question: " << j + 1 << endl;
		fflush(stdin);
		cin >> temp.answer;
		if (cin.peek() == '\n')
			cin.ignore();
		data_app.questions.push_back(temp);
	}
}

void display_2() {
	string filepath;
	cout << "\t\t\tWRITE TO FILE"<<endl;

	cout << "Enter path to the file location:" << endl;
	if (cin.peek() == '\n')
		cin.ignore();
	getline(std::cin, filepath);

	data_app.set_file(filepath);
	data_app.toFile();
	printf("a\n");
}

void display_3() {
	string filelocation;
	cout << "\t\t\tRead from the File"<<endl;
	cout << "Enter the file location: "<<endl;
	if (cin.peek() == '\n')
		cin.ignore();
	getline(cin, filelocation);

	data_app.set_file(filelocation);

	data_app.fromFile();
	
}

void display_4() {
	exit(0);
}

int main()
{
	int opt;
	while (true) {
		start_display();
		cout << "Wach ya wanna madafaka\n";
		cin >> opt;
		cin.clear();
		fflush(stdin);
		if (cin.peek() == '\n')
			cin.ignore();
		switch (opt) {
		case 1:
			display_1();
			break;
		case 2:
			display_2();
			break;
		case 3:
			display_3();
			break;
		case 4:
			display_4();
			break;
		default:
			break;
		}
	}
}

