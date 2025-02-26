#include "../SequenceList.hh"
void reverse(int* list, int i, int j)
{
	while (i < j)
	{
		int tmp	  = list[i];
		list[i++] = list[j];
		list[j--] = tmp;
	}
}
void ans()
{
	SequenceList<int> list1, list2;
	list1.InitList(3);
	list2.InitList(6);
	list1.FillRandInt(10);
	list2.FillRandInt(10);
	list1.PrintList();
	list2.PrintList();
	int* ans = new int[list1.Length() + list2.Length()];
	int	 k	 = 0;
	for (int i = 0; i < list1.Length(); ++i)
		ans[k++] = list1.data_[i];
	for (int i = 0; i < list2.Length(); ++i)
		ans[k++] = list2.data_[i];
	for (int i = 0; i < k; ++i)
		printf("%d ", ans[i]);
	printf("\n");

	int j = list1.Length();
	reverse(ans, 0, j - 1);
	reverse(ans, j, k - 1);
	reverse(ans, 0, k - 1);
	for (int i = 0; i < k; ++i)
		printf("%d ", ans[i]);
	printf("\n");
}

int main()
{
	ans();
	return 0;
}
