// Class turunan dari ProdukElektronik, khusus ponsel
public class Ponsel extends ProdukElektronik {
    // Atribut private
    private double ukuranLayar;
    private int kapasitasPenyimpanan;
    private int ram;

    // Konstruktor default
    public Ponsel() {
        super();
    }

    // Konstruktor dengan parameter
    public Ponsel(String nama, String merek, int harga, int stok, int konsumsiDaya, int voltase, int garansi,
                  double ukuranLayar, int kapasitasPenyimpanan, int ram) {
        // Memanggil konstruktor induk
        super(nama, merek, harga, stok, konsumsiDaya, voltase, garansi);
        this.ukuranLayar = ukuranLayar;
        this.kapasitasPenyimpanan = kapasitasPenyimpanan;
        this.ram = ram;
    }

    // Setter dan Getter untuk setiap atribut
    public void setUkuranLayar(double ukuranLayar) {
        this.ukuranLayar = ukuranLayar;
    }
    public double getUkuranLayar() {
        return this.ukuranLayar;
    }

    public void setKapasitasPenyimpanan(int kapasitasPenyimpanan) {
        this.kapasitasPenyimpanan = kapasitasPenyimpanan;
    }
    public int getKapasitasPenyimpanan() {
        return this.kapasitasPenyimpanan;
    }

    public void setRam(int ram) {
        this.ram = ram;
    }
    public int getRam() {
        return this.ram;
    }
}