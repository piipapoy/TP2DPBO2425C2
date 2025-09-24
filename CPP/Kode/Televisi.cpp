#pragma once

#include "ProdukElektronik.cpp"

class Televisi : public ProdukElektronik { // Class turunan dari ProdukElektronik, khusus televisi
    private: // Atribut private
        double ukuranLayar;
        string resolusi;
        bool isSmartTV;

    public: // Method public
        Televisi() { // Konstruktor default
        }

        Televisi(string nama, string merek, int harga, int stok, int konsumsiDaya, int voltase, int garansi,
            double ukuranLayar, string resolusi, bool isSmartTV) 
            : ProdukElektronik(nama, merek, harga, stok, konsumsiDaya, voltase, garansi) { // Memanggil konstruktor induk
            this->ukuranLayar = ukuranLayar;
            this->resolusi = resolusi;
            this->isSmartTV = isSmartTV;
        }

        // Setter dan Getter untuk setiap atribut

        void setUkuranLayar(double ukuranLayar) {
            this->ukuranLayar = ukuranLayar;
        }
        double getUkuranLayar() {
            return this->ukuranLayar;
        }

        void setResolusi(string resolusi) {
            this->resolusi = resolusi;
        }
        string getResolusi() {
            return this->resolusi;
        }

        void setIsSmartTV(bool isSmartTV) {
            this->isSmartTV = isSmartTV;
        }
        bool getIsSmartTV() {
            return this->isSmartTV;
        }

        ~Televisi() { // Destruktor
        }
};