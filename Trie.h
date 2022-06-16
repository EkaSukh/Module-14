#pragma once
#include <iostream>
#include <vector>
//using namespace std;

#define ALPHABET_SIZE 26

//структура узла
struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// принимает значене true, если ключ €вл€етс€ концом слова
	bool isEndOfWord;
};

//создание новог узла
TrieNode* getNewNode(void);

//вставка слова в дерево
void insertInTrie(TrieNode* root, std::string key);


//поиск слова в дереве
bool searcWord(TrieNode* root, std::string key);

//поиск префикса
bool search(TrieNode* root, std::string key);


//последний узел (не имеет потомков)
bool isEmpty(TrieNode* root);

//удаление слова из дерева
TrieNode* remove(TrieNode* root, std::string key, int depth);

//вычисление частоты участи€ ключа в различных словах дерева
int friquency(TrieNode* node);

//поиск минимального префикса слова
void findMinPrefixes(TrieNode* root, char buf[], int ind, std::string& res);

//возвращает указатель на узел последнего символа введенного префикса
TrieNode* getStart(TrieNode* root, const std::string key);

//заполн€ет вектор вариантов оканчиний префикса
void findEndsOfWords(TrieNode* start, char buf[], int ind, const std::string& key, std::vector<std::string>& storage);


//конструирует вектор вариантов полных слов от введенного префикса
//возвращает успешность работы
bool constructVariants(TrieNode* root, const std::string key, std::vector<std::string>& variants);

//распечатывает вектор вариантов
void printVariants(const std::vector<std::string>& variants);


//позвол€ет увидеть возможные варианты слов с данным префиксом
//возвращает выбранное слово (и может быть использована дл€ формировани€ потока вывода)
std::string GenerateWord(TrieNode* root, const std::string key);

//поддерживает пользовательский ввод и контролируемый выход из функции
void autocomleteInterface(TrieNode* root);
