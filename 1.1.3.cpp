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
using namespace std;
int days[20] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int n, cnt, ans[10];
bool rn(int n) {
    if (n % 400 == 0) return true;
    if (n % 100 == 0) return false;
    return n % 4 == 0;
}
int main() {
    cin >> n;
    for (int y = 1900; y <= 1900 + n - 1; y++) {
        days[2] = rn(y) ? 29 : 28;
        for (int m = 1; m <= 12; m++) 
            for (int d = 1; d <= days[m]; d++) {
                cnt++;
                if (cnt == 8) cnt = 1;
                if (d == 13) ans[cnt]++;
            }
    }
    cout << ans[6] << ' ' << ans[7] << ' ' << ans[1] << ' ' << ans[2];
    cout << ' ' << ans[3] << ' ' << ans[4] << ' ' << ans[5] << endl;
    return 0;
}