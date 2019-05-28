//
//  rec04.cpp
//  rec04
//
//  Created by Gordon Lei on 2/22/19.
//  Copyright © 2019 Gordon Lei. All rights reserved.
//
/*
    This file is used to conduct all the tasks listed in rec04
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//check if this works mate. hopefully it does. PLEADMIOWBUDjnwaipdwa. dadwdwadwdwadwadaw.
//dasdadasdsadadad
//mhm?


//task 16
struct Complex {
    double real;
    double img;
};

//task 17
class PlainOldClass {
public:
    PlainOldClass() : x(-72) {}
    int getX() const { return x; }
    void setX( int val )  { x = val; }
private:
    int x;
};

//task 18
class PlainOldClassV2 {
public:
    PlainOldClassV2() : x(-72) {}
    int getX() const { return x; }
    /*
     WRONG :
     void setX( int x )  { x = x; } // HMMMM???
     */
    void setX( int x )  { this->x = x; } // No confusion!
private:
    int x;
};

class Colour {
public:
    Colour(const string& name, unsigned r, unsigned g, unsigned b)
    : name(name), r(r), g(g), b(b) {}
    void display() const {
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
    }
private:
    string name;      // what we call this colour
    unsigned r, g, b; // red/green/blue values for displaying
};

//task 29
class SpeakerSystem {
public:
    void vibrateSpeakerCones(unsigned signal) const {
        
        cout << "Playing: " << signal << "Hz sound..." << endl;
        cout << "Buzz, buzzy, buzzer, bzap!!!\n";
    }
};

class Amplifier {
public:
    void attachSpeakers(const SpeakerSystem& spkrs)
    {
        if(attachedSpeakers)
            cout << "already have speakers attached!\n";
        else
            attachedSpeakers = &spkrs;
    }
    
    void detachSpeakers() { // should there be an "error" message if not attached?
        attachedSpeakers = nullptr;
    }
    
    void playMusic( ) const {
        if (attachedSpeakers)
            attachedSpeakers -> vibrateSpeakerCones(440);
        else
            cout << "No speakers attached\n";
    }
private:
    const SpeakerSystem* attachedSpeakers = nullptr;
    //by doing this you guarentee that the SpeakerSystem will not be modified
};

class Person {
public:
    Person(const string& name) : name(name), roomie(nullptr){}
    void movesInWith(Person& newRoomate) {
        if (roomie){
            cout << getName() << " has a roomate named " << getRoomiesName() <<
            " already" << endl;
        }
        else if (newRoomate.roomie){
            cout << newRoomate.getName() << " has a roomate named " <<
            newRoomate.getRoomiesName() << " already" << endl;
        }
        else{
            roomie = &newRoomate;        // now I have a new roomie
            newRoomate.roomie = this;    // and now they do too
        }
    }
    const string& getName() const { return name; }
    // Don't need to use getName() below, just there for you to use in debugging.
    const string getRoomiesName() const {
        if (!roomie){
            return "nobody";
        }
        return roomie->getName();
    }
private:
    Person* roomie;
    string name;
};

int main() {
    //task 1
    int x;
    x = 10;
    cout << "x = " << x << endl;
    /*
     int x is initilized with a "garbage" value.
     it gets assigned the value of 10 then is printed out
    */
    
    //task 8
    int* p;
    p = &x;
    cout << "p = " << p << endl;
    
    /*
     p starts as a null pointer
     it then changes its address to x's memory address
     then the memory address of p is printed.
     */
    
    //p = 0x0012fed4;
    //this will return an error because you cannot assign an integal value to a pointer
    // (we did not learn how to cast the intergral value to an int pointer)
    
    //task 10
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p contains " << *p << endl;
    
    //task 11
    *p = -2763;
    cout << "p points to where " << *p << " is      stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "x now contains " << x << endl;
    //x is now assigned to the value -2763 which *p will also show
    
    //task 12
    int y(13);
    cout << "y contains " << y << endl;
    p = &y;
    cout << "p now points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    *p = 980;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "y now contains " << y << endl;
    //we change the value of y through the p pointer because p points to y
    
    //task 13
    int* q;
    q = p;
    cout << "q points to where " << *q << " is stored\n";
    cout << "*q contains " << *q << endl;
    // q points to p which points to y. Thus q contains the memory address of y.
    
    //task 14
    double d(33.44);
    double* pD(&d);
    *pD = *p;
    *pD = 73.2343;
    *p  = *pD;
    *q  = *p;
    //pD  = p;
    //p   = pD;
    
    //pointers cannot change their "pointer type"
    
    //task 15
    int joe = 24;
    const int sal = 19;
    int*  pI;
      pI = &joe; //pI has the address of Joe
     *pI = 234; //assign 234 to Joe
      //pI = &sal; //will not compile because you will need to use a const int pointer
     *pI = 7623; //assign 7623 to Joe
    
    const int* pcI;
      pcI = &joe; //assign Joe's memory address to pcI. this works because
                    //const int* pcI means that you cannot change pcI (say you want to change
                    //its memory address it stores)
    //*pcI = 234;  //will not compile because you treat the contents as const so you cannot change it
      pcI = &sal; //assign Sal's memory address to pcI
    //pcI = 7623; //will not compule because you treat sal as const so you cannot change
    
    //int* const cpI; //will not work because there is no defualt initilization of the const type
    int* const cpI(&joe); //will assign the memory address of &joe to cpI because
                            //cpI is an int pointer and joe is an int
    //int* const cpI(&sal); //will not compule. cpI is an int pointer while &sal is const int
    //cpI = &joe; //will not compile because putting const after the type means that
                    // the pointer cannot change its memory address that it holds
     *cpI = 234; //joe is now assigned the number 234.
    //cpI = &sal; //will not compile because cpI is an int pointer while sal is a const int.
        // if we do this, we do not guarentee to the compiler that we won;t modify sal.
     *cpI = 7623; //joe is now assigned the number 7623.
    
    //const int* const cpcI; //there is no default constructor
    //const int* const cpcI(&joe); //will compile.
                                //this means that cpcI will treat joe as a const
    const int* const cpcI(&sal); //will compile for same reason as above.
        //below will not work because you are changing what the memory address holds
      //cpcI = &joe;   *cpcI = 234;
      //cpcI = &sal;
    // *cpcI = 7623;
    
    
    //task 16
    Complex c = {11.23,45.67};
    Complex* pC(&c);
    
    //cout << "real: " << *pC.real << "\nimaginary: " << *pC.img << endl;
        // Indirection requires pointer operand ('double' invalid)
        // the * operator has a lower redecendence than the . operator so it won't work
    cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img << endl;
        //woah typing the dots after the parenthesis pops up the accessible items
    
    cout << "real: " << pC -> real << "\nimaginary: " << pC -> img << endl;
        //the correct way of accessing items that pointers hold addresses to
        // -> only works on pointers to structs and classes
    

    
    PlainOldClass poc; //new POC where its x = -72
    PlainOldClass* ppoc( &poc ); //assign POC address to PPOC
    cout << ppoc->getX() << endl; //print -72
    ppoc->setX( 2837 );
    cout << ppoc->getX() << endl; //print 2837
    

    
    //before the changes:
    PlainOldClassV2 poc2; //new POC where its x = -72
    PlainOldClassV2* ppoc2( &poc2 ); //assign POC address to PPOC
    cout << ppoc2->getX() << endl; //print -72
    ppoc2->setX( 2837 ); //you assigned x to itself!
    cout << ppoc2->getX() << endl; //print -72. after the changes it prints 2837
    
    //task 19
    int* pDyn = new int(3); // p points to an int initialized to 3 on the heap
    *pDyn = 17;
    cout << "The " << *pDyn
    << " is stored at address " << pDyn
    << " which is in the heap\n";
    
    //task 20
    cout << pDyn << endl;
    delete pDyn;
    cout << pDyn << endl;
    
    cout << "The 17 might STILL be stored at address " << pDyn<< " even though we deleted pDyn\n";
    cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";
    //oh no its still there.
    pDyn = nullptr;
    cout << pDyn << endl; //now this is a null pointer
    
    double* pDouble = nullptr;
    //the following 2 lines will give the following error:
    // Thread 1: EXC_BAD_ACCESS (code=1, address=0x0)
    
    //cout << "Can we dereference nullptr?  " << *pDyn << endl;
    //cout << "Can we dereference nullptr?  " << *pDouble << endl;
    
    //task 24
    double* pTest = new double(12);
    delete pTest;
    pTest = nullptr;
    delete pTest; // safe
    
    short* pShrt = new short(5);
    delete pShrt;
    //delete pShrt; //returns Thread 1: signal SIGABRT because cannot find pShrt
    
    //task 26
    long jumper = 12238743;
    //delete jumper;
    long* ptrTolong = &jumper;
    //delete ptrTolong;
    Complex cmplx;
    //delete cmplx;
    
    //NOTE: you can only delete stuff in the heap (which you madde by using the keyword new
    
    //task27
    vector<Complex*> complV; // can hold pointers to Complex objects
    Complex* tmpPCmplx;      // space for a Complex pointer
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        tmpPCmplx = new Complex; // create a new Complex object on the heap
        tmpPCmplx->real = ndx;   // set real and img to be the
        tmpPCmplx->img  = ndx;   // value of the current ndx
        complV.push_back(tmpPCmplx); // store the ADDRESS of the object in a vector or pointer to Complex
    }
    // display the objects using the pointers stored in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        cout << complV[ ndx ]->real << endl;
        cout << complV[ ndx ]->img  << endl;
    }
    // release the heap space pointed at by the pointers in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        delete complV[ndx];
    }
    // clear the vector
    complV.clear(); //this does not delete the pointers in the vector. you do it manually
    
    //task28

    
    vector<Colour*> colours;
    string inputName;
    unsigned inputR, inputG, inputB;
    
    // fill vector with Colours from the file
    // this could be from an actual file but here we are using the keyboard instead of a file
    // (so we don't have to create an actual file)
    // Do you remember the keystroke combination to indicate "end of file" at the keyboard?
    // somehow the while's test has to fail - from keyboard input
    
    
    while (cin >> inputName >> inputR >> inputG >> inputB) {
        colours.push_back(new Colour(inputName, inputR, inputG, inputB));
        //push Colour objects into colours vector that has pointers to the objects
    }
    
    // display all the Colours in the vector:
    for (size_t ndx = 0; ndx < colours.size(); ++ndx) {
        //display via pointers
        colours[ndx]->display();
        cout << endl;
    }

    

    
    SpeakerSystem speak1{};
    Amplifier amp1{};
    
    amp1.attachSpeakers(speak1);
    amp1.playMusic();
    
    //task 30
    
    
    // write code to model two people in this world
    Person joeBob("Joe Bob"), billyJane("Billy Jane");
    Person mark("mark");
    
    // now model these two becoming roommates
    joeBob.movesInWith(billyJane);
    mark.movesInWith(joeBob);
    billyJane.movesInWith(joeBob);
    // did this work out?
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
    cout << mark.getName() << " lives with " << mark.getRoomiesName() << endl;
}

