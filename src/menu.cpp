#include<menu.h>

#if defined(_MSC_VER)
   #include<conio.h>
#elif defined(__unix)
   	#include<termios.h>
	#include<cstdio>
   	static struct termios old, newt;

	/* Initialize new terminal i/o settings */
	void initTermios(int echo) 
	{
	  tcgetattr(0, &old); /* grab old terminal i/o settings */
	  newt = old; /* make new settings same as old settings */
	  newt.c_lflag &= ~ICANON; /* disable buffered i/o */
	  newt.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
	  tcsetattr(0, TCSANOW, &newt); /* use these new terminal i/o settings now */
	}

	/* Restore old terminal i/o settings */
	void resetTermios(void) 
	{
	  tcsetattr(0, TCSANOW, &old);
	}

	/* Read 1 character - echo defines echo mode */
	char getch_(int echo) 
	{
	  char ch;
	  initTermios(echo);
	  ch = getchar();
	  resetTermios();
	  return ch;
	}

	/* Read 1 character without echo */
	char getch(void) 
	{
	  return getch_(0);
	}

	/* Read 1 character with echo */
	char getche(void)
	{
	  return getch_(1);
	}
 #endif

menuConverter::menuConverter() {
    nameProgram = "Converter";
}

void menuConverter::romanToArabic() {
	string k;
	roman rom;
	converter conv;
	cout << "To exit, press 0" << endl;
	while (true) {
		cout << "Enter roman number: ";
		cin >> k;
		getch();
		if (k == "0") break;
		rom.value = k;
		conv.setRoman(rom);
		cout << "Arabic number: " << conv.getArabic().value << endl;
	}
}

void menuConverter::arabicToRoman() {
	int k = 0;
	arabic ar;
	converter conv;
	cout << "To exit, press 0" << endl;
	while (true) {
		cout << "Enter arabic number: ";
		cin >> k;
		getch();
		if (k == 0) break;
		ar.value = k;
		conv.setArabic(ar);
		cout << "Roman number: " << conv.getRoman().value << endl;
	}
}

void menuConverter::convText() {

}

void menuConverter::display() {
	bool isOpen = true;
	char c;
	int op = 0;
	int op_n = 4;
	string menuItems[] = {
	{"Convert from Roman to Arabic numbers"},
	{"Convert from Arabic to Roman numbers"},
	{"To convert the text with Roman numerals"},
	{"Exit"} };

	while (isOpen)
	{
		system("clear");
		cout << nameProgram << endl;
		cout << endl;

		for (int i = 0; i < op_n; i++)
		{
			if (i == op)
			{
				cout << "->" << menuItems[i] << "<-";
			}
			else
			{
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
				romanToArabic();
			} else if (op == 1) {
				arabicToRoman();
			} else if (op == 2) {
				convText();
			}
		}
	}
}