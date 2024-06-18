<div class="row">
    <div class="col-lg-12">
        <h1 class="page-header"> Jenis Sampah</h1>
    </div>
    <!-- /.col-lg-12 -->
</div>
<!-- /.row -->
<div class="row">
    <div class="col-lg-12">
        <div class="panel panel-default">
            <div class="panel-heading">
                Data Jenis Sampah
            </div>
            <!-- /.panel-heading -->
            <div class="panel-body">
                <table width="100%" class="table table-striped table-bordered table-hover" cellpadding="0" cellspacing="0" id="dataTables-example">
                    <thead>
                        <?php

                        if (is_array($db->tampil_data()) && count($db->tampil_data()) > 0) {

                        ?>
                            <tr>
                                <th>No</th>
                                <th>ID Jenis</th>
                                <th>Nama Jenis Sampah</th>
                                <th>Kategori</th>
                                <th>Stok</th>
                                <th>Aksi</th>
                            </tr>
                    </thead>
                    <tbody>
                        <?php
                            $no = 1;

                            foreach ($db->tampil_data() as $row) {

                        ?>
                            <tr>
                                <td><?= $no++ ?></td>
                                <td><?= $row['kode_barang'] ?></td>
                                <td><?= $row['nama_barang'] ?></td>
                                <td><?= $row['jumlah_brg'] ?></td>
                                <td>
                                    <?= $row['jenis_brg'] ?>
                                </td>
                                <td><a href="?id=<?= $row['kode_barang'] ?>&page=update">Edit</a> - <a href="?hapus&id=<?= $row['kode_barang'] ?>" onclick="return confirm('Yakin mau dihapus?');">Hapus</a></td>
                            </tr>
                    <?php }
                        } ?>
                    </tbody>
                </table>
                <!-- /.table-responsive -->

            </div>
            <!-- /.panel-body -->
        </div>
        <!-- /.panel -->
    </div>
    <!-- /.col-lg-12 -->
</div>
<!-- /.row -->