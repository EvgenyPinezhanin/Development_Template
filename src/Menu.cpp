#include<Menu.h>
#include<terminal.h>
 
menuText::menuText() {
    text = new Text;
    nameProgram = "Text editor";
	nameReadFile = "";
    isSaveFile = true;
    isReadFile = false;
}

menuText::~menuText() {
    delete text;
}

void menuText::saveFile() {
	if (isSaveFile) return;
    ofstream f;
	f.open(nameReadFile);
	f << *text;
	f.close();
	isSaveFile = true;
}

void menuText::loadFile() {
	if (!isSaveFile) saveFile;
	string str;
	cout << "Please enter the name of the file: ";
	getline(cin, str);
	ifstream f;
	f.open(str);
	f >> *text;
	isReadFile = true;
    nameReadFile = str;
	f.close();
}

void menuText::createNewFile() {
	if (!isSaveFile) saveFile;
	string str;
	cout << "Please enter the name of the new file: ";
	getline(cin, str);
	ifstream f;
	f.open(str);
	f >> *text;
	isReadFile = true;
    nameReadFile = str;
	f.close();
}

void menuText::menuShowText() {
	bool isOpen = true;
	char c;
	int op = 0;
	int op_n = 1;
	string str;
	string menuItems[] = {
	{"Back"} };

	while (isOpen)
	{
		system("clear");
		cout << nameProgram << endl;
		cout << endl;
		cout << "******************************************************" << endl;
		cout << "* 1.To go to the level below, press Enter            *" << endl;
		cout << "* 2.To exit, press q                                 *" << endl;
		cout << "* 3.To delete the current row, press z               *" << endl;
		cout << "* 4.To delete a sublevel of the current row, press x *" << endl;
		cout << "* 5.Add a row in the current level, press a          *" << endl;
		cout << "* 6.Add a row in a sublevel, press s                 *" << endl;
		cout << "* 6.To change the current row, press r               *" << endl;
		cout << "******************************************************" << endl;
		cout << endl;
		cout << "Current file: "<< nameReadFile << endl;
		cout << *text;

		c = getch();
		if (c == 27) {
			c = getch();
			c = getch();
		}

		switch (c)
		{
		case 65:
			if (text->isTop()) text->top();
			break;
		case 66:
			if (text->isNext())text->next();
			break;
		case 10:
			if (text->isDown())text->down();
			break;
		case 'z':
			text->delCurr();
			isSaveFile = false;
			break;
		case 'x':
			text->delDown();
			isSaveFile = false;
			break;
		case 'a':
			cout << "Please enter the string: ";
			getline(cin, str);
			text->addNext(str);
			isSaveFile = false;
			break;
		case 's':
			cout << "Please enter the string: ";
			getline(cin, str);
			text->addDown(str);
			isSaveFile = false;
			break;
		case 'r':
			cout << "Please enter the string: ";
			getline(cin, str);
			text->renameCurr(str);
			isSaveFile = false;
			break;
		case 'q':
			isOpen = false;
			break;
		}
	}
}

void menuText::display() {
    bool isOpen = true;
	char c;
	int op = 0;
	int op_n = 5;
	string menuItems[] = {
	{"Load the file"},
	{"Create the new file"},
	{"Show the text"},
	{"Save the file"},
	{"Exit"} };

	while (isOpen){
		system("clear");
		cout << nameProgram << endl;
		cout << endl;
		for (int i = 0; i < op_n; i++) {
			if (i == op) {
				cout << "->" << menuItems[i] << "<-";
			} else {
				cout << menuItems[i];
			}
			int k = 0;
			if (i == op) k = 4;
			if (i == 0) {
				cout << setw(40 - k) << right << "Name of the uploaded file: ";
        		if (!isSaveFile) cout << "*";
            	cout << nameReadFile;
			}
			cout << endl;
		}
		c = getch();
		if (c == 27) {
			c = getch();
			c = getch();
		}
		switch (c)
		{
		case 65:
			op = (op + op_n - 1) % op_n;
			break;
		case 66:
			op = (op + 1) % op_n;
			break;
		case 10:
			if (op == op_n - 1) {
				if (!isSaveFile) {
					cout << "The current file is not saved.(To save, press \"Y\", Exit \"E\", Cancel other)";
					c = getch();
					if (c == 'Y' || c == 'y') {
						saveFile();
						isOpen = false;
					} else if (c == 'E' || c == 'e') {
						isOpen = false;
					}
				} else {
					isOpen = false;
				}
			} else if (op == 0) {
				loadFile();
			} else if ((op == 1)) {
				createNewFile();
			} else if ((op == 2) && (isReadFile)) {
				menuShowText();
			} else if ((op == 3) && (isReadFile)) {
				saveFile();
			}
		}
	}
}