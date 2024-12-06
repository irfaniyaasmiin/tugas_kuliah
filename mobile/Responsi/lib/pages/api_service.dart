import 'dart:convert';
import 'package:http/http.dart' as http;
// import '../api/model.dart';

class ApiService {
  static const String baseUrl = "https://www.themealdb.com/api/json/v1/1";

  // Fetch articles, blogs, or reports
  static Future<List<dynamic>> fetchData(String endpoint) async {
    final response = await http.get(Uri.parse('$baseUrl/$endpoint'));

    if (response.statusCode == 200) {
      final data = jsonDecode(response.body);
      return data['results']; // Adjust based on API's structure
    } else {
      throw Exception("Failed to load $endpoint data");
    }
  }

  // Fetch details by ID
  static Future<dynamic> fetchDetails(String endpoint, int id) async {
    final response = await http.get(Uri.parse('$baseUrl/$endpoint/$id'));

    if (response.statusCode == 200) {
      return jsonDecode(response.body);
    } else {
      throw Exception("Failed to load $endpoint details");
    }
  }
}
