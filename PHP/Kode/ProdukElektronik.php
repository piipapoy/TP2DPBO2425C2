<?php
// Impor file induk menggunakan require_once
require_once 'Produk.php';

// Class turunan dari Produk, khusus produk elektronik
class ProdukElektronik extends Produk {
    // Atribut private
    private $konsumsiDaya;
    private $voltase;
    private $garansi;

    // Konstruktor
    public function __construct($nama = "", $merek = "", $harga = 0, $stok = 0, $foto_produk = "no-image.png", $konsumsiDaya = 0, $voltase = 0, $garansi = 0) {
        // Memanggil konstruktor induk
        parent::__construct($nama, $merek, $harga, $stok, $foto_produk);
        $this->konsumsiDaya = $konsumsiDaya;
        $this->voltase = $voltase;
        $this->garansi = $garansi;
    }

    // Setter dan Getter untuk setiap atribut
    public function setKonsumsiDaya($konsumsiDaya) {
        $this->konsumsiDaya = $konsumsiDaya;
    }

    public function getKonsumsiDaya() {
        return $this->konsumsiDaya;
    }

    public function setVoltase($voltase) {
        $this->voltase = $voltase;
    }

    public function getVoltase() {
        return $this->voltase;
    }

    public function setGaransi($garansi) {
        $this->garansi = $garansi;
    }

    public function getGaransi() {
        return $this->garansi;
    }
}