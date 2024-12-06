// class Meal {
//   final String id;
//   final String name;
//   final String category;
//   final String image;
//   final String instructions;

//   Meal({
//     required this.id,
//     required this.name,
//     required this.category,
//     required this.image,
//     required this.instructions,
//   });

//   // Method untuk mengonversi data JSON menjadi objek Meal
//   factory Meal.fromJson(Map<String, dynamic> json) {
//     return Meal(
//       id: json['idMeal'],  // Pastikan kunci sesuai dengan data API
//       name: json['strMeal'],
//       category: json['strCategory'],
//       image: json['strMealThumb'],
//       instructions: json['strInstructions'],
//     );
//   }
// }


class ClassName {
  final List<Categories>? categories;

  ClassName({
    this.categories,
  });

  ClassName.fromJson(Map<String, dynamic> json)
    : categories = (json['categories'] as List?)?.map((dynamic e) => Categories.fromJson(e as Map<String,dynamic>)).toList();

  Map<String, dynamic> toJson() => {
    'categories' : categories?.map((e) => e.toJson()).toList()
  };
}

class Categories {
  final String? idCategory;
  final String? strCategory;
  final String? strCategoryThumb;
  final String? strCategoryDescription;

  Categories({
    this.idCategory,
    this.strCategory,
    this.strCategoryThumb,
    this.strCategoryDescription,
  });

  Categories.fromJson(Map<String, dynamic> json)
    : idCategory = json['idCategory'] as String?,
      strCategory = json['strCategory'] as String?,
      strCategoryThumb = json['strCategoryThumb'] as String?,
      strCategoryDescription = json['strCategoryDescription'] as String?;

  Map<String, dynamic> toJson() => {
    'idCategory' : idCategory,
    'strCategory' : strCategory,
    'strCategoryThumb' : strCategoryThumb,
    'strCategoryDescription' : strCategoryDescription
  };
}





// class ClassName1 {
//   final List<Meals>? meals;

//   ClassName1({
//     this.meals,
//   });

//   ClassName1.fromJson(Map<String, dynamic> json)
//     : meals = (json['meals'] as List?)?.map((dynamic e) => Meals.fromJson(e as Map<String,dynamic>)).toList();

//   Map<String, dynamic> toJson() => {
//     'meals' : meals?.map((e) => e.toJson()).toList()
//   };
// }

// class Meals {
//   final String? strMeal;
//   final String? strMealThumb;
//   final String? idMeal;

//   Meals({
//     this.strMeal,
//     this.strMealThumb,
//     this.idMeal,
//   });

//   Meals.fromJson(Map<String, dynamic> json)
//     : strMeal = json['strMeal'] as String?,
//       strMealThumb = json['strMealThumb'] as String?,
//       idMeal = json['idMeal'] as String?;

//   Map<String, dynamic> toJson() => {
//     'strMeal' : strMeal,
//     'strMealThumb' : strMealThumb,
//     'idMeal' : idMeal
//   };
// }

