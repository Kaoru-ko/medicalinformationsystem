#include <iostream> // library buat input output dsb
#include <string.h> // buat string 
#include <conio.h> // buat clearscreen, pause, exit(0)
#include <sstream> // buat stringstream buat kode di antrian
using namespace std;

    bool riwayatada;
	int Poliklinik,dokter,hari,bulan,antrian = 1; // Antrian mulai dari 1
    string Kunjungan_H,Kunjungan_B,Kunjungan_J,Kunjungan_T,noantri,namapoliklinik,namadokter;
    string namadepan,namabelakang,gender,alamat,kontak;
        int main();
        void login();
        void menuu();
        void poliklinik();
        void riwayat();
        void identitas();

void login (){
    string user,pass,u,p;
    system("cls");
    cout<<"MENU LOGIN"<<endl;
    cout<<"username : "; cin>>user;
    cout<<"password : "; cin>>pass;
                    if (user == "admin" && pass == "admin"){
                    menuu();
                    }
                    else{
                    system("cls");
                    cout<<"password atau user salah, tekan enter untuk kembali . . ."<<endl;
                    main();
                    } 
}
void menuu() {
    int mileh;
    do{
    system("cls");
    cout<<"1. IDENTITAS DIRI"<<endl;
    cout<<"2. DAFTAR POLIKLINIK"<<endl;
    cout<<"3. Riwayat Kunjungan"<<endl;
    cout<<"4. KEMBALI KE HALAMAN LOGIN"<<endl;
    cout<<"PILIH OPSI "; cin>>mileh;
        switch(mileh){
            case 1:
            system("cls");
            identitas(); break;
            case 2:
            system("cls");
            poliklinik(); break;
            case 3:
            system("cls");
            riwayat(); break;
            case 4:
            system("cls");
            main(); break;
            default:
            cout<<"INPUT SALAH, COBA LAGI"<<endl;
            system("pause");
            }
    }
    while(mileh!=4);
}
void poliklinik(){

        while (true) { // Loop utama poliklinik
        cout << "Poliklinik\n";
        cout << "1. Gigi\n2. Anak\n3. Umum\n4. Kandungan\n";
        cout << "Pilih Poliklinik yang akan dituju (1-4) = ";
        cin >> Poliklinik;
        system("cls");
        if (Poliklinik < 1 || Poliklinik > 4) {
        system("cls");
            cout << "===== Pilihan poliklinik tidak valid =====\n";
            continue; // Ulang jika input salah
        }

        // Set nama poliklinik berdasarkan pilihan
        switch (Poliklinik) {
            case 1: namapoliklinik = "Gigi"; break;
            case 2: namapoliklinik = "Anak"; break;
            case 3: namapoliklinik = "Umum"; break;
            case 4: namapoliklinik = "Kandungan"; break;
        }

        // Pilih dokter di poliklinik yang dipilih
        while (true) { // Loop untuk pemilihan dokter
            cout << "Dokter di Poliklinik " << namapoliklinik << ":\n";
            if (Poliklinik == 1) {
                cout << "1. dr. Imam Ali Afandi\n2. dr. Achmad Agus Nur Triyono\n3. dr. Mahir Haqiqi S.Ab M.Sp\n";
            } else if (Poliklinik == 2) {
                cout << "1. dr. Budi Santoso\n2. dr. Citra Dewi\n3. dr. Eka Nugraha\n";
            } else if (Poliklinik == 3) {
                cout << "1. dr. Dedi Setiawan\n2. dr. Farah Indah\n3. dr. Gina Amelia\n";
            } else if (Poliklinik == 4) {
                cout << "1. dr. Hana Permata\n2. dr. Indra Saputra\n3. dr. Lili Surya\n";
            }

            cout << "Pilih Dokter (1-3, atau 0 untuk kembali ke poliklinik) = ";
            cin >> dokter;

            if (dokter == 0) {
                cout << "Kembali ke menu poliklinik...\n";
                break; // Kembali ke pemilihan poliklinik
            }

            if (dokter >= 1 && dokter <= 3) {
                // Set nama dokter berdasarkan pilihan
                if (Poliklinik == 1) {
                    if (dokter == 1) namadokter = "dr. Imam Ali Afandi";
                    if (dokter == 2) namadokter = "dr. Achmad Agus Nur Triyono";
                    if (dokter == 3) namadokter = "dr. Mahir Haqiqi S.Ab M.Sp";
                } else if (Poliklinik == 2) {
                    if (dokter == 1) namadokter = "dr. Budi Santoso";
                    if (dokter == 2) namadokter = "dr. Citra Dewi";
                    if (dokter == 3) namadokter = "dr. Eka Nugraha";
                } else if (Poliklinik == 3) {
                    if (dokter == 1) namadokter = "dr. Dedi Setiawan";
                    if (dokter == 2) namadokter = "dr. Farah Indah";
                    if (dokter == 3) namadokter = "dr. Gina Amelia";
                } else if (Poliklinik == 4) {
                    if (dokter == 1) namadokter = "dr. Hana Permata";
                    if (dokter == 2) namadokter = "dr. Indra Saputra";
                    if (dokter == 3) namadokter = "dr. Lili Surya";
                }
                break; // Keluar dari loop dokter jika valid
            }
            system("cls");
            cout << "===== Pilihan Dokter tidak valid =====\n";
        }

        if (dokter != 0) break; // Jika dokter dipilih dengan valid, lanjutkan proses
    }
    system("cls");
    cout << "Jadwal Kunjungan\n";
    cout << "Jam (contoh: 07.30) : ";
    cin >> Kunjungan_J;
    system("cls");
    do {
        cout << "Hari (contoh: 1-7) : ";
        cin >> hari;
        system("cls");
        if (hari < 1 || hari > 7) {
                    cout << "=====HANYA ANGKA 1 SAMPAI 7=====\n";
                    cout << "===========COBA LAGI============\n";
            continue;
        }
        switch (hari) {
            case 1: Kunjungan_H = "Senin"; break;
            case 2: Kunjungan_H = "Selasa"; break;
            case 3: Kunjungan_H = "Rabu"; break;
            case 4: Kunjungan_H = "Kamis"; break;
            case 5: Kunjungan_H = "Jumat"; break;
            case 6: Kunjungan_H = "Sabtu"; break;
            case 7: Kunjungan_H = "Minggu"; break;
        }
        break; // Keluar dari loop setelah input valid
    } while (true);
    system("cls");
    do{
        cout << "Bulan (contoh: 1-12): ";
        cin >> bulan;
        system("cls");
            if (bulan < 1 || bulan > 12) {
                    cout << "=====HANYA ANGKA 1 SAMPAI 12=====\n";
                    cout << "============COBA LAGI============\n";
            continue;}
        switch (bulan) {
        case 1: Kunjungan_B = "Januari"; break;
        case 2: Kunjungan_B = "Februari"; break;
        case 3: Kunjungan_B = "Maret"; break;
        case 4: Kunjungan_B = "April"; break;
        case 5: Kunjungan_B = "Mei"; break;
        case 6: Kunjungan_B = "Juni"; break;
        case 7: Kunjungan_B = "Juli"; break;
        case 8: Kunjungan_B = "Agustus"; break;
        case 9: Kunjungan_B = "September"; break;
        case 10: Kunjungan_B = "Oktober"; break;
        case 11: Kunjungan_B = "November"; break;
        case 12: Kunjungan_B = "Desember"; break;
        default: cout << "Hanya angka 1 sampai 12"; break;
        }
    break;
    }
    while(true);
    system("cls");
    cout << "Tahun : ";
    cin >> Kunjungan_T;
    system("cls");
    /* noantri = "A" + to_string(100 + antrian);*/
    //tidak bisa di compiler lama
    stringstream bntar;
    bntar << "A" << (100 + antrian);
    noantri = bntar.str(); 
    //kegunaan nya untuk mengubah int atau float jadi string. sama kaya to_string tapi dev cpp nya versi lama jadi paake ini sj
    cout << "Anda Memilih Poliklinik " << namapoliklinik << " dengan nomor antrian " << noantri;
    cout << "\ndan Dokter yang anda pilih " << namadokter;
    cout << ". Pada Pukul " << Kunjungan_J << ", Hari " << Kunjungan_H << " " << Kunjungan_B << " " << Kunjungan_T << endl;
    riwayatada = true;
    cout << "=====================================================================================================\nProgres sudah tersimpan" << endl;
    system("pause");
    menuu();
}
void riwayat(){
    if(!riwayatada){
        cout<<"belum membuat kunungan periksa ke Klinik."<<endl;
        system("pause");
        menuu();
    }
    else{
    cout<<"Tanggal kunjungan "<<Kunjungan_H<<" "<<Kunjungan_B<<" "<<Kunjungan_T<<endl;
    cout<<"Nama poliklinik "<<namapoliklinik<<endl;
    cout<<"Dokter yang menangani "<<namadokter<<endl;
    cout<<"Nomer Antrian "<<noantri<<endl;
    cout<<endl;
    system("pause");
    menuu();
    }
}
void identitas(){
    // variabel statis untuk menyimpan data agar tetap ada meskipun fungsi dipanggil ulang
    static string namadepan = "";
    static string namabelakang = "";
    static string gender = "";
    static string alamat = "";
    static string kontak = "";
    static bool identitasDiisi = false; // status apakah identitas sudah diisi

    // jika identitas belum diisi, user diminta untuk mengisi
    if (!identitasDiisi) {
        cout << "\n--- Masukkan Identitas Diri ---\n";
        cout << "Nama Depan: ";
        cin >> namadepan;
        cout << "Nama Belakang: ";
        cin >> namabelakang;
        cout << "Jenis Kelamin: ";
        cin >> gender;
        cout << "Alamat: ";
        cin.ignore(); // Membersihkan newline yang tertinggal di buffer
        getline(cin, alamat);
        cout << "Nomor Kontak: ";
        cin >> kontak;
        identitasDiisi = true;
    } else {
        // menu edit jika identitas sudah diisi
        int pilihan;
        do {
            cout << "\n--- Edit Identitas Diri ---\n";
            cout << "1. Nama Depan\n";
            cout << "2. Nama Belakang\n";
            cout << "3. Jenis Kelamin\n";
            cout << "4. Alamat\n";
            cout << "5. Nomor Kontak\n";
            cout << "6. Tidak ada perubahan\n";
            cout << "Pilih data yang ingin diubah (1-6): ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    cout << "Nama Depan: ";
                    cin >> namadepan;
                    break;
                case 2:
                    cout << "Nama Belakang: ";
                    cin >> namabelakang;
                    break;
                case 3:
                    cout << "Jenis Kelamin: ";
                    cin >> gender;
                    break;
                case 4:
                    cout << "Alamat: ";
                    cin.ignore(); // Membersihkan newline
                    getline(cin, alamat);
                    break;
                case 5:
                    cout << "Nomor Kontak: ";
                    cin >> kontak;
                    break;
                case 6:
                    cout << "Tidak ada perubahan.\n";
                    break;
                default:
                    cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            }
        } while (pilihan < 1 || pilihan > 6);
    }

    // Menampilkan identitas
    cout << "\n--- Identitas Diri ---\n";
    cout << "1. Nama Lengkap   : " << namadepan << " " << namabelakang << endl;
    cout << "2. Jenis Kelamin  : " << gender << endl;
    cout << "3. Alamat         : " << alamat << endl;
    cout << "4. Nomor Kontak   : " << kontak << endl;
    system("pause");
    menuu();
}


int main(){
        int pilihan;
do{

    cout<<"===================================================\n";
    cout<<"                     HALAMAN LOGIN                   "<<endl;
    cout<<"===================================================\n";
    cout<<"1. Login\n";
    cout<<"2.Keluar Program\n";
    cout<<"PILIH OPSI ";
    cin>>pilihan;
    cout<<endl;

        switch(pilihan){
            case 1:
                login();
                break;
            case 2:
                system("exit");
                break;
            default:
            system("cls");
            cout<<"Input salah!!"<<endl;
        }
    }
        while(pilihan !=2);
        return 0;
}