  /**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         CarRun01.ino
* @author       chengengyue
* @version      V1.0
* @date         2019.10.08
* @brief        
* @details
* @par History  no
*/
//Import library file
#include <Adafruit_NeoPixel.h>
#include <Adafruit_PWMServoDriver.h>
#include "Wire.h"

#define KEY_PIN 8    //Define Key pin
#define RGB_PIN 9    //Define the RGB pin
#define MAX_LED 4    //4 RGB lights

//Initialize WS2812 programming RGB
Adafruit_NeoPixel strip = Adafruit_NeoPixel(MAX_LED, RGB_PIN, NEO_RGB + NEO_KHZ800);

//PCA9685 Initialization
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

//Car control parameters
int CarSpeedControl = 60;

//Button status
bool button_press = false;

/**
* Function       run
* @author        chengengyue
* @date          2019.10.08
* @brief         Advance
* @param[in]     Speed(0-160)
* @param[out]    void
* @retval        void
* @par History   no
*/

void clearRGB()
{
  uint32_t color = strip.Color(0, 0, 0);
  for (uint8_t i = 0; i < MAX_LED; i++)
  {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void showRGB(int num, int R, int G, int B)
{
  uint32_t color = strip.Color(G, R, B);
  if (num > MAX_LED - 1)  
  {
    for (int i = 0; i < MAX_LED; i++)
    {
      strip.setPixelColor(i, color);
    }
  }
  else                   
  {
    strip.setPixelColor(num, color);
  }
  strip.show();
}


void run(int Speed)
{
  Speed = map(Speed, 0, 160, 0, 2560);
  pwm.setPWM(10, 0, Speed);    //Right rear wheel Forward
  pwm.setPWM(11, 0, 0);
  pwm.setPWM(8, 0, Speed);     //Right front wheel Forward
  pwm.setPWM(9, 0, 0);

  pwm.setPWM(13, 0, Speed);    //Left rear wheel Forward
  pwm.setPWM(12, 0, 0);
  pwm.setPWM(15, 0, Speed);    //Left front wheel Forward
  pwm.setPWM(14, 0, 0);
}

/**
* Function       brake
* @author        chengengyue
* @date          2019.10.08
* @brief         car stop
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   no
*/
void brake()
{
  pwm.setPWM(8, 0, 0);
  pwm.setPWM(9, 0, 0);
  pwm.setPWM(11, 0, 0);
  pwm.setPWM(10, 0, 0);

  pwm.setPWM(12, 0, 0);
  pwm.setPWM(13, 0, 0);
  pwm.setPWM(14, 0, 0);
  pwm.setPWM(15, 0, 0);
}

/**
* Function       back
* @author        chengengyue
* @date          2019.10.08
* @brief         car back
* @param[in]     Speed(0-160)
* @param[out]    void
* @retval        void
* @par History   no
*/
void back(int Speed)
{
  Speed = map(Speed, 0, 160, 0, 2560);
  pwm.setPWM(10, 0, 0);
  pwm.setPWM(11, 0, Speed);    //Right front reserve
  pwm.setPWM(8, 0, 0);
  pwm.setPWM(9, 0, Speed);     //Right rear reserve

  pwm.setPWM(13, 0, 0);
  pwm.setPWM(12, 0, Speed);    //Left front reserve
  pwm.setPWM(15, 0, 0);
  pwm.setPWM(14, 0, Speed);    //Left front reserve
}

/**
* Function       left
* @author        chengengyue
* @date          2019.10.08
* @brief         car left translation(A type wheel Reverse，B type wheel Forward)
* @param[in]     Speed(0-160)
* @param[out]    void
* @retval        void
* @par History   no
*/
void left(int Speed)
{
  Speed = map(Speed, 0, 160, 0, 2560);
  pwm.setPWM(10, 0, Speed);   //Right rear wheel(B type) Forward
  pwm.setPWM(11, 0, 0);
  pwm.setPWM(8, 0, 0);
  pwm.setPWM(9, 0, Speed);    //Right front wheel(A type) Reverse

  pwm.setPWM(13, 0, 0);
  pwm.setPWM(12, 0, Speed);   //Left rear wheel (A type) Reverse
  pwm.setPWM(15, 0, Speed);   //Left front wheel(B type) Forward
  pwm.setPWM(14, 0, 0);
}

/**
* Function       right
* @author        chengengyue
* @date          2019.10.08
* @brief         car right translation(A type wheel Forward，B type wheel Reverse)
* @param[in]     Speed(0-160)
* @param[out]    void
* @retval        void
* @par History   no
*/
void right(int Speed)
{
  Speed = map(Speed, 0, 160, 0, 2560);
  pwm.setPWM(10, 0, 0);
  pwm.setPWM(11, 0, Speed);   //Right front wheel(B type) Reverse
  pwm.setPWM(8, 0, Speed);    //Right rear wheel(A type) Forward
  pwm.setPWM(9, 0, 0);

  pwm.setPWM(13, 0, Speed);   //Left front wheel(A type) Forward
  pwm.setPWM(12, 0, 0);
  pwm.setPWM(15, 0, 0);
  pwm.setPWM(14, 0, Speed);   //Left rear wheel(B type) Reverse
}

/**
* Function       spin_left
* @author        chengengyue
* @date          2019.10.08
* @brief         car spin left(Left wheel Reverse,Right wheel Forward)
* @param[in]     Speed
* @param[out]    void
* @retval        void
* @par History   no
*/
void spin_left(int Speed)
{
  Speed = map(Speed, 0, 160, 0, 2560);
  pwm.setPWM(10, 0, Speed);   //Right front wheel Forward
  pwm.setPWM(11, 0, 0);
  pwm.setPWM(8, 0, Speed);    //Right rear wheel Forward
  pwm.setPWM(9, 0, 0);

  pwm.setPWM(13, 0, 0);
  pwm.setPWM(12, 0, Speed);   //Left front wheel  Reserve
  pwm.setPWM(15, 0, 0);
  pwm.setPWM(14, 0, Speed);   //Left rear wheel  Reserve
}

/**
* Function       spin_right
* @author        chengengyue
* @date          2019.06.25
* @brief         car spin right(Left wheel Forward,Right wheel Reserve)
* @param[in]     Speed
* @param[out]    void
* @retval        void
* @par History   no
*/
void spin_right(int Speed)
{
  Speed = map(Speed, 0, 160, 0, 2560);
  pwm.setPWM(10, 0, 0);
  pwm.setPWM(11, 0, Speed);   //Right front wheel Reserve
  pwm.setPWM(8, 0, 0);
  pwm.setPWM(9, 0, Speed);    //Right rear wheel Reserve

  pwm.setPWM(13, 0, Speed);   //Left front wheel Forward
  pwm.setPWM(12, 0, 0);
  pwm.setPWM(15, 0, Speed);   //Left rear wheel Forward
  pwm.setPWM(14, 0, 0);
}


/**
* Function       carRun01
* @author        chengengyue
* @date          2019.10.08
* @brief         carRun01
* @param[in]     void
* @retval        void
* @par History   no
*/
void carRun01()
{
  right(CarSpeedControl);         
  delay(1000);                          
  back(CarSpeedControl);            
  delay(1000);                          
  left(CarSpeedControl);          
  delay(1000);                          
  run(CarSpeedControl);             
  delay(1000);    
  brake();                         
  delay(500);
  spin_left(CarSpeedControl);       
  delay(2000);
  brake();                         
  delay(500);
  spin_right(CarSpeedControl);     
  delay(2000);
  brake();                          
}

/**
* Function       keyscan
* @author        chengengyue
* @date          2019.10.08
* @brief         key scan
* @param[in1]    void
* @retval        void
* @par History   no
*/
void keyscan()
{
  int val;
  val = digitalRead(KEY_PIN); //Read the digital 8-port level value assigned to val
  if (val == LOW)             //When the button is pressed
  {
    delay(10);                  //Delayed debounce
    val = digitalRead(KEY_PIN); //Read button status again
    while (val == LOW)
    {
      val = digitalRead(KEY_PIN); //Third read button status
      if (val == HIGH)            //Determine if the button is released, release it to execute
      {
        button_press = !button_press;
        return;
      }
    }
  }
}

/**
* Function       setup
* @author        chengengyue
* @date          2019.10.08
* @brief         Initialization settings
* @param[in]     void
* @retval        void
* @par History   no
* 
*/

class Tesla{
  public:
    Tesla();
    Tesla(int speed, int dist, int tour , char dir,int R, int G, int B, int num);
    void carre();
    void carre(int speed, int dist, int tour , char cote);

  private:
    int m_speed;
    int m_dist;
    int m_tour;
    char m_dir;
    int m_R;
    int m_G;
    int m_B;
    int m_num;
    
};



Tesla::Tesla(){
    m_speed = 50;
    m_dist = 1500;
    m_tour = 1;
    m_dir = 'r';
    m_R=150;
    m_G=150;
    m_B=150;
    m_num=5;
}
Tesla::Tesla(int speed, int dist, int tour , char dir, int R, int G, int B,int num) : m_speed(speed) ,m_dist(dist), m_tour(tour),m_dir(dir),m_R(R), m_B(B), m_G(G),m_num(num)
{
}
void Tesla::carre()
{
  showRGB(m_num,m_R,m_G,m_B);
  int nb = 0 ;
  delay(2000);
  for(int i =0; i < 3 ; i++){
  }
  while( nb < m_tour){
    if (m_dir == 'r'){
      run(m_speed); // 1er côté
      delay(m_dist);
      brake();
      delay(1000);
      spin_right(30);
      delay(450);
      run(m_speed); // 2e côté
      delay(m_dist);
      brake();
      delay(1000);
      spin_right(30);
      delay(450);
      run(m_speed); // 3e côté
      delay(m_dist);
      brake();
      delay(1000);
      spin_right(30);
      delay(450);
      run(m_speed); // 4e côté
      delay(m_dist);
      brake();
      delay(1000);
      spin_right(30);
      delay(450);
      brake();
    }
    else if ( m_dir == 'l'){
      run(m_speed); // 1er côté
      delay(m_dist);
      brake();
      delay(1000);
      spin_left(30);
      delay(450);
      run(m_speed); // 2e côté
      delay(m_dist);
      brake();
      delay(1000);
      spin_left(30);
      delay(450);
      run(m_speed); // 3e côté
      delay(m_dist);
      brake();
      delay(1000);
      spin_left(30);
      delay(450);
      run(m_speed); // 4e côté
      delay(m_dist);
      brake();
      delay(1000);
      spin_left(30);
      delay(450);
      brake();
    }
    nb++;
  }
  clearRGB();
  
}
void Tesla::carre(int speed, int dist, int tour , char cote)
{
  showRGB(m_num,m_R,m_G,m_B);
  int nb = 0 ;
  delay(2000);
  while( nb < tour){
    if (cote == 'r'){
      run(speed); // 1er côté
      delay(dist);
      brake();
      delay(1000);
      spin_right(30);
      delay(450);
      run(speed); // 2e côté
      delay(dist);
      brake();
      delay(1000);
      spin_right(30);
      delay(450);
      run(speed); // 3e côté
      delay(dist);
      brake();
      delay(1000);
      spin_right(30);
      delay(450);
      run(speed); // 4e côté
      delay(dist);
      brake();
      delay(1000);
      spin_right(30);
      delay(450);
      brake();
    }
    else if ( cote == 'l'){
      run(speed); // 1er côté
      delay(dist);
      brake();
      delay(1000);
      spin_left(30);
      delay(450);
      run(speed); // 2e côté
      delay(dist);
      brake();
      delay(1000);
      spin_left(30);
      delay(450);
      run(speed); // 3e côté
      delay(dist);
      brake();
      delay(1000);
      spin_left(30);
      delay(450);
      run(speed); // 4e côté
      delay(dist);
      brake();
      delay(1000);
      spin_left(30);
      delay(450);
      brake();
    }
    nb++;
  }
  clearRGB();
}



void setup() {
  // put your setup code here, to run once:
  pinMode(KEY_PIN, INPUT_PULLUP);
  pinMode(RGB_PIN, OUTPUT);        //Set the RGB pin to output mode
  pinMode(KEY_PIN, INPUT_PULLUP);  //Set the button pin to pull-up input mode

  Wire.begin();       
  pwm.begin();
  strip.begin();
  strip.show();
  pwm.setPWMFreq(60); // Analog servos run at ~60 Hz updates
  brake();   
  clearRGB();        
}

/**
* Function       loop
* @author        chengengyue
* @date          2019.10.08
* @brief         main function
* @param[in]     void
* @retval        void
* @par History   no
*/

int actionControl = 0;
void loop() {
  // put your main code here, to run repeatedly:
  //keyscan
  Tesla modelx; 
  Tesla modely(60,2000,2,'r',10,250,50,4);
  switch (actionControl)
  {
    case 0:
      modelx.carre();
      actionControl++;
      break;
    case 1:
      modely.carre();
      actionControl++;
      break;
  }
}
