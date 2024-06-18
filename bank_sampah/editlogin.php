<?php
include('config/config.php');

if (isset($_POST["login"])) {
  $username = $_POST["username"];
  $password = $_POST["password"];

  $result = mysqli_query($conn, "SELECT * FROM tbl_customer WHERE '$username' = username");
  if (mysqli_num_rows($result) === 1) {
    //cek password
    $row = mysqli_fetch_assoc($result);
    if (password_verify($password, $row["password"])) {
      header("location: index.php");
      exit;
    }
  }
  $error = true;
}

// session_start();
// include('koneksi.php');

// if (isset($_SESSION['admin_name'])) {
//   header('location:admin.php');
// }

// if (isset($_SESSION['user_name'])) {
//   header('location:user.php');
// }

// if (isset($_POST['submit'])) {
//   $username = mysqli_real_escape_string($dbcon, $_POST['username']);
//   $password = md5($_POST['password']);

//   $select = "SELECT * FROM user WHERE username= '$username' && password='$password'";

//   $result = mysqli_query($dbcon, $select);

//   if (mysqli_num_rows($result) > 0) {

//     $row = mysqli_fetch_array($result);

//     if ($row['user_type'] == 'admin') {
//       $_SESSION['admin_name'] = $row['name'];
//       header('location:admin.php');
//     } else if ($row['user_type'] == 'user') {
//       $_SESSION['user_name'] = $row['name'];
//       header('location:user.php');
//     }
//   } else {
//     $error[] = 'incorrect pass or username';
//   }
// };
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
  <title>Sign In</title>
</head>

<body>
  <section>
    <div class="form-box">
      <div class="form-value">
        <form action="" method="POST">
          <!-- <h6>Surolaras</h6> -->
          <h1>Sign In</h1>
          <div class="input-box">
            <ion-icon name="mail-outline"></ion-icon>
            <input type="text" name="username" required />
            <label for="username">Username</label>
          </div>
          <div class="input-box">
            <ion-icon name="lock-closed-outline"></ion-icon>
            <input type="password" name="password" required />
            <label for="password">Password</label>
          </div>
          <div class="alert">
            <?php if (isset($error)) :
              echo "<script>
                      alert('Username/password salah!')
                  </script>";
            ?>
              <!-- <p>Username/password salah!</p> -->
            <?php endif; ?>
          </div>
          <div class="forget">
            <label for=""><input type="checkbox" />Remember Me</label>
            <a href="#">Forget Password</a>
          </div>
          <bottom class="bottom">
            <button type="submit" name="login">Log In</button>
            <div class="register">
              <p>
                Don't have an account? <a href="fix_regis.php">Sign Up</a>
              </p>
            </div>
          </bottom>
        </form>
      </div>
    </div>
  </section>
</body>

</html>