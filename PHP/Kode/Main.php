<?php
// === BAGIAN 1: INCLUDE KELAS DARI FILE LAIN ===
// Cukup include kelas paling bawah (turunan), karena mereka sudah include induknya.
require_once 'Ponsel.php';
require_once 'Televisi.php';

// === BAGIAN 2: DATA HARDCODE ===
$MAX = 10;
$daftarProduk = [];
$daftarProduk[] = new Ponsel("Galaxy S25", "Samsung", 18000000, 50, "s25.jpg", 15, 5, 24, 6.8, 256, 12);
$daftarProduk[] = new Ponsel("iPhone 17", "Apple", 25000000, 30, "iphone17.jpg", 20, 5, 12, 6.1, 256, 8);
$daftarProduk[] = new Televisi("OLED C4", "LG", 22000000, 20, "lg_oled.jpg", 120, 220, 12, 65, "4K UHD", true);
$daftarProduk[] = new Televisi("Crystal UHD 9", "Samsung", 11000000, 40, "samsung_crystal.jpg", 90, 220, 24, 55, "4K UHD", true);
$daftarProduk[] = new Ponsel("Redmi Note 15", "Xiaomi", 4000000, 100, "redmi15.jpg", 10, 5, 12, 6.67, 128, 8);

?>
<!doctype html>
<html>
<head>
    <meta charset="utf-8">
    <title>Toko Elektronik — Dashboard</title>
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <style>
        :root{
            --bg: #f4f7fb;
            --panel: #ffffff;
            --muted: #6b7280;
            --accent: #0f6fff;
            --accent-2:#06b6d4;
            --table-border: #e6eef6;
            --radius:12px;
        }
        *{box-sizing:border-box}
        body{
            margin:0;
            font-family: Inter, ui-sans-serif, system-ui, -apple-system, "Segoe UI", Roboto, "Helvetica Neue", Arial;
            background: linear-gradient(180deg,#f8fbff 0%,var(--bg) 100%);
            color:#0f172a;
            -webkit-font-smoothing:antialiased;
            padding:28px;
        }
        .wrap{max-width:1100px;margin:0 auto}
        header.appbar{
            display:flex;align-items:center;justify-content:space-between;
            gap:12px;margin-bottom:18px;
        }
        .brand{
            display:flex;align-items:center;gap:12px;
        }
        .logo{
            width:44px;height:44px;border-radius:10px;background:linear-gradient(135deg,var(--accent),var(--accent-2));
            display:flex;align-items:center;justify-content:center;color:#fff;font-weight:700;box-shadow:0 6px 18px rgba(15,23,42,0.08)
        }
        .brand h1{font-size:18px;margin:0}
        
        .card{
            background:var(--panel); border-radius:var(--radius); padding:18px; box-shadow:0 6px 20px rgba(15,23,42,0.06);
        }
        
        .small{font-size:13px;color:var(--muted)}
        .badge{background:#eef2ff;color:var(--accent);padding:6px 10px;border-radius:999px;font-weight:700}

        .table-wrap{overflow:auto;border-radius:10px}
        table{width:100%;border-collapse:collapse;background:linear-gradient(180deg,#fff,#fcfdff);border:1px solid var(--table-border)}
        thead th{font-size:13px;text-align:left;padding:12px;border-bottom:1px solid var(--table-border);background:#fbfdff}
        td, th{padding:12px;border-bottom:1px solid var(--table-border);font-size:14px;vertical-align:middle}
        tbody tr:hover{background:linear-gradient(90deg, rgba(6,182,212,0.03), rgba(15,111,255,0.02));}
        td.center{text-align:center}

        img.thumb{width:120px;height:80px;object-fit:cover;border-radius:8px;border:1px solid #eef7ff}
        
        .search{
            flex:1; display:flex;align-items:center;gap:8px;padding:10px 12px;border-radius:999px;background:linear-gradient(180deg,#fff,#fbfdff);
            border:1px solid #e9f0fb
        }
        .search input{border:none;outline:none;background:transparent;width:100%;font-size:14px}
        .topbar{display:flex;align-items:center;gap:12px;margin-bottom:12px}
    </style>
</head>
<body>
<div class="wrap">
<header class="appbar">
    <div class="brand">
        <div class="logo">TE</div>
        <div>
            <h1>Toko Elektronik</h1>
        </div>
    </div>
    <div style="text-align:right">
        <div class="small muted">Jumlah produk</div>
        <div class="badge"><?php echo count($daftarProduk); ?>/<?php echo $MAX; ?></div>
    </div>
</header>

<main class="main">
    <div class="card">
        <div class="topbar">
            <div class="search">
                <svg width="18" height="18" viewBox="0 0 24 24" fill="none" style="opacity:.7"><path d="M21 21l-4.35-4.35" stroke="#2b3a67" stroke-linecap="round" stroke-linejoin="round"></path><circle cx="11" cy="11" r="6" stroke="#2b3a67" stroke-linecap="round" stroke-linejoin="round"></circle></svg>
                <input id="tableSearch" placeholder="Cari berdasarkan nama atau merek..." type="search">
            </div>
        </div>

        <div class="table-wrap">
        <table id="produkTable">
            <thead>
                <tr>
                    <th style="width:48px">#</th>
                    <th style="width:140px">Gambar</th>
                    <th>Nama</th>
                    <th>Merek</th>
                    <th style="width:110px">Harga</th>
                    <th style="width:80px">Stok</th>
                </tr>
            </thead>
            <tbody>
                <?php foreach ($daftarProduk as $i => $p): ?>
                    <tr data-nama="<?php echo htmlspecialchars(strtolower($p->getNama())); ?>" data-merek="<?php echo htmlspecialchars(strtolower($p->getMerek())); ?>">
                        <td class="center"><?php echo $i + 1; ?></td>
                        <td>
                            <img src="images/<?php echo htmlspecialchars($p->getFotoProduk()); ?>" class="thumb" alt="gambar produk">
                        </td>
                        <td><?php echo htmlspecialchars($p->getNama()); ?></td>
                        <td><?php echo htmlspecialchars($p->getMerek()); ?></td>
                        <td><?php echo number_format($p->getHarga()); ?></td>
                        <td class="center"><?php echo htmlspecialchars($p->getStok()); ?></td>
                    </tr>
                <?php endforeach; ?>
            </tbody>
        </table>
        </div>
    </div>
</main>

</div>

<script>
const searchInput = document.getElementById('tableSearch');
if (searchInput) {
    searchInput.addEventListener('input', function(){
        const q = this.value.trim().toLowerCase();
        const rows = document.querySelectorAll('#produkTable tbody tr');
        rows.forEach(r => {
            const nama = r.dataset.nama || '';
            const merek = r.dataset.merek || '';
            const visible = (!q) || nama.includes(q) || merek.includes(q);
            r.style.display = visible ? '' : 'none';
        });
    });
}
</script>
</body>
</html>