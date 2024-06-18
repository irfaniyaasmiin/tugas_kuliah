-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Waktu pembuatan: 18 Jun 2024 pada 07.23
-- Versi server: 10.4.32-MariaDB
-- Versi PHP: 8.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bank_sampah`
--

-- --------------------------------------------------------

--
-- Struktur dari tabel `tbl_barang`
--

CREATE TABLE `tbl_barang` (
  `kode_barang` varchar(8) NOT NULL,
  `nama_barang` varchar(30) NOT NULL,
  `kategori` varchar(25) NOT NULL,
  `jumlah_brg` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Struktur dari tabel `tbl_customer`
--

CREATE TABLE `tbl_customer` (
  `kode_customer` varchar(8) NOT NULL,
  `email` varchar(40) NOT NULL,
  `username` varchar(40) NOT NULL,
  `password` varchar(255) NOT NULL,
  `no_telp` char(13) NOT NULL,
  `alamat` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data untuk tabel `tbl_customer`
--

INSERT INTO `tbl_customer` (`kode_customer`, `email`, `username`, `password`, `no_telp`, `alamat`) VALUES
('', 'yaasmiinirfani@gmail.com', 'beruang', '$2y$10$eOSDv73nzm3.cVTMPofPgOY3Flf.D8Qb6hEa7X882foC4nSmuMYD.', '089999999', 'disini');

-- --------------------------------------------------------

--
-- Struktur dari tabel `tbl_keluarbarang`
--

CREATE TABLE `tbl_keluarbarang` (
  `no_pinjam` varchar(8) NOT NULL,
  `kode_barang` varchar(8) NOT NULL,
  `nama_barang` varchar(30) NOT NULL,
  `tgl_keluar` date NOT NULL,
  `penerima` varchar(35) NOT NULL,
  `jumlah_keluar` int(8) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Struktur dari tabel `tbl_masukbarang`
--

CREATE TABLE `tbl_masukbarang` (
  `id_masukbarang` varchar(11) NOT NULL,
  `kode_barang` varchar(8) NOT NULL,
  `nama_barang` varchar(30) NOT NULL,
  `tgl_masuk` date NOT NULL,
  `jumlah_masuk` int(8) NOT NULL,
  `kode_supplier` varchar(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Struktur dari tabel `tbl_pinjam`
--

CREATE TABLE `tbl_pinjam` (
  `nomor_pinjam` varchar(8) NOT NULL,
  `tgl_pinjam` date NOT NULL,
  `kode_barang` varchar(8) NOT NULL,
  `nama_barang` varchar(30) NOT NULL,
  `jumlah_pinjam` int(7) NOT NULL,
  `peminjam` varchar(35) NOT NULL,
  `tgl_kembali` date NOT NULL,
  `keterangan` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Struktur dari tabel `tbl_stok`
--

CREATE TABLE `tbl_stok` (
  `kode_barang` varchar(8) NOT NULL,
  `nama_barang` varchar(30) NOT NULL,
  `jml_barangmasuk` int(7) NOT NULL,
  `jml_barangkeluar` int(7) NOT NULL,
  `total_barang` int(8) NOT NULL,
  `keterangan` varchar(25) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data untuk tabel `tbl_stok`
--

INSERT INTO `tbl_stok` (`kode_barang`, `nama_barang`, `jml_barangmasuk`, `jml_barangkeluar`, `total_barang`, `keterangan`) VALUES
('B002', 'Buku Pemrograman Dasar', 2, 1, 2, 'Segera'),
('SMPH001', 'kaca', 0, 0, 0, '-'),
('SMPH001', 'kaca', 0, 0, 0, '-'),
('SMPH001', 'kaca', 0, 0, 0, 'tidak ada'),
('SMPH001', 'kaca', 0, 0, 0, '-'),
('SMPH001', 'kaca', 0, 0, 0, '-'),
('SMPH001', 'kaca', 0, 0, 0, '-'),
('SMPH001', 'kaca', 0, 0, 0, '-'),
('SMPH001', 'goni', 0, 0, 0, '-'),
('SMPH001', 'kaca', 0, 0, 0, 'u'),
('SMPH001', 'plastik', 0, 0, 0, '-'),
('SMPH001', 'keramik', 0, 0, 0, '-');

-- --------------------------------------------------------

--
-- Struktur dari tabel `tbl_supplier`
--

CREATE TABLE `tbl_supplier` (
  `kode_supplier` varchar(5) NOT NULL,
  `nama_supplier` varchar(35) NOT NULL,
  `alamat_supplier` varchar(50) NOT NULL,
  `telp_supplier` varchar(25) NOT NULL,
  `kota_supplier` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci ROW_FORMAT=COMPACT;

--
-- Dumping data untuk tabel `tbl_supplier`
--

INSERT INTO `tbl_supplier` (`kode_supplier`, `nama_supplier`, `alamat_supplier`, `telp_supplier`, `kota_supplier`) VALUES
('SP001', 'Gramedia', 'Jl. raya pajajaran No 37', '02518356341', 'Bogor'),
('SP002', 'Electronics Best', 'Jl. Gajah Mada No 55', '02518356341', 'Jakarta'),
('SP003', 'Furniture Indonesia', 'Jl. raya tamrin', '02513534764', 'Jakarta');

-- --------------------------------------------------------

--
-- Struktur dari tabel `tbl_user`
--

CREATE TABLE `tbl_user` (
  `id_user` varchar(8) NOT NULL,
  `username` varchar(35) NOT NULL,
  `password` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data untuk tabel `tbl_user`
--

INSERT INTO `tbl_user` (`id_user`, `username`, `password`) VALUES
('001', 'admin', '4QrcOUm6Wau+VuBX8g+IPg==');

--
-- Indexes for dumped tables
--

--
-- Indeks untuk tabel `tbl_barang`
--
ALTER TABLE `tbl_barang`
  ADD PRIMARY KEY (`kode_barang`);

--
-- Indeks untuk tabel `tbl_customer`
--
ALTER TABLE `tbl_customer`
  ADD PRIMARY KEY (`kode_customer`);

--
-- Indeks untuk tabel `tbl_masukbarang`
--
ALTER TABLE `tbl_masukbarang`
  ADD PRIMARY KEY (`id_masukbarang`);

--
-- Indeks untuk tabel `tbl_pinjam`
--
ALTER TABLE `tbl_pinjam`
  ADD PRIMARY KEY (`nomor_pinjam`);

--
-- Indeks untuk tabel `tbl_supplier`
--
ALTER TABLE `tbl_supplier`
  ADD PRIMARY KEY (`kode_supplier`);

--
-- Indeks untuk tabel `tbl_user`
--
ALTER TABLE `tbl_user`
  ADD PRIMARY KEY (`id_user`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
