#include "../SequenceList.hh"

int* merge(int* list1, int* list2, int len1, int len2)
{
	int* ans = new int[len1 + len2];
	int	 i = 0, j = 0, k = 0;
	while (i < len1 && j < len2)
	{
		ans[k++] = list1[i] < list2[j] ? list1[i++] : list2[j++];
	}
	for (; i < len1; ++i)
		ans[k++] = list1[i];
	for (; j < len2; ++j)
		ans[k++] = list2[j];
	return ans;
}

int* sort(int* list, int length)
{
	if (length <= 1)
		return list;
	int	 mid   = length / 2;
	int* left  = sort(list, mid);
	int* right = sort(list + mid, length - mid);
	return merge(left, right, mid, length - mid);
}
void ans()
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
	list.data_ = sort(list.data_, list.length_);
	list.PrintList();

	int i = 0, j = 1;
	while (j < list.Length())
	{
		if (list.data_[i] != list.data_[j])
			list.data_[++i] = list.data_[j++];
		else
			++j;
	}
	list.length_ = i + 1;
	list.PrintList();
	return;
}

int main()
{
	ans();
	return 0;
}
