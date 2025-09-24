import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // ArrayList penampung objek Produk
        ArrayList<Produk> daftarProduk = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        // 5 Produk pertama
        daftarProduk.add(new Ponsel("Galaxy S25", "Samsung", 18000000, 50, 15, 5, 24, 6.8, 12, 256));
        daftarProduk.add(new Ponsel("iPhone 17", "Apple", 25000000, 30, 20, 5, 12, 6.1, 8, 256));
        daftarProduk.add(new Televisi("OLED C4", "LG", 22000000, 20, 120, 220, 12, 65, "4K UHD", true));
        daftarProduk.add(new Televisi("Crystal UHD 9", "Samsung", 11000000, 40, 90, 220, 24, 55, "4K UHD", true));
        daftarProduk.add(new Ponsel("Redmi Note 15", "Xiaomi", 4000000, 100, 10, 5, 12, 6.67, 8, 128));
        
        boolean berjalan = true;
        while (berjalan) {
            // Tampilan menu
            System.out.println("\n===== Menu Toko Elektronik =====");
            System.out.println("1. Tambah Produk Baru");
            System.out.println("2. Tampilkan Semua Produk");
            System.out.println("0. Keluar");
            System.out.println("========================================");
            System.out.print("Pilih menu: ");

            try {
                int pilihan = scanner.nextInt();
                scanner.nextLine(); // Membersihkan newline

                if (pilihan == 1) {
                    // Menu tambah produk
                    System.out.print("\nPilih jenis produk (1: Ponsel, 2: Televisi): ");
                    try {
                        int jenis = scanner.nextInt();
                        scanner.nextLine(); // Membersihkan newline
                        
                        if (jenis == 1 || jenis == 2) {
                             // Variabel input atribut umum dan khusus
                            String nama, merek, resolusi;
                            int harga, stok, daya, volt, garansi, ram, storage;
                            double layar;

                            // Input atribut umum produk
                            System.out.print("Nama: "); nama = scanner.nextLine();
                            System.out.print("Merek: "); merek = scanner.nextLine();
                            System.out.print("Harga: "); harga = scanner.nextInt();
                            System.out.print("Stok: "); stok = scanner.nextInt();
                            System.out.print("Konsumsi Daya (W): "); daya = scanner.nextInt();
                            System.out.print("Voltase (V): "); volt = scanner.nextInt();
                            System.out.print("Garansi (bulan): "); garansi = scanner.nextInt();
                            System.out.print("Ukuran Layar (inci): "); layar = scanner.nextDouble();
                            scanner.nextLine(); // Membersihkan newline

                            if (jenis == 1) { // Ponsel
                                System.out.print("RAM (GB): "); ram = scanner.nextInt();
                                System.out.print("Storage (GB): "); storage = scanner.nextInt();
                                scanner.nextLine(); // Membersihkan newline
                                // Buat objek Ponsel baru dan simpan ke daftar
                                daftarProduk.add(new Ponsel(nama, merek, harga, stok, daya, volt, garansi, layar, ram, storage));
                                System.out.println("\n--> Ponsel baru berhasil ditambahkan!");
                            } else { // Televisi
                                System.out.print("Resolusi: "); resolusi = scanner.nextLine();
                                System.out.print("Smart TV? (y/n): "); String smartChoice = scanner.nextLine();
                                boolean isSmart = smartChoice.equalsIgnoreCase("y");
                                // Buat objek Televisi baru dan simpan ke daftar
                                daftarProduk.add(new Televisi(nama, merek, harga, stok, daya, volt, garansi, layar, resolusi, isSmart));
                                System.out.println("\n--> Televisi baru berhasil ditambahkan!");
                            }
                        } else {
                            System.out.println("Pilihan jenis tidak valid. Harus 1 atau 2.");
                        }
                    } catch (InputMismatchException e) {
                        System.out.println("Input jenis tidak valid, harus angka!");
                        scanner.nextLine(); // Membersihkan input yang salah
                    }
                } else if (pilihan == 2) {
                    // Menu tampilkan semua produk dalam bentuk tabel dinamis
                    System.out.println("\n--- Daftar Semua Produk ---");
                    if (daftarProduk.isEmpty()) {
                        System.out.println("Belum ada produk di dalam daftar.");
                    } else {
                        // Header kolom tabel
                        List<String> headers = Arrays.asList(
                            "No", "Kategori", "Nama Produk", "Merek", "Harga", "Stok",
                            "Daya(W)", "Volt(V)", "Garansi", "Layar(\")", "RAM(GB)",
                            "Storage(GB)", "Resolusi", "Smart TV"
                        );
                        // Map menyimpan lebar kolom maksimum
                        Map<String, Integer> widths = new HashMap<>();
                        for (String h : headers) {
                            widths.put(h, h.length());
                        }

                        // Cari lebar maksimum tiap kolom berdasarkan data
                        for (Produk p : daftarProduk) {
                            widths.put("Nama Produk", Math.max(widths.get("Nama Produk"), p.getNama().length()));
                            widths.put("Merek", Math.max(widths.get("Merek"), p.getMerek().length()));
                            widths.put("Harga", Math.max(widths.get("Harga"), String.valueOf(p.getHarga()).length()));
                            widths.put("Stok", Math.max(widths.get("Stok"), String.valueOf(p.getStok()).length()));
                            
                            // Cek tipe objek
                            if (p instanceof Ponsel) {
                                Ponsel ponsel = (Ponsel) p;
                                widths.put("Kategori", Math.max(widths.get("Kategori"), "Ponsel".length()));
                                widths.put("Daya(W)", Math.max(widths.get("Daya(W)"), String.valueOf(ponsel.getKonsumsiDaya()).length()));
                                widths.put("Volt(V)", Math.max(widths.get("Volt(V)"), String.valueOf(ponsel.getVoltase()).length()));
                                widths.put("Garansi", Math.max(widths.get("Garansi"), (String.valueOf(ponsel.getGaransi()) + " bln").length()));
                                widths.put("Layar(\")", Math.max(widths.get("Layar(\")"), String.valueOf(ponsel.getUkuranLayar()).length()));
                                widths.put("RAM(GB)", Math.max(widths.get("RAM(GB)"), String.valueOf(ponsel.getRam()).length()));
                                widths.put("Storage(GB)", Math.max(widths.get("Storage(GB)"), String.valueOf(ponsel.getKapasitasPenyimpanan()).length()));
                            } else if (p instanceof Televisi) {
                                Televisi tv = (Televisi) p;
                                widths.put("Kategori", Math.max(widths.get("Kategori"), "Televisi".length()));
                                widths.put("Daya(W)", Math.max(widths.get("Daya(W)"), String.valueOf(tv.getKonsumsiDaya()).length()));
                                widths.put("Volt(V)", Math.max(widths.get("Volt(V)"), String.valueOf(tv.getVoltase()).length()));
                                widths.put("Garansi", Math.max(widths.get("Garansi"), (String.valueOf(tv.getGaransi()) + " bln").length()));
                                widths.put("Layar(\")", Math.max(widths.get("Layar(\")"), String.valueOf(tv.getUkuranLayar()).length()));
                                widths.put("Resolusi", Math.max(widths.get("Resolusi"), tv.getResolusi().length()));
                                widths.put("Smart TV", Math.max(widths.get("Smart TV"), "Ya".length()));
                            }
                        }

                        // Untuk cetak garis horizontal tabel
                        Runnable printLine = () -> {
                            for (String h : headers) {
                                System.out.print("+-");
                                for (int i = 0; i < widths.get(h); i++) System.out.print("-");
                                System.out.print("-");
                            }
                            System.out.println("+");
                        };

                        // Cetak header dan baris tabel
                        printLine.run();
                        for (String h : headers) {
                            System.out.printf("| %-" + widths.get(h) + "s ", h);
                        }
                        System.out.println("|");
                        printLine.run();

                        // Cetak setiap baris produk
                        for (int i = 0; i < daftarProduk.size(); i++) {
                            Produk p = daftarProduk.get(i);
                            System.out.printf("| %-" + widths.get("No") + "s ", i + 1);

                            if (p instanceof Ponsel) {
                                Ponsel ponsel = (Ponsel) p;
                                System.out.printf("| %-" + widths.get("Kategori") + "s ", "Ponsel");
                                System.out.printf("| %-" + widths.get("Nama Produk") + "s ", ponsel.getNama());
                                System.out.printf("| %-" + widths.get("Merek") + "s ", ponsel.getMerek());
                                System.out.printf("| %-" + widths.get("Harga") + "d ", ponsel.getHarga());
                                System.out.printf("| %-" + widths.get("Stok") + "d ", ponsel.getStok());
                                System.out.printf("| %-" + widths.get("Daya(W)") + "d ", ponsel.getKonsumsiDaya());
                                System.out.printf("| %-" + widths.get("Volt(V)") + "d ", ponsel.getVoltase());
                                System.out.printf("| %-" + widths.get("Garansi") + "s ", ponsel.getGaransi() + " bln");
                                System.out.printf("| %-" + widths.get("Layar(\")") + ".2f ", ponsel.getUkuranLayar());
                                System.out.printf("| %-" + widths.get("RAM(GB)") + "d ", ponsel.getRam());
                                System.out.printf("| %-" + widths.get("Storage(GB)") + "d ", ponsel.getKapasitasPenyimpanan());
                                System.out.printf("| %-" + widths.get("Resolusi") + "s ", "-");
                                System.out.printf("| %-" + widths.get("Smart TV") + "s |", "-");
                                System.out.println();
                            } else if (p instanceof Televisi) {
                                Televisi tv = (Televisi) p;
                                System.out.printf("| %-" + widths.get("Kategori") + "s ", "Televisi");
                                System.out.printf("| %-" + widths.get("Nama Produk") + "s ", tv.getNama());
                                System.out.printf("| %-" + widths.get("Merek") + "s ", tv.getMerek());
                                System.out.printf("| %-" + widths.get("Harga") + "d ", tv.getHarga());
                                System.out.printf("| %-" + widths.get("Stok") + "d ", tv.getStok());
                                System.out.printf("| %-" + widths.get("Daya(W)") + "d ", tv.getKonsumsiDaya());
                                System.out.printf("| %-" + widths.get("Volt(V)") + "d ", tv.getVoltase());
                                System.out.printf("| %-" + widths.get("Garansi") + "s ", tv.getGaransi() + " bln");
                                System.out.printf("| %-" + widths.get("Layar(\")") + ".2f ", tv.getUkuranLayar());
                                System.out.printf("| %-" + widths.get("RAM(GB)") + "s ", "-");
                                System.out.printf("| %-" + widths.get("Storage(GB)") + "s ", "-");
                                System.out.printf("| %-" + widths.get("Resolusi") + "s ", tv.getResolusi());
                                System.out.printf("| %-" + widths.get("Smart TV") + "s |", (tv.getIsSmartTV() ? "Ya" : "Tidak"));
                                System.out.println();
                            }
                        }
                        printLine.run();
                    }
                } else if (pilihan == 0) {
                    System.out.println("Program selesai.");
                    berjalan = false; // Menghentikan loop
                } else {
                    System.out.println("Pilihan tidak valid! Harus antara 0-2.");
                }
            } catch (InputMismatchException e) {
                System.out.println("Input tidak valid, harus angka!");
                scanner.nextLine(); // Membersihkan input yang salah
            }

            if (berjalan) {
                // Tunggu input Enter dari user sebelum kembali ke menu
                System.out.print("\nTekan Enter untuk melanjutkan...");
                scanner.nextLine();
            }
        }
        scanner.close(); // Tutup scanner setelah selesai
    }
}