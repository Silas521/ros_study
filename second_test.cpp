#include<iostream>
using namespace std;
class Complex;
class Complex{
    public:
    int real;
    int imaginary;
    Complex(){}
    friend ostream& operator<<(ostream& cout,const Complex& p);
    friend istream& operator>>(istream& cin,Complex& p);
    Complex(int A,int B):real(A),imaginary(B){}
    Complex operator+(const Complex&p){
        Complex temp;
        temp.real=this->real+p.real;
        temp.imaginary=this->imaginary+p.imaginary;
        return temp;
    }
    Complex operator-(const Complex&p){
        Complex temp;
        temp.real=this->real-p.real;
        temp.imaginary=this->imaginary-p.imaginary;
        return temp;
    }
    Complex operator*(const Complex&p){
        Complex temp;
        temp.real=this->real*p.real-this->imaginary*p.imaginary;
        temp.imaginary=this->real*p.imaginary+this->imaginary*p.real;
        return temp;
    }
    Complex operator~(){
        Complex p;
        p.real=this->real;
        p.imaginary=-this->imaginary;
        return p;
    }
};
istream & operator>>(istream & cin,Complex& p){
    char ch;
    cin>>ch>>p.real>>ch>>p.imaginary>>ch;
    return cin;
}
ostream& operator<<(ostream& cout,const Complex& p){
    cout<<"("<<p.real<<","<<p.imaginary<<"i)"<<'\n';
    return cout;
}
int main () {
    Complex a(3,4);
    Complex c;
    cout<<"Enter a complex number(q to quit):\n";
    while(cin>>c){
        cout<<"c is"<<c<<'\n';
        cout<<"共轭复数为:"<<~c;
        cout<<"a is"<<a<<'\n';
        cout<<"a + c is"<<a+c<<'\n';
        cout<<"a - c is"<<a-c<<'\n';
        cout<<"a * c is"<<a*c<<'\n';
        cout<<"Enter a complex number(q to quit):\n";
    }
    cout<<"Done!\n";
    return 0;
}