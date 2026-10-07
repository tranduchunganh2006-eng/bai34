#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct NgayThangNam {
    int ngay;
    int thang;
    int nam;
};

struct NhanVien {
    string maNV;
    string hoTen;
    NgayThangNam ngaySinh;
    double luong;
};

void nhapNgaySinh(NgayThangNam& ns) {
    char ch1, ch2;
    cin >> ns.ngay >> ch1 >> ns.thang >> ch2 >> ns.nam;
}

void inNgaySinh(const NgayThangNam& ns) {
    cout << setfill('0') << setw(2) << ns.ngay << "/"
         << setw(2) << ns.thang << "/"
         << setw(4) << ns.nam << setfill(' ');
}

void nhapDanhSach(vector<NhanVien>& ds, int n) {
    for (int i = 0; i < n; i++) {
        NhanVien nv;
        cout << "\nNhap nhan vien thứ " << i + 1 << ":\n";
        cout << "Ma nhan vien: ";
        cin >> nv.maNV;
        cin.ignore();

        cout << "Ho ten: ";
        getline(cin, nv.hoTen);

        cout << "Ngay sinh (dd/mm/yyyy): ";
        nhapNgaySinh(nv.ngaySinh);

        cout << "Luong (trieu dong): ";
        cin >> nv.luong;

        ds.push_back(nv);
    }
}

void inTieuDe() {
    cout << left << setw(12) << "Ma NV"
         << setw(25) << "Ho Ten"
         << setw(15) << "Ngay Sinh"
         << setw(20) << "Luong (Trieu DD)" << endl;
    cout << string(72, '-') << endl;
}

void inNhanVien(const NhanVien& nv) {
    cout << left << setw(12) << nv.maNV
         << setw(25) << nv.hoTen;
    inNgaySinh(nv.ngaySinh);
    cout << setw(5) << "" 
         << setw(20) << fixed << setprecision(2) << nv.luong << endl;
}

void xuatDanhSach(const vector<NhanVien>& ds) {
    inTieuDe();
    for (const auto& nv : ds) {
        inNhanVien(nv);
    }
}

void bubbleSort(vector<NhanVien>& ds) {
    int n = ds.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].luong > ds[j + 1].luong) {
                swap(ds[j], ds[j + 1]);
            }
        }
    }
}

void timKiemNhiPhan(const vector<NhanVien>& ds, double X) {
    int left = 0;
    int right = ds.size() - 1;
    int foundIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ds[mid].luong == X) {
            foundIndex = mid;
            break;
        } else if (ds[mid].luong < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (foundIndex == -1) {
        cout << "\nKhong tim thay nhan vien co luong = " << fixed << setprecision(2) << X << " trieu dong.\n";
    } else {
        cout << "\n=== KET QUA TIM KIEM (Luong = " << fixed << setprecision(2) << X << " trieu dong) ===\n";
        inTieuDe();

        int l = foundIndex;
        while (l >= 0 && ds[l].luong == X) {
            l--;
        }

        for (int i = l + 1; i < ds.size() && ds[i].luong == X; i++) {
            inNhanVien(ds[i]);
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    if (n <= 0) return 0;

    vector<NhanVien> ds;

    nhapDanhSach(ds, n);

    cout << "\n=== DANH SACH NHAN VIEN VUA NHAP ===\n";
    xuatDanhSach(ds);

    bubbleSort(ds);
    cout << "\n=== DANH SACH SAU KHI SAP XEP NOI BOT (TANG DAN THEO LUONG) ===\n";
    xuatDanhSach(ds);

    double X;
    cout << "\nNhap muc luong X can tim: ";
    cin >> X;
    timKiemNhiPhan(ds, X);

    return 0;
}