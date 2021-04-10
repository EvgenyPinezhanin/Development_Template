#include<iostream>
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
	while(iter.hasNext()){
		tree.insert(iter.getValue());
		iter.next();
	}
    int count = 0;
	listIterator<string> iter = list->begin();
	while(iter.hasNext()){
		count = tree.search(iter.getValue());
		cout << iter.getValue() << ": " << count;
		iter.next();
	}
	return 0;
}
