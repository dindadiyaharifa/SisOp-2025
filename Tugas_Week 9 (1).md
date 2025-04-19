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

![Single vs Multi Thread](https://www.mahirkoding.com/wp-content/uploads/2017/11/Review_Singlevs.Multi-ThreadedProcesses.jpg)

## 2.	Kerjakan Programming Exercise
**Jawab:**  
git clone https://github.com/ferryastika/osc10e.git
cd osc10e
git pull origin master
cd ch4
javac SumTask.java
java SumTask
```java
import java.util.concurrent.*;

class SumTask implements Runnable {
    private int[] array;
    private int start, end;
    private long partialSum;

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

public class SumTask {
    public static void main(String[] args) throws InterruptedException {
        int[] array = new int[1000];
        for (int i = 0; i < array.length; i++) {
            array[i] = i + 1;
        }
        
        int threadCount = 4;
        ExecutorService executor = Executors.newFixedThreadPool(threadCount);
        SumTask[] tasks = new SumTask[threadCount];

        for (int i = 0; i < threadCount; i++) {
            int start = i * (array.length / threadCount);
            int end = (i == threadCount - 1) ? array.length : start + (array.length / threadCount);
            tasks[i] = new SumTask(array, start, end);
            executor.execute(tasks[i]);
        }

        executor.shutdown();
        executor.awaitTermination(1, TimeUnit.MINUTES);

        long totalSum = 0;
        for (SumTask task : tasks) {
            totalSum += task.getPartialSum();
        }
        System.out.println("The sum is " + totalSum);
    }
}
---
