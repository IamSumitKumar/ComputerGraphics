                                  ----//Bezier Curve\\---- File1
#include<stdio.h>
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

    void bezier(int x[4], int y[4])
    {
        double t;
        for(t=0.0;t < 1.0;t+=0.0005)
        {
            double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
            double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
            putpixel(xt,yt,WHITE);
        }

        for(int i=0;i < 4;i++)
        putpixel(x[i],y[i],YELLOW);
        getch();
        closegraph();
        return;
    }

    void main()
    {
        /* request auto detection */
        int gdriver = DETECT, gmode, errorcode;

        /* initialize graphics and local variables */
        initgraph(&gdriver, &gmode, "..\\bgi");

        /* read result of initialization */
        errorcode = graphresult();

        /* an error occurred */
        if (errorcode != grOk)
        {
            printf("Graphics error: %s\n", grapherrormsg(errorcode));
            printf("Press any key to halt:");
            getch();
            exit(1);
        }

        int x[4],y[4];
        int i;
        cout<<"Enter x and y coordinates"<<endl;

        for(i=0;i < 4;i++)
        {
            cin>>x[i];
            cout<<endl;
            cin>>y[i];
        }
        bezier(x,y);
    }
    
                          ----//Hermit Curve\\---- File2
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

    struct point
    {
        int x,y;
    };

    void hermite(point p1,point p4,double r1,double r4)
    {
        float x,y,t;
        for(t=0.0;t<=1.0;t+=0.001)
        {
            x=(2*t*t*t-3*t*t+1)*p1.x+(-2*t*t*t+3*t*t)*p4.x+(t*t*t-2*t*t+t)*r1+(t*t*t-t*t)*r4;
            y=(2*t*t*t-3*t*t+1)*p1.y+(-2*t*t*t+3*t*t)*p4.y+(t*t*t-2*t*t+1)*r1+(t*t*t-t*t)*r4;
            putpixel(x,y,YELLOW);
        }
    }

    void main()
    {
        /* request auto detection */
        int gdriver = DETECT, gmode, errorcode;

        /* initialize graphics and local variables */
        initgraph(&gdriver, &gmode, "..\\bgi");

        /* read result of initialization */
        errorcode = graphresult();

        /* an error occurred */
        if (errorcode != grOk)
        {
            printf("Graphics error: %s\n", grapherrormsg(errorcode));
            printf("Press any key to halt:");
            getch();
            exit(1);
        }

        double r1,r4;
        point p1,p2;
        cout<<"enter 2 hermite points"<<endl;
        cin>>p1.x>>p1.y>>p2.x>>p2.y;
        cout<<"enter tangents at p1 and p4"<<endl;
        cin>>r1>>r4;
        hermite(p1,p2,r1,r4);
        putpixel(p1.x,p1.y,WHITE);
        putpixel(p2.x,p2.y,WHITE);
        getch();
        closegraph();
    }
