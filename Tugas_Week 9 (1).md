# TUGAS Chapter 4 - SISTEM OPERASI

**Nama** : Dinda Diyah Arifa  
**NRP** : 3124500034  
**Kelas** : 1 D3 IT B

---

# 1. Jelaskan dalam 2 paragraf disertai dengan gambar tentang konsep single thread dan multithread!

**Jawab:**  
Single thread adalah model eksekusi program di mana tugas diproses secara berurutan dalam satu alur (thread). Setiap instruksi harus diselesaikan sebelum beralih ke instruksi berikutnya, sehingga cocok untuk tugas sederhana yang tidak memerlukan paralelisasi. Contohnya adalah program yang membaca file, memproses data, lalu menampilkan hasil secara sekuensial. Kelemahannya adalah efisiensi rendah saat menangani operasi I/O atau tugas berat yang menyebabkan blocking, karena thread utama akan terhenti sampai tugas selesai.

Multithread memungkinkan program menjalankan beberapa thread secara paralel dalam satu proses, meningkatkan pemanfaatan CPU dan responsivitas aplikasi. Misalnya, server web dapat menangani banyak permintaan secara bersamaan dengan memisahkan setiap koneksi ke thread terpisah. Keunggulan utamanya adalah efisiensi dalam tugas yang melibatkan I/O, komputasi paralel, atau operasi blocking. Namun, multithreading juga punya kompleksitas seperti race condition dan deadlock, yang memerlukan sinkronisasi menggunakan mekanisme seperti mutex atau semaphore.

### Ilustrasi Single Thread vs Multithread

![Single vs Multi Thread](https://www.mahirkoding.com/wp-content/uploads/2017/11/Review_Singlevs.Multi-ThreadedProcesses.jpg)

ubah ke md file text berikut Berikut template jawaban dalam format Markdown (`.md`) untuk Programming Exercise tentang thread:

# 2. Programming Exercise: Thread Implementation

## A. Penerapan Thread pada SumTask.java

### Kode Implementasi
```java
import java.util.concurrent.*;

class SumTask implements Runnable {
    private int[] array;
    private int start, end;
    private long partialSum;

    // Constructor
    public SumTask(int[] array, int start, int end) {
        this.array = array;
        this.start = start;
        this.end = end;
    }

    public long getPartialSum() {
        return partialSum;
    }

    @Override
    public void run() {
        partialSum = 0;
        for (int i = start; i < end; i++) {
            partialSum += array[i];
        }
    }
}

public class ParallelSum {
    public static void main(String[] args) throws InterruptedException {
        int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int threadCount = 2;
        
        ExecutorService executor = Executors.newFixedThreadPool(threadCount);
        SumTask[] tasks = new SumTask[threadCount];

        // Pembagian tugas
        for (int i = 0; i < threadCount; i++) {
            int start = i * (array.length / threadCount);
            int end = (i == threadCount - 1) ? array.length : start + (array.length / threadCount);
            tasks[i] = new SumTask(array, start, end);
            executor.execute(tasks[i]);
        }

        executor.shutdown();
        executor.awaitTermination(1, TimeUnit.MINUTES);

        // Penggabungan hasil
        long totalSum = 0;
        for (SumTask task : tasks) {
            totalSum += task.getPartialSum();
        }
        
        System.out.println("Total Sum: " + totalSum);
    }
}
```

- **Hasil Eksekusi**:
  ```bash
  javac ParallelSum.java
  java ParallelSum
  ```
  Output: `Total Sum: 55`

---

## B. Penerapan Thread di Linux dan Windows

### 1. POSIX Threads (Linux) - thrd-posix.c
```c
#include <pthread.h>
#include <stdio.h>

void* task(void* arg) {
    printf("Thread berjalan di Linux\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, task, NULL);
    pthread_join(thread, NULL);
    return 0;
}
```
### Hasil Eksekusi
```bash
dinda@vbox:~/osc1&e/ch4$ ./posix 10
sum = 55
```
### 2. WinAPI Threads (Windows) - thrd-win32.c
```c
#include <windows.h>
#include <stdio.h>

DWORD WINAPI task(LPVOID lpParam) {
    printf("Thread berjalan di Windows\n");
    return 0;
}

int main() {
    HANDLE thread = CreateThread(NULL, 0, task, NULL, 0, NULL);
    WaitForSingleObject(thread, INFINITE);
    CloseHandle(thread);
    return 0;
}
```
### Hasil Eksekusi
```bash
PS C:\Users\ACER-GK\osc10e\ch4> .\thrd-win32.exe 5
sum = 15
```
### C Essay Perbandingan

**Perbedaan Utama:**
1. **Library**:
   - POSIX menggunakan `<pthread.h>`
   - WinAPI menggunakan `<windows.h>`

2. **Portabilitas**:
   - POSIX thread dapat berjalan di berbagai sistem UNIX-like
   - WinAPI hanya untuk Windows

3. **Manajemen Thread**:
   - POSIX menggunakan `pthread_t` sebagai identifier
   - WinAPI menggunakan `HANDLE`

# 3. Kerjakan Chapter 4: Threads & Concurrency – Practice Exercises

## 4.1 Three Programming Examples Where Multithreading Outperforms Single Threading

### 1. Web Server
Web server seperti Apache atau Nginx memanfaatkan multithreading agar bisa melayani banyak permintaan pengguna secara paralel. Jika menggunakan single thread, hanya satu pengguna bisa dilayani pada satu waktu, menyebabkan delay besar.

### 2. Image Processing
Aplikasi pengeditan gambar (seperti Photoshop) dapat memproses berbagai filter secara paralel untuk setiap bagian gambar, sehingga mempercepat keseluruhan proses dibanding single thread.

### 3. Parallel File Download
Aplikasi pengunduh (download manager) bisa mengunduh berbagai bagian file secara bersamaan (multithread), yang jauh lebih cepat dibandingkan mengunduh satu bagian per satu waktu.

---

## 4.2 Amdahl’s Law Speedup Calculation

### Rumus Amdahl’s Law:
\[
\text{Speedup} = \frac{1}{(1 - P) + \frac{P}{N}}
\]

Dengan:
- \( P = 0.6 \) (komponen paralel)
- \( N \) = jumlah core

### a) Dua core:
\[
\text{Speedup} = \frac{1}{(1 - 0.6) + \frac{0.6}{2}} = \frac{1}{0.4 + 0.3} = \frac{1}{0.7} \approx 1.43
\]

### b) Empat core:
\[
\text{Speedup} = \frac{1}{(1 - 0.6) + \frac{0.6}{4}} = \frac{1}{0.4 + 0.15} = \frac{1}{0.55} \approx 1.82
\]

---

## 4.3 Task or Data Parallelism in Multithreaded Web Server

Multithreaded web server menunjukkan **task parallelism**, karena setiap thread menangani permintaan yang berbeda dari klien yang berbeda. Setiap tugas adalah mandiri, bukan bagian dari satu data yang dibagi-bagi.

---

## 4.4 User-Level vs Kernel-Level Threads

### Perbedaan:

#### User-Level Threads:
- Dikelola oleh user-level thread library (bukan oleh OS).
- Switching antar thread lebih cepat karena tidak perlu interaksi dengan kernel.

#### Kernel-Level Threads:
- Dikelola langsung oleh sistem operasi.
- Dapat dieksekusi secara paralel di banyak core.

### Kapan lebih baik?
- **User-level threads** cocok untuk aplikasi dengan **context switching tinggi** dan tidak membutuhkan paralelisme sejati.
- **Kernel-level threads** lebih baik untuk aplikasi yang membutuhkan **eksekusi paralel di banyak core**.

---

## 4.5 Kernel Actions During Context-Switch Between Kernel-Level Threads

Saat melakukan context switch antar kernel-level thread, kernel melakukan langkah-langkah berikut:

1. Menyimpan state (register, program counter, stack pointer) dari thread yang sedang berjalan ke PCB (Process Control Block).
2. Memuat state dari thread tujuan dari PCB ke CPU register.
3. Update tabel scheduler dan kontrol akses resource jika perlu.
4. Transfer kontrol eksekusi ke thread baru.


---
