#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct KhachHang {
    int maKH;
    string tenKH;
    string soDienThoai;
    double tongTienThanhToan;
};

void nhapDanhSach(vector<KhachHang>& ds, int n) {
    for (int i = 0; i < n; i++) {
        KhachHang kh;
        cout << "\nNhap khach hang " << i + 1 << ":\n";
        cout << "Ma KH: ";
        cin >> kh.maKH;
        cin.ignore();
        
        cout << "Ten KH: ";
        getline(cin, kh.tenKH);
        
        cout << "So dien thoai: ";
        getline(cin, kh.soDienThoai);
        
        cout << "Tong tien: ";
        cin >> kh.tongTienThanhToan;
        
        ds.push_back(kh);
    }
}

void inTieuDe() {
    cout << left << setw(10) << "Ma KH"
         << setw(25) << "Ten KH"
         << setw(15) << "SDT"
         << setw(20) << "Tong Tien" << endl;
    cout << string(70, '-') << endl;
}

void inKhachHang(const KhachHang& kh) {
    cout << left << setw(10) << kh.maKH
         << setw(25) << kh.tenKH
         << setw(15) << kh.soDienThoai
         << setw(20) << fixed << setprecision(2) << kh.tongTienThanhToan << endl;
}

void xuatDanhSach(const vector<KhachHang>& ds) {
    inTieuDe();
    for (const auto& kh : ds) {
        inKhachHang(kh);
    }
}

void insertionSort(vector<KhachHang>& ds) {
    int n = ds.size();
    for (int i = 1; i < n; i++) {
        KhachHang key = ds[i];
        int j = i - 1;
        while (j >= 0 && ds[j].tongTienThanhToan > key.tongTienThanhToan) {
            ds[j + 1] = ds[j];
            j--;
        }
        ds[j + 1] = key;
    }
}

void timKiemNhiPhan(const vector<KhachHang>& ds, double X) {
    int left = 0;
    int right = ds.size() - 1;
    int foundIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ds[mid].tongTienThanhToan == X) {
            foundIndex = mid;
            break;
        } else if (ds[mid].tongTienThanhToan < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (foundIndex == -1) {
        cout << "\nKhong tim thay khach hang co tong tien = " << fixed << setprecision(2) << X << endl;
    } else {
        cout << "\n--- KET QUA TIM KIEM (Tong tien = " << fixed << setprecision(2) << X << ") ---\n";
        inTieuDe();
        
        int l = foundIndex;
        while (l >= 0 && ds[l].tongTienThanhToan == X) {
            l--;
        }
        
        for (int i = l + 1; i < ds.size() && ds[i].tongTienThanhToan == X; i++) {
            inKhachHang(ds[i]);
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong khach hang: ";
    cin >> n;

    if (n <= 0) return 0;

    vector<KhachHang> ds;

    nhapDanhSach(ds, n);
    
    cout << "\n=== DANH SACH VUA NHAP ===\n";
    xuatDanhSach(ds);

    insertionSort(ds);
    cout << "\n=== DANH SACH SAU KHI SAP XEP TANG DAN ===\n";
    xuatDanhSach(ds);

    double X;
    cout << "\nNhap tong tien X can tim: ";
    cin >> X;
    timKiemNhiPhan(ds, X);

    return 0;
}