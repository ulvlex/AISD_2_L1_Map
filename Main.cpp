#include <iostream>
#include "Map.h"

using namespace std;

int main() {

	cout << "My map:" << endl;
	Map<int, int> map;
	map.insert(1, 10);
	map.insert(2, 20);
	map.insert(3, 30);
	map.insert(4, 40);
	map.insert(5, 50);
	map.insert(6, 60);
	map.print();

	map.remove(3);
	cout << '\n' << "My map:" << endl;
	map.print();

	cout << "\nThe value of the element with the key 2: " << endl;
	cout << map.find(2)->value << endl;

	cout << "\nThe list of Maps's keys:" << endl;
	List<int> keysList = map.get_keys();
	cout << keysList<< endl;

	cout << "The list of Map's values:" << endl;
	List<int> valuesList = map.get_values();
	cout << valuesList <<endl;

	return 0;
}
