#ifndef DRIVER_LCD_I2C_H
#define DRIVER_LCD_I2C_H

#include "LiquidCrystal_I2C.h"

class DriverLCD_I2C {
  private:
    
    uint8_t _lcdAddr;  // Endereço I2C do display.
    uint8_t _lcdCols;  // Número de colunas do display.
    uint8_t _lcdRows;  // Número de linhas do display.

    uint8_t _cursorCol; // Coluna atual do cursor.
    uint8_t _cursorRow; // Linha atual do cursor.


  public:
    // Enum class para os modos do LCD
    enum class Modo{
        Manual,
        Automatico,
        Ensaio
    };
   /**
    * @brief Construtor da classe DriverLCD_I2C.
    * 
    * Este construtor inicializa o display LCD I2C com o endereço especificado,
    * número de colunas e linhas. Além disso, configura o cursor inicial e limpa o display
    * após a inicialização.
    * 
    * @param lcd_Addr Endereço I2C do display LCD.
    * @param lcd_cols Número de colunas do display LCD.
    * @param lcd_rows Número de linhas do display LCD.
    */
    DriverLCD_I2C(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows);
   /**
    * @brief Destruidor da classe DriverLCD_I2C.
    * 
    * Este destruidor é responsável por liberar quaisquer recursos alocados
    * durante o uso da classe DriverLCD_I2C.
    */
    // Destruidor
    ~DriverLCD_I2C();

   /**
    * @brief Obtém a coluna atual do cursor no LCD.
    * 
    * Este método retorna o valor da coluna onde o cursor está atualmente posicionado
    * no display LCD.
    * 
    * @return uint8_t A coluna atual do cursor.
    */
    uint8_t getCursorCol() const;
    /**
    * @brief Obtém a linha atual do cursor no LCD.
    * 
    * Este método retorna o valor da linha onde o cursor está atualmente posicionado
    * no display LCD.
    * 
    * @return uint8_t A linha atual do cursor.
    */
    uint8_t getCursorRow() const;

   /**
    * @brief Define a coluna do cursor no LCD.
    * 
    * Este método define a coluna onde o cursor será posicionado no LCD.
    * O valor fornecido deve estar dentro do limite de colunas do LCD.
    * 
    * @param col A coluna onde o cursor será posicionado (de 0 a _lcdCols-1).
    */
    void setCursorCol(uint8_t col);
   /**
    * @brief Define a linha do cursor no LCD.
    * 
    * Este método define a linha onde o cursor será posicionado no LCD.
    * O valor fornecido deve estar dentro do limite de linhas do LCD.
    * 
    * @param row A linha onde o cursor será posicionado (de 0 a _lcdRows-1).
    */
    void setCursorRow(uint8_t row);
   /**
    * @brief Exibe o valor do ângulo no LCD.
    * 
    * Este método exibe o valor do ângulo no LCD. A string "Angle: " é seguida pelo valor do ângulo formatado com 2 casas decimais.
    * Se o valor não couber na linha, ele é centralizado na tela, dividindo em duas linhas.
    * 
    * @param angle O valor do ângulo a ser exibido no LCD.
    */
    void postAngle(float angle);

   /**
    * @brief Exibe a distância medida pelo sensor TOF da direita no LCD.
    * 
    * Este método exibe o valor da distância do sensor TOF da direita no LCD. A string "TOF Right: " é seguida pelo valor da distância formatado com 2 casas decimais.
    * Se o valor não couber na linha, ele é centralizado na tela, dividindo em duas linhas.
    * 
    * @param distance O valor da distância a ser exibido no LCD.
    */
    void postTofRight(float distance);

   /**
    * @brief Exibe a distância medida pelo sensor TOF da esquerda no LCD.
    * 
    * Este método exibe o valor da distância do sensor TOF da esquerda no LCD. A string "TOF Left: " é seguida pelo valor da distância formatado com 2 casas decimais.
    * Se o valor não couber na linha, ele é centralizado na tela, dividindo em duas linhas.
    * 
    * @param distance O valor da distância a ser exibido no LCD.
    */
    void postTofLeft(float distance);

   /**
    * @brief Exibe o valor da aceleração no LCD.
    * 
    * Este método exibe o valor da aceleração no LCD. A string "Acceleration: " é seguida pelo valor da aceleração formatado com 2 casas decimais.
    * Se o valor não couber na linha, ele é centralizado na tela, dividindo em duas linhas.
    * 
    * @param acceleration O valor da aceleração a ser exibido no LCD.
    */
    void postAccelerometer(float acceleration);

   /**
    * @brief Exibe o ponto de ajuste (setpoint) no LCD.
    * 
    * Este método exibe o valor do ponto de ajuste no LCD. A string "SetPoint: " é seguida pelo valor do ponto de ajuste formatado com 2 casas decimais.
    * Se o valor não couber na linha, ele é centralizado na tela, dividindo em duas linhas.
    * 
    * @param angle O valor do ponto de ajuste a ser exibido no LCD.
    */
    void postSetPoint(float angle);

   /**
    * @brief Exibe o modo operacional no LCD.
    * 
    * Este método exibe o modo operacional no LCD, centralizando a mensagem na tela. Pode ser um dos três modos: Manual, Automático, ou Ensaio.
    * 
    * @param modo O modo a ser exibido no LCD (Manual, Automático ou Ensaio).
    */
    void postOperatingMode(Modo modo);

   /**
    * @brief Exibe a medição de consumo de energia no LCD.
    * 
    * Este método exibe a medição de consumo de energia no LCD. A string "Consumption:" é seguida pela voltagem e corrente, com o respectivo símbolo de unidade.
    * Se a mensagem não couber, o número de casas decimais é reduzido para 2.
    * 
    * @param voltage A voltagem medida a ser exibida no LCD.
    * @param current A corrente medida a ser exibida no LCD.
    * @param voltageUnit A unidade de voltagem a ser exibida.
    * @param currentUnit A unidade de corrente a ser exibida.
    */
    void postConsumption(float voltage, float current, const char* voltageUnit, const char* currentUnit);

   /**
    * @brief Desliga o retroiluminamento do LCD.
    * 
    * Este método desliga o retroiluminamento do LCD.
    */
    void dashboardLightOn();

   /**
    * @brief Liga o retroiluminamento do LCD.
    * 
    * Este método liga o retroiluminamento do LCD.
    */
    void dashboardLightOff();

   /**
    * @brief Limpa a tela do LCD.
    * 
    * Este método limpa a tela do LCD e reposiciona o cursor no início.
    */
    void clear();

   /**
    * @brief Limpa uma linha específica do LCD.
    * 
    * Este método limpa uma linha específica do LCD, e muda o cursor para a linha line e coluna 0.
    * 
    * @param line A linha que deve ser limpa. O valor deve estar entre 0 e o número máximo de linhas do LCD.
    */
    void clearLine(uint8_t line);

};

#endif // DRIVER_LCD_I2C_H
