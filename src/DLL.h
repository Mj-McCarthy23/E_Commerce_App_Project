//
//  DLL.h
//  E-commerce-Project
//
//  Created by Micahel McCarthy and Anton David Guaman Davila on 2022-07-27.
//
#include <string>

using namespace std;


#ifndef DLL_h
#define DLL_h

// Node Class Begins
template < typename T >
  class NodeDLL {
    public:
      // Creation of data
      T data;
    // Creation of pointer to next node
    NodeDLL < T > * next;
    // Creation of pointer to previous node
    NodeDLL < T > * prev;

    NodeDLL(T new_data) {
      this -> data = new_data;
      next = NULL;
      prev = NULL;
    }
  };
// Node Class Ends

// Double Linked List Class Begins
template < typename T >
  class DLL {
    public:
      NodeDLL < T > * head_ref;
    // Constructor
    DLL() {
      head_ref = NULL;
    }
    // Function to print the DLL elements
    void printDLL() {
      NodeDLL < T > * temp = head_ref;

      if (head_ref == NULL) {
        cout << "List is empty!" << endl;
      } else {
        while (temp != NULL) {
          cout << temp -> data << ", ";
          temp = temp -> next;
        }
      }
    }
    // Function that inserts data to the begining of the DLL and returns a node
    // The function returns a node to facilitate deleting nodes
    NodeDLL < T > * pushDLL(T new_data) {
      NodeDLL < T > * new_node = new NodeDLL(new_data);
      if (head_ref == NULL) {
        // Make the new node next equal to the head reference
        new_node -> next = head_ref;
        // Make the head reference equal the new node
        head_ref = new_node;
        // Make the previous of the new node equal to NULL
        new_node -> prev = NULL;
      } else {
        // Make the new node next equal the head reference
        new_node -> next = head_ref;
        // Make the previous of head reference to the new node
        head_ref -> prev = new_node;
        // Make head reference point to the new node
        head_ref = new_node;
        // Make the previous node of the new_node point to NULL
        new_node -> prev = NULL;
      }
      return new_node;
    }
    // Function to delete nodes of the DLL adapted from Pesudo Code given in the
    // slides (Lecture 7 pg 16)
    void deleteNodepseudoDLL(NodeDLL < T > * nodedelete) {
      // Check if DLL is empty
      if (head_ref == NULL || nodedelete == NULL) {
        if (nodedelete == NULL && head_ref != NULL) {
          cout << "Nothing was deleted." << endl;
        } else {
          cout << "Nothing to be deleted. DLL is empty." << endl;
        }
        return;
      } else {
        // Address situation if head reference is being deleted
        NodeDLL < T > * curr = head_ref;
        NodeDLL < T > * prev = NULL;
        // Traverse through the DLL
        while (curr != nodedelete) {
          prev = curr;
          curr = curr -> next;
        }
        // Check if the node found is the only node in the list
        if (curr == nodedelete && curr -> next == NULL && curr -> prev == NULL &&
          curr == head_ref) {
          // Update the head reference to the next node
          head_ref = NULL;
          free(curr);
          cout << "Head node was deleted. Head node was the only node in the DLL" <<
            endl;
          return;
        }
        // Check if the node deleted is the first node and the DLL has more nodes
        else if (curr == head_ref) {
          head_ref = head_ref -> next;
          // Make sure the previous of the head reference is pointing to NULL
          head_ref -> prev = NULL;
          cout << "Head node was deleted. Head node was not the only node in the "
          "DLL" <<
          endl;
          delete curr;
        }
        // Check if the node deleted is the last node
        else if (curr -> next == NULL) {
          prev -> next = NULL;
          cout << "Last node was deleted" << endl;
          free(curr);
        }
        // Address the last situation where the node is not in the front or end of
        // the DLL
        else {
          prev -> next = curr -> next;
          (curr -> next) -> prev = curr -> prev;
          cout << "Node deleted. Found within the DLL. Not head or last node." <<
            endl;
          delete curr;
        }
      }
    }
    // Function to delete Node given from Lecture Slides (Lecture 7 pg 26)
    void deleteNodeDLL(NodeDLL < T > * nodedelete) {
      // Check if DLL is empty
      if (head_ref == NULL || nodedelete == NULL) {
        if (nodedelete == NULL && head_ref != NULL) {
          cout << "Nothing was deleted." << endl;
        } else {
          cout << "Nothing to be deleted. DLL is empty." << endl;
        }
        return;
      }
      // Check if the node deleted is the head of DLL
      if (head_ref == nodedelete) {
        head_ref = nodedelete -> next;
        cout << "Head node was deleted." << endl;
      }
      // Change next if node to be deleted is not the last node on the DLL
      if (nodedelete -> next != NULL) {
        (nodedelete -> next) -> prev = nodedelete -> prev;
        cout << "Node deleted is not the last Node." << endl;
      }
      // Change prev if node to be deleted is not the head node on the DLL
      if (nodedelete -> prev != NULL) {
        (nodedelete -> prev) -> next = nodedelete -> next;
        cout << "Node deleted is not the first Node." << endl;
      }
      // Free space
      free(nodedelete);
      return;
    }
    // Function to delete nodes of the DLL adapted from Pesudo Code given in the
    // slides (Lecture 7 pg 16)
    //The value passed
    void deletevalueDLL(T key) {
        // Check if DLL is empty
        if (head_ref == NULL || key == NULL) {
          if (head_ref == NULL) {
            cout << "Nothing to be deleted. DLL is empty." << endl;
          } else {
            cout << "Nothing was deleted. Key parameter is NULL" << endl;
          }
          return;
        } else {
          // Address situation if head reference is being deleted
          NodeDLL < T > * curr = head_ref;
          NodeDLL < T > * prev = NULL;
          // Traverse through the DLL
          while (curr -> data != key) {
            prev = curr;
            curr = curr -> next;
            //Address situation where the key is not withing the SLL
            if (curr == NULL) {
              cout << "The key is not inside the SLL" << endl;
              return;
            }

          }
          // Check if the node found is the only node in the list
          if (curr -> data == key && curr -> next == NULL && curr -> prev == NULL &&
            curr == head_ref) {
            // Update the head reference to NULL
            head_ref = NULL;
            free(curr);
            cout << "Head node was deleted. Head node was the only node in the DLL" <<
              endl;
            return;
          }
          // Check if the node deleted is the first node and the DLL has more nodes
          else if (curr == head_ref) {
            head_ref = head_ref -> next;
            // Make sure the previous of the head reference is pointing to NULL
            head_ref -> prev = NULL;
            cout << "Head node was deleted. Head node was not the only node in the "
            "DLL" <<
            endl;
            delete curr;
          }
          // Check if the node deleted is the last node
          else if (curr -> next == NULL) {
            prev -> next = NULL;
            cout << "Last node was deleted" << endl;
            free(curr);
          }
          // Address the last situation where the node is not in the front or end of
          // the DLL
          else {
            prev -> next = curr -> next;
            (curr -> next) -> prev = curr -> prev;
            cout << "Node deleted. Found within the DLL. Not head or last node." <<
              endl;
            delete curr;
          }
        }
      }
      // Destructor
      ~DLL() {
        NodeDLL < T > * curr = head_ref;
        NodeDLL < T > * prev = NULL;
        // Traverse through the DLL
        while (curr != NULL) {
          // Update curr and prev
          prev = curr;
          curr = curr -> next;
          delete curr;
        }
      }
  };
// Double Linked List Class Ends

#endif /* DLL_h */
