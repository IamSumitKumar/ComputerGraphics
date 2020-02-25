//from the Contributor : Deepanshu [KMV DU]
#include <conio.h>
#include <iostream>
#include <graphics.h>
using namespace std;

    //Shifted Origin at (400,400)
    int c = 400;

    //Declaration of class point
    class point
    {
        public:
        float x,y;
    };

    class matrix
    {
        private:
        point p[20];
        point t[2];
        point pp[1];
        int points;

        public:
        void read()
        {
            setcolor(2);
            cout<<"Enter no. of points : ";
            cin>>points;
            cout<<"\nCAUTION : Enter value between 0 and 400 for x and y values!!!\n";
            cout<<"\nEnter coordinates :-\n";
            for(int i=0;i<points;i++)
            {
                cout<<"Enter P"<<i+1<<" : ";
                cin>>p[i].x>>p[i].y;
            }
        }

        void readT()
        {
            cout<<"\nEnter Transformation matrix (2X2) :- \n";
            for(int i=0;i<2;i++)
            cin>>t[i].x>>t[i].y;
        }

        void transform()
        {
            setcolor(3);
            for(int i=0;i<points;i++)
            {
                pp[0].x = p[i].x*t[0].x + p[i].y*t[1].x;
                pp[0].y = p[i].x*t[0].y + p[i].y*t[1].y;

                p[i].x = (int)(pp[0].x);
                p[i].y = (int)(pp[0].y);
            }
        }

        void draw()
        {
            for(int i=0;i<points;i++)
                line(c+p[i].x, c-p[i].y, c+p[(i+1)%points].x, c-p[(i+1)%points].y);
            //c is added to represent points in shifted origin system
        }

        void show()
        {
            cout<<endl;
            for(int i=0;i<points;i++)
            cout<<p[i].x<<" "<<p[i].y<<endl;
        }
    };

    void printaxis()
    {
        setcolor(YELLOW);
        line(c,0,c,c*2);
        line(0,c,c*2,c);
        
        for(int i=50;i<c*2;i+=50) line(c-10,i,c+10,i);
            for(int i=50;i<c*2;i+=50) line(i,c-10,i,c+10);
                setcolor(WHITE);
    }

    int main()
    {
        initwindow(c*2,c*2);
        printaxis();
        matrix m;
        m.read();
        m.show();
        m.draw();

        m.readT();
        m.transform();
        m.show();
        m.draw();
        getch();
        return 0;
    }
