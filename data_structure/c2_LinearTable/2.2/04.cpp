#include "../SequenceList.hh"

void ans(int s, int t)
{
	SequenceList<int> list;
	list.InitList(10);
	list.FillRandInt(10);
	list.PrintList();

	if (list.Empty())
		throw std::out_of_range("List is empty");
	if (s < 0 || t < 0)
		throw std::out_of_range("Index less than 0.");
	if (s >= t)
		throw std::out_of_range("s is greater than t.");
	int i = 0;
	for (int j = 0; j < list.Length(); ++j)
	{
		if (list.data_[j] >= s && list.data_[j] <= t)
			continue;
		list.data_[i++] = list.data_[j];
	}
	list.length_ = i;
	list.PrintList();
}

int main()
{
	ans(2, 5);
	return 0;
}
