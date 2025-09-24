<?php
require_once 'ProdukElektronik.php';

// Class turunan dari ProdukElektronik, khusus televisi
class Televisi extends ProdukElektronik {
    // Atribut private
    private $ukuranLayar;
    private $resolusi;
    private $isSmartTV;

    // Konstruktor
    public function __construct($nama = "", $merek = "", $harga = 0, $stok = 0, $foto_produk = "no-image.png", $konsumsiDaya = 0, $voltase = 0, $garansi = 0, $ukuranLayar = 0.0, $resolusi = "", $isSmartTV = false) {
        // Memanggil konstruktor induk
        parent::__construct($nama, $merek, $harga, $stok, $foto_produk, $konsumsiDaya, $voltase, $garansi);
        $this->ukuranLayar = $ukuranLayar;
        $this->resolusi = $resolusi;
        $this->isSmartTV = $isSmartTV;
    }

    // Setter dan Getter untuk setiap atribut
    public function setUkuranLayar($ukuranLayar) {
        $this->ukuranLayar = $ukuranLayar;
    }

    public function getUkuranLayar() {
        return $this->ukuranLayar;
    }

    public function setResolusi($resolusi) {
        $this->resolusi = $resolusi;
    }

    public function getResolusi() {
        return $this->resolusi;
    }

    public function setIsSmartTV($isSmartTV) {
        $this->isSmartTV = $isSmartTV;
    }

    public function getIsSmartTV() {
        return $this->isSmartTV;
    }
}