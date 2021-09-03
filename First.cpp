#include <bits/stdc++.h>
using namespace std;

class places{

        public:     string placename;
                    double lat,lon;

};


void calcCoord(double lat1, double lon1, double lat2, double lon2, double *mdpt1, double *mdpt2){
        *mdpt1=lat1+lat2/2;
        *mdpt2=lon1+lon2/2;
}

void calcSquarePoints(double mid1, double mid2, double *x1, double *y1, double *x2, double *y2, double *x3, double *y3, double *x4, double *y4){

        *x1=(mid1-2);
        *y1=(mid2+2);

        *x2=(mid1+2);
        *y2=(mid2+2);

        *x3=(mid1+2);
        *y3=(mid2-2);

        *x4=(mid1-2);
        *y4=(mid2-2);
}

double area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) +  x3 * (y1 - y2)) / 2.0);
}


int main(){

    places p[50];

//GIVE ALL PLACES HERE-->

                        p[0].placename="bruh";
                        p[0].lat=7;
                        p[0].lon=5;


                        p[1].placename="Far place";
                        p[1].lat=3;
                        p[1].lon=2;
/*
                        p[2].placename="";
                        p[2].lat= ;
                        p[2].lon= ;

                        p[3].placename="";
                        p[3].lat= ;
                        p[3].lon= ;

                        p[4].placename="";
                        p[4].lat= ;
                        p[4].lon= ;

                        p[5].placename="";
                        p[5].lat= ;
                        p[5].lon= ;

                        p[6].placename="";
                        p[6].lat= ;
                        p[6].lon= ;

                        p[7].placename="";
                        p[7].lat= ;
                        p[7].lon= ;

                        p[8].placename="";
                        p[8].lat= ;
                        p[8].lon= ;

                        p[9].placename="";
                        p[9].lat= ;
                        p[9].lon= ;

                        p[10].placename="";
                        p[10].lat= ;
                        p[10].lon= ;

                        p[11].placename="";
                        p[11].lat= ;
                        p[11].lon= ;

                        p[12].placename="";
                        p[12].lat= ;
                        p[12].lon= ;

                        p[13].placename="";
                        p[13].lat= ;
                        p[13].lon= ;

                        p[14].placename="";
                        p[14].lat= ;
                        p[14].lon= ;

                        p[15].placename="";
                        p[15].lat= ;
                        p[15].lon= ;

                        p[16].placename="";
                        p[16].lat= ;
                        p[16].lon= ;

                        p[17].placename="";
                        p[17].lat= ;
                        p[17].lon= ;

                        p[18].placename="";
                        p[18].lat= ;
                        p[18].lon= ;

                        p[19].placename="";
                        p[19].lat= ;
                        p[19].lon= ;

                        p[20].placename="";
                        p[20].lat= ;
                        p[20].lon= ;

                        p[21].placename="";
                        p[21].lat= ;
                        p[21].lon= ;

                        p[22].placename="";
                        p[22].lat= ;
                        p[22].lon= ;

                        p[23].placename="";
                        p[23].lat= ;
                        p[23].lon= ;

                        p[24].placename="";
                        p[24].lat= ;
                        p[24].lon= ;

                        p[25].placename="";
                        p[25].lat= ;
                        p[25].lon= ;

                        p[26].placename="";
                        p[26].lat= ;
                        p[26].lon= ;

                        p[27].placename="";
                        p[27].lat= ;
                        p[27].lon= ;

                        p[27].placename="";
                        p[27].lat= ;
                        p[27].lon= ;

                        p[28].placename="";
                        p[28].lat= ;
                        p[28].lon= ;

                        p[29].placename="";
                        p[29].lat= ;
                        p[29].lon= ;

                        p[30].placename="";
                        p[30].lat= ;
                        p[30].lon= ;

*/
    int i,flag=0;
    double x_1,y_1,x_2,y_2,x_3,y_3,x_4,y_4;
    double midpt1,midpt2;
    double per1cord_1,per1cord_2;                                          //1st person co-ordinates
    double per2cord_1,per2cord_2;                                             //2nd person co-ordinates

    cout<<"=================================================================\n";
    cout<<"Enter Your Co-ordinate 1 and Co-ordinate 2 for First Person-->";
    cin>>per1cord_1>>per1cord_2;
    cout<<"\n---------------------------\n";
    cout<<"Enter Your Co-ordinate 1 and Co-ordinate 2 for Second Person-->";
    cin>>per2cord_1>>per2cord_2;
    cout<<"\nThanks for Entering data!";
    cout<<"\n=================================================================\n";

    calcCoord(per1cord_1,per1cord_2,per2cord_1,per2cord_2,&midpt1,&midpt2);             //saves value of mid point in midpt1 and midpt2

    calcSquarePoints(midpt1,midpt2,&x_1,&y_1,&x_2,&y_2,&x_3,&y_3,&x_4,&y_4);
/*
for(i=0; i<=50; i++){
        if (p[i].lat>x_1 && p[i].lat<x_3 && p[i].lon>y_1 && p[i].lon<y_3){
            cout<<"\nYou can go to-- "<<p[i].placename;
            flag++;
        }
}
*/

for(i=0; i<=50; i++){

    float A = area(x_1, y_1, x_2, y_2, x_3, y_3) +area(x_1, y_1, x_4, y_4, x_3, y_3);

    float A1 = area(p[i].lat, p[i].lon, x_1, y_1, x_2, y_2);

    float A2 = area(p[i].lat, p[i].lon, x_2, y_2, x_3, y_3);

    float A3 = area(p[i].lat, p[i].lon, x_3, y_3, x_4, y_4);

    float A4 = area(p[i].lat, p[i].lon, x_1, y_1, x_4, y_4);

    if(A == (A1+A2+A3+A4)){
        cout<<p[i].placename<<" is near both of you!\n";
        flag++;
        continue;
    }

}


if(flag==0){
    cout<<"\nSorry No Nearby Places!";
}

return 0;
}
