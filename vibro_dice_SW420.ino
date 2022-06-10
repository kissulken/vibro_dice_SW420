#include <TrueRandom.h>
#define vibro 13
#define one 6
uint8_t two[] = { 5, 7 };
uint8_t three[] = { 6, 4, 10 };
uint8_t four[] = { 4, 2, 10, 8 };
uint8_t five[] = { 2, 4, 6, 8, 10 };
uint8_t six[] = { 2, 3, 4, 8, 9, 10 };
uint8_t tmp, prev_tmp = 0;

void setup()
{
    Serial.begin(9600);
    for (int i = 2; i <= 10; i++)
        pinMode(i, OUTPUT);
}

void loop()
{
    if (digitalRead(vibro))
    {
        for (int i = 30; i >= 10; i--)
        {
            do
                tmp = TrueRandom.random(1, 7);
            while (prev_tmp == tmp);
            prev_tmp = tmp;
            Serial.println(tmp);
            switch (tmp)
            {
            case 1:
                digitalWrite(one, HIGH);
                break;
            case 2:
                for (int i = 0; i < sizeof(two); i++)
                    digitalWrite(two[i], HIGH);
                break;
            case 3:
                for (int i = 0; i < sizeof(three); i++)
                    digitalWrite(three[i], HIGH);
                break;
            case 4:
                for (int i = 0; i < sizeof(four); i++)
                    digitalWrite(four[i], HIGH);
                break;
            case 5:
                for (int i = 0; i < sizeof(five); i++)
                    digitalWrite(five[i], HIGH);
                break;
            case 6:
                for (int i = 0; i < sizeof(six); i++)
                    digitalWrite(six[i], HIGH);
                break;
            }
            delay(2000 / i);
            if (i > 10)
            {
                OFF();
                delay(2000 / i);
            }
        }
    }
}

void OFF()
{
    for (int i = 2; i < 11; i++)
        digitalWrite(i, LOW);
}
