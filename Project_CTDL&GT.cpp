#include <iostream>
using namespace std;

// Dinh nghia cau truc nut
struct Node {
    int info;
    Node* prev; // Con tro den nut truoc
    Node* next; // Con tro den nut sau
};



// Ham khoi tao danh sach rong
void init(Node* &pList) {
    pList = NULL;
}

// Ham kiem tra danh sach rong
bool isEmpty(Node* pList) {
    return pList == NULL;
}

// Ham tao mot nut voi gia tri cho truoc
Node* createNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

// Ham them nut vao cuoi danh sach de tao thanh 1 chuoi danh sach (nhap vao danh sach)
void addTail(Node*& pList, int x) {
    Node* p = createNode(x);
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

// Ham hien thi danh sach
void displayList(Node* pList) {
    Node* temp = pList;
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Ham tinh tong cac phan tu
int SumList(Node* pList) {
    int sum = 0;
    Node* temp = pList;
    while (temp != NULL) {
        sum += temp->info;
        temp = temp->next;
    }
    return sum;
}

// Ham xoa nut co gia tri x
void deleteNode(Node*& pList, int x) {
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
void sortDescending(Node*& pList) {
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
void insertDescending(Node*& pList, int x) {
    Node* p = createNode(x);
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
    int choice;
    int x;
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
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap gia tri (nhap -1 de ket thuc): "<<endl;
                while (true) {
                    cin>>x;
                    if (x == -1) break;
                    addTail(pList, x);
                }
                cout<<"Qua trinh nhap thong tin cho cac nut duoc hoan thanh"<<endl;
                break;
            case 2:
                if (isEmpty(pList)) {
                    cout << "Danh sach rong.\n";
                } else {
                    cout << "Danh sach: ";
                    displayList(pList);
                }
                break;
            case 3:
                if (isEmpty(pList)) {
                    cout << "Danh sach rong, khong co gi de tinh tong.\n";
                } else {
                    cout << "Tong cac phan tu trong danh sach: " << SumList(pList) << endl;
                }
                break;
            case 4:
                if (isEmpty(pList)) {
                    cout << "Danh sach rong, khong co gi de xoa.\n";
                } else {
                    cout << "Nhap gia tri x can xoa: ";
                    cin >> x;
                    deleteNode(pList, x);
                    cout<<"Da xoa nut co gia tri "<<x<<" ra khoi danh sach"<<endl;
                    cout<<"Danh sach sau khi xoa: ";
					displayList(pList); 
                }
                break;
            case 5:
                if (isEmpty(pList)) {
                    cout << "Danh sach rong, khong co gi de sap xep.\n";
                } else {
                    sortDescending(pList);
                    cout << "Danh sach sau khi sap xep: ";
                    displayList(pList);
                }
                break;
            case 6:
                cout << "Nhap gia tri x them: ";
                cin >> x;
                insertDescending(pList, x);
                cout << "Danh sach sau khi them: ";
                displayList(pList);
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
    } while (choice != 0);
}

// Main
int main() {
    Node* pList;
    init(pList);
    menu(pList);
    return 0;
}
