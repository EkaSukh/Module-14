#pragma once
#include <iostream>
#include <vector>
using namespace std;

#define ALPHABET_SIZE 26

//��������� ����
struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// ��������� ������� true, ���� ���� �������� ������ �����
	bool isEndOfWord;
};

//�������� ����� ����
TrieNode* getNewNode(void);

//������� ����� � ������
void insertInTrie(TrieNode* root, string key);


//����� ����� � ������
bool searcWord(TrieNode* root, string key);

//����� ��������
bool search(TrieNode* root, string key);


//��������� ���� (�� ����� ��������)
bool isEmpty(TrieNode* root);

//�������� ����� �� ������
TrieNode* remove(TrieNode* root, string key, int depth);

//���������� ������� ������� ����� � ��������� ������ ������
int friquency(TrieNode* node);

//����� ������������ �������� �����
void findMinPrefixes(TrieNode* root, char buf[], int ind, string& res);

//���������� ��������� �� ���� ���������� ������� ���������� ��������
TrieNode* getStart(TrieNode* root, const string key);

//��������� ������ ��������� ��������� ��������
void findEndsOfWords(TrieNode* start, char buf[], int ind, const string& key, vector<string>& storage);


//������������ ������ ��������� ������ ���� �� ���������� ��������
//���������� ���������� ������
bool constructVariants(TrieNode* root, const string key, vector<string>& variants);

//������������� ������ ���������
void printVariants(const vector<string>& variants);


//�������� ������� ��������� ������� ��������� �������� ���� � ������ ���������
//���������� ��������� ����� (� ����� ���� ������������ ��� ������������ ������ ������)
string GenerateWord(TrieNode* root, const string key);
