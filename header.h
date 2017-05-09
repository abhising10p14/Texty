

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class Hash
{

private:
  static const int tableSize = 1000001;

  typedef struct item
  {
    string word;
    //string def;
    item *next;
  } *itemPtr;

  itemPtr HashTable[tableSize];


public:
  int hash (string key);
    Hash ();
  void addItem (string word);
  int numberOfItemsInIndex (int index);
  //void printTable ();
  void printItemsInIndex (int index);
  bool searchForWord (string word);
  void printIndex (int index);
  void findMinimum ();
  void findMaximum ();
};


#endif
