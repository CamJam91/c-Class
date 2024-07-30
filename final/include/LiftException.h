#ifndef LIFTEXCEPTION_H
#define LIFTEXCEPTION_H
#include<fstream>
#include<iostream>
using namespace std;

    //throw an exception if an array goes out of bounds
class boundsException{
    private:
        int session;
    public:
        boundsException(int session){
            this->session = session;
        }
        int getSession(){
            return session;
        };
};

    //throw an exception if we our int/double range is out of bounds
class rangeException{
    private:
        int rangeI;
        double rangeD;
    public:
        rangeException(int range){
            this->rangeI = range;
        }
        rangeException(double range){
            this->rangeD = range;
        }
            //getters
        int getRangeInt(){
            return rangeI;
        }
        double getRangeDouble(){
            return rangeD;
        }
};

    //throw an ecxeption if the status is not desired
class fileException{
    private:
        ios::iostate status;
    public:
        fileException(ios::iostate){
        this->status = status;
    }
    ios::iostate getIoState(){
        return this->status;
    }
};

#endif