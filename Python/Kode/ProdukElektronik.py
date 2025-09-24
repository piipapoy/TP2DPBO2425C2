# Import kelas induk dari file-nya
from Produk import Produk

# Class turunan dari Produk, khusus produk elektronik
class ProdukElektronik(Produk):
    # Konstruktor
    def __init__(self, nama="", merek="", harga=0, stok=0, konsumsi_daya=0, voltase=0, garansi=0):
        # Memanggil konstruktor induk
        super().__init__(nama, merek, harga, stok)
        self.konsumsi_daya = konsumsi_daya
        self.voltase = voltase
        self.garansi = garansi
    
    # Setter dan Getter untuk setiap atribut baru
    def set_konsumsi_daya(self, konsumsi_daya):
        self.konsumsi_daya = konsumsi_daya

    def get_konsumsi_daya(self):
        return self.konsumsi_daya

    def set_voltase(self, voltase):
        self.voltase = voltase

    def get_voltase(self):
        return self.voltase

    def set_garansi(self, garansi):
        self.garansi = garansi

    def get_garansi(self):
        return self.garansi