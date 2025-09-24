<?php
require_once 'ProdukElektronik.php';

// Class turunan dari ProdukElektronik, khusus ponsel
class Ponsel extends ProdukElektronik {
    // Atribut private
    private $ukuranLayar;
    private $kapasitasPenyimpanan;
    private $ram;

    // Konstruktor
    public function __construct($nama = "", $merek = "", $harga = 0, $stok = 0, $foto_produk = "no-image.png", $konsumsiDaya = 0, $voltase = 0, $garansi = 0, $ukuranLayar = 0.0, $kapasitasPenyimpanan = 0, $ram = 0) {
        // Memanggil konstruktor induk
        parent::__construct($nama, $merek, $harga, $stok, $foto_produk, $konsumsiDaya, $voltase, $garansi);
        $this->ukuranLayar = $ukuranLayar;
        $this->kapasitasPenyimpanan = $kapasitasPenyimpanan;
        $this->ram = $ram;
    }

    // Setter dan Getter untuk setiap atribut
    public function setUkuranLayar($ukuranLayar) {
        $this->ukuranLayar = $ukuranLayar;
    }

    public function getUkuranLayar() {
        return $this->ukuranLayar;
    }

    public function setKapasitasPenyimpanan($kapasitasPenyimpanan) {
        $this->kapasitasPenyimpanan = $kapasitasPenyimpanan;
    }

    public function getKapasitasPenyimpanan() {
        return $this->kapasitasPenyimpanan;
    }

    public function setRam($ram) {
        $this->ram = $ram;
    }

    public function getRam() {
        return $this->ram;
    }
}