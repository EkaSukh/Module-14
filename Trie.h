#pragma once
#include <iostream>
#include <vector>
//using namespace std;

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
void insertInTrie(TrieNode* root, std::string key);


//����� ����� � ������
bool searcWord(TrieNode* root, std::string key);

//����� ��������
bool search(TrieNode* root, std::string key);


//��������� ���� (�� ����� ��������)
bool isEmpty(TrieNode* root);

//�������� ����� �� ������
TrieNode* remove(TrieNode* root, std::string key, int depth);

//���������� ������� ������� ����� � ��������� ������ ������
int friquency(TrieNode* node);

//����� ������������ �������� �����
void findMinPrefixes(TrieNode* root, char buf[], int ind, std::string& res);

//���������� ��������� �� ���� ���������� ������� ���������� ��������
TrieNode* getStart(TrieNode* root, const std::string key);

//��������� ������ ��������� ��������� ��������
void findEndsOfWords(TrieNode* start, char buf[], int ind, const std::string& key, std::vector<std::string>& storage);


//������������ ������ ��������� ������ ���� �� ���������� ��������
//���������� ���������� ������
bool constructVariants(TrieNode* root, const std::string key, std::vector<std::string>& variants);

//������������� ������ ���������
void printVariants(const std::vector<std::string>& variants);


//��������� ������� ��������� �������� ���� � ������ ���������
//���������� ��������� ����� (� ����� ���� ������������ ��� ������������ ������ ������)
std::string GenerateWord(TrieNode* root, const std::string key);

//������������ ���������������� ���� � �������������� ����� �� �������
void autocomleteInterface(TrieNode* root);
