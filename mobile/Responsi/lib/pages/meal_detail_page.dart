import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

class MealDetailPage extends StatefulWidget {
  final String mealId;

  MealDetailPage({required this.mealId});

  @override
  _MealDetailPageState createState() => _MealDetailPageState();
}

class _MealDetailPageState extends State<MealDetailPage> {
  late Map mealDetail;
  bool isLoading = true; // Manage loading state
  String errorMessage = ""; // For error messages

  @override
  void initState() {
    super.initState();
    fetchMealDetail();
  }

  Future<void> fetchMealDetail() async {
    final url =
        "https://www.themealdb.com/api/json/v1/1/lookup.php?i=${widget.mealId}";
    try {
      final response = await http.get(Uri.parse(url));
      if (response.statusCode == 200) {
        final data = jsonDecode(response.body);
        setState(() {
          mealDetail = data['meals'][0]; // Store meal data
          isLoading = false; // Set loading to false when data is loaded
        });
      } else {
        setState(() {
          isLoading = false;
          errorMessage = "Failed to load meal details.";
        });
      }
    } catch (e) {
      setState(() {
        isLoading = false;
        errorMessage = "Error fetching meal details: $e";
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title:
            Text(mealDetail.isEmpty ? "Meal Details" : mealDetail['strMeal']),
      ),
      body: isLoading
          ? Center(child: CircularProgressIndicator()) // Show loading indicator
          : errorMessage.isNotEmpty
              ? Center(
                  child: Text(errorMessage,
                      style: TextStyle(
                          color: Colors.red))) // Show error message if any
              : Padding(
                  padding: const EdgeInsets.all(16.0),
                  child: ListView(
                    children: [
                      Image.network(mealDetail['strMealThumb']),
                      SizedBox(height: 10),
                      Text(
                        mealDetail['strMeal'],
                        style: TextStyle(
                            fontSize: 24, fontWeight: FontWeight.bold),
                      ),
                      SizedBox(height: 10),
                      Text("Category: ${mealDetail['strCategory']}"),
                      Text("Area: ${mealDetail['strArea']}"),
                      SizedBox(height: 20),
                      Text("Ingredients:",
                          style: TextStyle(fontWeight: FontWeight.bold)),
                      for (int i = 1; i <= 20; i++)
                        if (mealDetail['strIngredient$i'] != "" &&
                            mealDetail['strIngredient$i'] != null)
                          Text(
                              "${mealDetail['strIngredient$i']} - ${mealDetail['strMeasure$i']}"),
                      SizedBox(height: 20),
                      Text("Instructions:",
                          style: TextStyle(fontWeight: FontWeight.bold)),
                      Text(mealDetail['strInstructions']),
                      SizedBox(height: 20),
                      ElevatedButton(
                        onPressed: () {
                          // Open the video tutorial
                          final tutorialUrl = mealDetail['strYoutube'];
                          print(
                              tutorialUrl); // You could use a webview to open the YouTube link
                        },
                        child: Text("Watch Tutorial"),
                      ),
                    ],
                  ),
                ),
    );
  }
}
