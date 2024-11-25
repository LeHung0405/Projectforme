#include <iostream>
using namespace std;

// Dinh nghia cau truc nut
struct Node {
    int info;
    Node* prev; // Con tro den nut truoc
    Node* next; // Con tro den nut sau
};



// Ham khoi tao danh sach rong
void KhoiTao(Node* &pList) {
    pList = NULL;
}

// Ham kiem tra danh sach rong
bool KiemTraDS(Node* pList) {
    return pList == NULL;
}

// Ham tao mot nut voi gia tri cho truoc
Node* TaoNut(int x) {
    Node* p = new Node;
    p->info = x;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

// Ham them nut vao cuoi danh sach de tao thanh 1 chuoi danh sach (nhap vao danh sach)
void ThemNutCuoi(Node*& pList, int n) {
	int x;
	for (int i=0; i<n ;i++){
		cout<<"Nhap gia tri cho nut thu "<<i+1<<": ";
		cin>>x;
		cin.ignore();
	    Node* p = TaoNut(x);
	    if (pList == NULL) {
	        pList = p;
	    } else {
	        Node* temp = pList;
	        while (temp->next != NULL) {
	            temp = temp->next;
	        }
	        temp->next = p;
	        p->prev = temp;
	    }
}
}

// Ham hien thi danh sach
void HienThiDS(Node* pList) {
    Node* temp = pList;
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Ham tinh tong cac phan tu
int TinhTong(Node* pList) {
    int sum = 0;
    Node* temp = pList;
    while (temp != NULL) {
        sum += temp->info;
        temp = temp->next;
    }
    return sum;
}

// Ham xoa nut co gia tri x
void XoaNutX(Node*& pList, int x) {
    Node* temp = pList;
    while (temp != NULL && temp->info != x) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Khong tim thay gia tri " << x << " trong danh sach.\n";
        return;
    }
    if (temp->prev == NULL) {
        pList = temp->next;
        if (pList != NULL) pList->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }
    delete temp;
}

// Ham sap xep danh sach giam dan
void SapXepGiamDan(Node*& pList) {
    if (pList == NULL) return;
    for (Node* i = pList; i->next != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->info < j->info) {
                swap(i->info, j->info);
            }
        }
    }
}

// Ham chen gia tri vao danh sach giam dan
void ChenGiaTriVaoDS_GiamDan(Node*& pList, int x) {
    Node* p = TaoNut(x);
    if (pList == NULL || pList->info < x) {
        p->next = pList;
        if (pList != NULL) pList->prev = p;
        pList = p;
    } else {
        Node* temp = pList;
        while (temp->next != NULL && temp->next->info >= x) {
            temp = temp->next;
        }
        p->next = temp->next;
        if (temp->next != NULL) temp->next->prev = p;
        temp->next = p;
        p->prev = temp;
    }
}

// Menu
void menu(Node*& pList) {
    int luachon;
    int x;
    int n;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap danh sach\n";
        cout << "2. Hien thi danh sach vua nhap\n";
        cout << "3. Tinh tong phan tu cua danh sach\n";
        cout << "4. Xoa nut gia tri x trong danh sach\n";
        cout << "5. Sap xep danh sach giam dan\n";
        cout << "6. Them nut moi voi thong tin x voi danh sach giam dan\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> luachon;

        switch (luachon) {
            case 1:
                cout << "Nhap vao so luong nut cua danh sach: ";
                cin>>n;
                ThemNutCuoi(pList, n);
                cout<<"Qua trinh nhap thong tin cho cac nut duoc hoan thanh"<<endl;
                break;
            case 2:
                if (KiemTraDS(pList)) {
                    cout << "Danh sach rong.\n";
                } else {
                    cout << "Danh sach: ";
                    HienThiDS(pList);
                }
                break;
            case 3:
                if (KiemTraDS(pList)) {
                    cout << "Danh sach rong, khong co gi de tinh tong.\n";
                } else {
                    cout << "Tong cac phan tu trong danh sach: " << TinhTong(pList) << endl;
                }
                break;
            case 4:
                if (KiemTraDS(pList)) {
                    cout << "Danh sach rong, khong co gi de xoa.\n";
                } else {
                    cout << "Nhap gia tri x can xoa: ";
                    cin >> x;
                    XoaNutX(pList, x);
                    cout<<"Da xoa nut co gia tri "<<x<<" ra khoi danh sach"<<endl;
                    cout<<"Danh sach sau khi xoa: ";
					HienThiDS(pList); 
                }
                break;
            case 5:
                if (KiemTraDS(pList)) {
                    cout << "Danh sach rong, khong co gi de sap xep.\n";
                } else {
                    SapXepGiamDan(pList);
                    cout << "Danh sach sau khi sap xep: ";
                    HienThiDS(pList);
                }
                break;
            case 6:
                cout << "Nhap gia tri x them: ";
                cin >> x;
                ChenGiaTriVaoDS_GiamDan(pList, x);
                cout << "Danh sach sau khi them: ";
                HienThiDS(pList);
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                cout<<endl;
                cout << "Cam on co da xem project cua nhom em :333";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
                break;
        }
    } while (luachon != 0);
}

// Main
int main() {
    Node* pList;
	KhoiTao(pList);
    menu(pList);
    return 0;
}
