#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define max 5

struct Movie {
    string title;
    int code;
    float rating;
} source[max] = {
    {"Inception", 1, 8.9},
    {"Interstellar", 2, 8.5},
    {"The Dark Knight", 3, 10.0},
    {"Tenet", 4, 7.9},
    {"Dunkirk", 5, 8.1}
};

Movie* ptr = source;
Movie temp[max];

void copySource() {
    for (int i = 0; i < max; i++) {
        temp[i] = source[i];
    }
}

void display(int index) {
    cout << "\nMOVIE CODE - " << ptr[index].code << endl;
    cout << "Title   : " << ptr[index].title << endl;
    cout << "Rating  : " << ptr[index].rating << endl;
}

void displayTemp(int index) {
    // cout << "\nINDEX - " << index << endl;
    cout << "\nMOVIE CODE - " << temp[index].code << endl;
    cout << "Title   : " << temp[index].title << endl;
    cout << "Rating  : " << temp[index].rating << endl;
}

int linearSearch(int code) {
    for (int i = 0; i < max; i++) {
        int key = source[i].code;
        if (key == code) return i;
    }
    return -1;
}

string normalizeString(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int binarySearch(string x) {
    int left = 0, right = max - 1;
    x = normalizeString(x); 

    while (left <= right) {
        int mid = (left + right) / 2;
        string midTitle = normalizeString(temp[mid].title);
        
        if (midTitle == x)
            return mid;
        else if (midTitle < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int partition(int low, int high) {
    float pivot = temp[high].rating;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (temp[j].rating < pivot) {
            i++;
            swap(temp[i], temp[j]);
        }
    }
    swap(temp[i + 1], temp[high]);
    return i + 1;
}

void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void bubbleSort() {
    for (int i = 0; i < max - 1; i++) {
        for (int j = 0; j < max - i - 1; j++) {
            if (temp[j].rating < temp[j + 1].rating) {
                swap(temp[j], temp[j + 1]);
            }
        }
    }
}

void searchByTitle() {
    string titleToSearch;
    cout << "Search by Title\n" << endl;
    cout << "Enter movie title: ";
    cin >> ws;
    getline(cin, titleToSearch);

    copySource();

    // sort by title
    sort(temp, temp + max, [](Movie a, Movie b) {
        return normalizeString(a.title) < normalizeString(b.title);
    });

    int foundIndex = binarySearch(titleToSearch);

    if (foundIndex != -1) {
        displayTemp(foundIndex);
    } else {
        cout << "\nMovie not found!\n";
    }
}

void searchByCode() {
    int codeToSearch;
    cout << "Search by Code\n" << endl;
    cout << "Enter movie code: ";
    cin >> codeToSearch;

    int result = linearSearch(codeToSearch);
    if (result != -1) {
        display(result);
    } else {
        cout << "\nMovie not found!\n";
    }
}

void displaySorted() {
    for (int i = 0; i < max; i++) {
        cout << i + 1 << ". Title: " << temp[i].title
             << ", Code: " << temp[i].code
             << ", Rating: " << temp[i].rating << endl;
    }
}

void displayAll() {
    cout << "Movie List:\n" << endl;
    for (int i = 0; i < max; i++) {
        cout << i + 1 << ". Title: " << ptr[i].title;
        cout << ", Code: " << ptr[i].code;
        cout << ", Rating: " << ptr[i].rating << endl;
    }
}

int main() {
    int menu;
    do {
        system("cls");
        cout << "======== My Cinema ========\n" << endl;
        cout << "1. Movie List\n";
        cout << "2. Search by Code\n";
        cout << "3. Search by Title\n";
        cout << "4. Sort by Rating (ASC)\n";
        cout << "5. Sort by Rating (DESC)\n";
        cout << "0. Exit\n";
        cout << "\nChoose menu: ";
        cin >> menu;
        cin.ignore();

        system("cls");

        switch (menu) {
            case 1:
                displayAll();
                cin.get();
                break;
            case 2:
                searchByCode();
                cin.ignore();
                cin.get();
                break;
            case 3:
                searchByTitle();
                // cin.ignore();
                cin.get();
                break;
            case 4:
                copySource();
                quickSort(0, max - 1);
                cout << "Movies sorted by rating (ASC)\n" << endl;
                displaySorted();
                cin.get();
                break;
            case 5:
                copySource();
                bubbleSort();
                cout << "Movies sorted by rating (DESC)\n" << endl;
                displaySorted();
                cin.get();
                break;
            case 0:
                break;
            default:
                cout << "Invalid menu.\n";
                cin.get();
                break;
        }
    } while (menu != 0);
    cout << "Exiting program...\n";
    system("pause");
    system("cls");

}
