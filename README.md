# Simulator Tumbuhan

Simulator Tumbuhan adalah sebuah permainan berbasis terminal yang memungkinkan pengguna untuk merawat tanaman virtual. Pengguna dapat memilih tanaman, memberikan air, pupuk, dan cahaya agar tanaman dapat tumbuh dengan sehat.

## Fitur
- Memilih jenis tanaman yang akan dirawat.
- Menyiram tanaman dengan air agar tetap hidup.
- Memberikan pupuk untuk mempercepat pertumbuhan.
- Memberikan cahaya agar tanaman tetap sehat.
- Menyimpan dan memuat data tanaman dari file.
- Menghadapi kejadian acak seperti hujan, hama, dan musim kemarau.
- Menampilkan animasi pertumbuhan tanaman hingga mencapai kemenangan.

## Cara Menjalankan
1. Pastikan Anda memiliki **compiler C++** seperti MinGW atau menggunakan Visual Studio Code dengan ekstensi C++.
2. Unduh atau klon repositori ini.
3. Buka terminal di dalam folder proyek.
4. Jalankan perintah berikut untuk mengompilasi kode:
   ```bash
   g++ plant.cpp -o plant.exe
   ```
5. Jalankan program dengan perintah berikut:
   ```bash
   plant.exe
   ```

## Kontrol Permainan
- **1** - Menyiram tanaman.
- **2** - Memberikan pupuk.
- **3** - Memberikan cahaya.
- **4** - Menyimpan dan keluar dari permainan.

## Syarat Kemenangan
- Tanaman akan dianggap tumbuh dengan sukses jika tingginya mencapai **30 satuan**.
- Jika kesehatan atau air habis, tanaman akan mati dan permainan berakhir.

## Penyimpanan Data
Data tanaman disimpan dalam file `tanaman.txt`, yang memungkinkan pengguna untuk melanjutkan permainan dari sesi sebelumnya.

## Dependencies
- C++ Standard Library
- `<iostream>`
- `<fstream>`
- `<string>`
- `<cstdlib>`
- `<ctime>`
- `<iomanip>`
- `<chrono>`
- `<thread>`
- `<conio.h>` (hanya untuk Windows)
- `<atomic>`

## Catatan
- Saat ini program hanya berjalan di **Windows**, karena menggunakan `<conio.h>` untuk menangani input pengguna.
- Jika ingin menjalankan di **Linux atau macOS**, Anda perlu mengganti `getch()` dengan `cin.get()` atau implementasi lain yang sesuai.
