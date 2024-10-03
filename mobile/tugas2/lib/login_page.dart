import 'package:flutter/material.dart';
// import 'package:vehicles/vehicle-data.dart';
import 'package:vehicles/vehicle_page.dart';

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Login App',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: LoginPage(),
    );
  }
}

class LoginPage extends StatefulWidget {
  const LoginPage({super.key});

  @override
  State<LoginPage> createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {
  String username = '';
  String password = '';
  bool isLoginSuccess = true;
  bool visible = true;

  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Scaffold(
        appBar: AppBar(
          title: const Text('Login Page'),
        ),
        body: Center(
          child: SingleChildScrollView(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                _usernameField(),
                _passwordField(),
                _loginButton(context),
              ],
            ),
          ),
        ),
      ),
    );
  }

  Widget _usernameField() {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
      child: TextFormField(
        onChanged: (value) {
          username = value;
        },
        enabled: true,
        decoration: InputDecoration(
          labelText: 'Username',
          border: OutlineInputBorder(
            borderRadius: BorderRadius.circular(10),
            borderSide: const BorderSide(color: Colors.black),
          ),
        ),
      ),
    );
  }

  Widget _passwordField() {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
      child: TextFormField(
        enabled: true,
        onChanged: (value) {
          password = value;
        },
        obscureText: visible,
        decoration: InputDecoration(
          suffixIcon: IconButton(
            onPressed: () {
              setState(() {
                visible = !visible;
              });
            },
            icon: Icon(visible ? Icons.visibility : Icons.visibility_off),
          ),
          labelText: 'Password',
          border: OutlineInputBorder(
            borderRadius: BorderRadius.circular(10),
            borderSide: const BorderSide(color: Colors.black),
          ),
        ),
      ),
    );
  }

  Widget _loginButton(BuildContext context) {
    return Container(
      padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
      width: MediaQuery.of(context).size.width,
      child: ElevatedButton(
        onPressed: () {
          String text = '';
          if (username == 'admin' && password == '1234') {
            setState(() {
              text = 'Login berhasil!';
              isLoginSuccess = true;
            });

            // Tampilkan SnackBar dan kemudian pindah ke HomePage setelah beberapa detik
            SnackBar snackBar = SnackBar(
              backgroundColor: isLoginSuccess ? Colors.green : Colors.red,
              duration:
                  const Duration(seconds: 1), // Snackbar tampil selama 2 detik
              content: Text(text),
            );
            ScaffoldMessenger.of(context).showSnackBar(snackBar);

            // Delay selama durasi snackBar dan navigasi ke HomePage
            Future.delayed(const Duration(seconds: 2), () {
              Navigator.pushReplacement(
                context,
                MaterialPageRoute(builder: (context) => VehiclePage()),
              );
            });
          } else {
            setState(() {
              text = 'Login gagal!';
              isLoginSuccess = false;
            });

            SnackBar snackBar = SnackBar(
              backgroundColor: isLoginSuccess ? Colors.green : Colors.red,
              duration: const Duration(seconds: 1),
              content: Text(text),
            );
            ScaffoldMessenger.of(context).showSnackBar(snackBar);
          }
        },
        child: const Text('Login'),
      ),
    );
  }
}
