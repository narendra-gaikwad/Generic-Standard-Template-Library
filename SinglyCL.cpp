#include<iostream>
using namespace std;

template <typename T>
struct node
{
    T data;
    struct node *next;
   
};

template <class T>
class SinglyCL
{
private:
   node <T>* first;
  node <T>* last;
    int size;
    
public:
    SinglyCL();
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
   SinglyCL<T>::SinglyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }
    
    template <class T>
    void SinglyCL<T>:: Display()
    {
      node <T> * temp = first;
        
        if((first == NULL) && (last == NULL))
        {
            return;
        }
        
        do
        {
            cout<<"|"<<temp->data<<"|-> ";
            temp = temp->next;
        }while(temp != last->next);
        
        cout<<"\n";
    }
    
    template <class T>
    int SinglyCL<T>:: Count()
    {
        return size;
    }
    

    template <class T>
    void SinglyCL<T>:: InsertFirst(T no)
    {
      node <T> * newn = new node<T>; 
        
        newn->data = no;
        newn->next = NULL;
        
        if((first == NULL) && (last == NULL))
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        
        last->next = first;
        size++;
    }
    
    template <class T>
    void SinglyCL<T>:: InsertLast(T no)
    {
       node <T> * newn = new node<T>; 
        
        newn->data = no;
        newn->next = NULL;
        
        if((first == NULL) && (last == NULL))
        {
            first = newn;
            last = newn;
        }
        else
        {
            last->next = newn;
            last = newn;
        }
        
        last->next = first;
        size++;
    }
    
    template <class T>
    void SinglyCL<T>:: InsertAtPos(T no, int ipos)
    {
        if((ipos < 1) || (ipos > (size+1)))
        {
            return;
        }
        
        if(ipos ==1)
        {
            InsertFirst(no);
        }
        else if(ipos == size+1)
        {
            InsertLast(no);
        }
        else
        {
             node <T> * newn = new node<T>; 
            
            newn->data = no;
            newn->next = NULL;
            
                node <T>* temp = first;
                
            
            for(int i = 1; i < ipos-1; i++)
            {
                temp = temp->next;
            }
            
            newn->next = temp->next;
            temp->next = newn;
            
            size++;
        }
    }
    
    template <class T>
    void SinglyCL<T>:: DeleteFirst()
    {
           node <T> * temp = first;
        if((first == NULL) && (last == NULL))
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            first = first->next;
            delete last->next;
            last->next = first;
        }
        size--;
    }
    
    template <class T>
    void SinglyCL<T>:: DeleteLast()
    {
       node <T>* temp = first;
        
        if((first == NULL) && (last == NULL))
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            while(temp->next != last)
            {
                temp = temp -> next;
            }
            
            delete last;
            last = temp;
                
            last->next = first;
        }
        size--;
    }
    
    template <class T>
    void SinglyCL<T>:: DeleteAtPos(int ipos)
    {
            node <T> * newn = new node<T>;  
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
            node <T>*temp = first;
            for(int i = 1; i < ipos-1; i++)
            {
                temp = temp->next;
            }
            
           node <T>* targated =  temp->next;
            
            temp->next = targated->next;    // temp->next = temp->next->next;
            delete targated;
            
            size--;
        }
        
    }


int main()
{
       int iret = 0;
  SinglyCL <char>cobj2;
    
    
    cobj2.InsertFirst('A');
    cobj2.InsertFirst('B');
    cobj2.InsertFirst('C');
    cobj2.InsertLast('D');
    cobj2.InsertLast('E');

    cobj2.DeleteAtPos(3);
    cobj2.DeleteLast();
    
    cobj2.Display();
    
    iret = cobj2.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";


////////////////////////////////////////////////


    SinglyCL <int>iobj2;
 
    
    iobj2.InsertFirst(51);
    iobj2.InsertFirst(21);
    iobj2.InsertFirst(11);
    
    iobj2.InsertLast(101);
    
    iobj2.InsertAtPos(55,4);
    
    iobj2.Display();
    iret = iobj2.Count();
    cout<<"Number of elements are : "<<iret<<"\n";
    
    iobj2.DeleteAtPos(4);
    
    iobj2.DeleteFirst();
    iobj2.DeleteLast();
    
    iobj2.Display();
    iret = iobj2.Count();
    cout<<"Number of elements are : "<<iret<<"\n";
    
    return 0;
}
