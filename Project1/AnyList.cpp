#include "AnyList.h"

	//constructor
AnyList::AnyList()
{
	ptrToFirst = nullptr;
	count = 0;
}

	//copy constructor
AnyList::AnyList(const AnyList& other) {
	Node *curr = other.ptrToFirst;
	while (curr != nullptr) {
		insertFront(curr->getData());
		curr = curr->getPtrToNext();
	}
}

	//move constructor
AnyList::AnyList(AnyList&& other) {
	count = other.count;
	ptrToFirst = other.ptrToFirst;
	other.ptrToFirst = nullptr;
	other.~AnyList();
}

	//copy assignment operator
AnyList& AnyList::operator=(const AnyList& other) {
	Node *curr = other.ptrToFirst;
	while (curr != nullptr) {
		insertFront(curr->getData());
		curr = curr->getPtrToNext();
	}
	return *this;
}

	//move assignment operator
AnyList& AnyList::operator=(AnyList&&other) {
	count = other.count;
	ptrToFirst = other.ptrToFirst;
	other.ptrToFirst = nullptr;
	other.~AnyList();
	return *this;
}


	//insertFront
void AnyList::insertFront(const string& newData)
{	
	ptrToFirst = new Node(newData, ptrToFirst);
	++count;
}

	//deleteNode
void AnyList::deleteNode(const string& deleteData)
{
	//Case: List is empty
	if (ptrToFirst == nullptr) 
	{
		cerr << "Cannot delete from an empty list.\n";
	}
	else 
	{
		Node *current;		   //create a pointer to traverse the list		
		bool found = false;	   //set a boolean value to keep track of 
							   //   whether the item is found or not

		//Case: The node to be deleted is the first
		if (ptrToFirst->getData() == deleteData)
		{
			current = ptrToFirst;  //set current to point to first
			ptrToFirst = ptrToFirst->getPtrToNext();	//make first be the next node						
			delete current;
			current = nullptr;
			--count;	
			found = true;
		}
		//Keep on searching the list
		else 
		{
			Node *trailCurrent;	   //create a pointer to be right behind current
			trailCurrent = ptrToFirst;		 //set trailCurrent to point to the first node
			current = ptrToFirst->getPtrToNext(); //set current to point to the second node

			while ((current != nullptr) && (!found))	//while you are not to the end of the list
			{										//   and the item has not been found
				//we already checked the first node
				//  and we know does not contain the 
				//  data we are looking for,
				//  so we look at the second node
				//  (current is pointing to that)
				if(current->getData() == deleteData)	//if current is pointing to the item
				{										//  to be deleted, delete that node

					//Case: The item was found
					trailCurrent->setPtrToNext(current->getPtrToNext());
					delete current;
					current = nullptr;
					--count;
					found = true;
				}
				else
				{
					trailCurrent = current;			//move trailCurrent forward
					current = current->getPtrToNext();	//move current forward
				}
			}			
		}
		//Case: Not found
		if (!found)
			cout << "Item to be deleted is not in the list." << endl;
	}
}

	//print
void AnyList::print() const
{
	if (ptrToFirst == nullptr) // check if list is empty
		cerr << "List is empty.";
	else
	{
		Node *current;	//create a pointer to traverse the list 
		current = ptrToFirst;	//set the current pointer to point to the first node

		while (current != nullptr)	//while the current pointer is not pointing to NULL
		{						//  that is, the current pointer has not reached the 
			//  end of the list
			cout << current->getData() << " ";	//output the data 
			current = current->getPtrToNext();		//move the current pointer forward
		}
	}
}

	//destroyList - Does not delete the list object; it only deletes the nodes.
void AnyList::destroyList()
{ 
    Node  *temp; //pointer to delete the node
	
	while (ptrToFirst != nullptr)
    {
		temp = ptrToFirst;
		ptrToFirst = ptrToFirst->getPtrToNext();
        delete temp;
		temp = nullptr;
    }

	count = 0;
}

	//destructor
AnyList::~AnyList()
{
	destroyList();
}
	//overloaded insertion operator
ostream& operator<<(ostream& out, const AnyList& other) {
	if (other.count > 0) {
		Node *curr = other.ptrToFirst;
		while (curr->getPtrToNext() != nullptr) {
			out << curr->getData() << " ";
			curr = curr->getPtrToNext();
		}
		out << curr->getData() << endl;
	}
	else out << "EMPTY" << endl;
	return out;
}