#include <iostream>
#include <string>

using namespace std;

struct SinhVien {
	string maSV;
	string hoTen;
	string gioiTinh;
	//Ngay ngaySinh;
	string diaChi;
	string lop;
	string khoa;
};

//struct Ngay {
//	int ngay, thang, nam;
//};

struct Node {
	SinhVien* data;
	Node* link;
};

struct List {
	Node* first;
	Node* last;
};

void initDS(List* lDS) {
	lDS->first = lDS->last = NULL;
}

SinhVien* make(string ma, string ten, string gioi,/* Ngay ngay,*/ string dc, string lop, string khoa) {
	SinhVien* p = new SinhVien;
	p->maSV = ma;
	p->hoTen = ten;
	p->gioiTinh = gioi;
	p->diaChi = dc;
	p->lop = lop;
	p->khoa = khoa;
	return p;
}

Node* callNode(string ma, string ten, string gioi,/* Ngay ngay,*/ string dc, string lop, string khoa) {
	Node* p;
	p = new Node;
	p->data = make(ma, ten, gioi, dc, lop, khoa);
	return p;
}

List* addNode(List* lDS, Node* p) {
	if (lDS->first == NULL) {
		lDS->first = p;
		lDS->last = p;
	}
	else {
		lDS->last->link = p;
		lDS->last = p;
		lDS->last->link = NULL;
	}
	return lDS;
}

List* attachNode(List* lDS, string ma, string ten, string gioi,/* Ngay ngay,*/ string dc, string lop, string khoa) {
	Node* pDS = callNode(ma, ten, gioi,/* ngay,*/ dc, lop, khoa);
	if (pDS == NULL) return lDS;
	lDS = addNode(lDS, pDS);
	return lDS;
}

void NhapDsSV(List* lDS) {
	string ma;
	string ten;
	string gioi;
	/*Ngay ngay;*/
	string dc;
	string lop;
	string khoa;
	int i = 0;
	cout << "Bat dau nhap DS Sinh Vien (Nhap MSSV 0 de ket thuc): " << endl;
	do {
		i++;
		cout << "Nhap SV thu " << i << endl;
		cout << "Nhap MSSV: ";
		getline(cin, ma);
		if (ma == "0") break;
		cout << "Nhap ho ten SV: ";
		fflush(stdin);
		getline(cin, ten);
		cout << "Nhap gioi tinh: ";
		fflush(stdin);
		getline(cin, gioi);
		/*cout << "Nhap ngay thang nam sinh (lan luot): ";
		cin >> ngay.ngay >> ngay.thang >> ngay.nam;*/
		cout << "Nhap dia chi SV: ";
		fflush(stdin);
		getline(cin, dc);
		cout << "Nhap lop SV: ";
		fflush(stdin);
		getline(cin, lop);
		cout << "Nhap khoa SV: ";
		fflush(stdin);
		getline(cin, khoa);
		lDS = attachNode(lDS, ma, ten, gioi,/* ngay,*/ dc, lop, khoa);
	} while (ma != "0");
	cout << "Ket thuc nhap." << endl;
}

void swapNode(List* lDS, Node* p, Node* q) {
	Node* k = new Node;
	Node* m = lDS->first;
	Node* n = lDS->first;
	if (m == NULL) return;
	while (m != p) {
		if (m->link == p) break;
		else m = m->link;
	}
	while (n != q) {
		if (n->link == q) break;
		else n = n->link;
	}
	k->link = p->link;
	p->link = q->link;
	q->link = k->link;
	if (m != p) m->link = q;
	if (n != q) n->link = p;
}

void sapXepDS(List* lDS) {
	Node* k, * p, * q;
	k = p = lDS->first;
	q = p->link;
	while (k->link->link != NULL) {
		do {
			if (p->data->maSV > q->data->maSV) p = q;
			q = q->link;
		} while (q != NULL);
		swapNode(lDS, p, k);
		k = k->link;
		p = k;
	}
}

void inDS(List* lDS) {
	if (lDS == NULL) return;
	Node* p = lDS->first;

	cout << "Danh sach Sinh Vien: " << endl;
	/*while (true) {
		cout << p->data->hoTen << " - " << p->data->maSV << endl;

		if (p == lDS->last) return;
		p = p->link;
	}*/
	while (p != NULL) {
		cout << p->data->hoTen << " - " << p->data->maSV << endl;
		p = p->link;
	}
}

void themSV(List* lDS, string ma, string ten, string gioi,/* Ngay ngay,*/ string dc, string lop, string khoa) {
	Node* pDS = callNode(ma, ten, gioi,/* ngay,*/ dc, lop, khoa);
	if (pDS == NULL) return;
	addNode(lDS, pDS);
	sapXepDS(lDS);
}

int main() {
	List DS1;
	initDS(&DS1);
	NhapDsSV(&DS1);
	sapXepDS(&DS1);
	inDS(&DS1);
	return 0;
}