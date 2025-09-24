#pragma once

#include <iostream>
#include <string>
using namespace std;

class Produk { // Class dasar untuk semua produk
    private: // Atribut private
        string nama;
        string merek;
        int harga;
        int stok;

    public: // Method public
        Produk() { // Konstruktor default
        }

        Produk(string nama, string merek, int harga, int stok) { // Konstruktor dengan parameter
            // this-> digunakan untuk membedakan antara atribut dan parameter
            this->nama = nama;
            this->merek = merek; 
            this->harga = harga;
            this->stok = stok;
        }

        // Setter dan Getter untuk setiap atribut

        void setNama(string nama) {
            this->nama = nama;
        }
        string getNama() {
            return this->nama;
        }

        void setMerek(string merek) {
            this->merek = merek;
        }
        string getMerek() {
            return this->merek;
        }

        void setHarga(int harga) {
            this->harga = harga;
        }
        int getHarga() {
            return this->harga;
        }

        void setStok(int stok) {
            this->stok = stok;
        }
        int getStok() {
            return this->stok;
        }

        virtual ~Produk() { // Destruktor virtual, supaya bisa polymorphic dan aman saat delete pointer turunan
        }
};