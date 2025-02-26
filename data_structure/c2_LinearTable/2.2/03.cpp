#include "../SequenceList.hh"

/* 想麻烦了，待删元素的索引不用主动变化,
 * 因为i右侧有用的元素已经被j索引取到i的左侧了，所以i右侧的元素不用主动保留,
 * i也就不必要主动更新了,
 * 只要不断更改j的大小就可以了。
 */
void ans(int elem)
{
	SequenceList<int> list;
	list.InitList(10);
	for (int i = 0; i < 10; ++i)
	{
		// if (i < 7 && i > 2)
		if (i % 2)
			list.ListInsert(i, 6);
		else
			list.ListInsert(i, i);
	}
	list.PrintList();

	int i = 0;
	int j = 0;
	while (i < list.Length() && j < list.Length())
	{
		while (i < list.Length() && list.data_[i] != elem)
			++i;
		if (j < i)
			j = i;
		while (j < list.Length() && list.data_[j] == elem)
			++j;
		if (j == list.Length())
			break;
		list.data_[i] = list.data_[j];
		list.data_[j] = elem;
	}
	list.length_ = i;
	list.PrintList();
	return;
}

void std_ans(int elem)
{
	SequenceList<int> list;
	list.InitList(10);
	for (int i = 0; i < 10; ++i)
	{
		if (i < 7 && i > 2)
			// if (i % 2)
			list.ListInsert(i, 6);
		else
			list.ListInsert(i, i);
	}
	list.PrintList();

	int k = 0;
	for (int i = 0; i < list.Length(); ++i)
	{
		if (list.data_[i] != elem)
			list.data_[k++] = list.data_[i];
	}
	list.length_ = k;
	list.PrintList();
}

int main()
{
	// ans(6);
	std_ans(6);
	return 0;
}
