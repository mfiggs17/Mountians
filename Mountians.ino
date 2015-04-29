#include <MeggyJrSimple.h> 

int mountians[8] = {2,2,2,2,2,2,2,2};
int playerY = 4; 
int counter = 0;
boolean gameOver = false;

void setup() {
    MeggyJrSimpleSetup();

}



void loop() {
  while(gameOver==false)
    playing();
}

void playing()
{
  player();
  if(counter%12==0)
  {
  moveLeft();
  wall();
  }
  draw();
  if(counter<120)
    counter++;
  else
    counter=0;
  delay(10);
}

void player()
{
  CheckButtonsPress();
  if(Button_Up)
    playerY++;
  if(Button_Down)
    playerY--;
  
}

void wall()
{
  mountians[7] = mountians[7] -1 + random(3);
  if(mountians[7]>3)
    mountians[7]=3;
  if(mountians[7]<0)
    mountians[7]=0;
}

void draw()
{
  for(int i=0;i<8;i++){
    for(int j=mountians[i];j>-1;j--)
      DrawPx(i,j,1);
    for(int j=mountians[i]+4;j<8;j++)
      DrawPx(i,j,1); 
  DrawPx(1,playerY,2);
}
  
  DisplaySlate();
  ClearSlate();
}

void moveLeft()
{
  for(int i=0;i<7;i++)
    mountians[i]=mountians[i+1];

}
