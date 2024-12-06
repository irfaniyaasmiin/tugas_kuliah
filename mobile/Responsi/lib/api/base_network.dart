import 'dart:convert';
import 'package:http/http.dart' as http;

class BaseNetwork {
  static final String baseNetwork = "https://www.themealdb.com/api/json/v1/1/";
  static Future<Map<String, dynamic>> get(String endpoint) async{
    final String fullUrl = baseNetwork + endpoint;
    final response = await http.get(Uri.parse(fullUrl));

    return _processResponse(response);
  }

  static Future<Map<String, dynamic>> _processResponse(
    http.Response response) async{
    if (response.body.isNotEmpty){
      return json.decode(response.body);
    } else {
      print("error gatau kenapa");
      return {"error": true};
    }
  }

}