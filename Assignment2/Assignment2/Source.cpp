#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class Box
{
public:
	Box();
	~Box();
	int Ha[10];
	string D[10];
	void setData(int, int, int, int, int, int, int, int, double);
	friend istream& operator >> (istream& input, Box& obj1);
	friend ostream& operator << (ostream& output, Box obj1[]);
	double getHeight();
	int getLength();
	int getWidth();
	int getMaxX();
	int getMaxY();
	int getMaxZ();
	int getMinX();
	int getMinY();
	int getMinZ();
	int getArea();
	double getVolume();		// must be used
	double divider;
private:
	int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy, z, length, width;
	double volume, height;
};

Box::Box()
{

}

void Box::setData(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, double z1)
{
	Ax = x1;
	Ay = y1;
	Bx = x2;
	By = y2;
	Cx = x3;
	Cy = y3;
	Dx = x4;
	Dy = y4;
	height = z1;
}

int Box::getMaxX()
{
	int localA[] = { Ax,Bx,Cx,Dx };
	for (int i = 0; i < 4; i++)
	{
		if (localA[0] < localA[i])
		{
			localA[0] = localA[i];
		}
	}
	return localA[0];
}

int Box::getMaxY()
{
	int localA[] = { Ax,Bx,Cx,Dx };
	for (int i = 0; i < 4; i++)
	{
		if (localA[0] < localA[i])
		{
			localA[0] = localA[i];
		}
	}
	return localA[0];
}

int Box::getMaxZ()
{
	for (int i = 0; i < 10; i++)
	{
		if (Ha[0] < Ha[i])
		{
			Ha[0] = Ha[i];
		}
	}
	return Ha[0];
}

int Box::getMinX()
{
	int localA[] = { Ax,Bx,Cx,Dx };
	for (int i = 0; i < 4; i++)
	{
		if (localA[0] > localA[i])
		{
			localA[0] = localA[i];
		}
	}
	return localA[0];
}

int Box::getMinY()
{
	int localA[] = { Ax,Bx,Cx,Dx };
	for (int i = 0; i < 4; i++)
	{
		if (localA[0] > localA[i])
		{
			localA[0] = localA[i];
		}
	}
	return localA[0];
}

int Box::getMinZ()
{
	for (int i = 0; i < 10; i++)
	{
		if (Ha[0] > Ha[i])
		{
			Ha[0] = Ha[i];
		}
	}
	return Ha[0];
}

double Box::getHeight()
{
	return height;
}

int Box::getLength()
{
	if (Ay == By)
	{
		length = abs(Ax - Bx);
	}
	if (Ay == Cy)
	{
		length = abs(Ax - Cx);
	}
	if (Ay == Dy)
	{
		length = abs(Ax - Dx);
	}
	return length;
}

int Box::getWidth()
{
	if (Ax == Bx)
	{
		width = abs(Ay - By);
	}
	if (Ax == Cx)
	{
		width = abs(Ay - Cy);
	}
	if (Ax == Dx)
	{
		width = abs(Ay - Dy);
	}
	return width;
}

int Box::getArea()
{
	return 0;
}

double Box::getVolume()
{
	getWidth();
	getLength();
	volume = height * width * length;
	return volume;
}
Box::~Box()
{

}

istream& operator >> (istream& input, Box& obj1)
{
	int x1, y1, x2, y2, x3, y3, x4, y4;
	double z;
	input >> x1;
	input.ignore();
	input >> y1;
	input.ignore();
	input >> x2;
	input.ignore();
	input >> y2;
	input.ignore();
	input >> x3;
	input.ignore();
	input >> y3;
	input.ignore();
	input >> x4;
	input.ignore();
	input >> y4;
	input.ignore();
	input >> z;
	obj1.setData(x1, y1, x2, y2, x3, y3, x4, y4, z);
	return input;
}
ostream& operator << (ostream& output, Box obj1[])
{
	Box Grandmaster;
	int gx, gy, gx2, gy2, gx3, gx4, gy4, gz;
	int Maxx[10];
	int Maxy[10];
	int Minx[10];
	int Miny[10];
	for (int i = 0; i < 10; i++)
	{
		Maxx[i] = obj1[i].getMaxX();
		Maxy[i] = obj1[i].getMaxY();
		Minx[i] = obj1[i].getMinX();
		Miny[i] = obj1[i].getMinY();
	}
	for (int i = 0; i < 10; i++)
	{
		if (Maxx[0] < Maxx[i])
		{
			Maxx[0] = Maxx[i];
		}
		if (Maxy[0] < Maxy[i])
		{
			Maxy[0] = Maxy[i];
		}
		if (Minx[0] > Minx[i])
		{
			Minx[0] = Minx[i];
		}
		if (Miny[0] > Miny[i])
		{
			Miny[0] = Miny[i];
		}
	}
	Grandmaster.setData(Minx[0], Miny[0], Maxx[0], Miny[0], Minx[0], Maxy[0], Maxy[0], Maxy[0], obj1->getMaxZ());
	output << "Minimum Container Specifications: " << endl;
	output << "Length: " << Grandmaster.getLength() << ".0    ";
	output << "Width: " << Grandmaster.getWidth() << ".0     ";
	output << "Height: " << Grandmaster.getHeight() << ".0    ";
	output << "Volume: " << Grandmaster.getVolume() << endl;
	obj1->divider = Grandmaster.getVolume();
	return output;
}
void Caller(Box p[]);
void displayResults(double& t, Box p[]);
void efficiency(double, double);
int main()
{
	double t = 0.0;
	//declare an array to hold objects of type Box
	Box* new1 = new Box[10];
	//call a global function to load the user input into each object -- use overloaded stream extraction operator
	Caller(new1);
	//call a global function to print results for part #1 and #2
	displayResults(t, new1);
	//call a global function to print results for part #3 -- use overloaded stream insertion operator
	cout << new1;
	//print the results for part #4
	efficiency(new1->divider, t);
}

void Caller(Box p[])
{
	string placeHolder;
	for (int i = 0; i < 10; i++)
	{
		cout << "Box " << i + 1 << ":";
		getline(cin, placeHolder);
		p->D[i] = placeHolder;
		cin >> p[i];
		cin.ignore();
		p->Ha[i] = p[i].getHeight();
	}
}

void displayResults(double& t, Box p[])
{
	double totalV = t;
	cout << "  Box#      " << left << setw(20);
	cout << " Descripiton " << setw(20);
	cout << "Volume(cu/units)" << right << setw(5) << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << "        " << left << setw(25);
		cout << p->D[i] << setw(25);
		cout << p[i].getVolume() << right << setw(5) << endl;
		totalV = totalV + p[i].getVolume();
	}
	t = totalV;
	cout << "The total volume of the cube is: " << totalV << " cu/units" << endl;
}
void efficiency(double capacityV, double userV)
{
	double percentage = userV / capacityV;
	if (percentage > 90.0)
	{
		cout << "The Layout is efficient, it uses " << (percentage * 100) << setprecision(3) << "% of the space";
	}
	else
	{
		cout << "The Layout is inefficient, it wastes " << (1 - percentage) * 100 << setprecision(3) << "% of the space";
	}
}