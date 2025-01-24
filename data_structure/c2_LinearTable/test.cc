#include "LinearTable.hh"

int main()
{
	SequenceList<int> list;
	list.InitList(100);
	list.ListInsert(10, 6);
	list.PrintList();
}
