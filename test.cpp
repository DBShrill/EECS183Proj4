/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * Contains functions for testing classes in the project. 
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();
void file_check();

void startTests() {
    //test_Point();
    //file_check();
	//test_Color();
	//test_Line();
	test_Triangle();

    return;
}

void file_check() {

	// open one of the text files that are part of the starter code
	ifstream ins;
	ins.open("data1.txt");

	// if the file was not in the correct directory, the stream state is fail
	if (ins.fail()) {
		cout << "Could not open data1.txt" << endl;
	}
	else {
		cout << "Success! Text files are in the right directory." << endl;
	}
	ins.close();

}

void test_Point() {
	// test of default constructor
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;
    
    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);

    // test of member functions getX() and getY()
    cout << "Expected: (5,3), actual: ";
    cout << "(" << p1.getX()
         << "," << p1.getY()
         << ")" << endl;

    //test read
	ifstream input_file;
	input_file.open("data1.txt");
	p1.read(input_file);
    cout << "Expecting (69,69), Actual: " << p1 << endl;
	input_file.close();

    //test write
    ofstream output_file;
    output_file.open("data2.txt");
    p1.write(output_file);
	output_file.close();
}

void test_Color() {
	cout << "Testing Color" << endl;

	cout << "Testing constructor\n";
	Color color1(69, 69, 69);
	cout << "Expecting (69, 69, 69), Actual: " << color1;

	cout << "Testing colors\n";
	color1.setRed(1);
	color1.setGreen(2);
	color1.setBlue(3);
	cout << "Expecting (1,2,3), Actual: "
		 << color1.getRed() << "  " << color1.getGreen() << "  " << color1.getBlue() << endl;

	//testing read
	ifstream inputFile;
	inputFile.open("data1.txt");
	color1.read(inputFile);
	cout << "Expecting (255,255,255), Actual: " << color1 << endl;
}

void test_Line() {
	cout << "Testing Line" << endl;
	Point pt1(1,0);
	Point pt2(0,1);
	Color c1(255,255,255);
	Line l1(pt1, pt2, c1);
	cout << "Expecting ( 1,0  0,1  white), Actual: " << l1;

	ifstream inputFile;
	ofstream outputFile;
	inputFile.open("data1.txt");
	outputFile.open("data2.txt");
	l1.read(inputFile);
	l1.write(outputFile);

}

void test_Triangle() {
	Point pt1(5,12);
	Point pt2(20,25);
	Point pt3(12,60);
	Color c1(20,40,30);
	Color c2(40,20,90);
	Color c3(100,230,134);
	Triangle t(pt1,c1,pt2,c2,pt3,c3);


	ofstream outputFile;
	outputFile.open("data2.txt");
	t.write(outputFile);
}

