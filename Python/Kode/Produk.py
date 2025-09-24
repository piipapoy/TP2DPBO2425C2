# Class dasar untuk semua produk
class Produk:
    def __init__(self, nama="", merek="", harga=0, stok=0):
        self.nama = nama
        self.merek = merek
        self.harga = harga
        self.stok = stok

    # Setter dan Getter untuk setiap atribut
    def set_nama(self, nama):
        self.nama = nama
    
    def get_nama(self):
        return self.nama

    def set_merek(self, merek):
        self.merek = merek
        
    def get_merek(self):
        return self.merek

    def set_harga(self, harga):
        self.harga = harga
        
    def get_harga(self):
        return self.harga

    def set_stok(self, stok):
        self.stok = stok

    def get_stok(self):
        return self.stok