#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct VeMayBay {
    int maVe;
    string khoiHanh;
    string den;
    float giaVe;
};
void nhapMộtVe(VeMayBay &ve) {
    cout << "Nhap ma ve: ";
    cin >> ve.maVe;
    cin.ignore(); 

    cout << "Nhap noi khoi hanh: ";
    getline(cin, ve.khoiHanh);

    cout << "Nhap noi den: ";
    getline(cin, ve.den);

    cout << "Nhap gia ve: ";
    cin >> ve.giaVe;
}

void inMộtVe(const VeMayBay &ve) {
    cout << left << setw(10) << ve.maVe 
         << setw(20) << ve.khoiHanh 
         << setw(20) << ve.den 
         << fixed << setprecision(2) << ve.giaVe << endl;
}

void nhapDanhSach(vector<VeMayBay> &ds, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin ve thu " << i + 1 << " ---\n";
        VeMayBay ve;
        nhapMộtVe(ve);
        ds.push_back(ve);
    }
}

void xuatDanhSach(const vector<VeMayBay> &ds) {
    cout << left << setw(10) << "Ma Ve" 
         << setw(20) << "Khoi Hanh" 
         << setw(20) << "Den" 
         << "Gia Ve" << endl;
    cout << string(60, '-') << endl;
    for (const auto &ve : ds) {
        inMộtVe(ve);
    }
}

int phânHoạch(vector<VeMayBay> &ds, int low, int high) {
    float pivot = ds[high].giaVe;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (ds[j].giaVe <= pivot) {
            i++;
            swap(ds[i], ds[j]);
        }
    }
    swap(ds[i + 1], ds[high]);
    return i + 1;
}

void quickSort(vector<VeMayBay> &ds, int low, int high) {
    if (low < high) {
        int pi = phânHoạch(ds, low, high);
        quickSort(ds, low, pi - 1);
        quickSort(ds, pi + 1, high);
    }
}

void timKiemNhiPhan(const vector<VeMayBay> &ds, float X) {
    int low = 0, high = ds.size() - 1;
    int viTriTimThay = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ds[mid].giaVe == X) {
            viTriTimThay = mid;
            break;
        } else if (ds[mid].giaVe < X) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (viTriTimThay == -1) {
        cout << "\nKhong tim thay ve may bay nao co gia ve bang " << fixed << setprecision(2) << X << endl;
        return;
    }

    int left = viTriTimThay, right = viTriTimThay;
    while (left > 0 && ds[left - 1].giaVe == X) left--;
    while (right < ds.size() - 1 && ds[right + 1].giaVe == X) right++;

    cout << "\n=== DANH SACH VE MAY BAY CO GIA VE " << fixed << setprecision(2) << X << " ===" << endl;
    cout << left << setw(10) << "Ma Ve" 
         << setw(20) << "Khoi Hanh" 
         << setw(20) << "Den" 
         << "Gia Ve" << endl;
    cout << string(60, '-') << endl;

    for (int i = left; i <= right; i++) {
        inMộtVe(ds[i]);
    }
}


int main() {
    int n;
    cout << "Nhap so luong ve may bay n: ";
    cin >> n;

    if (n <= 0) {
        cout << "So luong ve khong hop le!" << endl;
        return 0;
    }

    vector<VeMayBay> danhSach;

  
    nhapDanhSach(danhSach, n);
    cout << "\n=== DANH SACH VE MAY BAY VUA NHAP ===" << endl;
    xuatDanhSach(danhSach);

    quickSort(danhSach, 0, n - 1);
    cout << "\n=== DANH SACH SAU KHI SAP XEP TANG DAN THEO GIA VE (QUICK SORT) ===" << endl;
    xuatDanhSach(danhSach);
    float X;
    cout << "\nNhap gia ve X can tim: ";
    cin >> X;
    timKiemNhiPhan(danhSach, X);

    return 0;
}