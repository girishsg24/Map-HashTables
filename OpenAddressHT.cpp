#include <iostream>
#include <iomanip>
#include "OpenAddressHT.h"
#include "HashEntry.h"

using namespace std;

/**
 * Default constructor
 */
OpenAddressHT::OpenAddressHT() : HashTable() {}

/**
 * Constructor. Initialize each table slot to nullptr.
 */
OpenAddressHT::OpenAddressHT(int size) : HashTable(size)
{
    /***** Complete this member function. *****/
    for(int i=0,len=get_size();i<len;i++)
    {
        table.push_back(nullptr);
    }
}

/**
 * Destructor. Delete all the entries in the table.
 */
OpenAddressHT::~OpenAddressHT()
{
}

HashEntry *OpenAddressHT::get_entry(const int index) const
{
    /***** Complete this member function. *****/
    return table[index];
}

/**
 * Search for a given table entry. Count the number of probes.
 * @param key the key of the entry to find.
 * @param probe_count the cumulative count of probes.
 * @return the hash table index of the entry if found, else of an empty slot.
 */
int OpenAddressHT::search(const string& key, int& probe_count)
{
    /***** Complete this member function. *****/
    
    // Initial probe index.
    int index = hash(key);
    
    if  (table[index]==nullptr)
    {
        probe_count++;
        return index;
    }
    while(table[index]!=nullptr)
    {
        probe_count++;
        if(table[index]->word==key)
            {
            return index;
            }
        else 
            index = next_index(index);
    } 
    probe_count++;
    return index;  // of the found entry or of an empty slot
}

int OpenAddressHT::enter(const string& key, int& probe_count)
{
    // Search for the entry key.
    int index = search(key, probe_count);
    if (table[index]==nullptr)
    {
         HashEntry* newEntry_ptr=new HashEntry(key);
         table[index]=newEntry_ptr;
    }
    else
        table[index]->count=(table[index]->count)+1;
    return index;
}

/**
 * Print the contents of the hash table.
 * Skip empty table slots.
 */
void OpenAddressHT::dump() const
{
    /***** Complete this member function. *****/
    for(int i=0,len=get_size();i<len;i++)
    {
        if (table[i]!=nullptr)
        cout<<i<<":"<<'\t'<<table[i]->count<<"-"<<table[i]->word<<endl;  
    }
}
