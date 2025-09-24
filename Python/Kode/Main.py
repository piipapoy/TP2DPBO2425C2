# Import kelas-kelas yang akan dibuat objeknya
from Ponsel import Ponsel
from Televisi import Televisi

def main():
    # List penampung objek Produk
    daftar_produk = []

    # 5 Produk pertama
    daftar_produk.append(Ponsel("Galaxy S25", "Samsung", 18000000, 50, 15, 5, 24, 6.8, 12, 256))
    daftar_produk.append(Ponsel("iPhone 17", "Apple", 25000000, 30, 20, 5, 12, 6.1, 8, 256))
    daftar_produk.append(Televisi("OLED C4", "LG", 22000000, 20, 120, 220, 12, 65, "4K UHD", True))
    daftar_produk.append(Televisi("Crystal UHD 9", "Samsung", 11000000, 40, 90, 220, 24, 55, "4K UHD", True))
    daftar_produk.append(Ponsel("Redmi Note 15", "Xiaomi", 4000000, 100, 10, 5, 12, 6.67, 8, 128))

    # Variabel flag untuk loop
    berjalan = True
    while berjalan:
        # Tampilan menu
        print("\n===== Menu Toko Elektronik =====")
        print("1. Tambah Produk Baru")
        print("2. Tampilkan Semua Produk")
        print("0. Keluar")
        print("========================================")
        
        try:
            pilihan = int(input("Pilih menu: "))

            if pilihan == 1:
                # Menu tambah produk
                try:
                    jenis = int(input("\nPilih jenis produk (1: Ponsel, 2: Televisi): "))
                    if jenis == 1 or jenis == 2:
                        # Variabel input atribut umum dan khusus
                        nama = input("Nama: ")
                        merek = input("Merek: ")
                        harga = int(input("Harga: "))
                        stok = int(input("Stok: "))
                        daya = int(input("Konsumsi Daya (W): "))
                        volt = int(input("Voltase (V): "))
                        garansi = int(input("Garansi (bulan): "))
                        layar = float(input("Ukuran Layar (inci): "))

                        if jenis == 1:  # Ponsel
                            ram = int(input("RAM (GB): "))
                            storage = int(input("Storage (GB): "))
                            # Buat objek Ponsel baru dan simpan ke daftar
                            daftar_produk.append(Ponsel(nama, merek, harga, stok, daya, volt, garansi, layar, ram, storage))
                            print("\n--> Ponsel baru berhasil ditambahkan!")
                        else:  # Televisi
                            resolusi = input("Resolusi: ")
                            smart_choice = input("Smart TV? (y/n): ").lower()
                            is_smart = (smart_choice == 'y')
                            # Buat objek Televisi baru dan simpan ke daftar
                            daftar_produk.append(Televisi(nama, merek, harga, stok, daya, volt, garansi, layar, resolusi, is_smart))
                            print("\n--> Televisi baru berhasil ditambahkan!")
                    else:
                        print("Pilihan jenis tidak valid. Harus 1 atau 2.")
                except ValueError:
                    print("Input jenis tidak valid, harus angka!")

            elif pilihan == 2:
                # Menu tampilkan semua produk dalam bentuk tabel dinamis
                print("\n--- Daftar Semua Produk ---")
                if not daftar_produk:
                    print("Belum ada produk di dalam daftar.")
                else:
                    # Header kolom tabel
                    headers = [
                        "No", "Kategori", "Nama Produk", "Merek", "Harga", "Stok",
                        "Daya(W)", "Volt(V)", "Garansi", "Layar(\")", "RAM(GB)",
                        "Storage(GB)", "Resolusi", "Smart TV"
                    ]
                    
                    # Dictionary menyimpan lebar kolom maksimum
                    widths = {h: len(h) for h in headers}

                    # Cari lebar maksimum tiap kolom berdasarkan data
                    for p in daftar_produk:
                        widths["Nama Produk"] = max(widths["Nama Produk"], len(p.get_nama()))
                        widths["Merek"] = max(widths["Merek"], len(p.get_merek()))
                        widths["Harga"] = max(widths["Harga"], len(str(p.get_harga())))
                        widths["Stok"] = max(widths["Stok"], len(str(p.get_stok())))
                        
                        # Cek tipe objek (setara dynamic_cast)
                        if isinstance(p, Ponsel):
                            widths["Kategori"] = max(widths["Kategori"], len("Ponsel"))
                            widths["Daya(W)"] = max(widths["Daya(W)"], len(str(p.get_konsumsi_daya())))
                            widths["Volt(V)"] = max(widths["Volt(V)"], len(str(p.get_voltase())))
                            widths["Garansi"] = max(widths["Garansi"], len(f"{p.get_garansi()} bln"))
                            widths["Layar(\")"] = max(widths["Layar(\")"], len(str(p.get_ukuran_layar())))
                            widths["RAM(GB)"] = max(widths["RAM(GB)"], len(str(p.get_ram())))
                            widths["Storage(GB)"] = max(widths["Storage(GB)"], len(str(p.get_kapasitas_penyimpanan())))
                        elif isinstance(p, Televisi):
                            widths["Kategori"] = max(widths["Kategori"], len("Televisi"))
                            widths["Daya(W)"] = max(widths["Daya(W)"], len(str(p.get_konsumsi_daya())))
                            widths["Volt(V)"] = max(widths["Volt(V)"], len(str(p.get_voltase())))
                            widths["Garansi"] = max(widths["Garansi"], len(f"{p.get_garansi()} bln"))
                            widths["Layar(\")"] = max(widths["Layar(\")"], len(str(p.get_ukuran_layar())))
                            widths["Resolusi"] = max(widths["Resolusi"], len(p.get_resolusi()))
                            widths["Smart TV"] = max(widths["Smart TV"], len("Ya"))

                    # Fungsi untuk cetak garis horizontal tabel
                    def print_line():
                        line = ""
                        for h in headers:
                            line += "+-" + "-" * widths[h] + "-"
                        print(line + "+")

                    # Cetak header dan baris tabel
                    print_line()
                    header_line = ""
                    for h in headers:
                        header_line += f"| {h:<{widths[h]}} "
                    print(header_line + "|")
                    print_line()

                    # Cetak setiap baris produk
                    for i, p in enumerate(daftar_produk):
                        print(f"| {(i + 1):<{widths['No']}} ", end="")
                        
                        if isinstance(p, Ponsel):
                            print(f"| {'Ponsel':<{widths['Kategori']}} ", end="")
                            print(f"| {p.get_nama():<{widths['Nama Produk']}} ", end="")
                            print(f"| {p.get_merek():<{widths['Merek']}} ", end="")
                            print(f"| {p.get_harga():<{widths['Harga']}} ", end="")
                            print(f"| {p.get_stok():<{widths['Stok']}} ", end="")
                            print(f"| {p.get_konsumsi_daya():<{widths['Daya(W)']}} ", end="")
                            print(f"| {p.get_voltase():<{widths['Volt(V)']}} ", end="")
                            print(f"| {str(p.get_garansi()) + ' bln':<{widths['Garansi']}} ", end="")
                            print(f"| {p.get_ukuran_layar():<{widths['Layar(\")']}.2f} ", end="")
                            print(f"| {p.get_ram():<{widths['RAM(GB)']}} ", end="")
                            print(f"| {p.get_kapasitas_penyimpanan():<{widths['Storage(GB)']}} ", end="")
                            print(f"| {'-':<{widths['Resolusi']}} ", end="")
                            print(f"| {'-':<{widths['Smart TV']}} |")
                        elif isinstance(p, Televisi):
                            print(f"| {'Televisi':<{widths['Kategori']}} ", end="")
                            print(f"| {p.get_nama():<{widths['Nama Produk']}} ", end="")
                            print(f"| {p.get_merek():<{widths['Merek']}} ", end="")
                            print(f"| {p.get_harga():<{widths['Harga']}} ", end="")
                            print(f"| {p.get_stok():<{widths['Stok']}} ", end="")
                            print(f"| {p.get_konsumsi_daya():<{widths['Daya(W)']}} ", end="")
                            print(f"| {p.get_voltase():<{widths['Volt(V)']}} ", end="")
                            print(f"| {str(p.get_garansi()) + ' bln':<{widths['Garansi']}} ", end="")
                            print(f"| {p.get_ukuran_layar():<{widths['Layar(\")']}.2f} ", end="")
                            print(f"| {'-':<{widths['RAM(GB)']}} ", end="")
                            print(f"| {'-':<{widths['Storage(GB)']}} ", end="")
                            print(f"| {p.get_resolusi():<{widths['Resolusi']}} ", end="")
                            print(f"| {'Ya' if p.get_is_smart_tv() else 'Tidak':<{widths['Smart TV']}} |")
                    print_line()

            elif pilihan == 0:
                # Keluar dari program
                print("Program selesai.")
                berjalan = False # Menghentikan loop while
            else:
                print("Pilihan tidak valid! Harus antara 0-2.")

        except ValueError:
            print("Input tidak valid, harus angka!")
        
        if berjalan:
             # Tunggu input Enter dari user sebelum kembali ke menu
            input("\nTekan Enter untuk melanjutkan...")

if __name__ == "__main__":
    main()