import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';

class HomePage extends StatefulWidget {
  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  String username = '';

  @override
  void initState() {
    super.initState();
    _loadUsername();
  }

  Future<void> _loadUsername() async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    setState(() {
      username = prefs.getString('username') ?? 'Guest'; // Default to 'Guest' if not set
    });
  }

  Future<void> logout(BuildContext context) async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    prefs.setBool('isLoggedIn', false);
    Navigator.pushReplacementNamed(context, '/login');
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Welcome, $username'), // Display the username here
        actions: [
          IconButton(
            icon: Icon(Icons.logout),
            onPressed: () => logout(context),
          ),
        ],
      ),
      body: ListView(
        children: [
          ListTile(
            title: Text('News'),
            subtitle: Text('Latest spaceflight news'),
            leading: Icon(Icons.newspaper),
            onTap: () => Navigator.pushNamed(context, '/news'),
          ),
          ListTile(
            title: Text('Blogs'),
            subtitle: Text('Detailed spaceflight blogs'),
            leading: Icon(Icons.article),
            onTap: () => Navigator.pushNamed(context, '/blogs'),
          ),
          ListTile(
            title: Text('Reports'),
            subtitle: Text('Spaceflight reports'),
            leading: Icon(Icons.report),
            onTap: () => Navigator.pushNamed(context, '/reports'),
          ),
        ],
      ),
    );
  }
}
