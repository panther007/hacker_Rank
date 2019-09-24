#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */

class Rectangle{
    public:
    int w;
    int l;
    Rectangle(){
        w=0;
        l=0;
    }
    void display(){
        std::cout<<w<<" "<<l<<std::endl;
    }
};

class RectangleArea : public Rectangle{
    public:
    RectangleArea(){
        w=0;
        l=0;
    }
    void read_input(){
        std::cin>>w>>l;
    }
    void display(){
        std::cout<<w*l<<std::endl;
    }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}