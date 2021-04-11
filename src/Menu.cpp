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
	if (!isSaveFile) saveFile();
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
	if (!isSaveFile) saveFile();
	string str;
	cout << "Please enter the name of the new file: ";
	getline(cin, str);
	ofstream ofile;
	ofile.open(str);
	ofile << "{" << endl << "}";
	ofile.close();
	ifstream ifile;
	ifile.open(str);
	ifile >> *text;
	isReadFile = true;
    nameReadFile = str;
	ifile.close();
}

void menuText::addNext(Text& text, string val, string key) {
	if (val.length() > 1 && val[0] == '\"' && val[val.length() - 1] == '\"') {
        text.addNext(key, val.substr(1, val.length() - 2));
    } else if (val == "true") {
        text.addNext(key, true);
    } else if (val == "false") {
        text.addNext(key, false);
    } else if (checkNum(val)) {
        text.addNext(key, atoi(val.c_str()));
	} else {
		text.addNext(key, val);
	}
}

void menuText::addDown(Text& text, string val, string key) {
	if (val.length() > 1 && val[0] == '\"' && val[val.length() - 1] == '\"') {
        text.addDown(key, val.substr(1, val.length() - 2));
    } else if (val == "true") {
        text.addDown(key, true);
    } else if (val == "false") {
        text.addDown(key, false);
    } else if (checkNum(val)) {
        text.addDown(key, atoi(val.c_str()));
	} else {
		text.addDown(key, val);
	}
}

void menuText::changeCurrVal(Text& text, string val) {
	if (val.length() > 1 && val[0] == '\"' && val[val.length() - 1] == '\"') {
        text.changeCurrValue(val.substr(1, val.length() - 2));
    } else if (val == "true") {
        text.changeCurrValue(true);
    } else if (val == "false") {
        text.changeCurrValue(false);
    } else if (checkNum(val)) {
        text.changeCurrValue(atoi(val.c_str()));
	} else {
		text.changeCurrValue(val);
	}
}

void menuText::readingKeys(set<string> *setKey, Text *text) {
	setKey->insert(text->getCurrKey());
	if (text->isDown()) {
		text->down();
		readingKeys(setKey, text);
		text->top();
	}
	if (text->isNext()) {
		text->next();
		readingKeys(setKey, text);
		text->top();
	}
	return;
}

string menuText::getKey(set<string> *setKey, int& count) {
	while(true) {
		string key = "key" + to_string(count);
		if (setKey->count(key)) {
			count++;
		} else {
			setKey->insert(key);
			return key;
		}
	}
}

void menuText::menuShowText(bool b) {
	bool isOpen = true;
	char c;
	int op = 0;
	int op_n = 1;
	int count = 1;
	string str, str1;
	set<string> *setKey;
	if (!b) {
		setKey = new set<string>;
		if (!text->empty()) readingKeys(setKey, text);
	}

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
		cout << "* 7.To change the current val, press t               *" << endl;
		if (b) cout << "* 8.To change the current key, press r               *" << endl;
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
			if (text->isNext()) text->next();
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
			if (b) {
				cout << "Please enter the string key: ";
				getline(cin, str1);
			}
			str1 = getKey(setKey, count);
			cout << "Please enter the string value: ";
			getline(cin, str);
			addNext(*text, str, str1);
			isSaveFile = false;
			break;
		case 's':
			if (b) {
				cout << "Please enter the string key: ";
				getline(cin, str1);
			}
			str1 = getKey(setKey, count);
			cout << "Please enter the string value: ";
			getline(cin, str);
			addDown(*text, str, str1);
			isSaveFile = false;
			break;
		case 'r':
			if (!b) break;
			cout << "Please enter the string: ";
			getline(cin, str);
			text->changeCurrKey(str);
			isSaveFile = false;
			break;
		case 't':
			cout << "Please enter the string: ";
			getline(cin, str);
			changeCurrVal(*text, str);
			isSaveFile = false;
			break;
		case 'q':
			isOpen = false;
			break;
		}
	}
}

void menuText::menuSelectModeShow() {
    bool isOpen = true;
	char c;
	int op = 0;
	int op_n = 3;
	string menuItems[] = {
	{"Normal editing mode"},
	{"Advanced editing mode"},
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
				isOpen = false;
			} else if (op == 0) {
				menuShowText(false);
				isOpen = false;
			} else if ((op == 1)) {
				menuShowText(true);
				isOpen = false;
			}
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
				menuSelectModeShow();
			} else if ((op == 3) && (isReadFile)) {
				saveFile();
			}
		}
	}
}