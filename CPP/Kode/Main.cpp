#include "Ponsel.cpp"
#include "Televisi.cpp"

#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

int main() {
    // Vector penampung pointer ke objek Produk
    vector<Produk*> daftarProduk;

    // 5 Produk pertama
    daftarProduk.push_back(new Ponsel("Galaxy S25", "Samsung", 18000000, 50, 15, 5, 24, 6.8, 12, 256));
    daftarProduk.push_back(new Ponsel("iPhone 17", "Apple", 25000000, 30, 20, 5, 12, 6.1, 8, 256));
    daftarProduk.push_back(new Televisi("OLED C4", "LG", 22000000, 20, 120, 220, 12, 65, "4K UHD", true));
    daftarProduk.push_back(new Televisi("Crystal UHD 9", "Samsung", 11000000, 40, 90, 220, 24, 55, "4K UHD", true));
    daftarProduk.push_back(new Ponsel("Redmi Note 15", "Xiaomi", 4000000, 100, 10, 5, 12, 6.67, 8, 128));

    int pilihan;
    while (true) {
        // Tampilan menu
        cout << "\n===== Menu Toko Elektronik =====" << endl;
        cout << "1. Tambah Produk Baru" << endl;
        cout << "2. Tampilkan Semua Produk" << endl;
        cout << "0. Keluar" << endl;
        cout << "========================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (cin.fail()) {
            // Validasi input menu
            cout << "Input tidak valid, harus angka!" << endl;
            // Clear error state dan buang input sisa agar tidak loop terus
            cin.clear();
            string skip;
            getline(cin, skip);
        } else { // Jika input adalah angka, lanjutkan proses
            if (pilihan == 1) {
                // Menu tambah produk
                int jenis;
                cout << "\nPilih jenis produk (1: Ponsel, 2: Televisi): ";
                cin >> jenis;
                if (cin.fail()) {
                    cout << "Input jenis tidak valid, harus angka!" << endl;
                    cin.clear();
                    string skip;
                    getline(cin, skip);
                } else {
                    if (jenis == 1 || jenis == 2) {
                        // Variabel input atribut umum dan khusus
                        string nama, merek, resolusi;
                        int harga, stok, daya, volt, garansi, ram, storage;
                        double layar;
                        
                        // Input atribut umum produk
                        cout << "Nama: "; cin >> nama;
                        cout << "Merek: "; cin >> merek;
                        cout << "Harga: "; cin >> harga;
                        cout << "Stok: "; cin >> stok;
                        cout << "Konsumsi Daya (W): "; cin >> daya;
                        cout << "Voltase (V): "; cin >> volt;
                        cout << "Garansi (bulan): "; cin >> garansi;
                        cout << "Ukuran Layar (inci): "; cin >> layar;

                        if (jenis == 1) { // Ponsel
                            cout << "RAM (GB): "; cin >> ram;
                            cout << "Storage (GB): "; cin >> storage;
                            
                            // Buat objek Ponsel baru dan simpan ke daftar
                            daftarProduk.push_back(new Ponsel(nama, merek, harga, stok, daya, volt, garansi, layar, ram, storage));
                            cout << "\n--> Ponsel baru berhasil ditambahkan!" << endl;
                        
                        } else { // Televisi
                            // Karena sebelumnya pakai >>, buang newline sebelum getline
                            getline(cin, resolusi); // buang sisa baris
                            cout << "Resolusi: "; getline(cin, resolusi);
                            bool isSmart;
                            char smartChoice;
                            cout << "Smart TV? (y/n): "; cin >> smartChoice;
                            isSmart = (smartChoice == 'y' || smartChoice == 'Y');
                            
                            // Buat objek Televisi baru dan simpan ke daftar
                            daftarProduk.push_back(new Televisi(nama, merek, harga, stok, daya, volt, garansi, layar, resolusi, isSmart));
                            cout << "\n--> Televisi baru berhasil ditambahkan!" << endl;
                        }
                    } else {
                        cout << "Pilihan jenis tidak valid. Harus 1 atau 2." << endl;
                    }
                }

            } else if (pilihan == 2) {
                // Menu tampilkan semua produk dalam bentuk tabel dinamis
                cout << "\n--- Daftar Semua Produk ---" << endl;
                if (daftarProduk.empty()) {
                    cout << "Belum ada produk di dalam daftar." << endl;
                } else {
                    // Header kolom tabel
                    const vector<string> headers = {
                        "No", "Kategori", "Nama Produk", "Merek", "Harga", "Stok",
                        "Daya(W)", "Volt(V)", "Garansi", "Layar(\")", "RAM(GB)",
                        "Storage(GB)", "Resolusi", "Smart TV"
                    };

                    // Map menyimpan lebar kolom maksimum
                    map<string, int> widths;
                    for (const string& h : headers) {
                        widths[h] = h.length();
                    }

                    // Cari lebar maksimum tiap kolom berdasarkan data
                    for (Produk* p : daftarProduk) {
                        // Data umum selalu ada di Produk
                        widths["Nama Produk"] = max(widths["Nama Produk"], (int)p->getNama().length());
                        widths["Merek"] = max(widths["Merek"], (int)p->getMerek().length());
                        widths["Harga"] = max(widths["Harga"], (int)to_string(p->getHarga()).length());
                        widths["Stok"] = max(widths["Stok"], (int)to_string(p->getStok()).length());

                        // Coba cast ke tipe turunan untuk ambil data spesifik
                        Ponsel* ponsel = dynamic_cast<Ponsel*>(p);
                        Televisi* tv = dynamic_cast<Televisi*>(p);

                        if (ponsel) { // jika p adalah Ponsel
                            widths["Kategori"] = max(widths["Kategori"], (int)string("Ponsel").length());
                            widths["Daya(W)"] = max(widths["Daya(W)"], (int)to_string(ponsel->getKonsumsiDaya()).length());
                            widths["Volt(V)"] = max(widths["Volt(V)"], (int)to_string(ponsel->getVoltase()).length());
                            widths["Garansi"] = max(widths["Garansi"], (int)(to_string(ponsel->getGaransi()) + " bln").length());
                            widths["Layar(\")"] = max(widths["Layar(\")"], (int)to_string(ponsel->getUkuranLayar()).length());
                            widths["RAM(GB)"] = max(widths["RAM(GB)"], (int)to_string(ponsel->getRam()).length());
                            widths["Storage(GB)"] = max(widths["Storage(GB)"], (int)to_string(ponsel->getKapasitasPenyimpanan()).length());
                        } else if (tv) { // jika p adalah Televisi
                            widths["Kategori"] = max(widths["Kategori"], (int)string("Televisi").length());
                            widths["Daya(W)"] = max(widths["Daya(W)"], (int)to_string(tv->getKonsumsiDaya()).length());
                            widths["Volt(V)"] = max(widths["Volt(V)"], (int)to_string(tv->getVoltase()).length());
                            widths["Garansi"] = max(widths["Garansi"], (int)(to_string(tv->getGaransi()) + " bln").length());
                            widths["Layar(\")"] = max(widths["Layar(\")"], (int)to_string(tv->getUkuranLayar()).length());
                            widths["Resolusi"] = max(widths["Resolusi"], (int)tv->getResolusi().length());
                            widths["Smart TV"] = max(widths["Smart TV"], (int)string("Ya").length());
                        }
                    }

                    // Untuk cetak garis horizontal tabel
                    auto printLine = [&]() {
                        for (const string& h : headers) {
                            cout << "+-" << string(widths[h], '-') << "-";
                        }
                        cout << "+" << endl;
                    };

                    // Cetak header dan baris tabel
                    printLine();
                    for (const string& h : headers) {
                        cout << "| " << left << setw(widths[h]) << h << " ";
                    }
                    cout << "|" << endl;
                    printLine();

                    // Cetak setiap baris produk
                    for (size_t i = 0; i < daftarProduk.size(); ++i) {
                        Produk* p = daftarProduk[i];
                        Ponsel* ponsel = dynamic_cast<Ponsel*>(p);
                        Televisi* tv = dynamic_cast<Televisi*>(p);

                        // Kolom umum
                        cout << "| " << left << setw(widths["No"]) << (i + 1) << " ";
                        if (ponsel) cout << "| " << left << setw(widths["Kategori"]) << "Ponsel" << " ";
                        else if (tv) cout << "| " << left << setw(widths["Kategori"]) << "Televisi" << " ";
                        
                        cout << "| " << left << setw(widths["Nama Produk"]) << p->getNama() << " ";
                        cout << "| " << left << setw(widths["Merek"]) << p->getMerek() << " ";
                        cout << "| " << left << setw(widths["Harga"]) << p->getHarga() << " ";
                        cout << "| " << left << setw(widths["Stok"]) << p->getStok() << " ";
                        
                        // Kolom khusus sesuai tipe
                        if (ponsel) {
                            cout << "| " << left << setw(widths["Daya(W)"]) << ponsel->getKonsumsiDaya() << " ";
                            cout << "| " << left << setw(widths["Volt(V)"]) << ponsel->getVoltase() << " ";
                            cout << "| " << left << setw(widths["Garansi"]) << (to_string(ponsel->getGaransi()) + " bln") << " ";
                            cout << "| " << left << setw(widths["Layar(\")"]) << fixed << setprecision(2) << ponsel->getUkuranLayar() << " ";
                            cout << "| " << left << setw(widths["RAM(GB)"]) << ponsel->getRam() << " ";
                            cout << "| " << left << setw(widths["Storage(GB)"]) << ponsel->getKapasitasPenyimpanan() << " ";
                            cout << "| " << left << setw(widths["Resolusi"]) << "-" << " ";
                            cout << "| " << left << setw(widths["Smart TV"]) << "-" << " ";
                        } else if (tv) {
                            cout << "| " << left << setw(widths["Daya(W)"]) << tv->getKonsumsiDaya() << " ";
                            cout << "| " << left << setw(widths["Volt(V)"]) << tv->getVoltase() << " ";
                            cout << "| " << left << setw(widths["Garansi"]) << (to_string(tv->getGaransi()) + " bln") << " ";
                            cout << "| " << left << setw(widths["Layar(\")"]) << fixed << setprecision(2) << tv->getUkuranLayar() << " ";
                            cout << "| " << left << setw(widths["RAM(GB)"]) << "-" << " ";
                            cout << "| " << left << setw(widths["Storage(GB)"]) << "-" << " ";
                            cout << "| " << left << setw(widths["Resolusi"]) << tv->getResolusi() << " ";
                            cout << "| " << left << setw(widths["Smart TV"]) << (tv->getIsSmartTV() ? "Ya" : "Tidak") << " ";
                        }
                        cout << "|" << endl;
                    }
                    printLine();
                }
            } else if (pilihan == 0) {
                // Keluar dari program
                // Sebaiknya hapus objek yang dialokasikan (optional)
                for (Produk* p : daftarProduk) delete p;
                return 0;
            } else {
                cout << "Pilihan tidak valid! Harus antara 0-2." << endl;
            }
        }

        // Tunggu input Enter dari user sebelum kembali ke menu
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.get();
        // Jika ada newline sisa, paksa getline agar benar-benar menunggu Enter
        string tmp;
        getline(cin, tmp);
    }
}