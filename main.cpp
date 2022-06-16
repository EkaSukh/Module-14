#include <iostream>
#include "Trie.h"

int main()
{
	//создаем дерево
TrieNode* trie = getNewNode();

insertInTrie(trie, "a");
insertInTrie(trie, "an");
insertInTrie(trie, "am");
insertInTrie(trie, "answer");
insertInTrie(trie, "antilopa");
insertInTrie(trie, "anexiety");
insertInTrie(trie, "be");
insertInTrie(trie, "ball");
insertInTrie(trie, "balloon");
insertInTrie(trie, "cat");
insertInTrie(trie, "call");
insertInTrie(trie, "cantalope");
insertInTrie(trie, "cult");
insertInTrie(trie, "culture");
insertInTrie(trie, "i");
insertInTrie(trie, "icon");
insertInTrie(trie, "run");
insertInTrie(trie, "rut");
insertInTrie(trie, "hero");
insertInTrie(trie, "heroplain");
insertInTrie(trie, "exit");
insertInTrie(trie, "explain");

autocomleteInterface(trie);

return 0;
}

