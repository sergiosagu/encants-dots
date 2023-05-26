#include "Dots.h"

#define DIN 17
#define CS 16
#define CLK 15

Dots::Dots() : lc(DIN, CLK, CS)
{
    randomSeed(analogRead(0));
}

/*
 * Core methods
 */

void Dots::shutdown(bool status)
{
    lc.shutdown(0, status);
}

void Dots::setIntensity(int intensity)
{
    lc.setIntensity(0, intensity);
}

void Dots::clearDisplay()
{
    lc.clearDisplay(0);
}

void Dots::setLed(int row, int col, boolean state)
{
    lc.setLed(0, col, (7 - row) % 8, state);
}

void Dots::setRow(int row, byte value)
{
    lc.setColumn(0, (7 - row) % 8, value);
}

void Dots::setCol(int col, byte value)
{
    lc.setRow(0, col % 8, value);
}

void Dots::setMatrix(u_int8_t matrix[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            setLed(i, j, matrix[i][j] == 1);
        }
    }
}

void Dots::setMatrixByRow(byte matrix[8])
{
    for (int i = 0; i < 8; i++)
    {
        setRow(i, matrix[i]);
    }
}

/*
 * Visual effects methods
 */

void Dots::checkAll(uint32_t ms)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            setLed(i, j, true);
            delay(ms);
            setLed(i, j, false);
        }
    }
}

void Dots::randomDots(uint32_t ms)
{
    int row = random(8);
    int col = random(8);
    setLed(row, col, true);
    delay(ms);
    setLed(row, col, false);
}

void Dots::beamRow(int row, int col1, int col2, uint32_t ms)
{
    if (col1 == col2)
        return;

    if (col1 < col2)
    {
        for (int i = col1; i < col2; i++)
        {
            setLed(row, i, true);
            delay(ms);
            setLed(row, i, false);
        }
    }
    else // col1 > col2
    {
        for (int i = col1 - 1; i >= col2; i--)
        {
            setLed(row, i, true);
            delay(ms);
            setLed(row, i, false);
        }
    }
}

void Dots::beamCol(int row1, int row2, int col, uint32_t ms)
{
    if (row1 == row2)
        return;

    if (row1 < row2)
    {
        for (int i = row1; i < row2; i++)
        {
            setLed(i, col, true);
            delay(ms);
            setLed(i, col, false);
        }
    }
    else // row1 > row2
    {
        for (int i = row1 - 1; i >= row2; i--)
        {
            setLed(i, col, true);
            delay(ms);
            setLed(i, col, false);
        }
    }
}

void Dots::square(uint32_t ms)
{
    beamRow(0, 0, 8, ms);
    beamCol(1, 8, 7, ms);
    beamRow(7, 7, 0, ms);
    beamCol(7, 1, 0, ms);
}

void Dots::spiral(uint32_t ms)
{
    for (int i = 0; i < 4; i++)
    {
        beamRow(0 + i, 0 + i, 8 - i, ms);
        beamCol(i + 1, 8 - i, 8 - (i + 1), ms);
        beamRow(8 - (i + 1), 8 - (i + 1), 0 + i, ms);
        beamCol(8 - (i + 1), i + 1, 0 + i, ms);
    }
}

void Dots::knight(uint32_t ms)
{
    beamRow(0, 0, 8, ms);
    beamRow(0, 7, 1, ms);
}

void Dots::loading(uint32_t ms)
{
    byte loading[4][8] = {
        {B11110000, B11110000, B11110000, B11110000, B00000000, B00000000, B00000000, B00000000},
        {B00001111, B00001111, B00001111, B00001111, B00000000, B00000000, B00000000, B00000000},
        {B00000000, B00000000, B00000000, B00000000, B00001111, B00001111, B00001111, B00001111},
        {B00000000, B00000000, B00000000, B00000000, B11110000, B11110000, B11110000, B11110000}};

    for (int i = 0; i < 4; i++)
    {
        setMatrixByRow(loading[i]);
        delay(ms);
    }
}

void Dots::beating1(uint32_t ms)
{
    byte heart[2][8] = {{B01101100,
                         B10010010,
                         B10000010,
                         B10000010,
                         B01000100,
                         B00101000,
                         B00010000},
                        {B00000000,
                         B00101000,
                         B01010100,
                         B01000100,
                         B00101000,
                         B00010000,
                         B00000000}};

    for (int i = 0; i < 2; i++)
    {
        setMatrixByRow(heart[i]);
        delay(ms);
    }
}

void Dots::beating2(uint32_t ms)
{
    byte heart[2][8] = {{B01101100,
                         B11111110,
                         B11111110,
                         B11111110,
                         B01111100,
                         B00111000,
                         B00010000},
                        {B00000000,
                         B00101000,
                         B01111100,
                         B01111100,
                         B00111000,
                         B00010000,
                         B00000000}};

    for (int i = 0; i < 2; i++)
    {
        setMatrixByRow(heart[i]);
        delay(ms);
    }
}