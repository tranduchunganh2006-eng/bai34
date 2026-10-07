#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;



struct Ngay {
    int ngay;
    int thang;
    int nam;
};

struct HangHoa {
    string maHang;
    string tenHang;
    Ngay ngayXuat;
    double giaXuat;
};

void nhapNgay(Ngay &d) {
    char ch;
    cin >> d.ngay >> ch >> d.thang >> ch >> d.nam;
}

void xuatNgay(const Ngay &d) {
    cout << (d.ngay < 10 ? "0" : "") << d.ngay << "/"
         << (d.thang < 10 ? "0" : "") << d.thang << "/"
         << d.nam;
}

void nhapOneHangHoa(HangHoa &hh) {
    cout << "  Ma hang: ";
    getline(cin >> ws, hh.maHang);
    cout << "  Ten hang: ";
    getline(cin, hh.tenHang);
    cout << "  Ngay xuat (dd/mm/yyyy): ";
    nhapNgay(hh.ngayXuat);
    cout << "  Gia xuat (trieu dong): ";
    cin >> hh.giaXuat;
}

void xuatOneHangHoa(const HangHoa &hh) {
    cout << left << setw(15) << hh.maHang
         << setw(25) << hh.tenHang;
    
    // In ngày xuất và cách thêm khoảng trống trước cột giá xuất
    xuatNgay(hh.ngayXuat);
    cout << "\t\t" << fixed << setprecision(2) << hh.giaXuat << endl;
}

void nhapDanhSach(vector<HangHoa> &ds, int n) {
    ds.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin hang hoa thu " << i + 1 << ":\n";
        nhapOneHangHoa(ds[i]);
    }
}

void xuatDanhSach(const vector<HangHoa> &ds) {
    cout << left << setw(15) << "Ma Hang"
         << setw(25) << "Ten Hang"
         << setw(16) << "Ngay Xuat"
         << "Gia Xuat (Trieu)" << endl;
    cout << string(70, '-') << endl;
    for (const auto &hh : ds) {
        xuatOneHangHoa(hh);
    }
}

void selectionSort(vector<HangHoa> &ds) {
    int n = ds.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (ds[j].giaXuat < ds[minIdx].giaXuat) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(ds[i], ds[minIdx]);
        }
    }
}

void timKiemNhiPhan(const vector<HangHoa> &ds, double X) {
    int left = 0, right = ds.size() - 1;
    int foundIdx = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ds[mid].giaXuat == X) {
            foundIdx = mid;
            right = mid - 1;
        } else if (ds[mid].giaXuat < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (foundIdx == -1) {
        cout << "\nKhong tim thay hang hoa nao co gia xuat bang " << X << " trieu dong.\n";
        return;
    }

    cout << "\n--- CAC HANG HOA CO GIA XUAT BANG " << X << " TRIEU DONG ---\n";
    cout << left << setw(15) << "Ma Hang"
         << setw(25) << "Ten Hang"
         << setw(16) << "Ngay Xuat"
         << "Gia Xuat (Trieu)" << endl;
    cout << string(70, '-') << endl;

    for (int i = foundIdx; i < ds.size() && ds[i].giaXuat == X; i++) {
        xuatOneHangHoa(ds[i]);
    }
}

int main() {
    int n;
    cout << "Nhap so luong hang hoa n: ";
    cin >> n;

    if (n <= 0) {
        cout << "So luong hang hoa khong hop le!";
        return 0;
    }

    vector<HangHoa> ds;

    nhapDanhSach(ds, n);
    cout << "\n=== DANH SACH HANG HOA VUA NHAP ===\n";
    xuatDanhSach(ds);

    selectionSort(ds);
    cout << "\n=== DANH SACH SAU KHI SAP XEP TANG DAN THEO GIA XUAT ===\n";
    xuatDanhSach(ds);

    double X;
    cout << "\nNhap gia xuat X can tim (trieu dong): ";
    cin >> X;
    timKiemNhiPhan(ds, X);

    return 0;
}