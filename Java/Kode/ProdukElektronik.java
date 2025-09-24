// Class turunan dari Produk, khusus produk elektronik
public class ProdukElektronik extends Produk {
    // Atribut private
    private int konsumsiDaya;
    private int voltase;
    private int garansi;

    // Konstruktor default
    public ProdukElektronik() {
        super(); // Memanggil konstruktor induk
    }

    // Konstruktor dengan parameter
    public ProdukElektronik(String nama, String merek, int harga, int stok, int konsumsiDaya, int voltase, int garansi) {
        // Memanggil konstruktor induk
        super(nama, merek, harga, stok);
        this.konsumsiDaya = konsumsiDaya;
        this.voltase = voltase;
        this.garansi = garansi;
    }

    // Setter dan Getter untuk setiap atribut
    public void setKonsumsiDaya(int konsumsiDaya) {
        this.konsumsiDaya = konsumsiDaya;
    }
    public int getKonsumsiDaya() {
        return this.konsumsiDaya;
    }

    public void setVoltase(int voltase) {
        this.voltase = voltase;
    }
    public int getVoltase() {
        return this.voltase;
    }

    public void setGaransi(int garansi) {
        this.garansi = garansi;
    }
    public int getGaransi() {
        return this.garansi;
    }
}