#include <Arduino.h>
#include <LedControl.h>

/**
 * Small LedControl.h wrapper to
 * - override/overload core LedControl methods for this project, where the 8x8 LED matrix display is rotated 90 degrees clockwise
 * - add custom visual effects to the display
 */
class Dots
{
private:
    LedControl lc;

public:
    Dots();

    /*
     * Core methods
     */

    /**
     * @see LedControl#shutdown
     */
    void shutdown(bool status);

    /**
     * @see LedControl#setIntensity
     */
    void setIntensity(int intensity);

    /**
     * @see LedControl#clearDisplay
     */
    void clearDisplay();

    /**
     * @see LedControl#setLed
     */
    void setLed(int row, int col, boolean state);

    /**
     * @see LedControl#setRow
     */
    void setRow(int row, byte value);

    /**
     * @see LedControl#setColumn
     */
    void setCol(int col, byte value);

    /**
     * Set all 64 LEDs on the display LED by LED. 
     */
    void setMatrix(u_int8_t matrix[8][8]);

    /**
     * Set all 64 LEDs on the display row by row. 
     */
    void setMatrixByRow(byte matrix[8]);

    /*
     * Visual effects methods
     */

    void checkAll(uint32_t ms);

    void randomDots(uint32_t ms);

    void beamRow(int row, int col1, int col2, uint32_t ms);

    void beamCol(int row1, int row2, int col, uint32_t ms);

    void square(uint32_t ms);

    void spiral(uint32_t ms);

    void knight(uint32_t ms);

    void loading(uint32_t ms);

    void beating1(uint32_t ms);

    void beating2(uint32_t ms);
};
