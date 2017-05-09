#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "header.h"
#include<QFile>
#include<QTextStream>

Hash::Hash ()
{		//Constructor creates initial table and reads in file info
   // cout<<"constructor chala re "<<endl;
  for (int i = 0; i < tableSize; i++)
    {
      HashTable[i] = new item;
      HashTable[i]->word = "empty";
      //HashTable[i]->def = "empty";
      HashTable[i]->next = NULL;
    }

  /*ifstream inFile ("words.txt");
  string word;
  string def = "def";

  while (!inFile.eof ())
    {
      inFile >> word;
      addItem (word);
    }*/
  QFile f("/home/abhisingh10p14/-Text-Editor/words.txt");
  f.open(QIODevice::ReadOnly);
  QTextStream textStream(&f);
  if(!f.exists()) //For checking if the file is open or not also checking if the file is read only and is a text file
  {
    cout<<"dictonary does not exists"<<endl;
  }
  while (!f.atEnd()) {
          QString line = textStream.readLine();
           string str = line.toStdString();
           addItem (str);
      }

}

int
Hash::hash (string key)
{		//Hash function decides which bucket to place item
  int hash = 0;
  int index;
  unsigned  int i;
  for ( i = 0; i < key.length (); i++)
    {
      hash = hash + ((int) key[i]) * 5;
    }
  //cout << endl;

  index = hash % tableSize;

  return index;

}

void
Hash::addItem (string word)
{		//Function manually adds item to the tree
  //cout<<"Yaha"<<endl;
  int index = hash (word);

  if (HashTable[index]->word == "empty")
    {		// if table is empty
      HashTable[index]->word = word;

    }
  else
    {
      itemPtr n = HashTable[index];
      itemPtr p = new item;
      p->word = word;
      //p->def = def;
      p->next = NULL;

      while (n->next != NULL)
    {
      n = n->next;
    }
      n->next = p;
    }

}

int
Hash::numberOfItemsInIndex (int index)
{		//returns # of items in a bucket
  int count = 0;

  if (HashTable[index]->word == "empty")
    {
      return count;
    }
  else
    {
      count++;
      itemPtr p = HashTable[index];
      while (p->next != NULL)
    {
      count++;
      p = p->next;
    }
    }
  return count;


}

void
Hash::findMinimum ()
{		//Finds bucket with least amount of items in table
  int minimum = 2000;

  for (int i = 0; i < tableSize; i++)
    {
      if (numberOfItemsInIndex (i) < minimum)
    {
      minimum = numberOfItemsInIndex (i);
    }

    }

  cout << "Bucket with the least amount of items contains " << minimum <<
    " items." << endl;

}

void
Hash::findMaximum ()
{		//Finds bucket with most items in table
  int maximum = 0;

  for (int i = 0; i < tableSize; i++)
    {
      if (numberOfItemsInIndex (i) > maximum)
    {
      maximum = numberOfItemsInIndex (i);
    }
    }

  cout << "Bucket with the greatest amount of items contains " << maximum <<
    " items." << endl;

}





bool
Hash::searchForWord (string word)
{		//Finds user-entered word in hash table

  for (int i = 0; i < tableSize; i++)
    {
      itemPtr p = HashTable[i];
      while (p != NULL)
    {
      if (p->word == word)
        {
           return true;
        }
      else
        {
          p = p->next;
        }

    }


    }
     return false;


}

void
Hash::printItemsInIndex (int index)
{		//prints all contents of a bucket
  itemPtr p = HashTable[index];

  if (p->word == "empty")
    {
      cout << "Index = " << index << " is empty\n";
    }
  else
    {
      cout << "Index " << index << " contains the following items: \n";

      while (p != NULL)
    {
      cout << "--------------------\n";
      cout << p->word << endl;
      //cout << p->def << endl;
      cout << "--------------------\n";
      p = p->next;
    }
    }
}


void
Hash::printIndex (int index)
{		//Prints a specific index
  itemPtr p = HashTable[index];
  int number = numberOfItemsInIndex (index);

  if (p->word == "empty")
    {
      cout << "Index = " << index << " is empty\n";
    }
  else
    {
      cout << "Index " << index << " contains the following items: \n";
      cout << "--------------------\n";
      cout << p->word << endl;
     // cout << p->def << endl;
      cout << "Number of items in bucket: " << number << endl;
      cout << "--------------------\n";
    }
}
