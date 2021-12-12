#include<iostream>
using namespace std;

template <typename T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLL
{
private:
    node <T>* first;
    int size;
    
public:
    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T , int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};

template <class T>
 SinglyLL<T>::SinglyLL()
   {
       first = NULL;
       size = 0;
   }
   
    template <class T>
   void SinglyLL<T>::InsertFirst(T no)
   {
        node <T> * newn = new node<T>;  
       
       newn->data = no;
       newn->next = NULL;
       
       if(first == NULL)
       {
           first = newn;
       }
       else
       {
           newn->next = first;
           first = newn;
       }
       size++;
   }
   
    template <class T>
   void SinglyLL<T>::InsertLast(T no)
   {
        node <T> * newn = new node<T>;  
       
        newn->data = no;
        newn->next = NULL;
       
       if(first == NULL)
       {
           first = newn;
       }
       else
       {
            node <T>* temp = first;
           while(temp->next != NULL)
           {
               temp = temp->next;
           }
           temp->next = newn;
       }
       size++;
   }
   
    template <class T>
   void SinglyLL<T>::InsertAtPos(T no, int ipos)
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

        
            node <T>* temp = first;
        
        for(int i = 1; i < ipos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn->next = temp->next;
        temp->next = newn;

        size ++;
    }
   }
   
    template <class T>
   void SinglyLL<T>::DeleteFirst()
   {
        node <T> * temp = first;
       
       if(first != NULL)
       {
           first = first->next;
           delete temp;
           
           size--;
       }
   }

    template <class T>
   void SinglyLL<T>::DeleteLast()
   {
        node <T>* temp = first;
       
       if(first == NULL)
       {
           return;
       }
       else if(first->next == NULL)
       {
           delete first;
           first = NULL;
           size--;
       }
       else
       {
           while(temp->next->next != NULL)
           {
               temp = temp->next;
           }
           
           delete temp->next;
           temp->next = NULL;
           size--;
       }
   }
   
    template <class T>
   void SinglyLL<T>::DeleteAtPos(int ipos)
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
         node <T>* targated = first;
        
        for(int i = 1; i < ipos -1 ; i ++)
        {
            temp = temp -> next;
        }
       
        targated = temp -> next;
        temp -> next = targated->next;
        delete targated;
        
        size--;
    }
}

   
    template <class T>
   void SinglyLL<T>::Display()
   {
        node <T> * temp = first;
       
       while(temp!= NULL)
       {
           cout<<temp->data<<"\t";
           temp = temp->next;
       }
       cout<<"\n";
   }
   
    template <class T>
   int SinglyLL<T>::Count()
   {
       return size;
   }

/////////////////////////////////////////////
 
int main()
{
    int iret = 0;

    SinglyLL <char>cobj1;
    
    
    cobj1.InsertFirst('A');
    cobj1.InsertFirst('B');
    cobj1.InsertFirst('C');
    cobj1.InsertLast('D');
    cobj1.InsertLast('E');
    
    cobj1.Display();
    
    iret = cobj1.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
    
    /////////////////////////////////////////
    
    SinglyLL <int>iobj1;
     
     
     iobj1.InsertFirst(11);
     iobj1.InsertFirst(21);
     iobj1.InsertFirst(51);
     
     iobj1.InsertLast(101);
     iobj1.InsertLast(111);
     
     iobj1.Display();
     
     iret = iobj1.Count();
     cout<<"Number of elemensts are : "<<iret<<"\n";

     ///////////////////////////////////////////////////////////////////////////////////

     
    
    return 0;
}



















/*
 Type 1
 
 wihle(temp!= NULL)
 {
    temp = temp->next;
 }
 
 --------------------------------------
 
 Type 2
 
 while(temp->next != NULL)
 {
    temp = temp->next;
 }
 
 ---------------------------------------
 
 Type 3
 
while(temp->next->next != NULL)
 {
 temp = temp->next;
 }
 
 
 
 */










