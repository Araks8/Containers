#ifndef __LIST__
#define __LIST__
#include <iostream>
namespace m_list{
	template <typename T>
	struct list_node {
	  list_node<T>* next;
	  T m_data;
	};

	template<typename T>
	class List {
	public:
	List() = default;
	List(const T& data);
	~List();
	public: 
	void push_front(const T& data);
	void push_back(const T& data);
	void insert(const T& data, int pos);
	void remove(int pos);
	private: 
	list_node<T>* m_head = nullptr;
	size_t size{};
	};
#include "list.tpp"

}

#endif // LIST
