#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
      vector <string> fizzBuzz(int n) {
            vector <string> result;
            for (int i = 1; i <= n; i++)   {
                result.push_back (
                    (i % 15 == 0) ? "FizzBuzz" :
                    (i % 5 == 0)  ? "Buzz" :
                    (i % 3 == 0)  ? "Fizz" :
                    to_string(i)
                );
                
            }
            return result;
        }
};
