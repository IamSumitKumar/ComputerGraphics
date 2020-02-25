#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<conio.h>

    void plot8(int x, int y, int cx, int cy)
    {
        putpixel(x+cx,y+cy,RED);
        putpixel(y+cx,x+cy,RED);
        putpixel(y+cx,-x+cy,RED);
        putpixel(x+cx,-y+cy,RED);
        putpixel(-x+cx,-y+cy,RED);
        putpixel(-y+cx,-x+cy,RED);
        putpixel(-y+cx,x+cy,RED);
        putpixel(-x+cx,y+cy,RED);
    }
    
    void main()
    {
        /* request auto detection */
        int gdriver = DETECT, gmode, errorcode;
        int x,y,r,cx,cy,E,SE,D;
    
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
    
        cout<<"\nEnter centre(x): ";
        cin>>cx;
        cout<<"\nEnter centre(y): ";
        cin>>cy;
        cout<<"\nEnter radius: ";
        cin>>r;
    
        x=0;
        y=r;
    
        plot8(x,y,cx,cy);
    
        D=1-r;
    
        while(y>x)
        {
            if(D<=0)
            {
                E=(2*x)+3;
                D+=E;
                x++;
            }
            else
            {
                SE=(2*x)-(2*y)+5;
                D+=SE;
                x++;
                y--;
            }
            plot8(x,y,cx,cy);
        }
    
        /* clean up */
        getch();
        closegraph();
    }
