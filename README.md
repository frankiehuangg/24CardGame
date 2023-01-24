# Penyelesaian **Permainan Kartu 24** dengan Algoritma Brute Force
> Tugas Kecil 1 IF2211 Strategi Algoritma
>
> Aplikasi algoritma **Brute Force** pada Permainan Kartu 24
>
> 13521092 - Frankie Huang

## Daftar isi
* [Tentang Proyek](#tentang-proyek)
* [Fitur](#fitur)
* [Requirement](#requirement)
* [Setup](#setup)
* [Status Proyek](#status-proyek)
* [Room for Improvement](#room-for-improvement)
* [Acknowledgements](#acknowledgements)


## Tentang Proyek
- Penyelesaian [permainan kartu 24](http://24solver.us-west-2.elasticbeanstalk.com/?n1=1&n2=11&n3=12&n4=13) menggunakan algoritma brute force.
- Program berupa TUI.
- Input berupa masukan pengguna, output berupa keluaran program pada terminal dan/atau penyimpanan dalam file.
- Dicompile pada kernel Linux v.6.1.6


## Fitur
Program dapat menjalankan fitur-fitur:
- Menyelesaikan permainan kartu 24.
- Input berupa kartu acak.
- Output berupa penyimpanan keluaran pada file.


## Requirement
- C++
- g++


## Setup
Pastikan semua requirements telah ter-install pada local machine.

Kemudian clone repository berikut ini.
```sh
git clone https://github.com/frankiehuangg/Tucil1_13521092.git
```

Masuk ke repository, lalu compile ulang agar sesuai dengan local machine.
```sh
cd Tucil1_13521092
g++ src/main.cpp -O1 -o bin/main
```

Terakhir, execute file binary dengan command berikut.
```sh
./bin/main
```


## Status Proyek
Proyek telah: _selesai_.

*Tidak ada rencana perubahan, penambahan, maupun optimisasi program dalam jangka waktu dekat.*


## Room for Improvement
Room for improvement:
- Pembuatan GUI agar program tampak lebih menarik.


## Acknowledgements
- Tugas ini dipelopori oleh mata kuliah IF2211 Teknik Informatika Institut Teknologi Bandung, yang telah diorganisasikan dengan baik oleh tim pengajar dan asisten-asisten IF2211 - 2023.
- Template README oleh [@flynerdpl](https://www.flynerd.pl/): [README](https://github.com/ritaly/README-cheatsheet)
- Terima kasih kepada sumber-sumber referensi dan metode sebagai dasar yang telah dicantumkan pada bagian-bagian yang bersangkutan dalam source code
