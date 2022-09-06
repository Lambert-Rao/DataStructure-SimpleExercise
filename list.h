#pragma once
#include <initializer_list>
namespace my_data_structure
{
	template<typename ElmType>
	class list_node
	{
        template<typename T>
		friend class list;
	public:
		ElmType operator *()
		{
			return *d_ptr;
		}
		std::ostream& operator<<(std::ostream &os)
		{
			return os<<*d_ptr;
		}
	private:
		ElmType* d_ptr;
		ElmType* pre, * next;
		list_node(ElmType* ptr)
		{
			d_ptr = ptr;
			pre = next = nullptr;
		}
		list_node(ElmType* ptr, list_node* pre, list_node* next)
		{
			d_ptr = ptr;
			this->pre = pre;
			this->next = next;
		}
		~list_node()
		{
			if(d_ptr)
				delete d_ptr;
			
				this->pre.next = this->next;
				this->next.pre = this->pre;
			
		}

	};
	template<typename ElmType>
	class list
	{
	public:
		using node_type = list_node<ElmType>;
		using value_type = ElmType;
		using iterator = node_type*;
		iterator begin()
		{
			return *first;
		}
		iterator end()
		{
			return *last;
		}
		void push_back(ElmType dat)
		{
			node_type* new_node = new node_type(dat);
			if (first == nullptr)
			{
				first=last=new_node;
			}
			else
			{
				last->next = new_node;
				new_node->pre = last;
				last = new_node;
			}
		}
		void pop_back()
		{
			if (first == nullptr)
			{
				throw std::range_error("empty list");
			}
			else
			{
				node_type* temp = last;
				last = last->pre;
				delete temp;
			}
		}
		//constructors
		list(std::initializer_list<ElmType> list)
		{
			for (auto it = list.begin(); it != list.end(); ++it)
			{
				push_back(*it);
			}
		}
		list()
		{
			first = last = nullptr;
		}
		//destructor
		~list()
		{
			while(first!=nullptr)
			{
				node_type* temp = first;
				first = first->next;
				delete temp;
			}
		}
	private:
		node_type* first,* last;

	};

}