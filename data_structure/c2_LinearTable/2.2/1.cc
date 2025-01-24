#include "../SequenceList.hh"
#include <cstdlib>

int ans()
{
	SequenceList<int> list;
	list.InitList(10);
	list.FillRandInt(100);
	list.PrintList();

	if (list.Empty())
		throw std::out_of_range("Empty list.");
	int min_value = list.data_[0];
	int min_index = 0;
	for (int i = 0; i < list.Length(); ++i)
	{
		if (list.data_[i] < min_value)
		{
			min_value = list.data_[i];
			min_index = i;
		}
	}
	list.data_[min_index] = list.data_[list.Length() - 1];
	list.PrintList();
	return min_value;
}

int main()
{
	ans();
	return 0;
}
