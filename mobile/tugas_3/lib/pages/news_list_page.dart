import 'package:flutter/material.dart';

class NewsListPage extends StatelessWidget {
  // Simulating data for the news list
  final List<Map<String, dynamic>> newsList = List.generate(
    10,
    (index) => {
      'id': index, 
      'title': 'News $index', 
      'content': 'Subtitle for News $index'
    },
  );

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('News List')),
      body: ListView.builder(
        itemCount: newsList.length, // Use length of the news list
        itemBuilder: (context, index) {
          // Get news data
          var newsItem = newsList[index];

          return ListTile(
            title: Text(newsItem['title']), // Display title
            subtitle: Text(newsItem['content']), // Display content as subtitle
            onTap: () {
              // Navigate to the details page and pass the arguments
              Navigator.pushNamed(
                context,
                '/details',
                arguments: {
                  'endpoint': 'articles',  // Specify the endpoint, e.g., articles
                  'id': newsItem['id'],    // Pass the news item ID
                  'title': newsItem['title'], // Pass the news title
                },
              );
            },
          );
        },
      ),
    );
  }
}
