#include <iostream>
#include <iomanip>
#include "ChainedHT.h"
using namespace std;


ChainedHT::ChainedHT() : HashTable() {}

/**
 * Constructor. Initialize each table slot to nullptr.
//  /
*/
ChainedHT::ChainedHT(int size) : HashTable(size)
{
    
    for(int i=0;i<size;i++)
    {
        table.push_back(nullptr);
    }
}

/**
 * Destructor. Delete all the entries in the collision chains.
 */
ChainedHT::~ChainedHT()
{
}

/**
 * Search for a given table entry. Count the number of probes.
 * @param key the key of the entry to find.
 * @param probe_count the cumulative count of probes.
 * @return a pointer to the entry if found, else return nullptr.
 */
HashEntry *ChainedHT::search(const string& word, int& probe_count)
{
    int index = hash(word);
    HashNode* tempHashNode=table[index];
    
    if (tempHashNode!=nullptr)
    {
        probe_count++;
        if ((tempHashNode->entry->word)==word)
            {   
                
                return tempHashNode->entry;
            }
        while(tempHashNode->next!=nullptr)
        {
           
            tempHashNode=tempHashNode->next; 
            if ((tempHashNode->entry->word)==word)
            {probe_count++;  
                return tempHashNode->entry;}
                 probe_count++;
              
        }
    }
    return nullptr;
}


HashEntry *ChainedHT::enter(const string& word, int& probe_count)
{
    HashEntry *entry_ptr = search(word, probe_count);
    int index = hash(word);

    HashNode* tempHashNode=table[index];
    HashNode* head;
    if (entry_ptr!=nullptr)
        entry_ptr->count=(entry_ptr->count)+1;
    else
        {
            if (table[index]==nullptr)
            {
                HashEntry* newEntry_ptr=new HashEntry(word);
                HashNode* newNode_ptr=new HashNode(newEntry_ptr);
                entry_ptr=newEntry_ptr;
                table[index]=newNode_ptr;
            }   
            else
            {
                    head=tempHashNode;
                    HashEntry* newEntry_ptr=new HashEntry(word);
                    HashNode* newNode_ptr=new HashNode(newEntry_ptr);
                    entry_ptr=newEntry_ptr;
                    newNode_ptr->next=head;
                    table[index]=newNode_ptr;
            }    
            
        }
    return entry_ptr;
} 

void ChainedHT::dump() const
{
     /***** Complete this member function. *****/
    for(int i=0,len=table.size();i<len;i++)
    {
         HashNode* tempHashNode=table[i];
         if (tempHashNode!=nullptr)
            cout<<i<<":"<<endl;
        for(;tempHashNode!=nullptr;tempHashNode=tempHashNode->next)
        {
            
            cout<<'\t'<<tempHashNode->entry->count<<"-"<<tempHashNode->entry->word<<endl;
        }
    }
}

/**
 * Compute the average chain length.
 */
double ChainedHT::avg_chain_length() const
{
    /***** Complete this member function. *****/
    double chainCount=0;
    HashNode* tempHashNode;
    for(int i=0,len=get_size();i<len;i++)
    {
        tempHashNode=table[i];
        if (tempHashNode==nullptr);
        else
        {
            for(;tempHashNode!=nullptr;tempHashNode=tempHashNode->next)
            {
                chainCount++;
            }
        }
    }
    return (chainCount/get_size());
}