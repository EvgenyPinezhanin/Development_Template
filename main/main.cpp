#include<iostream>
#include<text.h>

using namespace std;

int main() {
	Text t;
	int op;

	while (true) {
		system("clear");

		cout << t << endl;

		cout << "0.exit\n";
		cout << "1.Next\n";
		cout << "2.Down\n";
		cout << "3.Top\n";
		cout << "4.Add Next\n";
		cout << "5.Add Down\n";
		cout << "6.Del Curr\n";
		cout << "7.Del Down\n";
		cin >> op;
		
		string tmp;
		try {
			switch (op) {
			case 0:
				return 0;
				break;
			case 1:
				t.next();
				break;
			case 2:
				t.down();
				break;
			case 3:
				t.top();
				break;
			case 4:
				cin >> tmp;
				t.addNext(tmp);
				break;
			case 5:
				cin >> tmp;
				t.addDown(tmp);
				break;
			case 6:
				t.delCurr();
				break;
			case 7:
				t.delDown();
				break;
			default:
				break;
			}
		} catch(const char * err_s) {
			cout << err_s << endl;
			getchar();
			getchar();
		}
	}

	return 0;
}
