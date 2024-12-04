#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Movie {
    string title;
    string director;
    int year;
    string genre;
};

vector<Movie> movies;

void createMovie() {
    Movie movie;

    cout << "Enter movie title: ";
    getline(cin, movie.title);
    cout << "Enter movie director: ";
    getline(cin, movie.director);
    cout << "Enter movie year: ";
    cin >> movie.year;
    cin.ignore(); // Consume newline
    cout << "Enter movie genre: ";
    getline(cin, movie.genre);

    movies.push_back(movie);
    cout << "Movie created successfully!" << endl;
}

void readMovies() {
    if (movies.empty()) {
        cout << "No movies found." << endl;
        return;
    }

    cout << "Movies:\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << "Index: " << i << endl; // Display the index
        cout << "Title: " << movies[i].title << endl;
        cout << "Director: " << movies[i].director << endl;
        cout << "Year: " << movies[i].year << endl;
        cout << "Genre: " << movies[i].genre << endl;
        cout << endl;
    }
}

void updateMovie(int index) {
    if (index < 0 || index >= movies.size()) {
        cout << "Invalid movie index." << endl;
        return;
    }

    Movie& movie = movies[index];

    cout << "Enter new movie title: ";
    getline(cin, movie.title);
    cout << "Enter new movie director: ";
    getline(cin, movie.director);
    cout << "Enter new movie year: ";
    cin >> movie.year;
    cin.ignore(); // Consume newline
    cout << "Enter new movie genre: ";
    getline(cin, movie.genre);

    cout << "Movie updated successfully!" << endl;
}

void deleteMovie(int index) {
    if (index < 0 || index >= movies.size()) {
        cout << "Invalid movie index." << endl;
        return;
    }

    movies.erase(movies.begin() + index);
    cout << "Movie deleted successfully!" << endl;
}

int main() {
    int choice;

    do {
        cout << "Movie Management System\n";
        cout << "1. Create Movie\n";
        cout << "2. Read Movies\n";
        cout << "3. Update Movie\n";
        cout << "4. Delete Movie\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Consume newline

        switch (choice) {
            case 1:
                createMovie();
                break;
            case 2:
                readMovies();
                break;
            case 3: {
                int index;
                cout << "Enter movie index to update: ";
                cin >> index;
                cin.ignore(); // Consume newline
                updateMovie(index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter movie index to delete: ";
                cin >> index;
                cin.ignore(); // Consume newline
                deleteMovie(index);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}