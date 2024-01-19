  class Metal{
int weight;
public:
  Metal(int w){
    weight = w;
  }
};


Q. Given the above base class Metal, derive from it a class called Iron. 
Iron should add a new data member called colour that is a dynamically allocated cstring. 
For the Iron class define a two argument constructor that takes in two arguments a constant cstring 
for the colour and an integer for the weight and use these parameters to initialize the object.



/*

class Iron : public Metal{

 char* colour;

public:

Iron(const char* c, int w) : Metal(w){
if(c!=nullptr && c[0]!='\0'){
colour = new char[strlen(c)+1];
strcpy(colour,c);
}
}

};






*/