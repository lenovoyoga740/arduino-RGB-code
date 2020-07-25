//定义RGB色彩的输出I/O
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

//标记颜色变化的方式,增加值还是减小值
bool redBool =false;
bool greenBool=true;
bool blueBool=false;
//颜色值,初始化为0,127,255
int redVal =0;
int greenVal=127;
int blueVal=255;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

/**
 * 改变颜色的增减顺序
 */
void changeStatus()
{
   if (redVal==0)
  {
    redBool=true;
  }
  else if (redVal==255)
  {
    redBool=false;
  }

  if (greenVal==0)
  {
    greenBool=true;
  }
  else if (greenVal==255)
  {
    greenBool=false;
  }

  if (blueVal==0)
  {
    blueBool=true;
  }
  else if (blueVal==255)
  {
    blueBool=false;
  }  
}

/**
 * 改变颜色的变化量,增加还是减少
 */
void changeColorVal()
{
    if (redBool)
  {
    redVal++;
  }
  else
  {
    redVal--;
  }
  if (greenBool)
  {
    greenVal++;
  }
  else
  {
    greenVal--;
  }
  if (blueBool)
  {
    blueVal++;
  }
  else
  {
    blueVal--;
  }
}
/**
 * 设置led灯颜色
 */
void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
void loop()
{
  //更新颜色变化状态
  changeStatus();
  //更新颜色值
  changeColorVal();
  //设置颜色
  setColor(redVal, greenVal, blueVal);
  delay(50);
}
