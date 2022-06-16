#include <iostream>
#include "Trie.h"

int main()
{
	//создаем дерево
TrieNode* trie = getNewNode();

insertInTrie(trie, "cat");
insertInTrie(trie, "call");
insertInTrie(trie, "cantalope");
insertInTrie(trie, "cult");
insertInTrie(trie, "culture");
insertInTrie(trie, "run");
insertInTrie(trie, "rut");
insertInTrie(trie, "a");
insertInTrie(trie, "answer");
insertInTrie(trie, "antilopa");
insertInTrie(trie, "hero");
insertInTrie(trie, "heroplain");

//выбираем префикс
string trial = "ca";

//помещаем результат работы функции в строку
string tmp = GenerateWord(trie, trial);

//выводм результат
cout << tmp << endl;

return 0;
}

