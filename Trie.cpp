#include "Trie.h"


//создание новог узла
TrieNode* getNewNode(void)
{
	// Выделяем память под новый узел
	struct TrieNode* pNode = new TrieNode;

	// устанавливаем флаг конца слова в false
	pNode->isEndOfWord = false;

	// инициализируем детей нулевым указателем
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = nullptr;

	return pNode;
}

//вставка слова в дерево
void insertInTrie(TrieNode* root, string key)
{
	//временный объект для перемещения по дереву
	TrieNode* nNode = root;

	//перемещение по элементам строки
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';

		//создание новых узлов для ключей если нет существующих
		if (nNode->children[index] == nullptr)
			nNode->children[index] = getNewNode();

		//смещение вниз по дереву
		nNode = nNode->children[index];
	}
	//достигли конца слова
	nNode->isEndOfWord = true;
}

//поиск слова в дереве
bool searcWord(TrieNode* root, string key)
{
	//временный объект для перемещения по дереву
	TrieNode* node = root;

	//перемещение по элементам слова
	for (int i = 0; i < key.length(); i++)
	{

		int index = key[i] - 'a';
		//обрыв слова
		if (!node->children[index])
			return false;

		//смещение вниз по дереву
		node = node->children[index];
	}

	// последний узел слова существует и его флаг обозначает конец слова
	return (node != nullptr && node->isEndOfWord);
}

//поиск префикса
bool search(TrieNode* root, string key)
{
	//временный объект для перемещения по дереву
	TrieNode* node = root;

	//перемещение по элементам префикса
	for (int i = 0; i < key.length(); i++)
	{

		int index = key[i] - 'a';
		//обрыв префикса
		if (!node->children[index])
			return false;
		//смещение вниз по дереву
		node = node->children[index];
	}

	// последний узел перфикса существует
	return (node != nullptr);
}


//последний узел (не имеет потомков)
bool isEmpty(TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return false;
	return true;
}

//удаление слова из дерева
TrieNode* remove(TrieNode* root, string key, int depth = 0)
{
	// Если дерево пустое
	if (!root)
		return nullptr;

	// Если дошли до конца слова
	if (depth == key.size()) {
		// удаление метки конца слова
		if (root->isEndOfWord)
			root->isEndOfWord = false;
		// Если ключ не является префиксом, удаляем его
		if (isEmpty(root)) {
			delete (root);
			root = nullptr;
		}

		return root;
	}

	int index = key[depth] - 'a';
	//рекурсивный вызов удаления для потомков узла
	root->children[index] = remove(root->children[index], key, depth + 1);

	// Если ключ не является префиксом, удаляем его
	if (isEmpty(root) && root->isEndOfWord == false) {
		delete (root);
		root = nullptr;
	}

	return root;
}

//вычисление частоты участия ключа в различных словах дерева
int friquency(TrieNode* node)
{
	//лист дерева принадлежит лишь одному слову
	if (isEmpty(node))
		return 1;
	//исходная частота улевая
	int f = 0;
	//если узел есть конец слова, то его минимальная частота единица
	if (node->isEndOfWord)
		f = 1;
	//движение по массмву потомков
	for (int j = 0; j < ALPHABET_SIZE; j++)
	{
		if (node->children[j])
			//частота узла равна сумме частот его потомков
			f += friquency(node->children[j]);
	}

	return f;
}


//поиск минимального префикса слова
void findMinPrefixes(TrieNode* root, char buf[], int ind, string& res)
{
	//если узел нулевой
	if (root == nullptr)
		return;
	//скольким словам принадлежит узел
	int friq = friquency(root);

	//если только одному слову
	if (friq == 1)
	{
		//заносим слово в строку вывода
		buf[ind] = '\0';
		res += buf;
		res = res + " ";

		return;
	}

	//если префикс уже есть слово, которое входит в другое слово
	if (root->isEndOfWord)
	{

		buf[ind] = '\0';
		res += buf;
		res += " ";
	}

	//движение вниз по дереву
	for (int j = 0; j < ALPHABET_SIZE; j++)
	{
		if (root->children[j] != nullptr)
			buf[ind] = 'a' + j;
		//рекурсивный вызов функции для потомков			
		findMinPrefixes(root->children[j], buf, ind + 1, res);
	}
}

//возвращает указатель на узел последнего символа введенного префикса
TrieNode* getStart(TrieNode* root, const string key)
{
	//если нет такого префикса
	if (!search(root, key)) {
		cerr << "didn't see the prefix.\n";
		return nullptr;
	}

	//иначе идем по префиксу до последнего символа
	TrieNode* node = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		node = node->children[index];
	}

	//возвращает на указатель последнего узла префикса
	return node;
}


//заполняет вектор вариантов оканчиний префикса
void findEndsOfWords(TrieNode* start, char buf[], int ind, const string& key, vector<string>& storage)
{
	//случай пустого узла
	if (start == nullptr)
		return;

	//случай конца слова
	if (start->isEndOfWord)
	{
		string str = key;

		buf[ind] = '\0';
		str += buf;
		//кладем слово в вектор вариантов
		storage.push_back(str);
	}

	//движение вниз по дереву
	for (int j = 0; j < ALPHABET_SIZE; j++)
	{
		if (start->children[j] != nullptr)
			buf[ind] = 'a' + j;
		//рекурсивный вызов функции для потомков
		findEndsOfWords(start->children[j], buf, ind + 1, key, storage);
	}
}

//конструирует вектор вариантов полных слов от введенного префикса
//возвращает успешность работы

bool constructVariants(TrieNode* root, const string key, vector<string>& variants)
{
	//получаем узел начала поиска окончаний слов для данного префикса
	TrieNode* start = getStart(root, key);
	//нет такого префикса и нет возможности сформировать массив вариантов
	if (!start) {
		cerr << "can not construct words variants and return false.\n";
		return false;
	}

	//буфер для работы функции заполнения массива варантов
	const int BUF_SIZE = 100;
	char buf[BUF_SIZE];

	//функция заполнения массива вариантов
	findEndsOfWords(start, buf, 0, key, variants);

	return true;
}

//распечатывает вектор вариантов
void printVariants(const vector<string>& variants)
{
	int index = 1;
	for (auto i = variants.begin(); i != variants.end(); ++i)
	{
		cout << index << " " << *i << endl;
		++index;
	}
}


//конечная функция позволяет увидеть возможные варианты слов с данным префиксом
//возвращает выбранное слово (и может быть использована для формирования потока вывода)
string GenerateWord(TrieNode* root, const string key)
{
	//массив возможных вариантов окончаний
	vector<string> variants;
	//конечная строка, которую вернет функция
	string result;

	//пытаемся сконструировать массив вариантов окончания префикса
	bool successToConstruct = constructVariants(root, key, variants);

	//если не получилось
	if (!successToConstruct)
	{
		cout << "Unable to construct variants on the prefix.\n";
		//возвращаем пустую строку
		return result;
	}

	//выводит массив вариантов
	printVariants(variants);

	//жаем пользователю возможность выбора слова
	cout << "Enter a number of a variant: ";
	int index;

	//контроль ввода пользователя по типу
	while (!(std::cin >> index))//проверка ввода
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Input should be an integer. Please, try again.\n";
	}
	//контроль ввода пользователя по диапазону введенного значения
	if (index > variants.size() || index <= 0)
	{
		cout << "The number is out of variant's range.\n";
		return result;
	}

	//формируем конечную строку
	result = variants[index - 1];

	return result;
}