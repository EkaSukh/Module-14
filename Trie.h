#pragma once
#include <iostream>
#include <vector>
using namespace std;

#define ALPHABET_SIZE 26

//структура узла
struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// принимает значене true, если ключ является концом слова
	bool isEndOfWord;
};

//создание новог узла
TrieNode* getNewNode(void);

//вставка слова в дерево
void insertInTrie(TrieNode* root, string key);


//поиск слова в дереве
bool searcWord(TrieNode* root, string key);

//поиск префикса
bool search(TrieNode* root, string key);


//последний узел (не имеет потомков)
bool isEmpty(TrieNode* root);

//удаление слова из дерева
TrieNode* remove(TrieNode* root, string key, int depth);

//вычисление частоты участия ключа в различных словах дерева
int friquency(TrieNode* node);

//поиск минимального префикса слова
void findMinPrefixes(TrieNode* root, char buf[], int ind, string& res);

//возвращает указатель на узел последнего символа введенного префикса
TrieNode* getStart(TrieNode* root, const string key);

//заполняет вектор вариантов оканчиний префикса
void findEndsOfWords(TrieNode* start, char buf[], int ind, const string& key, vector<string>& storage);


//конструирует вектор вариантов полных слов от введенного префикса
//возвращает успешность работы
bool constructVariants(TrieNode* root, const string key, vector<string>& variants);

//распечатывает вектор вариантов
void printVariants(const vector<string>& variants);


//конечная функция позволяет увидеть возможные варианты слов с данным префиксом
//возвращает выбранное слово (и может быть использована для формирования потока вывода)
string GenerateWord(TrieNode* root, const string key);
