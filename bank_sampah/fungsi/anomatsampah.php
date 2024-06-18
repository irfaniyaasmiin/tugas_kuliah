//CLEAR

<?php

// membuat query max untuk kode sampah
$carikode = mysqli_query($dbcon, "select max(id_jenis) from jenis_sampah") or die(mysqli_error());
// menjadikannya array
$datakode = mysqli_fetch_array($carikode);


// jika $datakode
if ($datakode) {
  // membuat variabel baru untuk mengambil kode sampah mulai dari 1
  $nilaikode = substr($datakode[0], 4);
  // menjadikan $nilaikode ( int )
  $kode = (int) $nilaikode;
  // setiap $kode di tambah 1
  $kode = $kode + 1;
  // hasil untuk menambahkan kode 
  // angka 3 untuk menambahkan tiga angka setelah B dan angka 0 angka yang berada di tengah
  // atau angka sebelum $kode
  $hasilkodemasuk = "SMPH" . str_pad($kode, 3, "0", STR_PAD_LEFT);
} else {
  $hasilkodemasuk = "SMPH001";
}

?>
