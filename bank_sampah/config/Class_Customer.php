<?php

/**
 * 
 */
class Class_Customer
{

    function tampil_data()
    {
        include("config.php");

        $sql = "select * from tbl_customer";

        $data = mysqli_query($conn, $sql);
        $data1 = mysqli_num_rows($data);
        if ($data1 == 0) {
            echo "<div class='alert alert-danger'>Tidak ada data</div>";
        } else {
            while ($d = mysqli_fetch_assoc($data)) {
                $hasil[] = $d;
            }
            return $hasil;
        }
    }

    function registrasi($data)
    {
        global $dbcon;

        $username = strtolower(stripslashes($data["username"]));
        $password = mysqli_real_escape_string($dbcon, $data["password"]);
        $confirmation = mysqli_real_escape_string($dbcon, $data["confirmation"]);
        $email = mysqli_real_escape_string($dbcon, $data["email"]);
        $no_telp = mysqli_real_escape_string($dbcon, $data["phone"]);
        $alamat = mysqli_real_escape_string($dbcon, $data["address"]);

        //cek redudansi username
        $result = mysqli_query($dbcon, "SELECT username FROM tbl_customer WHERE username = '$username'");
        if (mysqli_fetch_assoc($result)) {
            echo "<script>
                alert('Username tidak tersedia, silakan pilih username lain!')
            </script>";
            return false;
        }

        //cek konfirmasi pass
        if ($password !== $confirmation) {
            echo "<script>
                alert('Konfirmasi password salah!');
                </script>";
            return false;
        }
        // return 1;

        //enkripsi password
        $password = password_hash($password, PASSWORD_DEFAULT);
        // var_dump($password); die;

        //jika pass sama, tambahkan user baru ke db
        mysqli_query($dbcon, "INSERT INTO tbl_customer VALUES('', '$email', '$username', '$password', '$no_telp', '$alamat')");

        return mysqli_affected_rows($dbcon);
    }

    function input_customer($kode_customer, $email, $username, $password, $no_telp, $alamat)
    {
        include("config.php");
        
        $sql = "insert into tbl_supplier values('" . $kode_supplier . "','" . $nama_supplier . "','" . $alamat_supplier . "','" . $telp_supplier . "','" . $kota_supplier . "')";
        $data = mysqli_query($conn, $sql);
    }

    function edit_customer($kode_customer)
    {
        include("config.php");

        $sql = "select * from tbl_customer where kode_customer='" . $kode_customer . "'";
        $data = mysqli_query($conn, $sql);
        include("config.php");

        while ($d = mysqli_fetch_assoc($data)) {

            $hasil[] = $d;
        }
        return $hasil;
    }

    function update_customer($kode_customer, $email, $username, $no_telp, $alamat)
    {
        include("config.php");

        $sql = "update tbl_customer set email='" . $email . "', username='" . $username . "', phone='" . $no_telp . "', address='" . $alamat . "' where kode_customer='" . $kode_customer . "'";

        $data = mysqli_query($conn, $sql);
    }

    function hapus($kode_customer)
    {
        include("config.php");

        $sql = "delete from tbl_supplier where kode_customer = '" . $customer . "'";

        $data = mysqli_query($conn, $sql);
    }
}
