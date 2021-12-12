#include<iostream>
using namespace std;

template <typename T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};


template <typename T>
class DoublyLL
{
private:
   node <T>* first;
  node <T>* last;
    int size;
    
public: 

    DoublyLL();
  void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
    void Display();
    int Count();

};

template <class T>
     DoublyLL<T>::DoublyLL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }

template <class T>
void DoublyLL<T>:: InsertFirst(T no)
{
    node <T> * newn = new node<T>; 
        newn->next = NULL; 
        newn->prev = NULL; 
        newn->data = no; 

        if (first== NULL) 
            { 
            first = newn;
            } 

        else 
            { 
            newn->prev = newn; 
            newn ->next = first; 
            first = newn; 
            }  
            size++;
}


template <class T>
void DoublyLL<T>:: InsertLast(T no)
{
    node <T> * newn = new node<T>;     
    node <T> * temp = first;

    newn->next = NULL; 
    newn->prev = NULL; 
    newn->data = no; 
 
    
    if (first == NULL) 
    { 
        first = newn;
    } 
 
    else 
         { 
            while(temp->next != NULL)
            { 
               temp = temp->next; 
            } 
    
                temp->next = newn; 
                newn->prev = temp; 
        } 
    size++;
}

template <class T>
void DoublyLL<T>:: InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > size+1))
    {
        return;
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == size +1)
    {
        InsertLast(no);
    }
    else
    {
        node <T> * newn = new node<T>; 
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        
            node <T>* temp = first;
        
        for(int i = 1; i < ipos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size ++;
    }
}

template <class T>
void DoublyLL<T>:: DeleteFirst()
{
    node<T>*temp = first;
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next; 
        first->prev = NULL; 
    
    delete temp; 
    }
    size--;
}


template <class T>
void DoublyLL<T>:: DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    node <T> * temp = first;

    while((temp -> next) != NULL)
    { 
    temp = temp -> next; 
    } 
 
    temp->prev->next = NULL; 
    delete temp; 
    size--;
}



template <class T>
void DoublyLL<T>:: DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > size))
    {
        return;
    }
    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
         node <T>* temp = first;
        
        for(int i = 1; i < ipos -1 ; i ++)
        {
            temp = temp -> next;
        }
       
         temp->next = temp->next->next; 
        delete temp->next->prev; 
        temp->next->prev = temp; 
        
        size--;
    }
}

template <class T>
void DoublyLL<T>::  Display()
{
           node <T> * temp = first;
    
    for(int i = 1; i <= size; i++)
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int DoublyLL<T>:: Count()
{
    return size;
}

int main()
{
         int iret = 0;
       DoublyLL <char>cobj3;
     
    
    
    cobj3.InsertFirst('A');
    cobj3.InsertFirst('B');
    cobj3.InsertFirst('C');
    cobj3.InsertLast('D');
    cobj3.InsertLast('E');
    cobj3.Display();


    cobj3.DeleteAtPos(3);
    cobj3.DeleteFirst();
    cobj3.DeleteLast();
    cobj3.Display();
    
    iret = cobj3.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
    
    /////////////////////////////////////////

    DoublyLL <int>iobj3;
    
    iobj3.InsertFirst(21);
    iobj3.InsertFirst(11);
    
    iobj3.InsertLast(51);
    iobj3.InsertLast(101);
     iobj3.InsertLast(101);
    
    iobj3.InsertAtPos(75,3);
    iobj3.Display();
    
  
    
    iobj3.DeleteAtPos(4);
    iobj3.DeleteFirst();
    iobj3.DeleteLast();
    
    iobj3.Display();
       iret = iobj3.Count();
    cout<<"Number of elements are : "<< iret<<"\n";

    return 0;
}


