#include "Node.h";

class LinkedList {
  private:
    Node *head;
  public:
    LinkedList(){
      head = NULL;
    }

    ~LinkedList(){
      Node *p;
      while (head != NULL) {
        p = head;
        head = p->getNext();
        delete p;
      }
    }

    void insertValue(int _data){
      Node *n = new Node(_data); // Node you are inserting
      Node *p = head; 
      Node *prev = NULL; // prev to make sure that you connect prev -> p.next

      while (p != NULL && p->getData() < _data) {
        prev = p;
        p = p->getNext();
      }
      n->setNext(p);

      if (prev == NULL)
        head = n; // head of the list
      else
        prev->setNext(n);
    }

    bool valueExists(int _data){
      for (Node *currentNode = head; currentNode != NULL; currentNode = currentNode->getNext()){
          if (currentNode->getData() == _data)
            return true;
      }
      return false;
    }

    bool deleteValue(int _data){
      Node* p = head;
      Node* prev = NULL;
      while (p != NULL && p->getData() != _data) {
        prev = p;
        p = p->getNext();
      }
      if (p == NULL) 
        return false; // when data dne
      if (prev == NULL) 
        head = p->getNext(); // when prev is null, in other words p == head
      else
        prev->setNext(p->getNext());

      delete p;
      p = NULL;
      return true;
    }

    // Copy Constructor
    LinkedList(const LinkedList& original){
      Node* p = original.head;
      Node* np = NULL;
      head = NULL;
      while (p != NULL) {
        Node *n = new Node(p->getData());
        if (np == NULL) 
          head = n;
        else 
          np->setNext(n);
        p = p->getNext();
        np = n;
      }
    }
    
    LinkedList& operator= (const LinkedList& original){
      if (&original == this)
        return (*this);
      
      // empty the list 
      Node *p;
      if (head != NULL){ 
        p = head;
        head = p->getNext();
        delete p;
        p = NULL;
      }

      // copy list as copy constructor
      Node* p = original.head;
      Node* np = NULL;
      head = NULL;
      while (p != NULL) {
        Node *n = new Node(p->getData());
        if (np == NULL) 
          head = n;
        else 
          np->setNext(n);
        p = p->getNext();
        np = n;
      }

      return (*this);
    }
};