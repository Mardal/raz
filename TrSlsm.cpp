#include<iostream>

using namespace std;

void find_shortest_path_6(int distances[6][6]) {
	int currentMinimalPathDistance = 1000000;
	int firstCity = 0;
	int order[6];
	for (int secondCity = 1; secondCity <= 5; secondCity = secondCity + 1) {
		for (int thirdCity = 1; thirdCity <= 5; thirdCity = thirdCity + 1) {
			for (int fourthCity = 1; fourthCity <= 5; fourthCity = fourthCity + 1) {
				for (int fifthCity = 1; fifthCity <= 5; fifthCity = fifthCity + 1) {
					for (int sixthCity = 1; sixthCity <= 5; sixthCity = sixthCity + 1){
						int orderOfCitiesInPath[6] = { firstCity, secondCity, thirdCity, fourthCity, fifthCity, sixthCity };
						bool ñitiesInPathAreAllDifferent = true;
						for (int firstIndex = 0; firstIndex <= 5; firstIndex = firstIndex + 1) {
							for (int secondIndex = 0; secondIndex <= 5; secondIndex = secondIndex + 1) {
								if (firstIndex != secondIndex) {
									int firstCityToCheck = orderOfCitiesInPath[firstIndex];
									int secondCityToCheck = orderOfCitiesInPath[secondIndex];
									if (firstCityToCheck == secondCityToCheck) {
										ñitiesInPathAreAllDifferent = false;
									}
								}
							}
						}
						if (ñitiesInPathAreAllDifferent == false) {
							continue;
						}
						else {
							int currentPathDistance = 0;
							for (int i = 0; i < 5; i++) {
								currentPathDistance += distances[orderOfCitiesInPath[i]][orderOfCitiesInPath[i+1]];
							}
							currentPathDistance += distances[orderOfCitiesInPath[5]][orderOfCitiesInPath[0]];
							if (currentMinimalPathDistance > currentPathDistance) {
								currentMinimalPathDistance = currentPathDistance;
								for (int i = 0; i < 6; i++) {
									order[i] = orderOfCitiesInPath[i];
								}
							}
						}
						
					}
				}
			}
		}
	}
	cout << currentMinimalPathDistance << endl;
	for (int i = 0; i < 6; i++) {
		cout << order[i] << " ";
	}
}
int main() {
	int distances[6][6];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> distances[i][j];
		}
	}
	find_shortest_path_6(distances);
}