#include "mat.cpp"
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace ariel;

int main() {


try {
    	cout << mat(3, 8, '@', '-') << endl; 
	}
 catch (exception& ex) 
 {
	 	cout << " Exception: " << ex.what() << endl;  
 }

int col;
int row;
char char1;
char char2;

cout<<"Enter a number for the number of the columns must be a odd number :"<<endl;
cin>>col;
cout<<"Enter a number for the number of the rows must be a odd number:"<<endl;
cin>>row;
cout<<"Enter a char for char1:"<<endl;
cin>>char1;
cout<<"Enter a char for char2:"<<endl;
cin>>char2;
cout<<"The result:"<<endl;
cout<<mat(col,row,char1,char2)<<endl;



	cout << ariel::mat(11, 7, '%', '^') << endl;
/* Should print:
%%%%%%%%%%%
%^^^^^^^^^%  
%^%%%%%%%^%  
%^%^^^^^%^%  
%^%%%%%%%^%  
%^^^^^^^^^%  
%%%%%%%%%%%
*/


	cout << ariel::mat(1, 5, '(', ')') << endl; 
/* Should print:
(
(
(
(     
(        
*/

	cout << ariel::mat(1, 1, '*', ')') << endl; 
/* Should print:
   
   *       

*/


	cout << ariel::mat(3, 3, '&', '&') << endl; 
/* Should print:
&&&
&&&
&&&       
*/
	

return 0;
}
