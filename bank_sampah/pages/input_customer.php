<div class="row">
    <div class="col-lg-12">
        <h1 class="page-header">Form Customer</h1>
    </div>
    <!-- /.col-lg-12 -->
</div>
<!-- /.row -->
<div class="row">
    <div class="col-lg-12">
        <div class="panel panel-default">
            <div class="panel-heading">
                Form Customer Baru
            </div>
            <div class="panel-body">
                <div class="row">
                    <div class="col-lg-6">
                        <form action="pages/proses_customer.php?aksi=tambah" method="post" enctype="multipart/form-data">
                            <div class="form-group">
                                <label>ID Customer</label>
                                <input type="text" name="kode_customer" value="<?= $hasilkode ?>" class="form-control" readonly>
                            </div>
                            <div class="form-group">
                                <label>Email</label>
                                <input type="email" placeholder="email@gmail.com" name="email" class="form-control" class="form-control" required>
                            </div>
                            <div class="form-group">
                                <label>Username</label>
                                <input type="text" placeholder="Masukan Username" name="username" class="form-control" required>
                            </div>
                            <div class="form-group">
                                <label>Password</label>
                                <input type="password" placeholder="Password" name="password" class="form-control" required>
                            </div>
                            <div class="form-group">
                                <label>No Telepon Aktif</label>
                                <input type="number" placeholder="No Telepon" name="phone" class="form-control" required>
                            </div>
                            <div class="form-group">
                                <label>Kecamatan</label>
                                <select name="address" class="form-control" required>
                                    <option value="">Pilih Daerah</option>
                                    <option value="Sleman">Sleman</option>
                                    <option value="Turi">Turi</option>
                                    <option value="Pakem">Pakem</option>
                                    <option value="Tempel">Tempel</option>
                                    <option value="Seyegan">Seyegan</option>
                                    <option value="Prambanan">Prambanan</option>
                                    <option value="Minggir">Minggir</option>
                                    <option value="Ngemplak">Ngemplak</option>
                                    <option value="Mlati">Mlati</option>
                                    <option value="Moyudan">Moyudan</option>
                                    <option value="Ngaglik">Ngaglik</option>
                                    <option value="Cangkringan">Cangkringan</option>
                                    <option value="Kalasan">Kalasan</option>
                                    <option value="Depok">Depok</option>
                                    <option value="Godean">Godean</option>
                                    <option value="Gamping">Gamping</option>
                                    <option value="Berbah">Berbah</option>
                                </select>
                            </div>
                            <!-- <div class="form-group">
                                <label>Alamat</label>
                                <input type="text" placeholder="Alamat" name="adress" class="form-control" required>
                            </div> -->
                            <div class="form-group">
                                <button type="submit" name="submit" value="Simpan" class="btn btn-default" style="background-color: #333; color: #fff;">Submit</button>
                                <a href='?page=databarang' class="btn btn-default">Batal</a>
                            </div>
                    </div>
                    <!-- /.col-lg-6 (nested) -->
                    <!-- <div class="col-lg-6">
                        <div class="form-group">
                            <label>Kondisi</label>
                            <select name="kondisi" class="form-control" required>
                                <option value="">Pilih Kondisi</option>
                                <option value="Baru">Baru</option>
                                <option value="Bekas">Bekas</option>
                            </select>
                        </div>
                        <div class="form-group">
                            <label>Jenis Barang</label>
                            <input type="text" placeholder="Jenis Barang" name="jenis_barang" class="form-control" required>
                        </div>
                        <div class="form-group">
                            <label>Sumber Dana</label>
                            <input type="text" placeholder="Sumber Dana" name="sumber_dana" class="form-control" required>
                        </div>
                        <div class="form-group">
                            <label>Keterangan</label>
                            <textarea name="keterangan" class="form-control" required placeholder="keterangan"></textarea>
                        </div> -->

                    </form>
                </div>
                <!-- /.col-lg-6 (nested) -->
            </div>
            <!-- /.row (nested) -->
        </div>
        <!-- /.panel-body -->
    </div>
    <!-- /.panel -->
</div>
<!-- /.col-lg-12 -->
</div>
<!-- /.row -->