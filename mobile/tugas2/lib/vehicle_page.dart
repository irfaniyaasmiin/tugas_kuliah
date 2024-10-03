import 'package:flutter/material.dart';
import 'vehicle-data.dart';
import 'login_page.dart'; // Pastikan halaman login diimpor

class VehiclePage extends StatelessWidget {
  const VehiclePage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Vehicles"),
        backgroundColor: Colors.blue[200],
      ),
      body: GridView.builder(
        gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(
          crossAxisCount: 3,
        ),
        itemCount: vehicleList.length,
        itemBuilder: (context, index) {
          Vehicle vehicle = vehicleList[index];
          return Card(
            child: Column(
              children: [

                Text(vehicle.name),
                Text(vehicle.type),
                Text(vehicle.description),
                Text(vehicle.engine),
                Text(vehicle.fuelType),
                Text(vehicle.price),
                Image.network(
                  vehicle.imageUrls[0],
                  width: 100, 
                  height: 60, 
                  fit: BoxFit.fill),
              ],
            ),
          );
        },
      ),
      // FloatingActionButton untuk Logout
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          // Navigasi kembali ke halaman LoginPage
          Navigator.pushReplacement(
            context,
            MaterialPageRoute(builder: (context) => LoginPage()),
          );
        },
        child: Icon(Icons.logout),
        backgroundColor: Colors.red, // Warna merah untuk logout
        tooltip: 'Logout',
      ),
      floatingActionButtonLocation: FloatingActionButtonLocation.endFloat,
    );
  }
}
