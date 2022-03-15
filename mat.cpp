#include "mat.hpp"
using namespace std;
#include<vector>
#include<stdexcept>

/**
 * 
 * 
 *  
 * The algorithm is based on https://codegolf.stackexchange.com/questions/241219/mat-printing-matrix
 *
 * 
 */
namespace ariel {
   string mat(int columns, int rows, char char_a, char char_b) {
      int temp1; 
      int temp2; 
      const char ch_1 = 126; 
      const char ch_2 = 33;
      if(char_a > ch_1 || char_a < ch_2)
      {
         temp1 = 1;
      }
      else{
         temp1 = 0;
      }
      if(char_b > ch_1 || char_b < ch_2)
      {
         temp2 = 1;
      }
      else{
         temp2 = 0;
      }

      if (( columns % 2 == 0 || rows % 2 == 0)) 
      { 
         throw invalid_argument("columns and rows must to be an odd numbers");
      }
      if (( columns < 1 ||  rows < 1)) 
      {  
         throw invalid_argument("columns and rows must to be an non-negative values");
      }
      if ((temp1 == 1 || temp2 == 1))
       {  
         throw invalid_argument("ascii characters must to be over 33 and under 126 ");
      }
      
      
      string ans; 

      vector < vector <int>> matrix1(rows, vector <int> (columns, 0)); 
      vector < vector <int>> matrix2(rows, vector <int> (columns, 0));

      vector < vector <int>> matrixmin(rows, vector <int> (columns, 0)); // Minimum cell values of both matrices above

      for (int i = 1; i < rows; ++i)
       {
         for (int j = 1; j < columns; ++j) 
         {
            matrix1[i][j] = min(min(matrix1[i - 1][j - 1], matrix1[i][j - 1]), matrix1[i - 1][j]) + 1;
         }
      }


      /*
 *    # for example we have 7x5 matrix sized then the minimum function table would look like:
 * 
 *          0 0 0 0 0
 *          0 1 1 1 1
 *          0 1 2 2 2
 *          0 1 2 3 3
 *          0 1 2 3 4
 *          0 1 2 3 4
 *          0 1 2 3 4
*/

      reverse_copy(matrix1.begin(), matrix1.end(), matrix2.begin());


/*
            0 0 0 0 0         0 0 0 0 0
 *          0 1 1 1 1         1 1 1 1 0
 *          0 1 2 2 2         2 2 2 1 0
 *          0 1 2 3 3    =>   3 3 2 1 0 
 *          0 1 2 3 4         4 3 2 1 0
 *          0 1 2 3 4         4 3 2 1 0
 *          0 1 2 3 4         4 3 2 1 0
*/


      for (int i = columns - 1, j = 0; i > j; --i, j++) 
      {
         for (auto & v: matrix2) 
         {
            swap(v[i], v[j]);
         }
      }

/*                   0 0 0 0 0               4 3 2 1 0
 *                   1 1 1 1 0               4 3 2 1 0
 *                   2 2 2 1 0               4 3 2 1 0
 *                   3 3 2 1 0      =>       3 3 2 1 0
 *                   4 3 2 1 0               2 2 2 1 0
 *                   4 3 2 1 0               1 1 1 1 0
 *                   4 3 2 1 0               0 0 0 0 0
*/


   

 

      for (int i = 0; i < rows; ++i) 
      {
         for (int j = 0; j < columns; ++j) 
         {
            matrixmin[i][j] = min(matrix1[i][j], matrix2[i][j]);

            if(matrixmin[i][j]%2==0)
            {
               ans += char_a;
            }
            else
            {
               ans += char_b;

            }

         }
         if(i != rows - 1)
         {
            ans += '\n';

         }
      }


      /*
                0 0 0 0 0
 *              0 1 1 1 0
 *              0 1 2 1 0
 *              0 1 2 1 0
 *              0 1 2 1 0
 *              0 1 1 1 0
 *              0 0 0 0 0
 *     
     
 *                 ||
                   \/
                0 0 0 0 0
 *              0 1 1 1 0
 *              0 1 0 1 0
 *              0 1 0 1 0
 *              0 1 0 1 0
 *              0 1 1 1 0
 *              0 0 0 0 0
*
                  ||
                  \/
   
            for ex char_a = $ and char_b = %
            $ $ $ $ $
            $ % % % $ 
            $ % $ % $ 
            $ % $ % $ 
            $ % $ % $
            $ % % % $
            $ $ $ $ $
*/



        // deleted memory
        matrix1.clear();
        matrix2.clear();
        matrixmin.clear();
      
      return ans;

   }
}