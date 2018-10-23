// Abstract Data Type Stack: 
//    data object is a stack where the most-recently-added (or top) item
//                is most-easily accessible
//    operations on a stack:
//        create an empty stack
//        delete memory or "destroy" the stack
//        add a new item as the most-recently-added or top item
//        retrieve the most-recently-added or top item from the stack and copy
//        remove the most-recently-added or top item from the stack
//        check if the stack is empty

typedef char ItemType;

class Stack
{
public: // operations are called methods or member functions
   // creates an empty stack (called the constructor)
   Stack();
   
   // destroys the stack (called the destructor)
   ~Stack();
   
   // adds a new item as the most-recently added or top item
   // pre: newItem has been assigned; stack object exists
   // post: if the stack is not full, newItem is added at the top
   //          and isAdded is true; else isAdded is false
   void push (ItemType newItem, bool& isAdded);
   
   // removes the most-recently-added or top item
   // pre: stack object exists and is not empty
   // post: most-recently added or top item has been removed from the stack 
   void pop();
   
   // copies the most-recently added or top item from the stack
   // pre: stack object exists and is not empty
   // post: top item has been copied into topItem. stack is unchanged.
   void retrieve(ItemType& topItem);
 
   // checks whether or not a stack is empty
   // pre: stack object exists
   // post: if stack object is empty then returns true; else returns false
   bool isEmpty();
   
private:

   ItemType* stackptr;
   int topIndex;
};