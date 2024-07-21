#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEN 100
#define MAX_VACCINE 50
#define MAX_THOIGIAN 50
#define MAX_LICHTIEM 50

// C?u tr�c b?nh nh�n
typedef struct {
    char ten[MAX_TEN];          // T�n b?nh nh�n
    int tuoi;                  // Tu?i b?nh nh�n
    char loaiVaccine[MAX_VACCINE]; // Lo?i vaccine
    char thoiGian[MAX_THOIGIAN];   // Th?i gian ti�m
    char lichTiem[MAX_LICHTIEM];   // L?ch ti�m
} BenhNhan;

// Th�m b?nh nh�n v�o danh s�ch
void themBenhNhan(BenhNhan dsBenhNhan[], int *soLuong) {
    if (*soLuong >= 100) { // Gi?i h?n danh s�ch b?nh nh�n
        printf("Danh sach benh nhan da day.\n");
        return;
    }

    printf("Nhap ten benh nhan: ");
    getchar(); // X�a b? nh? d?m
    fgets(dsBenhNhan[*soLuong].ten, MAX_TEN, stdin);
    dsBenhNhan[*soLuong].ten[strcspn(dsBenhNhan[*soLuong].ten, "\n")] = '\0'; // X�a k� t? newline

    printf("Nhap tuoi benh nhan: ");
    scanf("%d", &dsBenhNhan[*soLuong].tuoi);

    printf("Nhap loai vaccine: ");
    getchar(); // X�a b? nh? d?m
    fgets(dsBenhNhan[*soLuong].loaiVaccine, MAX_VACCINE, stdin);
    dsBenhNhan[*soLuong].loaiVaccine[strcspn(dsBenhNhan[*soLuong].loaiVaccine, "\n")] = '\0'; // X�a k� t? newline

    printf("Nhap thoi gian tiem: ");
    fgets(dsBenhNhan[*soLuong].thoiGian, MAX_THOIGIAN, stdin);
    dsBenhNhan[*soLuong].thoiGian[strcspn(dsBenhNhan[*soLuong].thoiGian, "\n")] = '\0'; // X�a k� t? newline

    printf("Nhap lich tiem (ngay/thang/nam): ");
    fgets(dsBenhNhan[*soLuong].lichTiem, MAX_LICHTIEM, stdin);
    dsBenhNhan[*soLuong].lichTiem[strcspn(dsBenhNhan[*soLuong].lichTiem, "\n")] = '\0'; // X�a k� t? newline

    (*soLuong)++;
    printf("Da them benh nhan thanh cong.\n");
}

// X�a b?nh nh�n theo t�n
void xoaBenhNhan(BenhNhan dsBenhNhan[], int *soLuong) {
    char ten[MAX_TEN];
    printf("Nhap ten benh nhan can xoa: ");
    getchar(); // X�a b? nh? d?m
    fgets(ten, MAX_TEN, stdin);
    ten[strcspn(ten, "\n")] = '\0'; // X�a k� t? newline

    int i, j;
    for (i = 0; i < *soLuong; i++) {
        if (strcmp(dsBenhNhan[i].ten, ten) == 0) {
            for (j = i; j < *soLuong - 1; j++) {
                dsBenhNhan[j] = dsBenhNhan[j + 1];
            }
            (*soLuong)--;
            printf("Da xoa benh nhan thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay benh nhan.\n");
}

// S?a th�ng tin b?nh nh�n
void suaBenhNhan(BenhNhan dsBenhNhan[], int soLuong) {
    char ten[MAX_TEN];
    printf("Nhap ten benh nhan can sua: ");
    getchar(); // X�a b? nh? d?m
    fgets(ten, MAX_TEN, stdin);
    ten[strcspn(ten, "\n")] = '\0'; // X�a k� t? newline

    int i;
    for (i = 0; i < soLuong; i++) {
        if (strcmp(dsBenhNhan[i].ten, ten) == 0) {
            printf("Nhap tuoi moi: ");
            scanf("%d", &dsBenhNhan[i].tuoi);

            printf("Nhap loai vaccine moi: ");
            getchar(); // X�a b? nh? d?m
            fgets(dsBenhNhan[i].loaiVaccine, MAX_VACCINE, stdin);
            dsBenhNhan[i].loaiVaccine[strcspn(dsBenhNhan[i].loaiVaccine, "\n")] = '\0'; // X�a k� t? newline

            printf("Nhap thoi gian tiem moi: ");
            fgets(dsBenhNhan[i].thoiGian, MAX_THOIGIAN, stdin);
            dsBenhNhan[i].thoiGian[strcspn(dsBenhNhan[i].thoiGian, "\n")] = '\0'; // X�a k� t? newline

            printf("Nhap lich tiem moi (ngay/thang/nam): ");
            fgets(dsBenhNhan[i].lichTiem, MAX_LICHTIEM, stdin);
            dsBenhNhan[i].lichTiem[strcspn(dsBenhNhan[i].lichTiem, "\n")] = '\0'; // X�a k� t? newline

            printf("Da cap nhat thong tin benh nhan.\n");
            return;
        }
    }
    printf("Khong tim thay benh nhan.\n");
}

// Xem danh s�ch b?nh nh�n
void hienThiDanhSach(BenhNhan dsBenhNhan[], int soLuong) {
    if (soLuong == 0) {
        printf("Danh sach benh nhan rong.\n");
        return;
    }

    printf("\nDanh sach benh nhan:\n");
    for (int i = 0; i < soLuong; i++) {
        printf("Ten: %s, Tuoi: %d, Loai Vaccine: %s, Thoi Gian: %s, Lich Tiem: %s\n",
               dsBenhNhan[i].ten, dsBenhNhan[i].tuoi, dsBenhNhan[i].loaiVaccine,
               dsBenhNhan[i].thoiGian, dsBenhNhan[i].lichTiem);
    }
}

// Th?ng k� s? b?nh nh�n theo lo?i vaccine
void thongKeTheoVaccine(BenhNhan dsBenhNhan[], int soLuong) {
    int count[10] = {0}; // Gi? s? c� t?i da 10 lo?i vaccine kh�c nhau
    char vaccineList[10][MAX_VACCINE] = {"", "", "", "", "", "", "", "", "", ""};

    for (int i = 0; i < soLuong; i++) {
        int found = 0;
        for (int j = 0; j < 10; j++) {
            if (strcmp(dsBenhNhan[i].loaiVaccine, vaccineList[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            for (int k = 0; k < 10; k++) {
                if (vaccineList[k][0] == '\0') {
                    strcpy(vaccineList[k], dsBenhNhan[i].loaiVaccine);
                    count[k] = 1;
                    break;
                }
            }
        }
    }

    printf("\nThong ke so benh nhan theo loai vaccine:\n");
    for (int i = 0; i < 10; i++) {
        if (vaccineList[i][0] != '\0') {
            printf("Loai Vaccine: %s, So Benh Nhan: %d\n", vaccineList[i], count[i]);
        }
    }
}

// �?t l?ch ti�m cho b?nh nh�n
void datLichTiem(BenhNhan dsBenhNhan[], int soLuong) {
    char ten[MAX_TEN];
    printf("Nhap ten benh nhan can dat lich tiem: ");
    getchar(); // X�a b? nh? d?m
    fgets(ten, MAX_TEN, stdin);
    ten[strcspn(ten, "\n")] = '\0'; // X�a k� t? newline

    for (int i = 0; i < soLuong; i++) {
        if (strcmp(dsBenhNhan[i].ten, ten) == 0) {
            printf("Nhap lich tiem (ngay/thang/nam): ");
            fgets(dsBenhNhan[i].lichTiem, MAX_LICHTIEM, stdin);
            dsBenhNhan[i].lichTiem[strcspn(dsBenhNhan[i].lichTiem, "\n")] = '\0'; // X�a k� t? newline
            printf("Da cap nhat lich tiem cho benh nhan.\n");
            return;
        }
    }
    printf("Khong tim thay benh nhan.\n");
}

// Xem l?ch ti�m c?a t?t c? b?nh nh�n
void xemLichTiem(BenhNhan dsBenhNhan[], int soLuong) {
    if (soLuong == 0) {
        printf("Danh sach benh nhan rong.\n");
        return;
    }

    printf("\nLich tiem cua cac benh nhan:\n");
    for (int i = 0; i < soLuong; i++) {
        printf("Ten: %s, Lich Tiem: %s\n", dsBenhNhan[i].ten, dsBenhNhan[i].lichTiem);
    }
}

// Ghi danh s�ch b?nh nh�n ra file
void ghiDanhSachRaFile(BenhNhan dsBenhNhan[], int soLuong, const char* filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return;
    }

    for (int i = 0; i < soLuong; i++) {
        fprintf(file, "%s,%d,%s,%s,%s\n",
                dsBenhNhan[i].ten, dsBenhNhan[i].tuoi, dsBenhNhan[i].loaiVaccine,
                dsBenhNhan[i].thoiGian, dsBenhNhan[i].lichTiem);
    }

    fclose(file);
    printf("Da ghi danh sach benh nhan ra file.\n");
}

// �?c danh s�ch b?nh nh�n t? file
void docDanhSachTuFile(BenhNhan dsBenhNhan[], int *soLuong, const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file de doc.\n");
        return;
    }

    *soLuong = 0;
    while (fscanf(file, "%[^,],%d,%[^,],%[^,],%[^\n]\n",
                  dsBenhNhan[*soLuong].ten, &dsBenhNhan[*soLuong].tuoi,
                  dsBenhNhan[*soLuong].loaiVaccine, dsBenhNhan[*soLuong].thoiGian,
                  dsBenhNhan[*soLuong].lichTiem) != EOF) {
        (*soLuong)++;
        if (*soLuong >= 100) break; // Gi?i h?n s? lu?ng b?nh nh�n
    }

    fclose(file);
    printf("Da doc danh sach benh nhan tu file.\n");
}

// H�m menu ch�nh
void menu() {
    BenhNhan dsBenhNhan[100]; // Danh s�ch b?nh nh�n
    int soLuong = 0;
    int luaChon;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Them benh nhan\n");
        printf("2. Xoa benh nhan\n");
        printf("3. Sua thong tin benh nhan\n");
        printf("4. Xem danh sach benh nhan\n");
        printf("5. Thong ke so benh nhan theo loai vaccine\n");
        printf("6. Dat lich tiem\n");
        printf("7. Xem lich tiem\n");
        printf("8. Ghi danh sach benh nhan ra file\n");
        printf("9. Doc danh sach benh nhan tu file\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                themBenhNhan(dsBenhNhan, &soLuong); // Th�m b?nh nh�n
                break;
            case 2:
                xoaBenhNhan(dsBenhNhan, &soLuong); // X�a b?nh nh�n
                break;
            case 3:
                suaBenhNhan(dsBenhNhan, soLuong); // S?a th�ng tin b?nh nh�n
                break;
            case 4:
                hienThiDanhSach(dsBenhNhan, soLuong); // Xem danh s�ch b?nh nh�n
                break;
            case 5:
                thongKeTheoVaccine(dsBenhNhan, soLuong); // Th?ng k� b?nh nh�n theo vaccine
                break;
            case 6:
                datLichTiem(dsBenhNhan, soLuong); // �?t l?ch ti�m
                break;
            case 7:
                xemLichTiem(dsBenhNhan, soLuong); // Xem l?ch ti�m
                break;
            case 8: {
                char filename[MAX_TEN];
                printf("Nhap ten file de ghi: ");
                getchar(); // X�a b? nh? d?m
                fgets(filename, MAX_TEN, stdin);
                filename[strcspn(filename, "\n")] = '\0'; // X�a k� t? newline
                ghiDanhSachRaFile(dsBenhNhan, soLuong, filename); // Ghi danh s�ch b?nh nh�n v�o file
                break;
            }
            case 9: {
                char filename[MAX_TEN];
                printf("Nhap ten file de doc: ");
                getchar(); // X�a b? nh? d?m
                fgets(filename, MAX_TEN, stdin);
                filename[strcspn(filename, "\n")] = '\0'; // X�a k� t? newline
                docDanhSachTuFile(dsBenhNhan, &soLuong, filename); // �?c danh s�ch b?nh nh�n t? file
                break;
            }
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (luaChon != 0);
}

// H�m main
int main() {
    menu(); // G?i h�m menu d? ch?y chuong tr�nh
    return 0;
}
