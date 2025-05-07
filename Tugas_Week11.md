# FCFS Scheduling Algorithm

**Kelas:** 1 D3 IT B
**Nama Kelompok:**

* Dinda Diyah Arifa (3124500034)
* Oktavia Ramadhani (3124500038)
* Yosiyanti Cendekiasari (3124500059)

---

## 1. FCFS Scheduling Algorithm Without Arrival Time (AT)

### Code Program

```c
#include <stdio.h>

struct proc {
    int no, bt, ct, tat, wt;
};

struct proc read(int i) {
    struct proc p;
    printf("\nProcess No: %d\n", i);
    p.no = i;
    printf("Enter Burst Time: ");
    scanf("%d", &p.bt);
    return p;
}

int main() {
    struct proc p[10], tmp;
    float avgtat = 0, avgwt = 0;
    int n, ct = 0;

    printf("<-- FCFS Scheduling Algorithm Without Arrival Time (Non-Preemptive) -->\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        p[i] = read(i + 1);

    printf("\nProcessNo\tBT\tCT\tTAT\tWT\tRT\n");

    for (int i = 0; i < n; i++) {
        ct += p[i].bt;
        p[i].ct = p[i].tat = ct;
        avgtat += p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        avgwt += p[i].wt;
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n", p[i].no, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].wt);
    }

    avgtat /= n;
    avgwt /= n;
    printf("\nAverage TurnAroundTime = %f\nAverage WaitingTime = %f\n", avgtat, avgwt);
}
```

### Analisa

Program ini mengimplementasikan algoritma penjadwalan CPU **First-Come, First-Served (FCFS)** *non-preemptive*. CPU akan menjalankan proses sesuai urutan kedatangan tanpa interupsi hingga selesai.

**Struktur data** `struct proc` digunakan untuk menyimpan informasi proses seperti:

* `no`: nomor proses
* `bt`: burst time
* `ct`: completion time
* `tat`: turnaround time
* `wt`: waiting time

### Contoh Output & Perhitungan

**Input:**

```
Enter Number of Processes: 5

Process No: 1
Enter Burst Time: 3
Process No: 2
Enter Burst Time: 1
Process No: 3
Enter Burst Time: 4
Process No: 4
Enter Burst Time: 5
Process No: 5
Enter Burst Time: 2
```

**Output:**

```
ProcessNo   BT   CT   TAT  WT   RT
P1          3    3    3    0    0
P2          1    4    4    3    3
P3          4    8    8    4    4
P4          5    13   13   8    8
P5          2    15   15   13   13

Average TurnAroundTime = 8.600000
Average WaitingTime = 5.600000
```

### Rumus Perhitungan Manual

1. **Completion Time (CT):**

   ```
   CT1 = BT1
   CTi = CT(i-1) + BTi
   ```

   Hasil: 3, 4, 8, 13, 15

2. **Turnaround Time (TAT):**

   ```
   TAT = CT - AT (AT = 0)
   ```

   Hasil: 3, 4, 8, 13, 15

3. **Waiting Time (WT):**

   ```
   WT = TAT - BT
   ```

   Hasil: 0, 3, 4, 8, 13

4. **Response Time (RT):**

   ```
   RT = WT
   ```

   Hasil: 0, 3, 4, 8, 13

5. **Rata-rata:**

   ```
   TAT = (3 + 4 + 8 + 13 + 15) / 5 = 8.6
   WT  = (0 + 3 + 4 + 8 + 13) / 5 = 5.6
   ```

---

## 2. FCFS Scheduling Algorithm With Arrival Time (AT)

### Code Program

```c
#include <stdio.h>

struct proc {
    int no, at, bt, ct, tat, wt;
};

struct proc read(int i) {
    struct proc p;
    printf("\nProcess No: %d\n", i);
    p.no = i;
    printf("Enter Arrival Time: ");
    scanf("%d", &p.at);
    printf("Enter Burst Time: ");
    scanf("%d", &p.bt);
    return p;
}

int main() {
    struct proc p[10], tmp;
    float avgtat = 0, avgwt = 0;
    int n, ct = 0;

    printf("<-- FCFS Scheduling Algorithm (Non-Preemptive) -->\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        p[i] = read(i + 1);

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (p[j].at > p[j + 1].at) {
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }

    printf("\nProcessNo\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for (int i = 0; i < n; i++) {
        if (ct < p[i].at) ct = p[i].at;
        ct += p[i].bt;
        p[i].ct = ct;
        p[i].tat = p[i].ct - p[i].at;
        avgtat += p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        avgwt += p[i].wt;

        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].no, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].wt);
    }

    avgtat /= n;
    avgwt /= n;
    printf("\nAverage TurnAroundTime = %f\nAverage WaitingTime = %f\n", avgtat, avgwt);
}
```

### Analisa

Program ini mengimplementasikan FCFS *Non-Preemptive* dengan mempertimbangkan **Arrival Time (AT)**. Proses akan dieksekusi berdasarkan waktu kedatangannya.

### Contoh Output & Perhitungan

**Input:**

```
Enter Number of Processes: 4

Process No: 1
Enter Arrival Time: 0
Enter Burst Time: 8

Process No: 2
Enter Arrival Time: 1
Enter Burst Time: 4

Process No: 3
Enter Arrival Time: 2
Enter Burst Time: 9

Process No: 4
Enter Arrival Time: 3
Enter Burst Time: 5
```

**Output:**

```
ProcessNo   AT   BT   CT   TAT  WT   RT
P1          0    8    8    8    0    0
P2          1    4    12   11   7    7
P3          2    9    21   19   10   10
P4          3    5    26   23   18   18

Average TurnAroundTime = 15.250000
Average WaitingTime = 8.750000
```

### Rumus Perhitungan Manual

1. **Completion Time (CT):**

   ```
   CTi = max(CT(i-1), ATi) + BTi
   ```

   Hasil: 8, 12, 21, 26

2. **Turnaround Time (TAT):**

   ```
   TAT = CT - AT
   ```

   Hasil: 8, 11, 19, 23

3. **Waiting Time (WT):**

   ```
   WT = TAT - BT
   ```

   Hasil: 0, 7, 10, 18

4. **Response Time (RT):**

   ```
   RT = WT
   ```

   Hasil: 0, 7, 10, 18

5. **Rata-rata:**

   ```
   TAT = (8 + 11 + 19 + 23) / 4 = 15.25
   WT  = (0 + 7 + 10 + 18) / 4 = 8.75
   ```
