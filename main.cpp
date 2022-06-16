#include <iostream>
#include "Trie.h"

int main()
{
	//������� ������
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

//�������� �������
string trial = "ca";

//�������� ��������� ������ ������� � ������
string tmp = GenerateWord(trie, trial);

//������ ���������
cout << tmp << endl;

return 0;
}

