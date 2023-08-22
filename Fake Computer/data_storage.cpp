#include <map>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class DataStorage {
	
private:
	map<string, int> int_storage;
	map<string, float> float_storage;
	map<string, string> string_storage;

public:
	void set_int(const string& key, int value) {
		int_storage[key] = value;
	}
	
	void set_float(const string& key, float value) {
		float_storage[key] = value;
	}
	
	void set_string(const string& key, const string& value) {
		string_storage[key] = value;
	}
	
	int get_int(const string& key) {
		return int_storage[key];
	}
	
	float get_float(const string& key) {
		return float_storage[key];
	}
	
	string get_string(const string& key) {
		return string_storage[key];
	}
	
	void save_data_storage(const string& filename) {
		ofstream file(filename.c_str());
		if (file.is_open()) {
			map<string, int>::iterator int_it;
			for (int_it = int_storage.begin(); int_it != int_storage.end(); ++int_it) {
				file << "int " << int_it->first << " " << int_it->second << endl;
			}
			
			map<string, float>::iterator float_it;
			for (float_it = float_storage.begin(); float_it != float_storage.end(); ++float_it) {
				file << "float " << float_it->first << " " << float_it->second << endl;
			}
			
			map<string, string>::iterator string_it;
			for (string_it = string_storage.begin(); string_it != string_storage.end(); ++string_it) {
				file << "string " << string_it->first << " " << string_it->second << endl;
			}
			
			file.close();
		}
	}
	
	int load_data_storage(const string& filename) {
		ifstream file(filename.c_str());
		if (file.is_open()) {
			string type, key;
			while (file >> type >> key) {
				if (type == "int") {
					int value;
					file >> value;
					int_storage[key] = value;
				} else if (type == "float") {
					float value;
					file >> value;
					float_storage[key] = value;
				} else if (type == "string") {
					string value;
					file.ignore();
					getline(file, value);
					string_storage[key] = value;
				}
			}
			file.close();
			return 1;
		}
		else {
			return 0;
		}
	}
};
