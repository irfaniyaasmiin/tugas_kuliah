<?php 
include_once("../config/Class_Customer.php");
$db = new Class_Customer();
include_once("../config/config.php");

$aksi = $_GET["aksi"];

// ===========================================================================================
// CUSTOMER BARU
// ===========================================================================================

if ($aksi == "tambah") {

    $kode_customer = $_POST['kode_customer'];
    $email = $_POST['email'];
    $username = $_POST['username'];
    $no_telp = $_POST['phone'];
    $alamat = $_POST['address'];

    $db->input_customer($kode_customer,$email,$username,$no_telp,$alamat);

    echo "<script>alert('Data customer berhasil ditambahkan'); window.location.href='../customer.php';</script>";

}
if ($aksi == "update") {

    $kode_customer = $_POST['kode_customer'];
    $email = $_POST['email'];
    $username = $_POST['username'];
    $no_telp = $_POST['phone'];
    $alamat = $_POST['address'];

    $db->update_customer($kode_customer,$email,$username,$no_telp,$alamat);

    echo "<script>alert('Data customer berhasil diubah'); window.location.href='../customer.php';</script>";

}
