Tentu, mari kita analisis kode C ini baris per baris dengan penjelasan yang rinci dan mudah dipahami:

c
#include<stdio.h>

* **#include<stdio.h>*: Sama seperti sebelumnya, ini adalah *preprocessor directive yang menyertakan isi dari file header stdio.h. File ini menyediakan fungsi-fungsi standar untuk input dan output, seperti printf dan scanf. Tanpa baris ini, Anda tidak dapat menggunakan fungsi-fungsi tersebut.

c
struct proc
{
    int no,bt,ct,tat,wt;
};

* **struct proc**: Kata kunci struct mendefinisikan sebuah struktur data baru bernama proc. Struktur ini memungkinkan Anda mengelompokkan beberapa variabel dengan tipe data yang mungkin berbeda di bawah satu nama.
* **{ ... }**: Kurung kurawal ini mengapit anggota-anggota (members) dari struktur proc.
* **int no,bt,ct,tat,wt;**: Di dalam struktur proc, dideklarasikan lima variabel bertipe integer (int):
    * **no**: Kemungkinan digunakan untuk menyimpan nomor identifikasi proses.
    * **bt**: Singkatan dari "Burst Time" (Waktu Eksekusi). Ini menyimpan total waktu yang dibutuhkan CPU untuk menyelesaikan suatu proses.
    * **ct**: Singkatan dari "Completion Time" (Waktu Selesai). Ini menyimpan waktu ketika suatu proses selesai dieksekusi.
    * **tat**: Singkatan dari "Turnaround Time" (Waktu Tanggap). Ini adalah total waktu yang dihabiskan suatu proses dalam sistem, dihitung dari waktu kedatangan hingga waktu selesai. Karena kode ini tidak secara eksplisit mencatat waktu kedatangan, dalam konteks ini, diasumsikan waktu kedatangan semua proses adalah 0 atau mereka tiba secara berurutan tanpa penundaan.
    * **wt**: Singkatan dari "Waiting Time" (Waktu Tunggu). Ini adalah total waktu yang dihabiskan suatu proses menunggu di antrian sebelum dieksekusi oleh CPU.

c
struct proc read(int i)
{
    struct proc p;
    printf("\nProcess No: %d\n",i);
    p.no=i;
    printf("Enter Burst Time: ");
    scanf("%d",&p.bt);
    return p;
}

* **struct proc read(int i)**: Ini adalah definisi dari sebuah fungsi bernama read.
    * **struct proc**: Menunjukkan bahwa fungsi ini akan mengembalikan sebuah variabel bertipe struct proc.
    * **read**: Nama dari fungsi.
    * **(int i)**: Menunjukkan bahwa fungsi ini menerima satu parameter input berupa bilangan bulat (int) yang diberi nama i. Parameter ini kemungkinan digunakan untuk merepresentasikan nomor proses.
* **{ ... }**: Kurung kurawal ini mengapit badan (body) dari fungsi read.
* **struct proc p;**: Di dalam fungsi, dideklarasikan sebuah variabel bernama p yang bertipe struct proc. Variabel ini akan digunakan untuk menyimpan informasi tentang satu proses yang akan dibaca dari pengguna.
* **printf("\nProcess No: %d\n",i);**: Fungsi printf mencetak output ke layar. \n adalah karakter newline (baris baru). %d adalah format specifier yang akan digantikan oleh nilai dari variabel integer i (nomor proses).
* **p.no=i;**: Nilai dari parameter i (nomor proses) di присваивается (assigned) ke anggota no dari struktur p.
* **printf("Enter Burst Time: ");**: Mencetak pesan ke layar untuk meminta pengguna memasukkan waktu eksekusi (Burst Time) proses.
* **scanf("%d",&p.bt);**: Fungsi scanf membaca input dari keyboard. "%d" adalah format specifier untuk membaca bilangan bulat desimal. &p.bt adalah alamat memori dari anggota bt dari struktur p. Nilai waktu eksekusi yang dimasukkan pengguna akan disimpan ke dalam p.bt.
* **return p;**: Kata kunci return mengembalikan nilai dari fungsi. Dalam kasus ini, fungsi read mengembalikan variabel p yang bertipe struct proc dan berisi informasi (nomor dan waktu eksekusi) dari proses yang baru saja dibaca.

c
int main()
{
    struct proc p[10],tmp;
    float avgtat=0,avgwt=0;
    int n,ct=0;
    printf("<--FCFS Scheduling Algorithm Without Arrival Time (Non-Preemptive)-->\n");
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        p[i]=read(i+1);
    printf("\nProcessNo\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++)
    {
        ct+=p[i].bt;
        p[i].ct=p[i].tat=ct;
        avgtat+=p[i].tat;
        p[i].wt=p[i].tat-p[i].bt;
        avgwt+=p[i].wt;
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].wt);
    }
    avgtat/=n,avgwt/=n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f",avgtat,avgwt);
}

* **int main()**: Ini adalah fungsi utama di mana eksekusi program dimulai. int menunjukkan bahwa fungsi main akan mengembalikan nilai bertipe integer (biasanya 0 untuk menandakan eksekusi yang sukses).
* **{ ... }**: Kurung kurawal ini mengapit badan (body) dari fungsi main.
* **struct proc p[10],tmp;**: Mendeklarasikan dua variabel:
    * **struct proc p[10]**: Mendeklarasikan sebuah array bernama p yang dapat menampung hingga 10 elemen, di mana setiap elemennya bertipe struct proc. Array ini akan digunakan untuk menyimpan informasi tentang beberapa proses.
    * **struct proc tmp;**: Mendeklarasikan sebuah variabel bernama tmp bertipe struct proc. Meskipun dideklarasikan, variabel tmp tidak digunakan dalam kode ini. Ini bisa jadi sisa dari implementasi algoritma yang memerlukan pertukaran (swapping) proses berdasarkan waktu kedatangan (seperti FCFS dengan waktu kedatangan yang berbeda), tetapi dalam versi ini, waktu kedatangan diabaikan.
* **float avgtat=0,avgwt=0;**: Mendeklarasikan dua variabel bertipe float (bilangan desimal) dan menginisialisasinya dengan nilai 0:
    * **avgtat**: Akan digunakan untuk menyimpan total waktu tanggap (Turnaround Time) dari semua proses. Nantinya akan dibagi dengan jumlah proses untuk mendapatkan waktu tanggap rata-rata.
    * **avgwt**: Akan digunakan untuk menyimpan total waktu tunggu (Waiting Time) dari semua proses. Nantinya akan dibagi dengan jumlah proses untuk mendapatkan waktu tunggu rata-rata.
* **int n,ct=0;**: Mendeklarasikan dua variabel bertipe int:
    * **n**: Akan digunakan untuk menyimpan jumlah proses yang akan diinput oleh pengguna.
    * **ct**: Singkatan dari "Current Time" (Waktu Saat Ini) atau "Completion Time" (Waktu Selesai) kumulatif. Diinisialisasi dengan 0 dan akan digunakan untuk menghitung waktu selesai setiap proses.
* **printf("<--FCFS Scheduling Algorithm Without Arrival Time (Non-Preemptive)-->\n");**: Mencetak judul program ke layar, yang mengindikasikan bahwa program ini mengimplementasikan algoritma penjadwalan FCFS (First-Come, First-Served) yang bersifat non-preemptive, tetapi tanpa mempertimbangkan waktu kedatangan (atau menganggap semua proses tiba pada waktu 0 atau secara berurutan tanpa penundaan).
* **printf("Enter Number of Processes: ");**: Meminta pengguna untuk memasukkan jumlah proses yang ingin dijadwalkan.
* **scanf("%d",&n);**: Membaca jumlah proses yang dimasukkan pengguna dan menyimpannya ke dalam variabel n.
* **for(int i=0;i<n;i++)*: Ini adalah sebuah *loop for yang akan berjalan sebanyak n kali (untuk setiap proses).
* **p[i]=read(i+1);**: Di dalam loop, fungsi read dipanggil dengan argumen i+1. Fungsi read akan meminta pengguna untuk memasukkan waktu eksekusi (Burst Time) untuk proses ke-(i+1), dan kemudian mengembalikan sebuah struktur proc yang berisi nomor dan waktu eksekusi proses tersebut. Struktur yang dikembalikan ini disimpan ke dalam elemen ke-i dari array p.
* **printf("\nProcessNo\tBT\tCT\tTAT\tWT\tRT\n");**: Mencetak header tabel yang akan menampilkan informasi setiap proses (Nomor Proses, Waktu Eksekusi, Waktu Selesai, Waktu Tanggap, Waktu Tunggu, dan Waktu Respon). Karena tidak ada waktu kedatangan, waktu respon (RT) dalam kasus FCFS non-preemptive tanpa waktu kedatangan yang berbeda akan sama dengan 0 (jika kita menganggap proses langsung dieksekusi) atau sama dengan waktu tunggu (WT) jika ada proses yang menunggu giliran. Dalam implementasi ini, nilai RT tidak dihitung secara eksplisit.
* **for(int i=0;i<n;i++)**: Ini adalah loop lain yang berjalan sebanyak n kali, untuk menghitung dan mencetak informasi setiap proses. Karena tidak ada pengurutan berdasarkan waktu kedatangan (karena tidak ada informasi waktu kedatangan), proses akan diproses dalam urutan input.
* **{ ... }**: Blok kode ini akan dieksekusi untuk setiap proses dalam array p.
* **ct+=p[i].bt;**: Menghitung waktu selesai (Completion Time) dari proses saat ini. Karena ini adalah algoritma FCFS non-preemptive dan tanpa waktu kedatangan yang berbeda, waktu selesai proses saat ini adalah waktu selesai proses sebelumnya ditambah dengan waktu eksekusi (Burst Time) proses saat ini. Untuk proses pertama (i=0), ct akan sama dengan waktu eksekusinya karena ct diinisialisasi dengan 0.
* **p[i].ct=p[i].tat=ct;**: Menetapkan nilai waktu selesai (ct) ke anggota ct (Completion Time) dan tat (Turnaround Time) dari struktur proses saat ini (p[i]). Karena tidak ada waktu kedatangan (atau diasumsikan 0), maka Waktu Tanggap (TAT) sama dengan Waktu Selesai (CT).
* **avgtat+=p[i].tat;**: Menambahkan waktu tanggap proses saat ini ke variabel avgtat untuk menghitung total waktu tanggap dari semua proses.
* **p[i].wt=p[i].tat-p[i].bt;**: Menghitung waktu tunggu (Waiting Time) untuk proses saat ini dengan mengurangkan waktu eksekusi (bt) dari waktu tanggap (tat), dan menyimpannya ke dalam p[i].wt.
* **avgwt+=p[i].wt;**: Menambahkan waktu tunggu proses saat ini ke variabel avgwt untuk menghitung total waktu tunggu dari semua proses.
* **printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].wt);**: Mencetak informasi proses saat ini ke layar dalam format tabel. P%d mencetak "P" diikuti dengan nomor proses (p[i].no). Perhatikan bahwa nilai waktu tunggu (p[i].wt) dicetak dua kali, kemungkinan salah satu seharusnya adalah waktu respon (RT), tetapi karena tidak ada waktu kedatangan yang berbeda, waktu respon untuk FCFS non-preemptive biasanya dianggap sama dengan 0 atau sama dengan waktu tunggu.
* **avgtat/=n,avgwt/=n;**: Setelah loop selesai, baris ini menghitung waktu tanggap rata-rata (avgtat) dan waktu tunggu rata-rata (avgwt) dengan membagi total waktu tanggap dan total waktu tunggu dengan jumlah proses (n).
* **printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f",avgtat,avgwt);**: Mencetak nilai waktu tanggap rata-rata dan waktu tunggu rata-rata ke layar. %f adalah format specifier untuk mencetak nilai bertipe float.

Singkatnya, kode ini mengimplementasikan algoritma penjadwalan FCFS non-preemptive di mana waktu kedatangan semua proses dianggap sama (atau tidak relevan). Proses-proses dieksekusi dalam urutan input, dan program menghitung serta menampilkan waktu selesai, waktu tanggap, waktu tunggu, dan rata-rata waktu tanggap serta waktu tunggu. Tidak ada pengurutan proses berdasarkan waktu kedatangan dalam kode ini.
