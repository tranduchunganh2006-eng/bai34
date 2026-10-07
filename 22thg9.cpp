#include <iostream>
#include <string>

using namespace std;

struct SinhVien {
    int maSV;
    string tenSV;
    string lop;
    float diemTongKet;
    string hanhKiem;
};

struct Node {
    SinhVien data;
    Node* left;
    Node* right;
};

void initTree(Node* &root) {
    root = NULL;
}

Node* createNode(SinhVien sv) {
    Node* newNode = new Node();
    newNode->data = sv;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, SinhVien sv) {
    if (root == NULL) {
        return createNode(sv);
    }
    if (sv.maSV < root->data.maSV) {
        root->left = insert(root->left, sv);
    } else if (sv.maSV > root->data.maSV) {
        root->right = insert(root->right, sv);
    } else {
        cout << "Ma sinh vien " << sv.maSV << " da ton tai trong cay!\n";
    }
    return root;
}

Node* search(Node* root, int maSV) {
    if (root == NULL || root->data.maSV == maSV) {
        return root;
    }
    if (maSV < root->data.maSV) {
        return search(root->left, maSV);
    }
    return search(root->right, maSV);
}

void inThongTinSV(SinhVien sv) {
    cout << "Ma SV: " << sv.maSV 
         << " | Ten: " << sv.tenSV 
         << " | Lop: " << sv.lop 
         << " | Diem TK: " << sv.diemTongKet 
         << " | Hanh kiem: " << sv.hanhKiem << endl;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        inThongTinSV(root->data);
        inorderTraversal(root->right);
    }
}

SinhVien nhapSinhVien() {
    SinhVien sv;
    cout << "  - Nhap ma sinh vien: ";
    cin >> sv.maSV;
    cin.ignore();
    
    cout << "  - Nhap ho va ten: ";
    getline(cin, sv.tenSV);
    
    cout << "  - Nhap lop: ";
    getline(cin, sv.lop);
    
    cout << "  - Nhap diem tong ket: ";
    cin >> sv.diemTongKet;
    cin.ignore();
    
    cout << "  - Nhap hanh kiem: ";
    getline(cin, sv.hanhKiem);
    
    return sv;
}

int main() {
    Node* root;
    initTree(root);
    
    int n;
    cout << "Nhap so luong sinh vien n: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        SinhVien sv = nhapSinhVien();
        root = insert(root, sv);
    }
    
    cout << "\n=== DANH SACH SINH VIEN TRONG CAY ===" << endl;
    if (root == NULL) {
        cout << "Cay rong!" << endl;
    } else {
        inorderTraversal(root);
    }
    
    cout << "\n=== TIM KIEM SINH VIEN ===" << endl;
    int maTimKiem;
    cout << "Nhap ma sinh vien can tim: ";
    cin >> maTimKiem;g++ 22thg9.cpp 22thg9
    
    Node* result = search(root, maTimKiem);
    if (result != NULL) {
        cout << "Thong tin sinh vien co ma " << maTimKiem << ":" << endl;
        inThongTinSV(result->data);
    } else {
        cout << "Khong co sinh vien trong cay." << endl;
    }
    
    return 0;
}