#ifndef CPP_LINEARTABLE_HH
#define CPP_LINEARTABLE_HH
#include <iostream>

template <typename T> class SequenceList
{
  public:
	void InitList(int max_length);
	int	 Length();
	int	 LocateElem(T elem);
	T	 GetElem(int idx);
	int	 ListInsert(int idx, T elem);
	T	 ListDelete(int idx);
	void PrintList();
	bool Empty();
	void DestoryList();

  private:
	int length_;
	int max_length_;
	T*	data_;
};

template <typename T> void SequenceList<T>::InitList(int max_length)
{
	this->data_		  = new T[max_length];
	this->max_length_ = max_length;
	this->length_	  = 0;
	for (int i = 0; i < max_length; ++i)
	{
		this->data_[i] = 0;
	}
}

template <typename T> int SequenceList<T>::Length()
{
	std::cout << this->length_ << std::endl;
	return this->length_;
}

template <typename T> int SequenceList<T>::LocateElem(T elem)
{
	for (int i = 0; i < this->length_; ++i)
	{
		if (this->data_[i] == elem)
		{
			return i;
		}
	}
	std::cout << "Element not found." << std::endl;
	return -1;
}

template <typename T> T SequenceList<T>::GetElem(int idx)
{
	if (idx >= this->length_)
	{
		std::cout << "Out of range." << std::endl;
		return NULL;
	}
	return this->data_[idx];
}

template <typename T> int SequenceList<T>::ListInsert(int idx, T elem)
{
	if (idx >= this->max_length_ || idx < 0)
		throw std::out_of_range("Access denied.");

	if (idx >= this->length_)
	{
		this->data_[idx] = elem;
		this->length_	 = idx + 1;
	}
	else
	{
		for (int i = length_; i > idx; --i)
		{
			this->data_[i] = this->data_[i - 1];
		}
		this->data_[idx] = elem;
		++this->length_;
	}
	return 0;
}

template <typename T> T SequenceList<T>::ListDelete(int idx)
{
	if (idx >= this->length_ || idx < 0)
		throw std::out_of_range("Access denied.");

	int ret = this->data_[idx];
	for (int i = idx; i < this->length_; ++i)
	{
		this->data_[i] = this->data_[i + 1];
	}
	--this->length_;
	return ret;
}

template <typename T> void SequenceList<T>::PrintList()
{
	std::cout << "{";
	for (int i = 0; i < this->length_; ++i)
	{
		std::cout << this->data_[i] << ", ";
	}
	std::cout << "\b\b}" << std::endl;
}

template <typename T> bool SequenceList<T>::Empty()
{
	if (this->length_)
		return true;
	else
		return false;
}

template <typename T> void SequenceList<T>::DestoryList()
{
	delete[] this->data_;
	this->max_length_ = 0;
	this->length_	  = 0;
}

#endif
