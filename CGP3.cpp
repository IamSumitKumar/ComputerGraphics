#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream.h>
#include<conio.h>

    typedef unsigned int outcode;
    enum { TOP = 1, BOTTOM = 2, RIGHT = 4, LEFT = 8 };
    
    outcode comp_Outcode ( double x, double y, double xmin, double xmax, double ymin, double ymax)
    {
        outcode code = 0;

        if ( y > ymax )
            code |= TOP;

        else if ( y < ymin )
            code |= BOTTOM;

        if ( x > xmax )
            code |= RIGHT;

        else if ( x < xmin )
            code |= LEFT;

        return code;
    }
    
    void cohen_lineclipping ( double x_init, double y_init, double x1, double y1, double xmin, double xmax, double ymin, double ymax )
    {
        outcode outcode0, outcode1, outcodeout ;
        int accept = 0, done = 0;

        outcode0 = comp_Outcode ( x_init, y_init, xmin, xmax, ymin, ymax);
        outcode1 = comp_Outcode ( x1, y1, xmin, xmax, ymin, ymax);

        do
        {
            if (!(outcode0 | outcode1))
            {
                accept = 1;
                done = 1;
            }

            else if ( outcode0 & outcode1 )
            {
                done = 1;
            }

            else
            {
                double x, y;
                outcodeout = outcode0 ? outcode0 : outcode1 ;

                if ( outcodeout & TOP )
                {
                    x = x_init + ( ymax - y_init ) * ( x1 - x_init ) / ( y1 - y_init ) ;
                    y = ymax ;
                }

                else if ( outcodeout & BOTTOM )
                {
                    x = x_init + ( ymin - y_init ) * ( x1 - x_init ) / ( y1 - y_init ) ;
                    y = ymin ;
                }

                else if ( outcodeout & LEFT )
                {
                    y = y_init + ( xmin - x_init ) * ( y1 - y_init ) / ( x1 - x_init );
                    x = xmin;
                }

                else
                {
                    y = y_init + ( xmax - x_init ) * ( y1 - y_init ) / ( x1 - x_init );
                    x = xmax ;
                }

                if ( outcodeout == outcode0 )
                {
                    x_init = x;
                    y_init = y;
                    outcode0 = comp_Outcode ( x_init, y_init, xmin, xmax, ymin, ymax );
                }

                else
                {
                    x1 = x;
                    y1 = y;
                    outcode1 = comp_Outcode ( x1, y1, xmin, xmax, ymin, ymax );
                }
            }
        }while ( done == 0 );

        if ( accept )
        line ( x_init, y_init, x1, y1 );
    }
    
    int main(void)
    {
        int gdriver = DETECT, gmode, errorcode;
        double x_init, x1, y_init, y1, xmin, ymin, xmax, ymax;

        initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

        errorcode = graphresult();

        if (errorcode != grOk)
        {
            printf("Graphics error: %s\n", grapherrormsg(errorcode));
            printf("Press any key to halt:");
            getch();
            exit(1);
        }

        cout<<"\n Enter the start and end pt. of the line : ";
        cout<<"\n Enter first coordinate : ";
        cin>> x_init >> y_init ;

        cout<<"\n Enter second coordinate : ";
        cin>> x1 >> y1 ;

        cout<<"\n\n Enter the coodinates of the clipping rectangle : ";
        cout<<"\n Enter (xmin, ymin) : " ;
        cin>> xmin >> ymin;

        cout<<"\n Enter (xmax, ymax) : " ;
        cin>> xmax >> ymax;

        line ( xmin, ymin, xmax, ymin );
        line ( xmin, ymin, xmin, ymax );
        line ( xmin, ymax, xmax, ymax );
        line ( xmax, ymin, xmax, ymax );

        cohen_lineclipping ( x_init, y_init, x1, y1, xmin, xmax, ymin, ymax);

        setcolor ( 10 );
        line ( x_init+50, y_init, x1+50, y1);

        getch();
        closegraph();
        return 0;
    }
