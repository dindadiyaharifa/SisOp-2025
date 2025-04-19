# Benchutil

Program untuk mengukur Kemampuan CPU dalam satuan IOPS dan FLOPS.

Perintah ini digunakan untuk mengunduh, mengompilasi, dan menjalankan benchmark FLOPS (floating point operations per second) dan IOPS (input/output operations per second). Benchmark ini digunakan untuk mengukur performa sistem, khususnya dalam eksekusi operasi floating-point dan input/output.

## Langkah-langkah untuk menjalankan program:

### 1. Install Make
```bash
sudo apt install make
```
Install `make`, untuk mengotomatisasi proses kompilasi dan build dari sumber kode.

### 2. Cek Versi Make
```bash
make --version
```
Cek versi `make` yang sudah terinstall di sistem.

### 3. Install Git
```bash
sudo apt install git
```
Menginstall `git`, digunakan untuk mengelola sumber kode.

### 4. Clone Repository
```bash
git clone https://github.com/ferryastika/flops-iops.git
```
Mengunduh (clone) repository `flops-iops` dari GitHub ke dalam direktori lokal.

### 5. Pindah ke Direktori Proyek
```bash
cd flops-iops
```
Pindah ke direktori proyek `flops-iops` yang sudah di-clone.

### 6. Kompilasi Program
```bash
make
```
Jalankan `Makefile` yang ada dalam proyek untuk mengompilasi sumber kode menjadi file biner yang dapat dieksekusi.

### 7. Jalankan Benchmark IOPS
```bash
./iops64 $(nproc)
```
Menjalankan program `iops64` dengan parameter jumlah prosesor yang tersedia (`$(nproc)` mengembalikan jumlah core CPU yang ada).

### 8. Jalankan Benchmark FLOPS
```bash
./flops64 $(nproc)
```
Menjalankan program `flops64` sesuai dengan jumlah core CPU yang tersedia.

### 9. Jalankan Benchmark IOPS dengan 1 Core
```bash
./iops64 1
```
Menjalankan program `iops64` dengan hanya 1 thread atau 1 core CPU.

### 10. Bersihkan File Hasil Kompilasi
```bash
make clean
```
Membersihkan file hasil kompilasi untuk menghemat ruang atau untuk persiapan build ulang.
