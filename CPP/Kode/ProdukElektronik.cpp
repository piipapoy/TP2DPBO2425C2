#pragma once

#include "Produk.cpp"

class ProdukElektronik : public Produk { // Class turunan dari Produk, khusus produk elektronik
    private: // Atribut private
        int konsumsiDaya;
        int voltase;
        int garansi;

    public: // Method public
        ProdukElektronik() { // Konstruktor default
        }

        ProdukElektronik(string nama, string merek, int harga, int stok, // Konstruktor dengan parameter
            int konsumsiDaya, int voltase, int garansi) 
            : Produk(nama, merek, harga, stok) { // Memanggil konstruktor induk
            this->konsumsiDaya = konsumsiDaya;
            this->voltase = voltase; 
            this->garansi = garansi;
        }

        // Setter dan Getter untuk setiap atribut

        void setKonsumsiDaya(int konsumsiDaya) {
            this->konsumsiDaya = konsumsiDaya;
        }
        int getKonsumsiDaya() {
            return this->konsumsiDaya;
        }

        void setVoltase(int voltase) {
            this->voltase = voltase;
        }
        int getVoltase() {
            return this->voltase;
        }

        void setGaransi(int garansi) {
            this->garansi = garansi;
        }
        int getGaransi() {
            return this->garansi;
        }

        ~ProdukElektronik() { // Destruktor
        }
};