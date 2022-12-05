#include <iostream>
#include<string.h>
using namespace std;

struct Ngay
{
	int ngay, thang, nam;
};
struct SinhVien
{
	char MaSV[8];
	char hoTen[50];
	int gioiTinh;
	Ngay ngaySinh;
	char diaChi[100];
	char lop[12];
	char khoa[7];
};
struct Node
{
	SinhVien data;
	Node* next;
};

struct LinkedList
{
	Node* head;
	Node* tail;
};
Node* CreateNode(SinhVien init_data)
{
	Node* node = new Node;
	node->data = init_data;
	node->next = NULL;
	return node;
}

void CreateList(LinkedList& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void AddHead(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		node->next = l.head;
		l.head = node;
	}
}

void AddTail(LinkedList& l, Node* node)
{
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		l.tail->next = node;
		l.tail = node;
	}
}

void InsertAfterQ(LinkedList& l, Node* p, Node* q)
{
	if (q != NULL)
	{
		cout << 1 << ":T";
		p->next = q->next;
		q->next = p;
		if (l.tail == q)
			l.tail = p;
	}
	else
		AddTail(l, p);
}

int RemoveHead(LinkedList& l, SinhVien& x)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		x = node->data;
		l.head = node->next;
		delete node;
		if (l.head == NULL)
			l.tail = NULL;
		return 1;
	}
	return 0;
}

int RemoveAfterQ(LinkedList& l, Node* q, SinhVien& x)
{
	if (q != NULL)
	{
		Node* p = q->next;
		if (p != NULL)
		{
			if (l.tail == p)
				l.tail = q;
			q->next = p->next;
			x = p->data;
			delete p;
			return 1;
		}
		return 0;
	}
	return 0;
}

Node* GetNode(LinkedList l, int index)
{
	Node* node = l.head;
	int i = 0;
	while (node != NULL && i != index)
	{
		node = node->next;
		i++;
	}
	if (i == index && node != NULL)
		return node;
	return NULL;
}
void XuatNode(Node* node)
{
	cout << node->data.MaSV << ' '
		<< node->data.hoTen << ' '
		<< node->data.gioiTinh << ' '
		<< node->data.ngaySinh.nam << "/"
		<< node->data.ngaySinh.thang << "/"
		<< node->data.ngaySinh.nam << ' '
		<< node->data.diaChi << ' '
		<< node->data.lop << ' '
		<< node->data.khoa
		<< endl;
}
void PrintList(LinkedList l)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		while (node != NULL)
		{
			XuatNode(node);
			node = node->next;
		}
	}
}


Node* SearchInsert(LinkedList l, SinhVien x)
{
	Node* node = l.head;
	while (node != NULL && strcmp(node->data.MaSV, x.MaSV) < 0)
	{

		node = node->next;
	}
	if (node != NULL)
		return node;
	return NULL;
}
void SortList(LinkedList& list)
{
	// for loop thứ nhất
	for (Node* pTmp = list.head; pTmp != NULL; pTmp = pTmp->next)
	{
		//for loop thứ hai
		for (Node* pTmp2 = pTmp->next; pTmp2 != NULL; pTmp2 = pTmp2->next)
		{
			if (strcmp(pTmp->data.MaSV, pTmp2->data.MaSV) > 0) // nếu giá trị trước > giá trị sau thì hoán đổi hai vị trí
			{
				SinhVien tmp = pTmp->data;
				pTmp->data = pTmp2->data;
				pTmp2->data = tmp;
			}
		}
	}
}
int Length(LinkedList l)
{
	int count = 0;
	Node* node = l.head;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}

void DestroyList(LinkedList& l)
{
	SinhVien x;
	Node* node = l.head;
	while (node != NULL)
	{
		RemoveHead(l, x);
		node = l.head;
	}
	l.tail = NULL;
}
void NhapSv(SinhVien& sv)
{
	cout << "Nhap MaSV: "; fflush(stdin); gets(sv.MaSV);
	cout << "Nhap HoTen: "; fflush(stdin); gets(sv.hoTen);
	cout << "Nhap gioi tinh: (Nam:1 Nu:0)"; cin >> sv.gioiTinh;
	cout << "Nhap ngay sinh: "; fflush(stdin); cin >> sv.ngaySinh.ngay;
	cout << "Nhap thang sinh: "; fflush(stdin); cin >> sv.ngaySinh.thang;
	cout << "Nhap nam sinh: "; fflush(stdin); cin >> sv.ngaySinh.nam;
	cout << "Nhap dia chi: "; fflush(stdin); gets(sv.diaChi);
	cout << "Nhap lop: "; fflush(stdin); gets(sv.lop);
	cout << "Nhap khoa: "; fflush(stdin); gets(sv.khoa);
}
void SinhViensameNgaySinh(LinkedList list)
{
	int len = Length(list);
	bool Check[len] = {};
	int i = 0, j;
	bool checkNull = false;
	cout << "Danh sach Sinh Vien cung ngay sinh" << endl;
	for (Node* pTmp = list.head; pTmp != NULL; pTmp = pTmp->next)
	{//for loop thứ hai
		bool checkdelete = false;
		j = i + 1;
		if (!Check[i])
		{
			XuatNode(pTmp);
		}
		for (Node* pTmp2 = pTmp->next; pTmp2 != NULL; pTmp2 = pTmp2->next)
		{
			if (pTmp->data.ngaySinh.ngay == pTmp2->data.ngaySinh.ngay and !Check[j]) // nếu giá trị trước > giá trị sau thì hoán đổi hai vị trí
			{
				RemoveAfterQ(list, pTmp2, pTmp->data);
				XuatNode(pTmp2);
				Check[j] = true;
				checkNull = true;
				checkdelete = true;
			}
			j++;
		}
		if (checkdelete)
		{
			RemoveAfterQ(list, pTmp, pTmp->data);
		}
		i++;
		cout << "-------------------------------------------------------" << endl;

	}
	if (!checkNull)
	{
		cout << "khong co sinh vien nao cung ngay sinh" << endl;
	}
}
int main()
{
	// Create a linked list
	LinkedList list;
	CreateList(list);

	// Add sample data to list
	Node* node;
	SinhVien sv;
	int len1;
	cout << "Nhap vao so luong danh sach: "; cin >> len1;
	for (auto i = 1; i <= len1; i++)
	{
		NhapSv(sv);
		// Create new node with init data is sv
		node = CreateNode(sv);
		AddTail(list, node);
	}
	SortList(list);
	// Print list
	PrintList(list);
	cout << endl;

	// Get list's length
	int len = Length(list);
	cout << "Length of list: " << len << endl;
	DestroyList(list);

	return 0;
}