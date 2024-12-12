#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <thread>
#include <conio.h>
#include <atomic>
using namespace std;

struct Tanaman {
    string jenis;
    int tinggi;
    int kesehatan;
    int air;
    int pupuk;
    int cahaya;
    bool hidup;
};

Tanaman tanaman;
atomic<bool> gameRunning = true;

void bonus();
void petunjuk();
void animLoad(int durasi);
void landingPage();
void saveData(Tanaman &tanaman);
void loadData(Tanaman &tanaman);
void newPlant();
void gameMenu();
void randomEvent();
void randMessage();
void panelMenang(const Tanaman &tanaman);

int main() {
    system("cls");
    animLoad(2);
    landingPage();
    return 0;
}

void animLoad(int durasi) {
    const char spinner[] = {'|', '/', '-', '\\'};
    int spinnerSize = sizeof(spinner) / sizeof(spinner[0]);
    int steps = durasi * 5;

    for (int i = 0; i < steps; ++i) {
        cout << "\rMemuat " << spinner[i % spinnerSize] << " " << (i * 100) / steps << "%" << flush;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << "\rSelesai!          " << endl;
    cout << "Tekan enter untuk melanjutkan.";
    getch();
}

void landingPage() {
    int pilihan;
    do {
        system("cls");
        cout << "=====================================" << endl;
        cout << "Selamat Datang di Simulator Tumbuhan!" << endl;
        cout << "=====================================" << endl;
        cout << "1. Load Data" << endl;
        cout << "2. Tanaman Baru" << endl;
        cout << "3. Petunjuk" << endl;
        cout << "4. Keluar/Exit" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            loadData(tanaman);
        } else if (pilihan == 2) {
            newPlant();
        } else if (pilihan == 3) {
            petunjuk();
        } else if (pilihan == 4) {
            system("cls");
            cout << "Terima kasih sudah bermain ^-^ !!!! \nDatang kembali nanti!!!" << endl;
            exit(0);
        } else {
            cout << "Menu tidak valid. Tolong pilih kembali! (tekan enter)" << endl;
            getch();
        }
    } while (pilihan != 4);
}

void saveData(Tanaman &tanaman) {
    ofstream file("tanaman.txt");
    if (file.is_open()) {
        file << tanaman.jenis << endl;
        file << tanaman.tinggi << endl;
        file << tanaman.kesehatan << endl;
        file << tanaman.air << endl;
        file << tanaman.pupuk << endl;
        file << tanaman.cahaya << endl;
        file << tanaman.hidup << endl;
        file.close();
        cout << "Tanaman berhasil disimpan!" << endl;
    } else {
        cout << "Gagal menyimpan Tanaman!" << endl;
    }
}

void loadData(Tanaman &tanaman) {
    ifstream file("tanaman.txt");
    if (file.is_open()) {
        getline(file, tanaman.jenis);
        file >> tanaman.tinggi;
        file >> tanaman.kesehatan;
        file >> tanaman.air;
        file >> tanaman.pupuk;
        file >> tanaman.cahaya;
        file >> tanaman.hidup;
        file.close();
        cout << "Tanaman berhasil dimuat!" << endl;
        gameMenu();
    } else {
        cout << "\nGagal memuat Tanaman! File tidak ditemukan." << endl;
        cout << "Tekan enter untuk kembali ke Landing Page." << endl;
        getch();
        landingPage();
    }
}

void newPlant() {
    system("cls");
    int pilihan;

    do {
        system("cls");
        cout << "====================================" << endl;
        cout << "            List Tanaman            " << endl;
        cout << "1. Lavender" << endl;
        cout << "2. Daisy" << endl;
        cout << "3. Lily of The Valley" << endl;
        cout << "4. Kembali" << endl;
        cout << "====================================" << endl;
        cout << "Pilih Tanaman atau kembali ke Menu Utama: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tanaman.jenis = "Lavender";
                tanaman.tinggi = 10;
                tanaman.kesehatan = 100;
                tanaman.air = 50;
                tanaman.pupuk = 50;
                tanaman.cahaya = 50;
                tanaman.hidup = true;
                gameMenu();
                break;
            case 2:
                tanaman.jenis = "Daisy";
                tanaman.tinggi = 12;
                tanaman.kesehatan = 100;
                tanaman.air = 60;
                tanaman.pupuk = 40;
                tanaman.cahaya = 50;
                tanaman.hidup = true;
                gameMenu();
                break;
            case 3:
                tanaman.jenis = "Lily of The Valley";
                tanaman.tinggi = 8;
                tanaman.kesehatan = 100;
                tanaman.air = 40;
                tanaman.pupuk = 60;
                tanaman.cahaya = 50;
                tanaman.hidup = true;
                gameMenu();
                break;
            case 4:
                landingPage();
                break;
            default:
                cout << "Menu yang anda pilih tidak ada. Coba masukkan kembali!!" << endl;
                getch();
        }
    } while (pilihan != 4);
}

void petunjuk() {
    system("cls");
    cout << "=======================================" << endl;
    cout << "                Petunjuk               " << endl;
    cout << "1. Anda dapat memenangkan permainan\n   jika tinggi tanaman anda diatas 30." << endl;
    cout << "2. Anda akan kalah jika tanaman anda\n   tidak tumbuh dengan sehat." << endl;
    cout << "3. Akan ada musim dan hama yang bisa\n   membantu bahkan mempersulit\n   pertumbuhan tanaman anda." << endl;
    cout << "=======================================" << endl;
    cout << "Tekan Enter untuk kembali ke Menu Utama.";
    getch();
    landingPage();
}

void gameMenu() {
    int pilihan;
    int count = 0;
    int countair = 0;
    int countpupuk = 0;
    int countcahaya = 0;
    bool menang;

    while (gameRunning) {

        system("cls");
        cout << "====================================" << endl;
        cout << "Status Tanaman: " << tanaman.jenis << endl;
        cout << "Tinggi: " << tanaman.tinggi << endl;
        cout << "Kesehatan: " << (tanaman.kesehatan > 100 ? 100 : tanaman.kesehatan) << endl;
        cout << "Air: " << (tanaman.air > 100 ? 100 : tanaman.air) << endl;
        cout << "Pupuk: " << (tanaman.pupuk > 100 ? 100 : tanaman.pupuk) << endl;
        cout << "Cahaya: " << (tanaman.cahaya > 100 ? 100 : tanaman.cahaya) << endl;
        cout << "====================================" << endl;

        if (tanaman.pupuk > 80) {
            cout << "PERINGATAN: Tanaman menerima terlalu banyak pupuk!, Kesehatan akan berkurang." << endl;
        }

        cout << "1. Siram Air" << endl;
        cout << "2. Tambah Pupuk" << endl;
        cout << "3. Berikan Cahaya" << endl;
        cout << "4. Simpan dan Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        if (pilihan == 1) {
            tanaman.air += 15;
            tanaman.cahaya -= 5;
            tanaman.pupuk -= 5;
            tanaman.kesehatan += 5;
            tanaman.tinggi += 1;
            if (tanaman.pupuk >= 85) {
                tanaman.kesehatan -= 10;    
            }
            count++;
            countair++;
            randMessage();
        }
        else if (pilihan == 2) {
            tanaman.pupuk += 30;
            tanaman.cahaya -= 10;
            tanaman.tinggi += 2;
            if (tanaman.pupuk >= 85) {
                tanaman.kesehatan -= 10;    
            }
            count++;
            countpupuk++;
            randMessage();
        }
        else if (pilihan == 3) {
            tanaman.cahaya += 15;
            tanaman.air -= 5;
            tanaman.pupuk -=10;
            tanaman.tinggi += 1;
            if (tanaman.pupuk >= 85) {
                tanaman.kesehatan -= 10;    
            }
            count++;
            countcahaya++;
            randMessage();
        }    
        else if (pilihan == 4) {
            saveData(tanaman);
            gameRunning = false;
            landingPage();
        }
        else {     
            cout << "Pilihan tidak valid!" << endl;
        }

        if (tanaman.tinggi >= 30) {
            panelMenang(tanaman);
            gameRunning = false;
            landingPage();
        }

        if (countair == 4) {
            if (countcahaya == 2) { 
                countair = 0;
                countcahaya = 0;
                bonus();
            }
        }

        if (count %4 == 0) {
            randomEvent();
        }

        
        if (tanaman.air <= 0 || tanaman.kesehatan <= 0) {
            tanaman.hidup = false;
            gameRunning = false;
            cout << "Tanaman Anda mati. Game selesai!" << endl;
            getch();
            landingPage();
        }
    }
}

void bonus() {
    cout << "Anda mendapatkan bonus percepatan tumbuhan tinggi tanaman." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    tanaman.tinggi += 5;
}


void randomEvent() {
    int event = rand() % 3;

    if (event == 0) {
        cout << "Hujan turun! Air bertambah." << endl;
        tanaman.air += 20;
    } else if (event == 1) {
        cout << "Hama menyerang! Kesehatan menurun." << endl;
        tanaman.kesehatan -= 20;
    } else if (event == 2) {
        cout << "Kemarau datang! Air akan berkurang." << endl;
            tanaman.air -= 10;
            tanaman.cahaya += 20;
    }
    this_thread::sleep_for(chrono::seconds(2));
}

void randMessage() {
    const string messages[] = {
        "Tanaman merasa senang sekali karena sudah dirawat dengan baik.",
        "Tanaman tumbuh subur dan berterima kasih!",
        "Tanaman menyerap nutrisi dengan bahagia!",
        "Tanaman merasa dihargai oleh Anda!",
        "Matkul Bu Febri seru banget!"
    };

    cout << messages[rand() % 4] << endl;
    this_thread::sleep_for(chrono::seconds(2));
}

void lavender() {
    cout << "        *" << endl;
    cout << "       ***" << endl;
    cout << "      *****" << endl;
    cout << "       ***" << endl;
    cout << "        *" << endl;
    cout << "        |" << endl;
    cout << "        |" << endl;
    cout << "        |" << endl;
    cout << "        |" << endl;
    cout << "        |" << endl;
    cout << "       /|\\" << endl;
    cout << "      //|\\\\" << endl;
    cout << "     ///|\\\\\\" << endl;
    cout << "        |" << endl;
    cout << "        |" << endl;
    cout << "        |" << endl;
    cout << "       /|\\" << endl;
    cout << "      //|\\\\" << endl;
    cout << "     ///|\\\\\\" << endl;
    cout << "        |" << endl;
    cout << "        |" << endl;
    cout << "        |" << endl;
    cout << "       / \\" << endl;
    cout << "      /   \\" << endl;
    cout << "     /     \\" << endl;
}

void daisy() {
    cout << "        @@@        " << endl;
    cout << "      @@@@@@@      " << endl;
    cout << "   @@@@@@@@@@@@@   " << endl;
    cout << "  @@@@@@@@@@@@@@@  " << endl;
    cout << "   @@@@@@@@@@@@@   " << endl;
    cout << "      @@@@@@@      " << endl;
    cout << "        @@@        " << endl;
    cout << "         |         " << endl;
    cout << "         |         " << endl;
    cout << "        /|\\        " << endl;
    cout << "       //|\\\\       " << endl;
    cout << "      ///|\\\\\\      " << endl;
    cout << "         |         " << endl;
    cout << "         |         " << endl;
    cout << "         |         " << endl;
    cout << "        / \\        " << endl;
    cout << "       /   \\       " << endl;
    cout << "      /     \\      " << endl;
}

void lily() {
    cout << "         __         " << endl;
    cout << "        |  |        " << endl;
    cout << "       (    )       " << endl;
    cout << "        |  |        " << endl;
    cout << "        |  |        " << endl;
    cout << "     __/    \\__     " << endl;
    cout << "    |          |    " << endl;
    cout << "   (            )   " << endl;
    cout << "    |          |    " << endl;
    cout << "     \\__    __/     " << endl;
    cout << "        |  |        " << endl;
    cout << "        |  |        " << endl;
    cout << "         |||         " << endl;
    cout << "         |||         " << endl;
    cout << "        //|\\\\       " << endl;
    cout << "       ///|\\\\\\      " << endl;
    cout << "         |||         " << endl;
    cout << "         |||         " << endl;
    cout << "        /   \\        " << endl;
    cout << "       /     \\       " << endl;
    cout << "      /       \\      " << endl;
}

void panelMenang(const Tanaman &tanaman) {
    system("cls");
    if (tanaman.jenis == "Lavender") {
        lavender();
    } else if (tanaman.jenis == "Daisy") {
        daisy();
    } else if (tanaman.jenis == "Lily of The Valley") {
        lily();
    }

    cout << "====================================" << endl;
    cout << "             SELAMAT!!!             " << endl;
    cout << "    Anda telah berhasil merawat     " << endl;
    cout << "        tanaman dengan baik!        " << endl;
    cout << "====================================" << endl;

    cout << "Tanaman Anda kini telah tumbuh \nsubur dan bahagia." << endl;
    cout << "Terima kasih telah bermain!" << endl;
    cout << "====================================" << endl;
    cout << "Tekan Enter untuk keluar." << endl;
    getch();
}
