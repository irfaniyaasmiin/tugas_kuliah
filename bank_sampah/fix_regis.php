<?php
session_start();
include('config/config.php');

//fungsi registrasi yang sebelumnya dideklarasikan di koneksi.php
if (isset($_POST["register"])) {
    if (registrasi($_POST) > 0) {
        echo "<script>
            alert('Registrasi berhasil!');
            </script>
        ";
    } else {
        echo mysqli_error($dbcon);
    }
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <!-- Fonts -->
    <link rel="preconnect" href="https://fonts.googleapis.com" />
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />
    <link href="https://fonts.googleapis.com/css2?family=Poppins:ital,wght@0,100;0,300;0,400;0,700;1,700&display=swap" rel="stylesheet" />

    <!-- Icons -->
    <script type="module" src="https://unpkg.com/ionicons@7.1.0/dist/ionicons/ionicons.esm.js"></script>
    <script nomodule src="https://unpkg.com/ionicons@7.1.0/dist/ionicons/ionicons.js"></script>

    <!-- My Style -->
    <link rel="stylesheet" href="dist/css/form.css" />
    <title>Sign Up</title>
</head>

<body>
    <section>
        <div class="form-box">
            <div class="form-value">
                <form action="" method="POST">
                    <!-- <h6>Surolaras</h6> -->
                    <h1>Sign Up</h1>
                    <div class="input-box">
                        <ion-icon name="mail-outline"></ion-icon>
                        <input type="text" name="email" required>
                        <label for="email">Email</label>
                    </div>
                    <div class="input-box">
                        <ion-icon name="user-outline"></ion-icon>
                        <input type="text" name="username" required>
                        <label for="username">Username</label>
                    </div>
                    <div class="input-box">
                        <ion-icon name="lock-closed-outline"></ion-icon>
                        <input type="password" name="password" required>
                        <label for="password">Password</label>
                    </div>
                    <div class="input-box">
                        <ion-icon name="document-lock-outline"></ion-icon>
                        <input type="password" name="confirmation" required>
                        <label for="confirmation">Password Confirmation</label>
                    </div>
                    <div class="input-box">
                        <ion-icon name="user-outline"></ion-icon>
                        <input type="number" name="phone" required>
                        <label for="phone">Phone</label>
                    </div>
                    <div class="input-box">
                        <ion-icon name="user-outline"></ion-icon>
                        <input type="text" name="address" required>
                        <label for="username">Address</label>
                    </div>

                    <!-- <select name="user_type" id="">
                        <option value="user">user</option>
                        <option value="admin" selected>admin</option>
                    </select> -->

                    <bottom class="bottom">
                        <button type="submit" name="register">Sign Up</button>
                        <div class="register">
                            <p>Already have an account? <a href="editlogin.php">Sign In</a></p>
                        </div>
                    </bottom>
                </form>
            </div>
        </div>
    </section>
</body>

</html>