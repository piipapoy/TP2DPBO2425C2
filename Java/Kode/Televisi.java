// Class turunan dari ProdukElektronik, khusus televisi
public class Televisi extends ProdukElektronik {
    // Atribut private
    private double ukuranLayar;
    private String resolusi;
    private boolean isSmartTV;

    // Konstruktor default
    public Televisi() {
        super();
    }

    // Konstruktor dengan parameter
    public Televisi(String nama, String merek, int harga, int stok, int konsumsiDaya, int voltase, int garansi,
                    double ukuranLayar, String resolusi, boolean isSmartTV) {
        // Memanggil konstruktor induk
        super(nama, merek, harga, stok, konsumsiDaya, voltase, garansi);
        this.ukuranLayar = ukuranLayar;
        this.resolusi = resolusi;
        this.isSmartTV = isSmartTV;
    }

    // Setter dan Getter untuk setiap atribut
    public void setUkuranLayar(double ukuranLayar) {
        this.ukuranLayar = ukuranLayar;
    }
    public double getUkuranLayar() {
        return this.ukuranLayar;
    }

    public void setResolusi(String resolusi) {
        this.resolusi = resolusi;
    }
    public String getResolusi() {
        return this.resolusi;
    }

    public void setIsSmartTV(boolean isSmartTV) {
        this.isSmartTV = isSmartTV;
    }
    public boolean getIsSmartTV() {
        return this.isSmartTV;
    }
}