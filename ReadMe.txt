Input data will be a text file of the U.S. constitution and its amendments.

Enter the input file’s words into the map and hash tables.
Store with each word its frequency count how many times it appears in the input text.
In other words, the purpose of each map or hash table is to store, update, and enable
access to the number of times each word occurs in the input file. For example, after processing the input file
, if you look up the word “president” (using the word as the key), you should get the value 121 (which is how many times the word appears in the file). You will also count the total number of probes it took to search for words in each hash table.