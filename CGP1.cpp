#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<conio.h>

    void main()
    {
        /* request auto detection */
        int gdriver = DETECT, gmode, errorcode;
        int x1,x2,y1,y2;
        float m,ynew;

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

        cout<<"\nEnter x1: ";
        cin>>x1;
        cout<<"\nEnter x2: ";
        cin>>x2;
        cout<<"\nEnter y1: ";
        cin>>y1;
        cout<<"\nEnter y2: ";
        cin>>y2;

        m=(y2-y1)/(float)(x2-x1);

        if(abs(m) < 1)
        {
            if(x1 < x2)
            {
                putpixel(x1,y1,GREEN);
                ynew=y1;
                for(int i=x1;i < x2;i++)
                {
                    x1++;
                    ynew+=m;
                    putpixel(x1,floor(ynew+0.5),RED);
                }
            }
            else
            {
                putpixel(x2,y2,GREEN);
                ynew=y2;
                for(int i=x2;i < x1;i++)
                {
                    x2++;
                    ynew+=m;
                    putpixel(x2,floor(ynew+0.5),RED);
                }
            }
        }

        /* clean up */
        getch();
        closegraph();
    }
