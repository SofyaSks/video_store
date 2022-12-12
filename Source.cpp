#include <iostream>
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <string>

using namespace std;

class Films {
public:

	Films(){
	}

	Films(string n, string d, string g, double r, int p) {
		name = n;
		director = d;
		genre = g;
		rating = r;
		price = p;
	}


	void Print() {
		cout << "Name: " << name << endl <<
			"Director: " << director << endl <<
			"Genre: " << genre << endl <<
			"Rating: " << rating << endl <<
			"Price: " << price << "\n\n";
	}

	void recordFilmInfo(Films arr[], int length) {
		ofstream fout;
		fout.open("film_all.txt", ofstream::out);
		if (!fout.is_open()) {
			cout << "ERROR! File is not open\n";
		}
		else {
			cout << "File is open" << endl;
			for (int i = 0; i < length; i++)
			{
				fout.write((char*)&arr[i], sizeof(Films));
			}
			cout << "End of file\n" << endl;
			fout.close();
		}
	}

	void showFilmInfo(Films arr[], int length) {
		ifstream fin;

		fin.open("film_all.txt");
		if (!fin.is_open()) {
			cout << "Error. File is not open\n";
		}
		else {
			int i = 0;
			cout << "File is open\n" << endl;
			while (fin.read((char*)&arr[i], sizeof(Films))) {
				arr[i].Print();
				i++;
			}
			fin.close();
			cout << "End of read\n\n";
		}
	}

	void serchByName(Films arr[], int length) {
		ifstream fin;

		fin.open("film_all.txt");
		if (!fin.is_open()) {
			cout << "Error. File is not open\n";	
		}
		else {
			cout << "File is open\n" << endl;
			cout << "Enter movie name: ";
			string movie;
			cin >> movie;
			int i = 0;
			while (fin.read((char*)&arr[i], sizeof(Films))) {
				if (arr[i].name == movie) {
					arr[i].Print();
				}
				else
					i++;
			}
			fin.close();

		}
	}

	void searchByGenre(Films arr[], int length) {
		ifstream fin;

		fin.open("film_all.txt");
		if (!fin.is_open()) {
			cout << "Error. File is not open\n";
		}
		else {
			cout << "File is open\n" << endl;
			cout << "Enter movie genre: ";
			string movie;
			cin >> movie;
			int i = 0;
			while (fin.read((char*)&arr[i], sizeof(Films))) {
				if (arr[i].genre == movie) {
					arr[i].Print();
				}
				else
					i++;
			}
			fin.close();
		}
	}

	void searchByDirector(Films arr[], int length) {
		ifstream fin;

		fin.open("film_all.txt");
		if (!fin.is_open()) {
			cout << "Error. File is not open\n";
		}
		else {
			cout << "File is open\n" << endl;
			cout << "Enter movie director: ";
			string movie;
			cin >> movie;
			int i = 0;
			while (fin.read((char*)&arr[i], sizeof(Films))) {
				if (arr[i].director == movie) {
					arr[i].Print();
				}
				else
					i++;
			}
			fin.close();
		}
	}

	void showPopular(Films arr[], int length) {
		ifstream fin;

		fin.open("film_all.txt");
		if (!fin.is_open()) {
			cout << "Error. File is not open\n";
		}
		else {
			cout << "File is open\n" << endl;
			cout << "The most popular film: ";
			int i = 0;
			while (fin.read((char*)&arr[i], sizeof(Films))) {
				int best = arr[0].rating;
				if (arr[i].rating < arr[i+1].rating) {
					best = arr[i + 1].rating;
					i++;
				}
				int j = 0;
				while (fin.read((char*)&arr[j], sizeof(Films))) {
					if (arr[j].rating == best)
						arr[j].Print();
					else
						j++;
				}
				
			}
			fin.close();
		}
	}

	void addFilm() {
		ofstream fout;
		fout.open("film_all.txt", ofstream::out);
		if (!fout.is_open()) {
			cout << "ERROR! File is not open\n";
		}
		else {
			cout << "File is open" << endl;
			cout << "Enter name:";
			cin >> name;
			fout.write((char*)&name, 1);
			cout << "Enter director:";
			cin >> director;
			fout.write((char*)&director, 1);
			cout << "Enter genre:";
			cin >> genre;
			fout.write((char*)&genre, 1);
			cout << "Enter rating:";
			cin >> rating;
			fout.write((char*)&rating, 1);
			cout << "Enter price:";
			cin >> price;
			fout.write((char*)&price, 1);
			
			cout << "End of file\n" << endl;
			fout.close();
		}
	}

	void deleteFilm(Films arr[], int length) {

	}


private:
	string name;
	string director;
	string genre;
	double rating;
	int price;
};

int main() {

	Films f1;

	Films arr[5] = {
		Films("Titanic", "Alan_Walker", "Drama", 8.4, 10),
		Films("Hatiko", "Jenna_Ortega", "Drama", 10, 15),
		Films("Avatar", "Wensday_Adams", "Fantasy", 6.9, 22),
		Films("Spiderman", "Some_Guy", "Thriller", 9.7, 44),
		Films("Batman", "Marian_Cross", "Horror", 8.8, 7)
	};

	f1.recordFilmInfo(arr, 5);

	f1.showFilmInfo(arr, 5);

	f1.serchByName(arr, 5);

	f1.searchByGenre(arr, 5);

	f1.searchByDirector(arr, 5);

	f1.showPopular(arr, 5);

	//f1.addFilm();

	return 0;
}