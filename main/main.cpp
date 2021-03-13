#include<iostream>
#include<list.h>

using namespace std;

const int length = 100;
const int nodeLoop = 50;

int main()
{
	List list1;
	List list2;
    for (int i = 0; i < length - 1; i++) {
        Node *nd = new Node(i);
        list1.addNode(nd);
    }
	Node *nodeL = new Node(length - 1, list1.getPointer(nodeLoop));
    list1.addNode(nodeL);
	for (int i = 0; i < length; i++) {
        Node *nd = new Node(i);
        list2.addNode(nd);
    }

	cout << "the first method " << "list1 " << list1.CheckLoop1() << endl;
	cout << "the first method " << "list2 " << list2.CheckLoop1() << endl;

    cout << "the second method " << "list1 " << list1.CheckLoop2() << endl;
	cout << "the second method " << "list2 " << list2.CheckLoop2() << endl;

    cout << list1 << endl;
    cout << "the third method " << "list1 " << list1.CheckLoop3() << endl;
    cout << list1 << endl;
	cout << "the third method " << "list2 " << list2.CheckLoop3() << endl;

    return 0;
}