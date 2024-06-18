//CLEAR

<?php

// membuat query max untuk kode setoran
$carikode = mysqli_query($dbcon, "select max(id_setoran) from setoran") or die(mysqli_error());
// menjadikannya array
$datakode = mysqli_fetch_array($carikode);


// jika $datakode
if ($datakode) {
  // membuat variabel baru untuk mengambil kode setoran mulai dari 1
  $nilaikode = substr($datakode[0], 3);
  // menjadikan $nilaikode ( int )
  $kode = (int) $nilaikode;
  // setiap $kode di tambah 1
  $kode = $kode + 1;
  // hasil untuk menambahkan kode 
  // angka 3 untuk menambahkan tiga angka setelah B dan angka 0 angka yang berada di tengah
  // atau angka sebelum $kode
  $hasilkodemasuk = "STR" . str_pad($kode, 3, "0", STR_PAD_LEFT);
} else {
  $hasilkodemasuk = "STR001";
}

?>
