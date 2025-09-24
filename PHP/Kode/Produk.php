<?php

// Class dasar untuk semua produk
class Produk {
    // Atribut private, di PHP diawali dengan $
    private $nama;
    private $merek;
    private $harga;
    private $stok;
    private $foto_produk; // Atribut baru khusus PHP

    // __construct adalah konstruktor di PHP
    public function __construct($nama = "", $merek = "", $harga = 0, $stok = 0, $foto_produk = "no-image.png") {
        // $this digunakan seperti 'this' di Java/C++
        $this->nama = $nama;
        $this->merek = $merek;
        $this->harga = $harga;
        $this->stok = $stok;
        $this->foto_produk = $foto_produk;
    }

    // Setter dan Getter untuk setiap atribut
    public function setNama($nama) {
        $this->nama = $nama;
    }

    public function getNama() {
        return $this->nama;
    }

    public function setMerek($merek) {
        $this->merek = $merek;
    }

    public function getMerek() {
        return $this->merek;
    }

    public function setHarga($harga) {
        $this->harga = $harga;
    }

    public function getHarga() {
        return $this->harga;
    }

    public function setStok($stok) {
        $this->stok = $stok;
    }

    public function getStok() {
        return $this->stok;
    }

    public function setFotoProduk($foto_produk) {
        $this->foto_produk = $foto_produk;
    }

    public function getFotoProduk() {
        return $this->foto_produk;
    }
}