#include <iostream>
using namespace std;

// �?nh nghia c?u tr�c Node
struct Node {
    int info;
    Node* prev; // Con tr? d?n n�t tru?c
    Node* next; // Con tr? d?n n�t sau
};

// Kh?i t?o danh s�ch r?ng
void KhoiTao(Node*& pList) {
    pList = NULL;
}

// Ki?m tra danh s�ch r?ng
bool KiemTraDS(Node* pList) {
    return pList == NULL;
}

// T?o m?t n�t m?i
Node* TaoNut(int x) {
    Node* p = new Node;
    p->info = x;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

// Th�m m?t n�t v�o cu?i danh s�ch
void ThemCuoi(Node*& pList, int x) {
    Node* p = TaoNut(x);
    if (pList == NULL) { // N?u danh s�ch r?ng
        pList = p;
    } else {
        p->prev = pList;   // Li�n k?t n�t m?i v?i n�t cu?i hi?n t?i
        pList->next = p;   // Li�n k?t n�t cu?i hi?n t?i v?i n�t m?i
        pList = p;         // C?p nh?t pList tr? t?i n�t cu?i
    }
}

// Hi?n th? danh s�ch t? d?u d?n cu?i
void HienThiDS_TuDau(Node* pList) {
    if (pList == NULL) {
        cout << "Danh sach rong.\n";
        return;
    }

    // Duyet nguoc ve dau danh s�ch
    Node* temp = pList;
    while (temp->prev != NULL) {
        temp = temp->prev;
    }

    // Hien thi danh s�ch tu dau
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

// T�nh tong c�c phan tu trong danh s�ch
int TinhTong(Node* pList) {
    int sum = 0;
    Node* temp = pList;

    // Duyet nguoc ve dau danh s�ch
    while (temp != NULL && temp->prev != NULL) {
        temp = temp->prev;
    }

    // T�nh tong tu dau den cuoi
    while (temp != NULL) {
        sum += temp->info;
        temp = temp->next;
    }

    return sum;
}

// X�a n�t c� gi� tr? x trong danh s�ch
void XoaNutX(Node*& pList, int x) {
    Node* temp = pList;

    // Duy?t ngu?c v? d?u danh s�ch
    while (temp != NULL && temp->prev != NULL) {
        temp = temp->prev;
    }

    // T�m n�t c� gi� tr? x
    while (temp != NULL && temp->info != x) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Khong tim thay gia tri " << x << " trong danh sach.\n";
        return;
    }

    // X�a n�t
    if (temp->prev == NULL) { // X�a n�t d?u
        if (temp->next != NULL) temp->next->prev = NULL;
    } else if (temp->next == NULL) { // X�a n�t cu?i
        pList = temp->prev; // C?p nh?t pList tr? t?i n�t cu?i m?i
        temp->prev->next = NULL;
    } else { // X�a n�t gi?a
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
}

// S?p x?p danh s�ch gi?m d?n
void SapXepGiamDan(Node*& pList) {
    if (pList == NULL) return;

    // Duy?t ngu?c v? d?u danh s�ch
    Node* temp = pList;
    while (temp != NULL && temp->prev != NULL) {
        temp = temp->prev;
    }

    // S?p x?p b?ng thu?t to�n d?i ch?
    for (Node* i = temp; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->info < j->info) {
                swap(i->info, j->info);
            }
        }
    }
}

// Th�m m?t n�t v�o danh s�ch gi?m d?n
void ChenGiaTriVaoDS_GiamDan(Node*& pList, int x) {
    Node* p = TaoNut(x);

    // Duy?t ngu?c v? d?u danh s�ch
    Node* temp = pList;
    while (temp != NULL && temp->prev != NULL) {
        temp = temp->prev;
    }

    // T�m v? tr� ch�n
    while (temp != NULL && temp->info > x) {
        temp = temp->next;
    }

    if (temp == NULL) { // Ch�n v�o cu?i
        if (pList == NULL) {
            pList = p;
        } else {
            p->prev = pList;
            pList->next = p;
            pList = p;
        }
    } else if (temp->prev == NULL) { // Ch�n v�o d?u
        p->next = temp;
        temp->prev = p;
    } else { // Ch�n v�o vi tri x
        p->next = temp;
        p->prev = temp->prev;
        temp->prev->next = p;
        temp->prev = p;
    }
}

// Menu
void menu(Node*& pList) {
    int luachon, x, n;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap danh sach\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Tinh tong cac phan tu\n";
        cout << "4. Xoa nut co gia tri x\n";
        cout << "5. Sap xep danh sach giam dan\n";
        cout << "6. Chen gia tri vao danh sach giam dan\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> luachon;

        switch (luachon) {
            case 1:
                cout << "Nhap so luong phan tu: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Nhap gia tri cua nut thu "<<i+1<<": ";
                    cin >> x;
                    ThemCuoi(pList, x);
                }
                break;
            case 2:
                cout << "Danh sach: ";
                HienThiDS_TuDau(pList);
                break;
            case 3:
                cout << "Tong cac phan tu: " << TinhTong(pList) << endl;
                break;
            case 4:
                cout << "Nhap gia tri x can xoa: ";
                cin >> x;
                XoaNutX(pList, x);
                cout<<"Ban da xoa gia tri "<<x<<" ra khoi danh sach"<<endl;
                cout<<"Danh sach sau moi sau khi xoa: ";
                HienThiDS_TuDau(pList);
                break;
            case 5:
                SapXepGiamDan(pList);
                cout << "Danh sach sau khi sap xep: ";
                HienThiDS_TuDau(pList);
                break;
            case 6:
                cout << "Nhap gia tri x can chen: ";
                cin >> x;
                ChenGiaTriVaoDS_GiamDan(pList, x);
                cout << "Danh sach sau khi chen: ";
                HienThiDS_TuDau(pList);
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
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
