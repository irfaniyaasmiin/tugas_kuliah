<?php 
ob_start();

$host = "localhost";
$dbuser = "root";
$dbpass = "";
$dbname = "bank_sampah";

// membuat koneksi
$conn = new mysqli("$host","$dbuser","$dbpass","$dbname");

// pengecekan koneksi
if ($conn->connect_error) {
    die("Koneksi gagal :" . $conn->connect_error);
}
// else
// {
//     echo "berhasil";
// }

 ?>