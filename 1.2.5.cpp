/*                        ..
                        .' @`._
         ~       ...._.'  ,__.-;
      _..- - - /`           .-'    ~
     :     __./'       ,  .'-'- .._
  ~   `- -(.-'''- -.    \`._       `.   ~
    _.- '(  .______.'.-' `-.`         `.
   :      `-..____`-.                   ;
   `.             ````  稻花香里说丰年，  ;   ~
     `-.__          听取人生经验。  __.-'
          ````- - -.......- - -'''    ~
       ~                   ~
-------------------------------------
|           Code by masnn           |
|      Email:masnn0@outlook.com     |
|            Do not copy            |
-----------------------------------*/
#include <iostream>
#include <stack>
using namespace std;
int n, s, t;
bool hw(int a, int k) {
    string t = "";
    while (a) {
        t = char(a % k + '0') + t;
        a /= k;
    }
    for (int i = 1; i <= t.length() / 2; i++)
        if (t[i - 1] != t[t.length() - i]) return false;
    return true;
}
int main() {
    cin >> n >> s;
    while (n) {
        s++;
        t = 0;
        for (int i = 2; i <= 10; i++)
            if (hw(s, i)) t++;
        if (t >= 2) {
            n--;
            cout << s << endl;
        }
    }
    return 0;
}