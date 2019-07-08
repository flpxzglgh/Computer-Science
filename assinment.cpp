#include <iostream>

using namespace std;

template <class EType>
class Node
{
	public:
    EType data;
    Node * next;
    Node():next(NULL){}
};

template <class ElementType>
class List_Linked
{
public:

	List_Linked(): mySize(0)
	{
	}


    /***** empty operation *****/
	bool empty() const
	{
		return mySize == 0;
	}


    /***** insert and erase *****/


	void insert_before_node(ElementType item){
		Node<ElementType> * newnode = new Node<ElementType>;
		newnode->data = item;
		Node<ElementType> * curnode = first;
				int curind = 0;
			
				while(curnode != NULL && curind < pos-1)
				{
					curnode = curnode->next;
					curind ++;
				}
			
				newnode->next = curnode->next;
				curnode->next = newnode;
				mySize++;

	}
	void insert_after_node(ElementType item){

	}

void delete_before_node(int pos){

}
void delete_after_node(int pos){

}


	void insert(ElementType item, int pos)
	{
		if (!is_pos_legal(pos,true))
		{
			return;
		}

		Node<ElementType> * newnode = new Node<ElementType>;
		newnode->data = item;

		if (empty())
			first = newnode;
		else
		{
			if(pos == 0)
			{
				newnode->next = first;
				first = newnode;
			}
			else if(pos == mySize)
			{
				Node<ElementType> * curnode = first;
			
				while(curnode->next != NULL)
				{
					curnode = curnode->next;
				}
				curnode->next = newnode;
			}
			else
			{
				Node<ElementType> * curnode = first;
				int curind = 0;
			
				while(curnode != NULL && curind < pos-1)
				{
					curnode = curnode->next;
					curind ++;
				}
			
				newnode->next = curnode->next;
				curnode->next = newnode;
			}        
		}
		mySize++;
	}

	void erase(int pos)
	{
		if (!is_pos_legal(pos))
		{
			return;
		}
	
		if(pos == 0)
		{
			Node<ElementType> * temp = first;
			first = first->next;
			delete temp;
		}
		else if(pos == mySize-1)
		{
			Node<ElementType> * curnode = first;
			while(curnode->next->next != NULL)
			{
				curnode = curnode->next;
			}
			Node<ElementType> * temp = curnode->next;
			curnode->next = NULL;
			delete temp;
		}
		else
		{
			Node<ElementType> * curnode = first;
			int curind = 0;
			while(curnode != NULL && curind < pos-1)
			{
				curnode = curnode->next;
				curind++;
			}
			Node<ElementType> * temp = curnode->next;
			curnode->next = temp->next;
			delete temp;
		}
		mySize--;
	}    
	
    /***** output *****/
	void display(ostream & out) const
	{
		Node<ElementType> * temp = first;
		while(temp != NULL)
		{
			out << temp->data << " | ";    	
			temp = temp->next;
		}
	}    
    /***** access to existing element  *****/    
	bool is_pos_legal(int pos,bool insert=false)
	{
		if(insert)
		{
			if (pos < 0 || pos > mySize)
			{
				cerr << "Illegal location to insert -- " << pos
				<< ".  List_Linked unchanged. ***\n";
				return false;
			}
			else
				return true;
		}
		else
		{
			if (pos < 0 || pos >= mySize)
			{
				cerr << "Illegal location to erase -- " << pos
				<< ".  List_Linked unchanged. ***\n";
				return false;
			}
			else
				return true;        
		}
	}
    
private:
    int mySize;                     // current size of List_Linked stored
    Node<ElementType> * first;
};

//--- Definition of output operator
template <class ElementType>
ostream & operator<< (ostream & out, const List_Linked<ElementType> & aList_Linked)
{
    aList_Linked.display(out);
    return out;
}



int main()
{
	cout << "========== list1  =========\n";
	List_Linked<double> mylist;
	mylist.insert(5.7,0);
	mylist.insert(10.4,1);	
	cout << mylist << endl;
	
	cout << "========== list1 erase val  =========\n";	
	mylist.erase(0);
	cout << mylist << endl;

	cout << "========== list2  =========\n";	
	List_Linked<double> mylist1 = mylist;
	mylist1.insert(0.5,0);
	mylist1.insert(0.2,1);
	cout << mylist1 << endl;
	

	
	
	return 0;
}
