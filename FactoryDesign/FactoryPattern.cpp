/*
A square,rectangle and triangle are all polygons. Each polygon will have a way to draw it. So the relationships are described below
Square "IS A" polygon.
Rectangle "IS A" polygon.
Triangle "IS A" polygon. 

DrawTriangle is a way to draw a triangle So it implements InterfaceDrawPolygon. 
Same goes for all the other polygons too.
*/

class InterfaceDrawPolygon
{
	public:
		virtual void draw() = 0;
};


class AbstractPolygon
{
	public:
		InterfaceDrawPolygon* drawBehaviour;
		void draw()
		{
			drawBehaviour->draw();
		}
};

class DrawTriangle : public InterfaceDrawPolygon
{
	public:
		void draw() override
		{
			cout<<"Drawing Triangle"<<endl;
		}
};

class DrawSquare : public InterfaceDrawPolygon
{
public:
	void draw() override
	{
		cout<<"Drawing square"<<endl;
	}
};

class DrawRectangle: public InterfaceDrawPolygon
{
public:
	void draw() override
	{
		cout<<"Drawing rectangle"<<endl;
	}
};


class Square : public AbstractPolygon
{
public:
	Square()
	{
		drawBehaviour = new DrawSquare();
	}
};

class Rectangle : public AbstractPolygon
{
public:
	Rectangle()
	{
		drawBehaviour = new DrawRectangle();
	}
};

class Triangle : public AbstractPolygon
{
public:
	Triangle()
	{
		drawBehaviour = new DrawTriangle();
	}
};

class PolygonFactory // this violates OPEN-CLOSED PRINCIPLE
{
public:
	static AbstractPolygon* create_polygon(string s)
	{
		if(s == "square")
			return new Square();
		else if(s=="rectangle")
			return new Rectangle();
		else if(s=="triangle")
			return new Triangle();
	}
};

int main()
{
	Square* s1 = new Square();
	Rectangle* r1 = new Rectangle();
	Triangle* t1 = new Triangle();
	s1->draw();
	r1->draw();
	t1->draw();
	
	// using PolygonFactory class
	cout<<"Using PolygonFactory class"<<endl;
	AbstractPolygon* s2 = PolygonFactory::create_polygon("square"); // Take a note of syntax of how static methods are called !!
	AbstractPolygon* r2 = PolygonFactory::create_polygon("rectangle");
	AbstractPolygon* t2 = PolygonFactory::create_polygon("triangle");
	
	s2->draw();
	r2->draw();
	t2->draw();
}
