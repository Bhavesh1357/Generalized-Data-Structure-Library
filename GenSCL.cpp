
#include<iostream>
using namespace std;

template <class T>
struct node
{
	T data;
	struct node *next;


};

template <class T>
class SinglyCLL
{
    public:
     
     struct node<T> *Head;
     struct node<T> *Tail;
     int Count;

	SinglyCLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int pos);
	void Display();
	int CountNode();

};

template <class T>
    SinglyCLL<T>::SinglyCLL()
    {
    	Head = NULL;
    	Tail = NULL;
    	Count=0;


    }
    template <class T>
	void SinglyCLL<T>::InsertFirst(T no)
	{
		struct node<T> *newn = NULL;
		newn = new node<T>;

		newn->data = no;
		newn->next = NULL;

		if((Head==NULL)&&(Tail==NULL))
		{
			Head = newn;
			Tail = newn;
			


		}

		else
		{
			newn->next = Head;
			Head = newn;
           
		}

		Tail->next = Head;

		Count++;
	}

	template <class T>
	void SinglyCLL<T>::InsertLast(T no)
	{
		struct node<T> *newn = NULL;
		newn = new node<T>;

		newn->data = no;
		newn->next = NULL;

		if((Head==NULL)&&(Tail==NULL))
		{
			Head = newn;
			Tail = newn;
			

		}

		else
		{
			Tail->next = newn;
			Tail = newn;
			
		}


		Tail->next = Head;

		Count++;
	}

	template <class T>
	void SinglyCLL<T>::InsertAtPos(T no,int pos)
	{
		int size = CountNode();

		if((pos<1)||(pos>(size+1)))
		{
			return;
		}

		else if(pos==1)
		{
			InsertFirst(no);
		}

		else if(pos==(size+1))
		{
			InsertLast(no);
		}


		else
		{
			struct node<T> *newn = NULL;
		    newn = new node<T>;

		    newn->data = no;
		    newn->next = NULL;

            struct node<T> *temp = Head;

            for(int i=1;i<(pos-1);i++)
            {
            	temp=temp->next;
            }


            newn->next=temp->next;
            temp->next = newn;
		}

		Count++;
	}

	template <class T>
	void SinglyCLL<T>::DeleteFirst()
	{
		if((Head==NULL)&(Tail==NULL))
		{
			return;
		}

		else if(Head==Tail)
		{
			delete Head;
			delete Tail;

			Head=NULL;
			Tail=NULL;
		}

		else
		{
			Head=Head->next;
			delete (Tail->next);
			Tail->next = Head;

		}

		Count--;
	}

	template <class T>
	void SinglyCLL<T>::DeleteLast()
	{
		if((Head==NULL)&(Tail==NULL))
		{
			return;
		}

		else if(Head==Tail)
		{
			delete Head;
			delete Tail;

			Head=NULL;
			Tail=NULL;
		}

		else
		{
			struct node<T> *temp = Head;
			while(temp->next!=Tail)
			{
				temp = temp->next;
			}

			delete (temp->next);
			Tail = temp;
			Tail->next = Head;
			
		}

		Count--;
	}

	template <class T>
	void SinglyCLL<T>::DeleteAtPos(int pos)
	{
		int size = CountNode();

		if((pos<1)||(pos>(size)))
		{
			return;
		}

		else if(pos==1)
		{
			DeleteFirst();
		}

		else if(pos==(size))
		{
			DeleteLast();
		}


		else
		{
		

            struct node <T>*temp = Head;

            for(int i=1;i<(pos-1);i++)
            {
            	temp=temp->next;
            }

            struct node<T> *tempd = temp->next;
            temp->next = temp->next->next;
            delete (tempd);


            
		}

		Count--;
	}

	template <class T>
	void SinglyCLL<T>::Display()
	{

		if((Head==NULL)&&(Tail==NULL))
		{
			return;
		}

		cout<<"Elements from linked list are :"<<endl;
	    struct node<T> *temp =Head;
		do
		{
			cout<<temp->data<<" ";
			temp=temp->next;

		}while(temp!=Head);

		cout<<endl;

	}

	template <class T>
	int  SinglyCLL<T>::CountNode()
	{
		return Count;

	}




int main()
{
	SinglyCLL<int>obj1;

    SinglyCLL<float>obj2;

    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertFirst(156);
    obj1.InsertFirst(586);
    obj1.InsertLast(51);
    obj1.InsertLast(101);

	obj1.Display();
	cout<<"no of nodes are : "<<obj1.CountNode()<<endl;

	obj1.DeleteFirst();
    obj1.DeleteLast();
	
	obj1.Display();
	cout<<"no of nodes are : "<<obj1.CountNode()<<endl;


	obj1.InsertAtPos(425,2);
	obj1.Display();
	cout<<"no of nodes are : "<<obj1.CountNode()<<endl;


	obj1.DeleteAtPos(2);
	obj1.Display();
	cout<<"no of nodes are : "<<obj1.CountNode()<<endl;



	 obj2.InsertFirst(21.11);
    obj2.InsertFirst(11.15);
    obj2.InsertFirst(156.45);
    obj2.InsertFirst(586.26);
    obj2.InsertLast(51.58);
    obj2.InsertLast(101.6);

    obj2.DeleteFirst();
    obj2.DeleteLast();
	
	obj2.Display();
	cout<<"no of nodes are : "<<obj2.CountNode()<<endl;



	obj2.InsertAtPos(425.12,3);
	obj2.Display();
	cout<<"no of nodes are : "<<obj2.CountNode()<<endl;

	obj2.InsertAtPos(42.19,4);
	obj2.Display();
	cout<<"no of nodes are : "<<obj2.CountNode()<<endl;



	obj2.DeleteAtPos(3);
	obj2.Display();
	cout<<"no of nodes are : "<<obj2.CountNode()<<endl;

	obj2.DeleteAtPos(2);
	obj2.Display();
	cout<<"no of nodes are : "<<obj2.CountNode()<<endl;

	return 0;
}