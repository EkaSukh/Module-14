#include "Trie.h"


//�������� ����� ����
TrieNode* getNewNode(void)
{
	// �������� ������ ��� ����� ����
	struct TrieNode* pNode = new TrieNode;

	// ������������� ���� ����� ����� � false
	pNode->isEndOfWord = false;

	// �������������� ����� ������� ����������
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = nullptr;

	return pNode;
}

//������� ����� � ������
void insertInTrie(TrieNode* root, string key)
{
	//��������� ������ ��� ����������� �� ������
	TrieNode* nNode = root;

	//����������� �� ��������� ������
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';

		//�������� ����� ����� ��� ������ ���� ��� ������������
		if (nNode->children[index] == nullptr)
			nNode->children[index] = getNewNode();

		//�������� ���� �� ������
		nNode = nNode->children[index];
	}
	//�������� ����� �����
	nNode->isEndOfWord = true;
}

//����� ����� � ������
bool searcWord(TrieNode* root, string key)
{
	//��������� ������ ��� ����������� �� ������
	TrieNode* node = root;

	//����������� �� ��������� �����
	for (int i = 0; i < key.length(); i++)
	{

		int index = key[i] - 'a';
		//����� �����
		if (!node->children[index])
			return false;

		//�������� ���� �� ������
		node = node->children[index];
	}

	// ��������� ���� ����� ���������� � ��� ���� ���������� ����� �����
	return (node != nullptr && node->isEndOfWord);
}

//����� ��������
bool search(TrieNode* root, string key)
{
	//��������� ������ ��� ����������� �� ������
	TrieNode* node = root;

	//����������� �� ��������� ��������
	for (int i = 0; i < key.length(); i++)
	{

		int index = key[i] - 'a';
		//����� ��������
		if (!node->children[index])
			return false;
		//�������� ���� �� ������
		node = node->children[index];
	}

	// ��������� ���� �������� ����������
	return (node != nullptr);
}


//��������� ���� (�� ����� ��������)
bool isEmpty(TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return false;
	return true;
}

//�������� ����� �� ������
TrieNode* remove(TrieNode* root, string key, int depth = 0)
{
	// ���� ������ ������
	if (!root)
		return nullptr;

	// ���� ����� �� ����� �����
	if (depth == key.size()) {
		// �������� ����� ����� �����
		if (root->isEndOfWord)
			root->isEndOfWord = false;
		// ���� ���� �� �������� ���������, ������� ���
		if (isEmpty(root)) {
			delete (root);
			root = nullptr;
		}

		return root;
	}

	int index = key[depth] - 'a';
	//����������� ����� �������� ��� �������� ����
	root->children[index] = remove(root->children[index], key, depth + 1);

	// ���� ���� �� �������� ���������, ������� ���
	if (isEmpty(root) && root->isEndOfWord == false) {
		delete (root);
		root = nullptr;
	}

	return root;
}

//���������� ������� ������� ����� � ��������� ������ ������
int friquency(TrieNode* node)
{
	//���� ������ ����������� ���� ������ �����
	if (isEmpty(node))
		return 1;
	//�������� ������� ������
	int f = 0;
	//���� ���� ���� ����� �����, �� ��� ����������� ������� �������
	if (node->isEndOfWord)
		f = 1;
	//�������� �� ������� ��������
	for (int j = 0; j < ALPHABET_SIZE; j++)
	{
		if (node->children[j])
			//������� ���� ����� ����� ������ ��� ��������
			f += friquency(node->children[j]);
	}

	return f;
}


//����� ������������ �������� �����
void findMinPrefixes(TrieNode* root, char buf[], int ind, string& res)
{
	//���� ���� �������
	if (root == nullptr)
		return;
	//�������� ������ ����������� ����
	int friq = friquency(root);

	//���� ������ ������ �����
	if (friq == 1)
	{
		//������� ����� � ������ ������
		buf[ind] = '\0';
		res += buf;
		res = res + " ";

		return;
	}

	//���� ������� ��� ���� �����, ������� ������ � ������ �����
	if (root->isEndOfWord)
	{

		buf[ind] = '\0';
		res += buf;
		res += " ";
	}

	//�������� ���� �� ������
	for (int j = 0; j < ALPHABET_SIZE; j++)
	{
		if (root->children[j] != nullptr)
			buf[ind] = 'a' + j;
		//����������� ����� ������� ��� ��������			
		findMinPrefixes(root->children[j], buf, ind + 1, res);
	}
}

//���������� ��������� �� ���� ���������� ������� ���������� ��������
TrieNode* getStart(TrieNode* root, const string key)
{
	//���� ��� ������ ��������
	if (!search(root, key)) {
		cerr << "didn't see the prefix.\n";
		return nullptr;
	}

	//����� ���� �� �������� �� ���������� �������
	TrieNode* node = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		node = node->children[index];
	}

	//���������� �� ��������� ���������� ���� ��������
	return node;
}


//��������� ������ ��������� ��������� ��������
void findEndsOfWords(TrieNode* start, char buf[], int ind, const string& key, vector<string>& storage)
{
	//������ ������� ����
	if (start == nullptr)
		return;

	//������ ����� �����
	if (start->isEndOfWord)
	{
		string str = key;

		buf[ind] = '\0';
		str += buf;
		//������ ����� � ������ ���������
		storage.push_back(str);
	}

	//�������� ���� �� ������
	for (int j = 0; j < ALPHABET_SIZE; j++)
	{
		if (start->children[j] != nullptr)
			buf[ind] = 'a' + j;
		//����������� ����� ������� ��� ��������
		findEndsOfWords(start->children[j], buf, ind + 1, key, storage);
	}
}

//������������ ������ ��������� ������ ���� �� ���������� ��������
//���������� ���������� ������

bool constructVariants(TrieNode* root, const string key, vector<string>& variants)
{
	//�������� ���� ������ ������ ��������� ���� ��� ������� ��������
	TrieNode* start = getStart(root, key);
	//��� ������ �������� � ��� ����������� ������������ ������ ���������
	if (!start) {
		cerr << "can not construct words variants and return false.\n";
		return false;
	}

	//����� ��� ������ ������� ���������� ������� ��������
	const int BUF_SIZE = 100;
	char buf[BUF_SIZE];

	//������� ���������� ������� ���������
	findEndsOfWords(start, buf, 0, key, variants);

	return true;
}

//������������� ������ ���������
void printVariants(const vector<string>& variants)
{
	int index = 1;
	for (auto i = variants.begin(); i != variants.end(); ++i)
	{
		cout << index << " " << *i << endl;
		++index;
	}
}


//�������� ������� ��������� ������� ��������� �������� ���� � ������ ���������
//���������� ��������� ����� (� ����� ���� ������������ ��� ������������ ������ ������)
string GenerateWord(TrieNode* root, const string key)
{
	//������ ��������� ��������� ���������
	vector<string> variants;
	//�������� ������, ������� ������ �������
	string result;

	//�������� ��������������� ������ ��������� ��������� ��������
	bool successToConstruct = constructVariants(root, key, variants);

	//���� �� ����������
	if (!successToConstruct)
	{
		cout << "Unable to construct variants on the prefix.\n";
		//���������� ������ ������
		return result;
	}

	//������� ������ ���������
	printVariants(variants);

	//���� ������������ ����������� ������ �����
	cout << "Enter a number of a variant: ";
	int index;

	//�������� ����� ������������ �� ����
	while (!(std::cin >> index))//�������� �����
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Input should be an integer. Please, try again.\n";
	}
	//�������� ����� ������������ �� ��������� ���������� ��������
	if (index > variants.size() || index <= 0)
	{
		cout << "The number is out of variant's range.\n";
		return result;
	}

	//��������� �������� ������
	result = variants[index - 1];

	return result;
}