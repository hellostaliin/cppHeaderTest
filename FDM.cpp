#include <iostream>
#include <vector>
using namespace std;

class Domain{
    public:
    int step;
    float xmin,xmax,ymin,ymax,stepSizeX,stepSizeY;
    vector<float> x,y;
    //Constructor
    Domain(int step,float xmin,float xmax,float ymin,float ymax):step(step),xmin(xmin),xmax(xmax),ymin(ymin),ymax(ymax),
    stepSizeX((xmax-xmin)/step),stepSizeY((ymax-ymin)/step) {
        x.resize(step);
        y.resize(step);
        for (int i=0;i<=step;i++){
            x[i] = i*stepSizeX;
            y[i] = i*stepSizeY;
        };
    }
};

int main(){
    Domain d(10,0,1,0,1);
    cout<<d.x[9]<<endl;



    return 0;
}