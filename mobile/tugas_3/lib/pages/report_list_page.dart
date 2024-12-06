import 'package:flutter/material.dart';

class ReportListPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Report List')),
      body: ListView.builder(
        itemCount: 10, // Replace with API data length
        itemBuilder: (context, index) {
          return ListTile(
            title: Text('Report $index'),
            subtitle: Text('Subtitle for Report $index'),
            onTap: () {
              Navigator.pushNamed(context, '/details', arguments: {
                'type': 'reports',
                'id': index,
              });
            },
          );
        },
      ),
    );
  }
}
