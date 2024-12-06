import 'package:flutter/material.dart';

class DetailsPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // Use a null check and provide fallback values to avoid errors
    final Map<String, dynamic> args =
        ModalRoute.of(context)!.settings.arguments as Map<String, dynamic>? ?? {};

    // Use null-aware operators to safely handle missing values
    final String type = args['type'] ?? 'Unknown'; // Provide default value
    final int id = args['id'] ?? 0; // Provide default value for id

    return Scaffold(
      appBar: AppBar(title: Text('$type Details')),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text('$type Item #$id', style: TextStyle(fontSize: 20)),
            SizedBox(height: 20),
            FloatingActionButton(
              onPressed: () {
                // Replace with the actual URL
                print('Redirect to external link');
              },
              child: Icon(Icons.link),
            ),
          ],
        ),
      ),
    );
  }
}
