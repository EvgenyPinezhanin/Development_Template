#include<iostream>
#include<set>
#include<text.h>
#include<TreeSearch.h>

using namespace std;

int main() {
	Text text;
	string str;
	getline(cin, str);
	text.setString(str);
	text.replace();
	List<string> *list = text.split(' ');
	TreeSearch tree;
	listIterator<string> iter = list->begin();
	set<string> setStr;
	while(iter.hasNext()){
		tree.insert(iter.getValue());
		setStr.insert(iter.getValue());
		iter.next();
	}
    int count = 0;
	for (auto iter = setStr.begin(); iter != setStr.end(); iter++) {
		count = tree.search(*iter);
		cout << *iter << ": " << count << endl;
	}
	return 0;
}
