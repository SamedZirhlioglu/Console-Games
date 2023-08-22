#include "data_storage.cpp"

#include <iostream>
using namespace std;

int main() {
	DataStorage storage;
	
	storage.set_int("age", 25);
	storage.set_float("pi", 3.14159f);
	storage.set_string("name", "John Doe");
	
	storage.save_data_storage("data.txt");
	
	DataStorage loadedStorage;
	int status = loadedStorage.load_data_storage("data.txt");
	
	cout << "status: " << status << endl;
	cout << "Loaded age: " << loadedStorage.get_int("age") << endl;
	cout << "Loaded pi: " << loadedStorage.get_float("pi") << endl;
	cout << "Loaded name: " << loadedStorage.get_string("name") << endl;
	
	return 0;
}
