#include <iostream>
#include <string>
#include <vector>

#include "mystr.h"

using namespace std;

int main(){
	const string str = "this is a test string!";
	string s;
   	strcpy( s, str );
	cout << "After the strcpy, the value of the string s:" << s << endl;
	strcat( s, "while this test will be ok !" );
	cout << "After the strcat, the value of the string s:" << s << endl;
	int ans = strcmp (s, str);
	cout << "the ans of the strcmp is " <<ans << endl;
	return 0;
}

