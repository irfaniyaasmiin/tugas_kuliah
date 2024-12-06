import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'pages/login_page.dart';
import 'pages/register_page.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'SpaceFlight News',
      theme: ThemeData(primarySwatch: Colors.purple),
      initialRoute: '/checkLogin',
      routes: {
        '/checkLogin': (context) => CheckLoginStatus(),
        '/login': (context) => LoginPage(),
        '/register': (context) => RegisterPage(),
      },
    );
  }
}

class CheckLoginStatus extends StatefulWidget {
  @override
  _CheckLoginStatusState createState() => _CheckLoginStatusState();
}

class _CheckLoginStatusState extends State<CheckLoginStatus> {
  @override
  void initState() {
    super.initState();
    _checkLoginStatus();
  }

  Future<void> _checkLoginStatus() async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    bool isLoggedIn = prefs.getBool('isLoggedIn') ?? false;

    // Navigate to the appropriate page based on login status
    Future.delayed(Duration.zero, () {
      if (isLoggedIn) {
        Navigator.pushReplacementNamed(
            context, '/login'); // Navigate to HomePage
      } else {
        Navigator.pushReplacementNamed(
            context, '/login'); // Navigate to LoginPage
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    // Loading indicator while login status is being checked
    return const Scaffold(
      body: Center(child: CircularProgressIndicator()),
    );
  }
}
