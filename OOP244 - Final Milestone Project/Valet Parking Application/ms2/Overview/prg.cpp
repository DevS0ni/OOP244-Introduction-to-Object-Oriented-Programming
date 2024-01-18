class Foo {
public:
   // prevent copying and assignment
   Foo(const Foo&) = delete;
   void operator=(const Foo&) = delete;

};

/*

bool done = false;
while(!done){
   titles printed
   Menu is displayed
   switch(user's selection){
      case 1: 
          // whatever
          break;
      case 2:

      case 6:
         exitProgram;
         done = true;
    }
}



















*/