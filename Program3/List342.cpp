// Name: Jessica Runandy
// Date: November 7, 2019
// Program 3: Linked Lists
// Description: List 342 is a templated class for a fully ordered list which allows
// different types of objects to be stored in it.


//#include "List342.h"
//using namespace std;
//
//// Default constructor
//template <class ItemType>
//List342<ItemType>::List342() {
//  head = nullptr;
//}
//
//// Destructor
//template <class ItemType>
//List342<ItemType>::~List342() {
//  this->DeleteList();
//}
//
//// Copy constructor
//template <class ItemType>
//List342<ItemType>::List342(const List342 &source) {
//  this->head = nullptr;
//  *this = source;
//}
//
//// Assignment operator
//template <class ItemType>
//List342<ItemType> &List342<ItemType>::operator=(const List342 &source) {
//  if (this == &source) {
//    return *this;
//  }
//
//  // source, desination, and insert node
//  Node<ItemType> *sNode, *dNode, *insNode;
//
//  // If the source is empty, then return
//  sNode = source.head;
//  if (sNode == nullptr) {
//    return *this;
//  }
//
//  // Get first node on destination
//  dNode = new Node<ItemType>;
//  dNode->data = (source.head)->data;
//  this->head = dNode;
//
//  sNode = sNode->next;
//
//  // Copy the rest
//  while (sNode != nullptr) {
//    insNode = new Node<ItemType>;
//    insNode->data = sNode->data;
//    insNode->next = nullptr;
//    dNode->next = insNode;
//    dNode = dNode->next;
//    sNode = sNode->next;
//  }
//  return *this;
//}
//
//// Precondition: Object class knows how to read from a file.
//// Postcondition: Opens the file represented by the string, reads the object from file, and build
//// an ordered list. Inserts each item into the list as it reads from the file. If a list already has items,
//// add new items to the list.
//template <class ItemType>
//bool List342<ItemType>::BuildList(string fileName) {
//  ifstream inFile;
//  inFile.open(fileName);
//  if (inFile.is_open()) {
//    while (!inFile.eof()) {
//      ItemType temp;
//      inFile >> temp;
//      Insert(&temp);
//    }
//    inFile.close();
//  } else {
//    cerr << "Could not find file: " << fileName << endl;
//    return false;
//  }
//  return true;
//}
//
//// Precondition: No duplicates of an object. Insert an object in the list in the correct place.
//// Postcondition: Returns true if the insert is successful. If there is a duplicate, return false.
//template <class ItemType>
//bool List342<ItemType>::Insert(ItemType *obj) {
//  Node<ItemType>* insNode = new Node<ItemType>();
//  insNode->data = new ItemType(*obj);
//  insNode->next = nullptr;
//
//  if (isEmpty()) {
//    head = insNode;
//    return true;
//  }
//
//  // compare to 1st element
//  if (*obj < *head->data) {
//    insNode->next = head;
//    head = insNode;
//    return true;
//  } else if (*obj == *head->data) {
//    delete insNode->data;
//    delete insNode;
//    return false;
//  }
//
//  // pNode = pointer to the node
//  Node<ItemType>* pNode = head;
//  while ((pNode->next != nullptr) && ((*pNode->next->data) <= *obj)) {
//    if (*pNode->next->data == *obj) {
//      delete insNode->data;
//      delete insNode;
//      return false;
//    }
//    pNode = pNode->next;
//  }
//  insNode->next = pNode->next; //pNode->next is null
//  pNode->next = insNode;
//  return true;
//}
//
//// Removes the target item from the list.
//// Postcondition: Return the item using a second parameter passed in by the reference. If the item
//// was found and removed, return true.
//template <class ItemType>
//bool List342<ItemType>::Remove(ItemType target, ItemType &result) {
//  Node<ItemType>* pTemp;
//  Node<ItemType>* pNode;
//  if (head == nullptr) {
//    return false;
//  }
//  if (*head->data == target) {
//    pTemp = head;
//    result = *head->data;
//    head = head->next;
//    delete pTemp->data;
//    delete pTemp;
//    return true;
//  }
//  pNode = head;
//  while (pNode->next != nullptr) {
//    if (*pNode->next->data == target) {
//      result = *pNode->next->data;
//      pTemp = pNode->next;
//      pNode->next = pNode->next->next;
//      delete pTemp->data;
//      delete pTemp;
//      return true;
//    }
//    pNode = pNode->next;
//  }
//  return false;
//}
//
//// Finds the target item from the list and returns the item using a second parameter that is
//// passed in by the reference. If the item was found, return true, else return false.
//template <class ItemType>
//bool List342<ItemType>::Peek(ItemType target, ItemType &result) {
//  if (isEmpty()) {
//    return false;
//  }
//  Node<ItemType>* temp;
//
//  // checks the 1st node
//  if (*head->data == target) {
//    temp = head;
//    result = *temp->data;
//    return true;
//  }
//
//  Node<ItemType>* pNode = head;
//  while ((pNode->next != nullptr) && (*pNode->next->data != target)) {
//    pNode = pNode->next;
//  }
//  if (pNode->next == nullptr) {
//    return false;
//  }
//  temp = pNode->next;
//  result = *temp->data;
//  return true;
//}
//
//// Returns true if list is empty.
//template <class ItemType>
//bool List342<ItemType>::isEmpty() const {
//  return head == nullptr;
//}
//
//// Remove all items from the list.
//template <class ItemType>
//void List342<ItemType>::DeleteList() {
//  Node<ItemType>* temp;
//  temp = head;
//  while (temp != nullptr) {
//    Node<ItemType>* temp2 = temp;
//    temp = temp->next;
//    temp2 = nullptr;
//    delete temp2;
//  }
//  head = nullptr;
//}
//
//// Takes a sorted list and merge into the calling sorted list. At termination of function, the list passed
//// in should be empty (unless it is the calling list). No duplicates are allowed.
//template <class ItemType>
//bool List342<ItemType>::Merge(List342 &list1) {
//  Node<ItemType> *temp = head;
//  Node<ItemType> *temp2 = list1.head;
//
//  if (this->isEmpty()) {
//    head = temp2;
//    list1.head = nullptr;
//    return true;
//  }
//
//  if (list1.isEmpty()) {
//    return true;
//  }
//
//  if (*this == list1) {
//    return true;
//  }
//
//  Node<ItemType> *insert;
//  insert = list1.head;
//  while (insert != nullptr) {
//    this->Insert(insert->data);
//    insert = insert->next;
//  }
//  list1.DeleteList();
//  return true;
//}
//
//// Precondition: Lists are sorted.
//// Postcondition: Add two lists together. The returned list must also be sorted.
//template <class ItemType>
//List342<ItemType> List342<ItemType>::operator+(const List342 &other) const {
//  List342 result = *this;
//  result += other;
//  return result;
//}
//
//// Precondition: Lists are sorted.
//// Postcondition: Add two lists together. The returned list must also be sorted.
//template <class ItemType>
//List342<ItemType> &List342<ItemType>::operator+=(const List342 &other) {
//  List342<ItemType> copyList = other;
//  this->Merge(copyList);
//  return *this;
//}
//
//// Display the list and only the List object, no extra blanks, no tabs, no endl.
//// Display the items on the list in increasing order.
//template <class ItemType>
//ostream &operator<<(ostream &outStream, const List342<ItemType> &list) {
//  Node<ItemType>* temp = list.head;
//  while (temp != nullptr) {
//    ItemType temp2 = *(temp->data);
//    outStream << temp2;
//    temp = temp->next;
//  }
//  return outStream;
//}
//
//// Checks if the two lists are equal to each other. Returns true if they are equal.
//template <class ItemType>
//bool List342<ItemType>::operator==(const List342 &other) const {
//  if (isEmpty() && other.isEmpty()) {
//    return true;
//  }
//  Node<ItemType> *list1, *list2;
//  list1 = head;
//  list2 = other.head;
//  while ((list1 != nullptr) || (list2 != nullptr)) {
//    if ((list2 == nullptr) || (list1 == nullptr)) {
//      return false;
//    }
//    if (*list1->data != *list2->data) {
//      return false;
//    }
//    list1 = list1->next;
//    list2 = list2->next;
//  }
//  return true;
//}
//
//// Checks if the two lists are equal to each other. Returns true if they are not equal.
//template <class ItemType>
//bool List342<ItemType>::operator!=(const List342<ItemType> &other) const {
//  return !(*this == other);
//}
