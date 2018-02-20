#include <DS1307.h>

#include "NixieTube.h"

DS1307 clock;

NixieTube tube(11, 12, 13, 10, 2);

int col = 0;

void setup() {

}

void loop() {
  if (digitalRead(A7) == HIGH) {
    tube.setNumber(0,-1);
    tube.setNumber(1,-1);
    tube.setColon(0,Upper);
    tube.setColon(1,Upper);
    tube.display();
    while (digitalRead(A7) == HIGH) {

      if (digitalRead(A1) == HIGH) {
        clock.getTime();
        int h = clock.hour;
        int m = clock.minute;
        int s = clock.second;

        if (h < 24){
          h ++;
        } else {
          h = 0;
        }

        clock.fillByHMS(h, m, s);
        clock.setTime;
        tube.printf("%02d", h);
        tube.display();
      }

      if (digitalRead(A2) == HIGH) {
        clock.getTime();
        int h = clock.hour;
        int m = clock.minute;
        int s = clock.second;

        if (m < 60){
          m ++;
        } else {
          m = 0;
        }

        s = 0;

        clock.fillByHMS(h, m, s);
        clock.setTime;
        tube.printf("%02d", m);
        tube.display();
      }

      if (digitalRead(A3) == HIGH) {
        clock.getTime();
        int ye = clock.year + 2000;
        int mo = clock.month;
        int da = clock.dayOfMonth;

        if (mo < 12){
          mo ++;
        } else {
          mo = 0;
        }

        clock.fillByYMD(ye, mo, da);
        clock.setTime;
        tube.printf("%02d", mo);
        tube.display();
      }

      if (digitalRead(A6) == HIGH) {
        clock.getTime();
        int ye = clock.year + 2000;
        int mo = clock.month;
        int da = clock.dayOfMonth;

        if (mo == 1 || mo == 3 || mo == 5 || mo == 7 || mo == 8 || mo == 10 || mo == 12){

          if (mo < 31){
            da ++;
          } else {
            da = 0;
          }

        } else {

          if (mo < 30){
            da ++;
          } else {
            da = 0;
          }

        }

        clock.fillByYMD(ye, mo, da);
        clock.setTime;
        
        tube.printf("%02d", da);
        tube.display();
      }

    }

  }else {

    if (digitalRead(A1) == LOW && digitalRead(A2) == LOW && digitalRead(A3) == LOW && digitalRead(A6) == LOW && digitalRead(A7) == LOW ) {
      tube.setNumber(0,-1);
      tube.setNumber(1,-1);
      tube.display();
    }

    if (digitalRead(A1) == HIGH) {
      clock.getTime();
      tube.printf("%02d:", clock.hour);
      tube.display();
      delay(1000);

      clock.getTime();
      tube.printf("%02d", clock.minute);
      tube.display();
      delay(1000);
    }

    if (digitalRead(A2) == HIGH) {
      clock.getTime();
      tube.printf("%2d", clock.second);
      tube.display();
      delay(200);
    }

    if (digitalRead(A3) == HIGH) {
      clock.getTime();
      tube.printf("%02d.", clock.month);
      tube.display();
      delay(1000);
      tube.printf("%02d", clock.dayOfMonth);
      delay(1000);

    }

    if (digitalRead(A6) == HIGH) {

      if (col < 7 ) {
        col ++;
        while(digitalRead(A3) == HIGH ) {
          delay(1);
        }
      } else {
        col = 0;
      }

      switch(col) {
        case 0:
        tube.setBackgroundColor(0, White);
        tube.setBackgroundColor(1, White);
        break;

        case 1:
        tube.setBackgroundColor(0, Yellow);
        tube.setBackgroundColor(1, Yellow);
        break;

        case 2:
        tube.setBackgroundColor(0, Cyan);
        tube.setBackgroundColor(1, Cyan);
        break;

        case 3:
        tube.setBackgroundColor(0, Green);
        tube.setBackgroundColor(1, Green);
        break;

        case 4:
        tube.setBackgroundColor(0, Magenta);
        tube.setBackgroundColor(1, Magenta);
        break;

        case 5:
        tube.setBackgroundColor(0, Red);
        tube.setBackgroundColor(1, Red);
        break;

        case 6:
        tube.setBackgroundColor(0, Blue);
        tube.setBackgroundColor(1, Blue);
        break;

        case 7:
        tube.setBackgroundColor(0, Black);
        tube.setBackgroundColor(1, Black);
        break;
      }

      tube.display();
    }
  }
}
