#include "clsDbLinkedList.h";

int main() {

	clsDbLinkedList <int> list;

	list.AddAtEnd(1);
	list.AddAtEnd(2);
	list.AddAtEnd(3);
	list.AddAtEnd(4);
	list.AddAtEnd(50);
	list.AddAtEnd(6);
	list.AddAtEnd(7);
	list.AddBefore(2, 999);

	list.PrintList();

	cout << "\n\n\n";

	list.InsertAfter(10, 333);

	list.PrintList();

	system("pause>0");
	return 0;
}