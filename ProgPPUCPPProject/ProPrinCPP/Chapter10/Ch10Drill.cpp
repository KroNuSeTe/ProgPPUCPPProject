// Copyright by Javier Dueñas
// Learning with Bjarne
#include "../std_lib_facilities.h"
#include <map>

struct Point {
	int x;	// coordinate member x
	int y;	// coordinate member y
};

map<int, string> numbers{
	{ 1, "first" }, { 2, "second" }, 
	{ 3, "third" }, { 4, "fouth" },
	{ 5, "fifth" }, { 6, "sixth" }, 
	{ 7, "seventh" }
};

const string filename = "mydata.txt";

int main()
{
	vector<Point> original_points{7};
	for (int i = 0; i < original_points.size(); i++)
	{
		cout << "Insert " << numbers.at(i+1) << " coordinate(99 99):";
		cin >> original_points[i].x >> original_points[i].y;
	}

	ofstream ost{ filename };
	if (!ost) error("Can´t open output file ", filename);

	int nameNumCounter = 1;
	for (Point point_element : original_points)
	{
		cout << "The " << numbers.at(nameNumCounter) << " coordinate is: " << point_element.x << " " << point_element.y<<"\n";
		nameNumCounter++;
		ost << "(" << point_element.x << "," << point_element.y << ")\n";
	}
	ost.close();

	ifstream ist{ filename };
	if (!ist) error("Can´t open input file ", filename);

	vector<Point> processed_points;
	char char1, char2, char3;
	int xValue, yValue;
	int counter = 0;
	while (ist >> char1 >> xValue >> char2 >> yValue >> char3)
	{
		processed_points.push_back(Point{ xValue, yValue });
		counter++;
	}
	ist.close();

	cout << "\n\nThe Original Points are:\n";
	for (Point opoint : original_points)
	{
		cout << opoint.x << " " << opoint.y << "\n";
	}

	cout << "\nThe Processed Points are:\n";
	for (Point ppoint : processed_points)
	{
		cout << ppoint.x << " " << ppoint.y << "\n";
	}

	if (original_points.size() != processed_points.size())
	{
		cout<<"\n\nSomething's wrong!\nNot the same Number of Vector's Elements";
	}
	else {
		for (int i = 0; i < original_points.size(); i++) {
			if (original_points[i].x != processed_points[i].x || original_points[i].y != processed_points[i].y)
			{
				cout << "\n\nSomething's wrong!\nSome Element does not match";
			}
		}
	}
	
}