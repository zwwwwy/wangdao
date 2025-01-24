#include "../SequenceList.hh"

void ans()
{
	SequenceList<int> list;
	list.InitList(11);
	list.FillRandInt(100);
	list.PrintList();

	int tmp;
	int i = 0;
	int j = list.Length() - 1;
	while (i < j)
	{
		tmp = list.data_[i];

		list.data_[i++] = list.data_[j];
		list.data_[j--] = tmp;
	}
	list.PrintList();
	return;
}

int main()
{
	ans();
	return 0;
}
