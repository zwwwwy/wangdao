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
/*
 * 标准答案在使用二分法的时候，取start=mid+1或end=mid-1
 * 这样课确保可以自动跳出循环而不用手动判断
 * 懒得写了就这样吧
 */
void ans(int elem)
{
	SequenceList<int> list;
	list.InitList(10);
	list.FillRandInt(10);
	list.data_ = sort(list.data_, list.length_);
	list.PrintList();

	if (list.Empty())
	{
		throw std::out_of_range("Empty list.");
	}
	int start = 0;
	int end	  = list.Length() - 1;
	int idx	  = 0;
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (mid == start && elem != list.data_[start] && elem != list.data_[end])
		{
			if (elem < list.data_[start])
				idx = start;
			else
				idx = end;
			printf("idx=%d\n", idx);
			for (int i = list.Length() - 1; i > idx; --i)
				list.data_[i] = list.data_[i - 1];
			list.data_[idx] = elem;
			list.PrintList();
			return;
		}
		else if (elem == list.data_[end]) // 仅剩两个元素时，下面的逻辑可以判断start但不能判断end，所以要在这里提前检查
		{
			printf("idx=%d\n", end);
			return;
		}
		if (elem > list.data_[mid])
			start = mid;
		else if (elem < list.data_[mid])
			end = mid;
		else
		{
			printf("idx=%d\n", mid);
			int tmp				= list.data_[mid];
			list.data_[mid]		= list.data_[mid + 1];
			list.data_[mid + 1] = tmp;
			return;
		}
	}

	return;
}

int main()
{
	ans(9);
	return 0;
}
