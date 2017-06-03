// TODO: add header file guard here 
#ifndef SICT_PASSENGER_H__
#define SICT_PASSENGER_H__
namespace sict {

   const int nsize = 33; // size 32 chars + null
   class Passenger {
   public:
      // TODO: implement the default constructor here
      Passenger();
      // TODO: implement the constructor with 2 parameters here
      Passenger(char* name, char* destination);
      // TODO: implement isEmpty query here
      bool isEmpty() const;
      // TODO: implement display query here
      void display() const;
      
      void setEmpty();


   private:
      char pname[nsize];
      char des[nsize];
      bool check;
   };



}

#endif // !SICT_PASSENGER_H__

// TODO: declare your namespace here

    // TODO: define the Passenger class here

