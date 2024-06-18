<?php 

include_once("config/Class_Customer.php");
$cs = new Class_Supplier();

include_once("config/config.php");
include_once("fungsi/nomatcustomer.php");


if (isset($_GET['hapus'])) {

    $cs->hapus($_GET['id']);
    echo "<script>alert('Data customer berhasil dihapus'); window.location.href='customer.php';</script>";
}
 ?>
<!DOCTYPE html>
<html lang="en">
<?php 
include_once("config/Class_Barang.php");
$db = new Class_Barang();
 

 ?>
<head>

    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="">
    <meta name="author" content="">

    <title>AISP - SMKFU</title>

    <?php 
    include_once("includes/header.php"); ?>

</head>

<body>

    <div id="wrapper">

        <!-- Navigation -->
            <?php include_once("includes/navbar.php"); ?>
            <!-- /.navbar-top-links -->
            <?php include_once("includes/sidebar.php"); ?>
            
            <!-- /.navbar-static-side -->
        <div id="page-wrapper">

<?php 

            if (isset($_GET['page']) && $_GET['page'] == "customerbaru") {

                include_once("supplier/input_customer.php");
            }
            else if (isset($_GET['page']) && $_GET['page'] == "updatecustomer") {

                include_once("supplier/edit_customer.php");
            }
            else{
                include_once("supplier/data_customer.php");
            }

 ?>
            
        </div>
        <!-- /#pag-wrapper -->

    </div>
    <!-- /#wrapper -->

   <?php include_once("includes/footer.php"); ?>

<!-- <script>
$(document).ready(function() {
$('#dataTables-example').DataTable({
responsive: true
});
});
</script>
 -->
</body>

</html>
