#pragma once

#include "ProdukElektronik.cpp"

class Ponsel : public ProdukElektronik { // Class turunan dari ProdukElektronik, khusus ponsel
    private: // Atribut private
        double ukuranLayar;
        int kapasitasPenyimpanan;
        int ram;

    public: // Method public
        Ponsel() { // Konstruktor default
        }

        Ponsel(string nama, string merek, int harga, int stok, int konsumsiDaya, int voltase, int garansi,
            double ukuranLayar, int kapasitasPenyimpanan, int ram) 
            : ProdukElektronik(nama, merek, harga, stok, konsumsiDaya, voltase, garansi) { // Memanggil konstruktor induk
            this->ukuranLayar = ukuranLayar;
            this->kapasitasPenyimpanan = kapasitasPenyimpanan;
            this->ram = ram;
        }

        // Setter dan Getter untuk setiap atribut

        void setUkuranLayar(double ukuranLayar) {
            this->ukuranLayar = ukuranLayar;
        }
        double getUkuranLayar() {
            return this->ukuranLayar;
        }

        void setKapasitasPenyimpanan(int kapasitasPenyimpanan) {
            this->kapasitasPenyimpanan = kapasitasPenyimpanan;
        }
        int getKapasitasPenyimpanan() {
            return this->kapasitasPenyimpanan;
        }

        void setRam(int ram) {
            this->ram = ram;
        }
        int getRam() {
            return this->ram;
        }

        ~Ponsel() { // Destruktor
        }
};