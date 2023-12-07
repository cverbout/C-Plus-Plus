using namespace std;
// Chase Verbout
// Program 2
// CS202 Spring 2022
// list.tpp

// The purpose for this file is to hold the function definitions for the template classes:
// Node<T> and DLL<T>. The DLL<T> template class contains Node<T> objects.
// There is heavy usage of shared_ptr objects in this file. 

// Node<T> Constructor
template <typename T>
Node<T>::Node():next(nullptr), prev(nullptr)
{}



// Node<T> Copy Constructor
template <typename T>
Node<T>::Node(const T & source): data(source), next(nullptr), prev(nullptr)
{}



// Returns this Node's next shared_ptr
template <typename T>
shared_ptr<Node<T>>& Node<T>::get_next()
{
	 return next;	
}



// Returns this Node's prev shared_ptr
template <typename T>
shared_ptr<Node<T>>& Node<T>::get_prev()
{
	 return prev;
}



// Set this Node's next shared_ptr
template <typename T>
shared_ptr<Node<T>>& Node<T>::set_next(const shared_ptr<Node<T>>& a_node)
{
	 next = a_node;
	 return next;
}



// Set this Node's prev shared_ptr
template <typename T>
shared_ptr<Node<T>>& Node<T>::set_prev(const shared_ptr<Node<T>>& a_node)
{
	 prev = move(a_node);
	 return prev;
}



// Return true if this Node has a next item
template <typename T>
bool Node<T>::has_next(void) const
{
	 return next;
}



// Return true if this Node has a prev item
template <typename T>
bool Node<T>::has_prev(void) const
{
	 return prev;
}



// Return true if this Node's data is less than or equal to the arguments
template <typename T>
bool Node<T>::le(const T& other) const
{
	 return data <= other;
}



// Return true if this Node's data is greater than or equal to the arguments
template <typename T>
bool Node<T>::ge(const T& other) const
{
	 return data >= other;
}



// Return true if this Node's data is less than the arguments
template <typename T>
bool Node<T>::less(const T& other) const
{
	 return data < other;
}



// Return true if this Node's data is greater than the arguments
template <typename T>
bool Node<T>::greater(const T& other) const
{
	 return data > other;
}



// Return the data in this Node
template <typename T>
T Node<T>::get_data(void) const
{
	 return data;
}



// Output this Node's data
template <typename T>
void Node<T>::display() const
{
	 cout << data;
}



// DLL Constructor
template <typename T>
DLL<T>::DLL(void): head(nullptr), tail(nullptr)
{}



// DLL Copy Constructor
template <typename T>
DLL<T>::DLL(const DLL& a_DLL): head(nullptr), tail(nullptr)
{
	 if (a_DLL.head)
	 {
		  shared_ptr<Node<T>> temp(new Node<T>(a_DLL.head->get_data()));
		  head = tail = temp;
		  copy(head->get_next(), head, a_DLL.head->get_next());
	 }
}



// DLL Destructor
template <typename T>
DLL<T>::~DLL(void)
{
	 if (head)
		  remove_all(head);
	 head = nullptr;
	 tail = nullptr;
}



// Resets all shared pointer objects in the DLL recursively
template <typename T>
int DLL<T>::remove_all(shared_ptr<Node<T>>& curr)
{
	 if (!curr)
		  return 0;
	 int count = 1 + remove_all(curr->get_next());
	 curr.reset();
	 return count;	
}



// DLL operator overload for '='
template <typename T>
DLL<T>& DLL<T>::operator = (const DLL& a_DLL)
{
	 if (this == &a_DLL)
		  return *this;
	 if (head)
		  return *this;	
	 if (!a_DLL.head)
		  return *this;

	 shared_ptr<Node<T>> temp(new Node<T>(data));
	 head.swap(temp);
	 tail = head;

	 copy(head->get_next(), head, a_DLL.head);
	 return *this;
}



// Inserts an object T with smallest data value at the front largest at the back
template <typename T>
int DLL<T>::insert(const T& data)
{
	 // Check if we have no head yet
	 if (!head)
	 {
		  shared_ptr<Node<T>> temp(new Node<T>(data));
		  head.swap(temp);
		  tail = head;
		  return 1;
	 }

	 // Check if we need to go before the head
	 if (head->greater(data))
	 {
		  shared_ptr<Node<T>> temp(new Node<T>(data));
		  head.swap(temp);
		  head->set_next(temp);
		  temp->set_prev(head);
		  return 2;
	 }
	 return 1 + insert(head->get_next(), head, data);
}



// Displays all DLL objects
template <typename T>
int DLL<T>::display(void) const
{
	 if(!head)
		  return 0;
	 return display(head);	
}



// Private recursive copy helper function
template <typename T>
int DLL<T>::copy(shared_ptr<Node<T>>& curr, shared_ptr<Node<T>>& prev, const shared_ptr<Node<T>>& source)
{
	 if (!source)
		  return 0;

	 shared_ptr<Node<T>> temp(new Node<T>(source->get_data()));
	 curr = temp;
	 curr->set_prev(prev);
	 tail = curr;
	 return 1 + copy(curr->get_next(), curr, source->get_next());
}



// Private insert recursive helper function
template <typename T>
int DLL<T>::insert(shared_ptr<Node<T>>& curr, shared_ptr<Node<T>>& prev, const T& to_add)
{
	 shared_ptr<Node<T>> temp(new Node<T>(to_add));
	 // If we have reached the end go ahead and add - we are the largest
	 if (!curr)
	 {
		  curr = temp;
		  curr->set_prev(prev);
		  tail = curr;
		  return 1;
	 }
	 // If we are larger than what we are adding - stop - and add before us
	 if (curr->greater(to_add))
	 {
		  curr->set_prev(temp);	
		  temp->set_next(curr);
		  prev->set_next(temp);
		  temp->set_prev(prev);
		  return 1;

	 }

	 return 1 + insert(curr->get_next(),curr, to_add);
}



// Private display recursive helper function
template <typename T>
int DLL<T>::display(const shared_ptr<Node<T>>& curr) const
{
	 if (!curr)
		  return 0;
	 curr->display();
	 cout << endl;
	 return 1 + display(curr->get_next());
}

