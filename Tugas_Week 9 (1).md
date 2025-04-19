# TUGAS Chapter 4 - SISTEM OPERASI

**Nama** : Dinda Diyah Arifa  
**NRP** : 3124500034  
**Kelas** : 1 D3 IT B

---

## 1. Jelaskan dalam 2 paragraf disertai dengan gambar tentang konsep single thread dan multithread!

**Jawab:**  
Single thread adalah model eksekusi program di mana tugas diproses secara berurutan dalam satu alur (thread). Setiap instruksi harus diselesaikan sebelum beralih ke instruksi berikutnya, sehingga cocok untuk tugas sederhana yang tidak memerlukan paralelisasi. Contohnya adalah program yang membaca file, memproses data, lalu menampilkan hasil secara sekuensial. Kelemahannya adalah efisiensi rendah saat menangani operasi I/O atau tugas berat yang menyebabkan blocking, karena thread utama akan terhenti sampai tugas selesai.

Multithread memungkinkan program menjalankan beberapa thread secara paralel dalam satu proses, meningkatkan pemanfaatan CPU dan responsivitas aplikasi. Misalnya, server web dapat menangani banyak permintaan secara bersamaan dengan memisahkan setiap koneksi ke thread terpisah. Keunggulan utamanya adalah efisiensi dalam tugas yang melibatkan I/O, komputasi paralel, atau operasi blocking. Namun, multithreading juga punya kompleksitas seperti race condition dan deadlock, yang memerlukan sinkronisasi menggunakan mekanisme seperti mutex atau semaphore.

### Ilustrasi Single Thread vs Multithread

![Ilustrasi Single Thread vs Multithread](https://upload.wikimedia.org/wikipedia/commons/6/68/Single_vs_multithreaded_process.png)
*Sumber: Wikimedia Commons*

---
