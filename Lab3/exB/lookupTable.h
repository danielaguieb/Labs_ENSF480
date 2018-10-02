// LookupTable.h
// ENSF 480 - Fall 2018 - Lab 3, Ex B
// M. Moussavi: Sept 26, 2018

#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H
#include <iostream>

using namespace std;

// class LookupTable: GENERAL CONCEPTS
//
//    key/datum pairs are ordered.  The first pair is the pair with
//    the lowest key, the second pair is the pair with the second
//    lowest key, and so on.  This implies that you must be able to
//    compare two keys with the < operator.
//
//    Each LookupTable has an embedded iterator class that allows users
//    of the class to traverse trhough the list and  have acess to each
//    node. 

#include "customer.h"
typedef int LT_Key; 
typedef Customer LT_Datum;
 
template <class K, class D>
struct Pair 
{
  //constructor
  Pair(K keyA, D datumA):key(keyA), datum(datumA)
  {
  } 
  
  K key;
  D datum;
};


// no need for templating? A: no
template <class K, class D> class LT_Node;

template <class K, class D>
class LT_Node {
  friend class LookupTable;
private:
  Pair<K, D> pairM;
  LT_Node *nextM;

  // This ctor should be convenient in insert and copy operations.
  LT_Node(const Pair<K,D>& pairA, LT_Node *nextA);
};


template <class K, class D> class LookupTable;

template <class K, class D>
class LookupTable {
 public:
  // Nested class
  class Iterator {
    friend class LookupTable;
    LookupTable<K,D> *LT;
      
  public:
    Iterator():LT(0){}
    Iterator(LookupTable<K,D>& x): LT(&x){}    
    const D&  operator *();
    const D& operator ++();
    const D& operator ++(int);
    int operator !();

    void step_fwd(){  assert(LT->cursor_ok());
    LT->step_fwd();}
  }; // End of class Iterator

  LookupTable();
  LookupTable(const LookupTable<K,D>& source);
  LookupTable<K,D>& operator =(const LookupTable<K,D>& rhs);
  ~LookupTable();

  LookupTable<K,D>& begin();

  int size() const;
  // PROMISES: Returns number of keys in the table.

  int cursor_ok() const;
  // PROMISES: 
  //   Returns 1 if the cursorM is attached to a key/datum pair,
  //   and 0 if the cursorM is in the off-list state.

  const K& cursor_key() const;
  // REQUIRES: cursor_ok()
  // PROMISES: Returns key of key/datum pair to which cursorM is attached.

  const D& cursor_datum() const;
  // REQUIRES: cursor_ok()
  // PROMISES: Returns datum of key/datum pair to which cursorM is attached.

  void insert(const Pair<K,D>& pariA);
  // PROMISES:
  //   If keyA matches a key in the table, the datum for that
  //   key is set equal to datumA.
  //   If keyA does not match an existing key, keyA and datumM are
  //   used to create a new key/datum pair in the table.
  //   In either case, the cursorM goes to the off-list state.

  void remove(const K& keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the corresponding
  //   key/datum pair is removed from the table.
  //   If keyA does not match an existing key, the table is unchanged.
  //   In either case, the cursorM goes to the off-list state.

  void find(const K& keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the cursorM is attached
  //   to the corresponding key/datum pair.
  //   If keyA does not match an existing key, the cursorM is put in
  //   the off-list state.

  void go_to_first();
  // PROMISES: If size() > 0, cursorM is moved to the first key/datum pair
  //   in the table.

  void step_fwd();
  // REQUIRES: cursor_ok()
  // PROMISES: 
  //   If cursorM is at the last key/datum pair in the list, cursorM
  //   goes to the off-list state.
  //   Otherwise the cursorM moves forward from one pair to the next.

  void make_empty();
  // PROMISES: size() == 0.
  
  friend  ostream& operator << <K,D> (ostream& os, const LookupTable<K,D>& lt);

 private:
  int sizeM;
  LT_Node<K, D> *headM;
  LT_Node<K, D> *cursorM;

  void destroy();
  // Deallocate all nodes, set headM to zero.
  
  void copy(const LookupTable<K,D>& source);
  // Establishes *this as a copy of source.  cursorM of *this will
  // point to the twin of whatever the source's cursor points to.
};
#endif

template <class K, class D>
LookupTable<K, D>& LookupTable<K,D>::begin(){
  cursorM = headM;
  return *this;
}

template <class K, class D>
LT_Node<K,D>::LT_Node(const Pair<K,D>& pairA, LT_Node<K, D> *nextA)
  : pairM(pairA), nextM(nextA)
{
}

template <class K, class D>
LookupTable<K,D>::LookupTable()
  : sizeM(0), headM(0), cursorM(0)
{
}

template <class K, class D>
LookupTable<K,D>::LookupTable(const LookupTable<K,D>& source)
{
  copy(source);
}

template <class K, class D>
LookupTable<K,D>& LookupTable<K,D>::operator =(const LookupTable<K,D>& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

template <class K, class D>
LookupTable<K,D>::~LookupTable()
{
  destroy();
}

template <class K, class D>
int LookupTable<K,D>::size() const
{
  return sizeM;
}

template <class K, class D>
int LookupTable<K,D>::cursor_ok() const
{
  return cursorM != 0;
}

template <class K, class D>
const K& LookupTable<K,D>::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->pairM.key;
}

template <class K, class D>
const D& LookupTable<K,D>::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->pairM.datum;
}

template <class K, class D>
void LookupTable<K,D>::insert(const Pair<K,D>& pairA)
{
  // Add new node at head?
  if (headM == 0 || pairA.key < headM->pairM.key) {
    headM = new LT_Node<K,D>(pairA, headM);
    sizeM++;
  }

  // Overwrite datum at head?
  else if (pairA.key == headM->pairM.key)
    headM->pairM.datum = pairA.datum;

  // Have to search ...

  else {
    LT_Node<K,D>* before= headM;
    LT_Node<K,D>* after=headM->nextM;

    while(after!=NULL && (pairA.key > after->pairM.key))
      {
	before=after;
	after=after->nextM;
      }
    
    if(after!=NULL && pairA.key == after->pairM.key)
      {
	after->pairM.datum = pairA.datum;
      }
    else
      {
	before->nextM = new LT_Node<K,D>(pairA, before->nextM);
	sizeM++;
      }
  }
}

template <class K, class D>
void LookupTable<K,D>::remove(const K& keyA)
{

  if (headM == 0 || keyA < headM->pairM.key)
    return;

  LT_Node<K,D>* doomed_node = 0;
  if (keyA == headM->pairM.key) {
    doomed_node = headM;
    headM = headM->nextM;
    sizeM--;
  }
  else {
    LT_Node<K,D> *before = headM;
    LT_Node<K,D> *maybe_doomed = headM->nextM;
    while(maybe_doomed != 0 && keyA > maybe_doomed->pairM.key) {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->nextM;
    }

    if (maybe_doomed != 0 && maybe_doomed->pairM.key == keyA) {
      doomed_node = maybe_doomed;
      before->nextM = maybe_doomed->nextM;
      sizeM--;
    }      
  } 
  delete doomed_node;           // Does nothing if doomed_node == 0.
}

template <class K, class D>
void LookupTable<K,D>::find(const K& keyA)
{
  LT_Node<K,D> *ptr=headM;
  while (ptr!=NULL && ptr->pairM.key != keyA)
    {
     ptr=ptr->nextM;

    }
   cursorM = ptr;
}

template <class K, class D>
void LookupTable<K,D>::go_to_first()
{
  cursorM = headM;
}

template <class K, class D>
void LookupTable<K,D>::step_fwd()
{
  assert(cursor_ok());
  cursorM = cursorM->nextM;
}

template <class K, class D>
void LookupTable<K,D>::make_empty()
{
  destroy();
  sizeM = 0;
  cursorM = 0;
}

template <class K, class D>
void LookupTable<K,D>::destroy()
{

  LT_Node<K,D> *ptr = headM;
  while (ptr!=NULL)
    {
      headM=headM->nextM;
      delete ptr;
      ptr=headM;

    }
  cursorM = NULL;
  sizeM=0;
}

template <class K, class D>
void LookupTable<K,D>::copy(const LookupTable& source)
{

  headM=0;
  cursorM =0;

  if(source.headM ==0)
    return; 

  for(LT_Node<K,D> *p = source.headM; p != 0; p=p->nextM)
    {
      insert(Pair<K,D> (p->pairM.key, p->pairM.datum));
      if(source.cursorM == p)
	find(p->pairM.key);
    }
}


// TODO what is wrong with this
template <class K, class D>
ostream& operator << <K,D> (ostream& os, const LookupTable<K,D>& lt)
{
  if (lt.cursor_ok())
    os <<lt.cursor_key() << "  " << lt.cursor_datum();
  else
    os<<"Not Found.";

  return os;
}

template <>
ostream& operator << <int, Customer> (ostream& os, const LookupTable<int, Customer>& lt)
{
  if (lt.cursor_ok())
    os <<lt.cursor_key() << "  " << lt.cursor_datum();
  else
    os<<"Not Found.";

  return os;
}

template <> 
ostream& operator << <,D> (ostream& os, const LookupTable<K,D>& lt)
{
  if (lt.cursor_ok())
    os <<lt.cursor_key() << "  " << lt.cursor_datum();
  else
    os<<"Not Found.";

  return os;
}



template <class K, class D>
const D& LookupTable<K,D>::Iterator::operator *()
{
  assert(LT ->cursor_ok());
  return LT->cursor_datum();
}

template <class K, class D>
const D& LookupTable<K,D>::Iterator::operator ++()
{
  assert(LT->cursor_ok());
  const D& x = LT->cursor_datum();
  LT->step_fwd();
  return x;
}

template <class K, class D>
const D& LookupTable<K,D>::Iterator::operator ++(int)
{
  assert(LT->cursor_ok());
 
  LT->step_fwd();
  return LT->cursor_datum();
}

template <class K, class D>
int LookupTable<K,D>::Iterator::operator!()
{
  return (LT->cursor_ok());
}


