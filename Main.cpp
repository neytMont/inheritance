#include <iostream>
#include <string>
#include <vector>
using namespace std;
int getInt();

//parent class luggage
class luggage
{
    protected:
            string type;
    public:
        luggage()
        {
            type = "luggage";
        }
        void display()
        {
            cout << "\nLuggage Type: " << type;
        }

        virtual double volume() = 0;//pure virtual function
        string getType()
        {
            return type;
        }
    
};

//child class box 
//has protected data members of w, h, l
class box : public luggage
{
    protected:
		double width, height, length;
	public:
        box(double w, double h, double l)
        {
            type = "box";
            width = w;
            height = h;
            length = l;
        }
		double getWidth()
        {
            return width;
        }
		double getHeight()
        {
            return height;
        }
        double getLength()
        {
            return length;
        }
        string getType()
        {
            return type;
        }
        void display()
        {
            luggage::display();
            cout << "	volume: " << volume() << endl;
        }
		double volume()//formula for volume of box = h*w*l
		{
			return (height * width * length);
		}
};

//child class sphere
//has protected data members of r
class sphere : public luggage
{
    protected:
		double radius;
    public:
        sphere(double r)
        {
            type = "sphere";
            radius = r;
        }
		double getRadius()
        {
            return radius;
        }
        void display()
        {
            luggage::display();
            cout << "	volume: " << volume() << endl;
        }
        string getType()
        {
            return type;
        }
		double volume()//formula for volume of sphere = (3/4)pi*r^3 let pi = 3.14
        {
            return ((0.75) * 3.14 * radius * radius);
        }
};

//child class cube
//has protected data members of w
class cube : public luggage
{
    protected:
		double width;
    public:
        cube(double w)
        {
            type = "cube";
            width = w;
        }
		double getWidth()
        {
            return width;
        }
        void display()
        {
            luggage::display();
            cout << "	volume: " << volume() << endl;
        }
        string getType()
        {
            return type;
        }
		double volume()//formula for volume of cube = w^3
        {
            return (width * width * width);
        }
};

//child class box 
//has protected data members of b, h
class pyramid : public luggage
{
    protected:
		double base, height;
    public:
        pyramid(double b, double h)
        {
            type = "pyramid";
            base = b;
            height = h;
        }
		double getBase()
        {
            return base;
        }
		double getHeight()
        {
            return height;
        }
        string getType()
        {
            return type;
        }
        void display()
        {
            luggage::display();
            cout << "	volume: " << volume() << endl;
        }
		double volume()//formula for volume of pyramid = (1/3)*b*h
        {
            return ((base*height)/3);
        }            
};

//child class cylinder
//has protected data members of r, l
class cylinder : public luggage
{
    protected:
		double radius, length;
    public:
        cylinder(double r, double l)
        {
            type = "cylinder";
            radius = r;
            length = l;
        }
		double getRadius()
        {
            return radius;
        }
		double getLength()
        {
            return length;
        }
        string getType()
        {
            return type;
        }
        void display()
        {
            luggage::display();
            cout << "	volume: " << volume() << endl;
        }
		double volume()//formula for volume of cylinder = pi*l*r^2 let pi = 3.14
        {
            return (3.14 * radius * radius * length);
        }    
};

//child class Triangular Prism
//has protected data members of b, h, l
class TriangularPrism : public luggage
{
    protected:
		double base, height, length;
    public:
        TriangularPrism(double b, double h, double l)
        {
            type = "Triangular Prism";
            base = b;
            height = h;
            length = l;
        }
		double getBase()
        {
            return base;
        }
		double getHeight()
        {
            return height;
        }
		double getLength()
        {
            return length;
        }
        string getType()
        {
            return type;
        }
        void display()
        {
            luggage::display();
            cout << "	volume: " << volume() << endl;
        }
		double volume()//formula for volume of triangular prism = (b*h*l)/2
        {
            return ((base * height * length)/2);
        }
};

//child class Triangular Prism
//has protected data members of b, h, l
class ellipsoid : public luggage
{
	protected:
		double length, width, height;
    public:
		ellipsoid(double l, double w, double h)
        {
            type = "ellipsoid";
			length = l;
			width = w;
			height = h;
        }
		double getLength()
        {
            return length;
        }
		double getWidth()
        {
            return width;
        }
		double getHeight()
        {
            return height;
        }
        string getType()
        {
            return type;
        }
        void display()
        {
            luggage::display();
            cout<<" volume: "<<volume()<<endl;
        }
		double volume()//formula for volume of ellipsoid = (3/4)*pi*l*w*h
        {
			return  ((0.75) * 3.14 * length * width * height);
        }  
};

//child class cone 
//has protected data members of r, h
class cone : public luggage
{
    protected:
		double radius, height;
    public:
        cone(double r, double h)
        {
            type = "cone";
            radius = r;
            height = h;
        }
		double getRadius()
        {
            return radius;
        }
		double getheight()
        {
            return height;
        }
        string getType()
        {
            return type;
        }
        void display()
        {
            luggage::display();
            cout<<" volume: "<<volume()<<endl;
        }
		double volume()//formula for volume of cone = pi*(h/3)*r^2
        {
            return (3.14 * radius * radius * (height/3));
        }
};

void showTotal(vector <luggage*> storage)
{
    vector<luggage*>::iterator it;
    int totLug = 0;
    int totVol = 0;
    cout<<"\n";
    for(it = storage.begin() ; it != storage.end() ; ++it)
    {
        totLug++;
        totVol = totVol + (*it)->volume();
    }
    cout << "\nTotal Luggages: " << totLug << "		Volume of all Luggages: " << totVol << endl;
}

void showLuggage(vector <luggage*> storage)
{
    vector<luggage*>::iterator it;
    int counter = 0;
    cout<<"\n";
    for(it = storage.begin() ; it != storage.end() ; ++it)
    {
        counter++;
        cout << counter<<". "<<(*it)->getType() << endl;
    }
}

void menu()
{
    cout<<"1. Box\n";
    cout<<"2. Sphere\n";
    cout<<"3. Cube\n";
    cout<<"4. Pyramid\n";
    cout<<"5. Cylinder\n";
    cout<<"6. Triangular Prism\n";
    cout<<"7. Ellipsoid\n";
	cout<<"8. Cone\n";
}

//Main menu
int main()
{
    vector <luggage*> storage;
    bool loop = true;
    int choice;
    while(loop)
    {
        cout<<"\n1) Add luggage to storage container\n";
        cout<<"2) Remove luggage from storage container\n";
        cout<<"3) Show all luggage\n";
        cout<<"4) Quit\n";
		choice = getInt();
        if(choice == 1)//add luggage
        {
            menu();
            int addLuggage;
            cin >> addLuggage;
            if(addLuggage == 1)
            {
                int w, h, l;
                cout<<"Set Width of box: ";
                cin >> w;
                cout<<"Set Height of box: ";
                cin>>h;
                cout<<"Set Length of box: ";
                cin>>l;
                box *b1 = new box(w,h,l);
                luggage *pointer = b1;
                storage.push_back(pointer);
            } 
            else if(addLuggage == 2)
            {
                int r;
                cout<<"Set Radius of sphere: ";
                cin >> r;
                sphere *s1 = new sphere(r);
                luggage *spointer = s1;
                storage.push_back(spointer);
            }
            else if(addLuggage == 3)
            {
                int w;
                cout<<"Set Width of cube: ";
                cin>>w;
                cube *c1 = new cube(w);
                luggage *cpointer = c1;
                storage.push_back(cpointer);
            }
            else if(addLuggage == 4)
            {
                int b, h;
                cout<<"Set Base of pyramid: ";
                cin>>b;
                cout<<"Set Height of pyramid: ";
                cin >> h;
                pyramid *p1 = new pyramid(b,h);
                luggage *pluggage = p1;
                storage.push_back(pluggage);
            }
            else if(addLuggage == 5)
            {
                int r, l;
                cout<<"Set Radius for cylinder: ";
                cin>>r;
                cout<<"Set Length for cylinder: ";
                cin>>l;
                cylinder *cy1 = new cylinder(r,l);
                luggage *cypointer = cy1;
                storage.push_back(cypointer);
            }
            else if(addLuggage == 6)
            {
                int b, h, l;
                cout<<"Set Width of Triangular Prism: ";
                cin >> b;
                cout<<"Set Height of Triangular Prism: ";
                cin>>h;
                cout<<"Set Length of Triangular Prism: ";
                cin>>l;
				TriangularPrism *tp1 = new TriangularPrism(b,h,l);
                luggage *tppointer = tp1;
                storage.push_back(tppointer);
            }
            else if(addLuggage == 7)
            {
                int l,w,h;
				cout<<"Set Length of ellipsoid: ";
                cin >> l;
                cout<<"Set Width of ellipsoid: ";
                cin >> w;
                cout<<"Set Height of ellipsoid: ";
                cin >> h;
				ellipsoid *el1 = new ellipsoid(l,w,h);
                luggage *elpointer = el1;
                storage.push_back(elpointer);
            }
            else if(addLuggage == 8)
            {
                int r, h;
                cout<<"Set Radius of Cone: ";
                cin>>r;
                cout<<"Set Height of Cone: ";
                cin>>h;
                cone *co1 = new cone(r,h);
                luggage *copointer = co1;
                storage.push_back(copointer);
            }
        }
        else if(choice == 2)//remove luggage
        {
            showLuggage(storage);
            int StoreNum;
            cout<<"\nChoose a number to remove the stored luggage: ";
            cin >> StoreNum;
            storage.erase(storage.begin() + (StoreNum-1));
            showLuggage(storage);

        }
        else if(choice == 3)//show luggage
        {
            int size = storage.size();
            for(int i = 0; i < size;i++)
            {
                luggage *temp = storage[i];
                if (temp->getType() == "box")
                {
                    box* b2 = static_cast<box*>(temp);
                    box boxTemp(b2->getWidth(), b2->getHeight(), b2->getLength());
                    boxTemp.display();
                }
                else if (temp->getType() == "sphere")
                {
                    sphere* c2 = static_cast<sphere*>(temp);
                    sphere spheretemp(c2->getRadius());
                    spheretemp.display();
                }
                else if(temp->getType() == "cube")
                {
                    cube* cu2 = static_cast<cube*>(temp);
                    cube cubeTemp(cu2->getWidth());
                    cubeTemp.display();
                }
                else if(temp->getType() == "pyramid")
                {
                    pyramid* py2 = static_cast<pyramid*>(temp);
                    pyramid pyramidTemp(py2->getBase(), py2->getHeight());
                    pyramidTemp.display();
                }
                else if(temp->getType() == "cylinder")
                {
                    cylinder* cy2 = static_cast<cylinder*>(temp);
                    cylinder cylinTemp(cy2->getRadius(), cy2->getLength());
                    cylinTemp.display();
                }
                else if(temp->getType() == "Triangular Prism")
                {
					TriangularPrism* tp2 = static_cast<TriangularPrism*>(temp);
					TriangularPrism tpTemp(tp2->getBase(), tp2->getHeight(), tp2->getLength());
                    tpTemp.display();
                }
                else if(temp->getType() == "ellipsoid")
				{
					ellipsoid* el2 = static_cast<ellipsoid*>(temp);
					ellipsoid eltemp(el2->getLength(), el2->getWidth(),el2->getHeight());
                    eltemp.display();
                }
                else if(temp->getType() == "cone")
                {
                    cone* co2 = static_cast<cone*>(temp);
                    cone coTemp(co2->getRadius(), co2->getheight());
                    coTemp.display();
                }
            }
            showTotal(storage);
        }
        else//quit
        {
            cout << "Thank you" << endl;
            loop = false;
        }
    }
}

int getInt()
{
	int num = 0;
	bool valid = false;
	while (!valid)
	{
		if (cin >> num)
		{
			if (num >= 1 && num <= 4)
			{
			valid = true;
			}
			else
			{
				cout<< "Invalid. Enter a new number from 1 to 4: ";
			}
		}
		else
		{
			cin.clear();
			string invalid;
			cin >> invalid;
			cout << "Invalid. Enter a number from 1 to 4: ";
		}
	}
	return num;
}