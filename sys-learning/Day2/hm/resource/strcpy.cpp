#include <memory>
#include <string>

using namespace std;

int strcmp( const string& s1, const string& s2 ){
	auto len = s1.length() > s2.length() ? s2.length() : s1.length();
	for ( int i = 0; i < len; ++i ){
		if ( s1[i] < s2[i] )  return -1;
		if ( s1[i] > s2[i] )  return 1;
	}
	if ( s1.length() == s2.length() ) return 0;
	else return -1;
}
