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
	SequenceList<int> list1;
	SequenceList<int> list2;
	SequenceList<int> list3;
	list1.InitList(10);
	list2.InitList(10);
	list3.InitList(10);
	list1.FillRandInt(10);
	list2.FillRandInt(10);
	list3.FillRandInt(10);
	list1.data_ = sort(list1.data_, list1.Length());
	list2.data_ = sort(list2.data_, list2.Length());
	list3.data_ = sort(list3.data_, list3.Length());
	list1.PrintList();
	list2.PrintList();
	list3.PrintList();

	int i = 0, j = 0, k = 0;
	int data1, data2, data3, max;
	while (i < list1.Length() && j < list2.Length() && k < list3.Length())
	{
		data1 = list1.data_[i];
		data2 = list2.data_[j];
		data3 = list3.data_[k];
		if (data1 == data2 && data2 == data3)
		{
			printf("%d\n", list1.data_[i]);
			++i;
			++j;
			++k;
		}
		else
		{
			max = data1;
			if (data2 > max)
				max = data2;
			if (data3 > max)
				max = data3;

			if (data1 < max)
				++i;
			if (data2 < max)
				++j;
			if (data3 < max)
				++k;
		}
	}
}

int main()
{
	ans();
	return 0;
}
