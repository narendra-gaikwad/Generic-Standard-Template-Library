#include<iostream>
using namespace std;

template <typename T>
 struct node
{
    T data;
    struct node *next;
};

template <class T>
class Stack     // Singly Linear Linked List
{
    private:
                node <T>* first;
                int size;
        
    public:
                Stack();
                void push(T);
                int pop();
                void Display();
                int Count();

};

template <class T>
 Stack<T>::Stack()
   {
       first = NULL;
       size = 0;
   }

template <class T>
    void Stack<T>::push(T no)   // InsertFirst()
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
    int Stack<T>::pop()  // DeleteFirst()
    {
        int no = 0;
     node <T>* temp = first;
        
        if(size == 0)
        {
            cout<<"Stack is empty\n";
            return -1;
        }
        
        if(size == 1)
        {
            no = first->data;
            delete first;
            first = NULL;
        }
        else
        {
            no = first->data;
            first = first -> next;
            delete temp;
        }
        
        size--;
        return no;
        
    }
    
   template <class T>
   void Stack<T>::Display()
    {
        node <T> * temp = first;
        
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"|"<<"\n";
            temp = temp->next;
        }
    }
    
    template <class T>
   int Stack<T>::Count()
    {
        return size;
    }

int main()
{
      int iret1= 0;
      int iret2 = 0;
    Stack<int>obj5;
    
    obj5.push(11);
    obj5.push(21);
    obj5.push(51);
    obj5.push(101);
    
    cout<<"Elements of stack\n";
    obj5.Display();
    
     iret1 = obj5.pop();       // 101
    cout<<"Poped element is : "<<iret1<<"\n";                     // 101
    
    cout<<"Elements of stack\n";
    obj5.Display();          // 51       21      11
    iret2= obj5.Count();
    
    cout<<"Size of stack is : "<<iret2<<"\n";        // 3
    
    return 0;
}
