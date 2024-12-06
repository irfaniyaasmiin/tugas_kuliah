import 'base_network.dart';

class ApiDatasource {
  static ApiDatasource instance = ApiDatasource();

  Future<Map<String, dynamic>> loadUsers(String categories) {
    return BaseNetwork.get(categories);
  }
}
