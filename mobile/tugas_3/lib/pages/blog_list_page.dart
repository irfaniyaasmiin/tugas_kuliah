import 'package:flutter/material.dart';

class BlogListPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Blog List')),
      body: ListView.builder(
        itemCount: 10, // Replace with API data length
        itemBuilder: (context, index) {
          return ListTile(
            title: Text('Blog $index'),
            subtitle: Text('Subtitle for Blog $index'),
            onTap: () {
              Navigator.pushNamed(context, '/details', arguments: {
                'type': 'blogs',
                'id': index,
              });
            },
          );
        },
      ),
    );
  }
}
