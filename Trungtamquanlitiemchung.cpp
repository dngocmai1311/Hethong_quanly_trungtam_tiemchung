#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include<map>
#include<sstream>
using namespace std;

// Lớp BenhNhan để lưu trữ thông tin bệnh nhân
class BenhNhan {
private:
    string ten;           // Tên bệnh nhân
    int tuoi;            // Tuổi bệnh nhân
    string loaiVaccine;  // Loại vaccine
    string thoiGian;     // Thời gian tiêm
    string lichTiem;     // Lịch tiêm

public:
    // Constructor mặc định
    BenhNhan() : ten(""), tuoi(0), loaiVaccine(""), thoiGian(""), lichTiem("") {}

    // Constructor với các tham số
    BenhNhan(string t, int u, string lv, string tg, string lt)
        : ten(t), tuoi(u), loaiVaccine(lv), thoiGian(tg), lichTiem(lt) {}

    // Các phương thức setter
    void setTen(string t) {
        ten = t;
    }

    void setTuoi(int u) {
        tuoi = u;
    }

    void setLoaiVaccine(string lv) {
        loaiVaccine = lv;
    }

    void setThoiGian(string tg) {
        thoiGian = tg;
    }

    void setLichTiem(string lt) {
        lichTiem = lt;
    }

    // Các phương thức getter
    string getTen() const {
        return ten;
    }

    int getTuoi() const {
        return tuoi;
    }

    string getLoaiVaccine() const {
        return loaiVaccine;
    }

    string getThoiGian() const {
        return thoiGian;
    }

    string getLichTiem() const {
        return lichTiem;
    }

    // Hiển thị thông tin bệnh nhân
    void display() const {
        cout << "Ten: " << ten << ", Tuoi: " << tuoi
             << ", Loai Vaccine: " << loaiVaccine
             << ", Thoi Gian: " << thoiGian
             << ", Lich Tiem: " << lichTiem << endl;
    }
};

// Hàm thêm bệnh nhân vào danh sách
void themBenhNhan(vector<BenhNhan>& dsBenhNhan) {
    string ten, loaiVaccine, thoiGian, lichTiem;
    int tuoi;
    
    cout << "Nhap ten benh nhan: ";
    cin.ignore(); // Xóa bộ nhớ đệm
    getline(cin, ten);
    cout << "Nhap tuoi benh nhan: ";
    cin >> tuoi;
    cout << "Nhap loai vaccine: ";
    cin.ignore(); // Xóa bộ nhớ đệm
    getline(cin, loaiVaccine);
    cout << "Nhap thoi gian tiem: ";
    getline(cin, thoiGian);
    cout << "Nhap lich tiem (ngay/thang/nam): ";
    getline(cin, lichTiem);

    BenhNhan bn(ten, tuoi, loaiVaccine, thoiGian, lichTiem);
    dsBenhNhan.push_back(bn);

    cout << "Da them benh nhan thanh cong." << endl;
}

// Hàm xóa bệnh nhân theo tên
void xoaBenhNhan(vector<BenhNhan>& dsBenhNhan) {
    string ten;
    cout << "Nhap ten benh nhan can xoa: ";
    cin.ignore(); // Xóa bộ nhớ đệm
    getline(cin, ten);

    auto it = remove_if(dsBenhNhan.begin(), dsBenhNhan.end(), [&](const BenhNhan& bn) {
        return bn.getTen() == ten;
    });

    if (it != dsBenhNhan.end()) {
        dsBenhNhan.erase(it, dsBenhNhan.end());
        cout << "Da xoa benh nhan thanh cong." << endl;
    } else {
        cout << "Khong tim thay benh nhan." << endl;
    }
}

// Hàm sửa thông tin bệnh nhân
void suaBenhNhan(vector<BenhNhan>& dsBenhNhan) {
    string ten;
    cout << "Nhap ten benh nhan can sua: ";
    cin.ignore(); // Xóa bộ nhớ đệm
    getline(cin, ten);

    for (auto& bn : dsBenhNhan) {
        if (bn.getTen() == ten) {
            string loaiVaccine, thoiGian, lichTiem;
            int tuoi;

            cout << "Nhap tuoi moi: ";
            cin >> tuoi;
            cout << "Nhap loai vaccine moi: ";
            cin.ignore(); // Xóa bộ nhớ đệm
            getline(cin, loaiVaccine);
            cout << "Nhap thoi gian tiem moi: ";
            getline(cin, thoiGian);
            cout << "Nhap lich tiem moi (ngay/thang/nam): ";
            getline(cin, lichTiem);

            bn.setTuoi(tuoi);
            bn.setLoaiVaccine(loaiVaccine);
            bn.setThoiGian(thoiGian);
            bn.setLichTiem(lichTiem);

            cout << "Da cap nhat thong tin benh nhan." << endl;
            return;
        }
    }
    cout << "Khong tim thay benh nhan." << endl;
}

// Hàm xem danh sách bệnh nhân
void hienThiDanhSach(const vector<BenhNhan>& dsBenhNhan) {
    if (dsBenhNhan.empty()) {
        cout << "Danh sach benh nhan rong." << endl;
        return;
    }

    cout << "\nDanh sach benh nhan:" << endl;
    for (const auto& bn : dsBenhNhan) {
        bn.display();
    }
}

// Hàm thống kê số bệnh nhân theo loại vaccine
void thongKeTheoVaccine(const vector<BenhNhan>& dsBenhNhan) {
    map<string, int> vaccineCount;

    for (const auto& bn : dsBenhNhan) {
        vaccineCount[bn.getLoaiVaccine()]++;
    }

    cout << "\nThong ke so benh nhan theo loai vaccine:" << endl;
    for (const auto& pair : vaccineCount) {
        cout << "Loai Vaccine: " << pair.first << ", So Benh Nhan: " << pair.second << endl;
    }
}

// Hàm đặt lịch tiêm cho bệnh nhân
void datLichTiem(vector<BenhNhan>& dsBenhNhan) {
    string ten;
    cout << "Nhap ten benh nhan can dat lich tiem: ";
    cin.ignore(); // Xóa bộ nhớ đệm
    getline(cin, ten);

    for (auto& bn : dsBenhNhan) {
        if (bn.getTen() == ten) {
            string lichTiem;
            cout << "Nhap lich tiem (ngay/thang/nam): ";
            getline(cin, lichTiem);
            bn.setLichTiem(lichTiem);
            cout << "Da cap nhat lich tiem cho benh nhan." << endl;
            return;
        }
    }
    cout << "Khong tim thay benh nhan." << endl;
}

// Hàm hiển thị lịch tiêm của tất cả bệnh nhân
void xemLichTiem(const vector<BenhNhan>& dsBenhNhan) {
    if (dsBenhNhan.empty()) {
        cout << "Danh sach benh nhan rong." << endl;
        return;
    }

    cout << "\nDanh sach lich tiem:" << endl;
    for (const auto& bn : dsBenhNhan) {
        cout << "Ten: " << bn.getTen() << ", Lich Tiem: " << bn.getLichTiem() << endl;
    }
}

// Hàm ghi danh sách bệnh nhân ra file
void ghiDanhSachRaFile(const vector<BenhNhan>& dsBenhNhan, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Khong the mo file de ghi!" << endl;
        return;
    }

    for (const auto& bn : dsBenhNhan) {
        file << bn.getTen() << "," << bn.getTuoi() << ","
             << bn.getLoaiVaccine() << "," << bn.getThoiGian() << ","
             << bn.getLichTiem() << endl;
    }

    file.close();
    cout << "Da ghi danh sach benh nhan ra file." << endl;
}

// Hàm đọc danh sách bệnh nhân từ file
void docDanhSachTuFile(vector<BenhNhan>& dsBenhNhan, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Khong the mo file de doc!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string ten, loaiVaccine, thoiGian, lichTiem;
        int tuoi;

        getline(ss, ten, ',');
        ss >> tuoi;
        ss.ignore(); // Xóa bộ nhớ đệm
        getline(ss, loaiVaccine, ',');
        getline(ss, thoiGian, ',');
        getline(ss, lichTiem);

        BenhNhan bn(ten, tuoi, loaiVaccine, thoiGian, lichTiem);
        dsBenhNhan.push_back(bn);
    }

    file.close();
    cout << "Da doc danh sach benh nhan tu file." << endl;
}

// Hàm menu chính
void menu() {
    vector<BenhNhan> dsBenhNhan; // Danh sách bệnh nhân
    int luaChon;

    do {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Them benh nhan" << endl;
        cout << "2. Xoa benh nhan" << endl;
        cout << "3. Sua thong tin benh nhan" << endl;
        cout << "4. Xem danh sach benh nhan" << endl;
        cout << "5. Thong ke so benh nhan theo loai vaccine" << endl;
        cout << "6. Dat lich tiem" << endl;
        cout << "7. Xem lich tiem" << endl;
        cout << "8. Ghi danh sach benh nhan ra file" << endl;
        cout << "9. Doc danh sach benh nhan tu file" << endl;
        cout << "0. Thoat" << endl;
        cout << "Chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                themBenhNhan(dsBenhNhan); // Thêm bệnh nhân
                break;
            case 2:
                xoaBenhNhan(dsBenhNhan); // Xóa bệnh nhân
                break;
            case 3:
                suaBenhNhan(dsBenhNhan); // Sửa thông tin bệnh nhân
                break;
            case 4:
                hienThiDanhSach(dsBenhNhan); // Xem danh sách bệnh nhân
                break;
            case 5:
                thongKeTheoVaccine(dsBenhNhan); // Thống kê bệnh nhân theo vaccine
                break;
            case 6:
                datLichTiem(dsBenhNhan); // Đặt lịch tiêm
                break;
            case 7:
                xemLichTiem(dsBenhNhan); // Xem lịch tiêm
                break;
            case 8: {
                string filename;
                cout << "Nhap ten file de ghi: ";
                cin.ignore(); // Xóa bộ nhớ đệm
                getline(cin, filename);
                ghiDanhSachRaFile(dsBenhNhan, filename); // Ghi danh sách bệnh nhân vào file
                break;
            }
            case 9: {
                string filename;
                cout << "Nhap ten file de doc: ";
                cin.ignore(); // Xóa bộ nhớ đệm
                getline(cin, filename);
                docDanhSachTuFile(dsBenhNhan, filename); // Đọc danh sách bệnh nhân từ file
                break;
            }
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
        }
    } while (luaChon != 0);
}

// Hàm main
int main() {
    menu(); // Gọi hàm menu để chạy chương trình
    return 0;
}
