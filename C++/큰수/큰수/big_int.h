/*
 programmed by Matthew, CHANG
 www.izect.kr
 matthew.chang@me.com
 */
#include<iostream>
using namespace std;
class big_int{
private:
   char* cDigits;
   unsigned int iLength;
   bool bSign;
public:
   big_int(void);
   big_int(int);
   big_int(const char*);
   big_int(const big_int&);
   ~big_int();
   big_int& operator=(const big_int&);
   friend bool operator==(const big_int& , const big_int&);
   friend bool operator!=(const big_int& , const big_int&);
   friend bool operator>(const big_int& , const big_int&);
   friend bool operator<(const big_int& , const big_int&);
   friend big_int operator+(const big_int& , const big_int&);
   friend big_int operator-(const big_int& , const big_int&);
   friend big_int operator*(const big_int& , const big_int&);
   friend ostream& operator<<(ostream&, const big_int&);
};
