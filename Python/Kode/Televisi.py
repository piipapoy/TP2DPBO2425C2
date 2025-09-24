from ProdukElektronik import ProdukElektronik

# Class turunan dari ProdukElektronik, khusus televisi
class Televisi(ProdukElektronik):
    # Konstruktor
    def __init__(self, nama="", merek="", harga=0, stok=0, konsumsi_daya=0, voltase=0, garansi=0, ukuran_layar=0.0, resolusi="", is_smart_tv=False):
        # Memanggil konstruktor induk
        super().__init__(nama, merek, harga, stok, konsumsi_daya, voltase, garansi)
        self.ukuran_layar = ukuran_layar
        self.resolusi = resolusi
        self.is_smart_tv = is_smart_tv

    # Setter dan Getter untuk setiap atribut baru
    def set_ukuran_layar(self, ukuran_layar):
        self.ukuran_layar = ukuran_layar

    def get_ukuran_layar(self):
        return self.ukuran_layar

    def set_resolusi(self, resolusi):
        self.resolusi = resolusi

    def get_resolusi(self):
        return self.resolusi

    def set_is_smart_tv(self, is_smart_tv):
        self.is_smart_tv = is_smart_tv

    def get_is_smart_tv(self):
        return self.is_smart_tv