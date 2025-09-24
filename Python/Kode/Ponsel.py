from ProdukElektronik import ProdukElektronik

# Class turunan dari ProdukElektronik, khusus ponsel
class Ponsel(ProdukElektronik):
    # Konstruktor
    def __init__(self, nama="", merek="", harga=0, stok=0, konsumsi_daya=0, voltase=0, garansi=0, ukuran_layar=0.0, kapasitas_penyimpanan=0, ram=0):
        # Memanggil konstruktor induk
        super().__init__(nama, merek, harga, stok, konsumsi_daya, voltase, garansi)
        self.ukuran_layar = ukuran_layar
        self.kapasitas_penyimpanan = kapasitas_penyimpanan
        self.ram = ram

    # Setter dan Getter untuk setiap atribut baru
    def set_ukuran_layar(self, ukuran_layar):
        self.ukuran_layar = ukuran_layar

    def get_ukuran_layar(self):
        return self.ukuran_layar
    
    def set_kapasitas_penyimpanan(self, kapasitas_penyimpanan):
        self.kapasitas_penyimpanan = kapasitas_penyimpanan

    def get_kapasitas_penyimpanan(self):
        return self.kapasitas_penyimpanan

    def set_ram(self, ram):
        self.ram = ram

    def get_ram(self):
        return self.ram