#include "main.h"

template <class List_ItemType>
class LinkedList;

struct Candle
{
	long TIME;
	float OP;
	float HP;
	float LP;
	float CP;
};

struct Exchange
{
	string BC;
	string QC;
	LinkedList<Candle> *details;
};

// Each NODE for Exchange or Candle
template <class ItemType>
class Node
{
public:
	ItemType data;
	Node<ItemType> *link;

	Node()
	{
		this->link = NULL;
	};
	Node(ItemType data)
	{
		this->data = data;
		this->link = NULL;
	};
};

// LinkedList for both Exchanges and Candles
template <class List_ItemType>
class LinkedList
{

public:
	Node<List_ItemType> *head;
	int count;

	LinkedList()
	{
		this->head = NULL;
		this->count = 0;
	};
	~LinkedList(){};
	int InsertItem(List_ItemType value, int position);
	int UpdateItem(List_ItemType value);
	int DeleteItem(int position);
	void Print2Console();
};

// Place to store all data
class ProcessData
{
private:
	LinkedList<Exchange> *data = new LinkedList<Exchange>();
	static const int MAXSIZECODE = 8; // số lượng MAX parameters của 1 command trong file txt
	static int split(string line, string *&sp);

public:
	ProcessData();
	~ProcessData();
	int process(string line);
	void printAllCandle();
	int insert(const string *sp, const int n);
	int deleteCandle(const string *sp, const int n);
	int updateCandle(const string *sp, const int n);
	int spinningTop(const string *sp, const int n);
	int marubozu(const string *sp, const int n);
	int doji(const string *sp, const int n);
	int engulfing(const string *sp, const int n);
};

// template <typename T>
// class Link {
// 	public:
// 		T data;
// 		Link<T>* next;
// 		Link<T>(const Link<T>& n=nullptr) {next = n;}
// 		Link<T>(const T& ele, const Link<T>& n=nullptr) {
// 			data = ele;
// 			next = n;
// 		}
// };

// template <typename T>
// class List {
//   // Return: The number of elements in the list.
//   	virtual int length() const = 0;
// 	virtual void insert(const T& ele) = 0;
// };

// template <typename T>
// class LList: public List<T> {
// 	private:
// 		Link<T>* head;
// 		Link<T>* last;
// 		Link<T>* curr;
// 		int cnt;
// 	public:
// 		LList() {head = last = curr = new Link<T>();}
// 		int length() const {return cnt;}
// 		void insert(const T& ele) {
// 			curr->next = new Link(ele,curr->next);
// 		}
// };