#include <stddef.h>

class Node {
  private:
    int data; 
    Node *next;

  public:
    Node(){ 
      data = 0; next = NULL; 
    }

    Node(int _data){ 
      data =  _data; 
      next = NULL; 
    }

    Node(int _data, Node* _next){ 
      data = _data; 
      next = _next; 
    }

    // Accessors
    int getData() const { 
      return data; 
    }

    Node *getNext() const { 
      return next; 
    }
    
    // Mutators
    void setData (int _data) { 
      data = _data; 
    }

    void setNext(Node* _next){ 
      next = _next; 
    }
};