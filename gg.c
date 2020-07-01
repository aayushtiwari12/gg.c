int level=1;
float rect_x=300;
float rect_y=20;
float move_x=-2;
float move_y=2;
int x=300;
int y= 300;
int a=40;
int speed=3;
int speed_y=0;
int key_press=0;
color player_color=#ffffff;
boolean game_over=false;
//----------------------
int mainGame = 1;
float AFic = 0.00001;
float Fic = 0.1;
float gra = .3;


// scoring
int result = 0;
int mHeal = 100;
float Heal = 100;
float dHeal = 0.5;
int HealBWidth = 60;

// ball settings
float tPaperX, tPaperY;
float tPaperSvert = 1;
float tPaperSHizon = 1;
float tPaperSize = 30;
color tPapercoloure = color(#FFFF00);

// racket settings
color rColoure = color(#FFFF00);
float rwidth = 100;
float rheight = 10;

// wall settings
int wsped = 5;
int winterval = 1000;
float ltime = 0;
int minheight = 200;
int maxheight = 300;
int wallw = 80;
color wallcoloure = (#0000FF);
// This arraylist stores data of the gaps between the walls. Actuals walls are drawn accordingly.
// [gapWallX, gapWallY, gapwallw, gapWallHeight, resultd]
ArrayList<int[]> walls = new ArrayList<int[]>();


void setup(){
  size(600,600);
frameRate(60);
}

 void draw(){
   if(level==1){
     level1_draw();
   }else{
     level2_draw();
   };
 

}

     



void mousePressed() {
if(level==1){
  level1_mouse();
 }else{
   level2_mouse();
 }

}


void level1_draw(){
  
       {noStroke();
       fill(56,random(123),21);
       rect(0,0,600,200);
       }

    {
      noStroke();
    fill( random(255),180,155);
    rect(0,200,600,200);}
    { 
      noStroke();
    fill(random(135),12,123);
    rect(0,400,600,200);}
            {
    fill(255);
    noStroke();
    rect(rect_x,rect_y,20,40);
    rect(rect_x,rect_y , 20, 20);
rect(rect_x,rect_y , 20, 20);

   
       rect_x= rect_x+move_x;
    rect_y= rect_y+move_y;
    if (rect_x>width){
      rect_x=width;
      move_x= -move_x;
    }
    if (rect_y>height){
      rect_y=height;
      move_y=-move_y;
    }
    if(rect_x<0){
      rect_x=0;
      move_x=-move_x;
    }
    if(rect_y<0){
      rect_y=0;
      move_y=-move_y;
    }
        

  fill(player_color);      
       ellipse(x, y, 50, 50);}
 {fill(#0000FF);
 ellipse(x-10,y-10,10,15);}
 {fill(#0000FF);
 ellipse(x+10,y-10,10,15);}
 {fill(0);
 if(!game_over){
 arc(x,y+10,20,16,3,6.5);
 }else{
   //arc(x,y+10,20,16,3,6.5);
   arc(x,y+10, 20, 20, 0, PI, CHORD);
 }
 };
     
     
     
     
if(int(sqrt(pow(x-rect_x,2)+pow(y-rect_y,2)))==50){
  game_over=true;
  level++;
}
  
       textSize(20);
         fill(255,255,255);
   text("key count",10,30);
   text(key_press,120,30);
           
           
           
           
 
 if(key_press>15){
    textSize(20);
           fill(255,255,255);
   text("Mouse activated",10,50);
 };
           
  
  if(game_over==false){
    y=y+speed_y;        
    x=x+speed;
  
   if(x>width-1){
     speed=speed*-1;}
     else if (x<0){
       speed=speed*-1;}
           
    if(keyPressed){
      if(key=='d'){x=x+5;key_press+=1;};
      if(key=='a'){x=x-5;key_press+=1;};
      if(key=='w'){y=y-5;key_press+=1;};
      if(key=='s'){y=y+5;key_press+=1;};
   };
   
if(game_over==true){
  }   
  }};
  
  
  
void level1_mouse(){
   if(key_press>15 && !game_over){
    x = mouseX;
    y = mouseY; 
  }};
  
void level2_draw(){
    if (mainGame == 0) { 

  } else if (mainGame == 1) { 
    mainGame();
  } else if (mainGame == 2) { 
    gameOverScreen();
  }
  
};
void level2_mouse(){
    if (mainGame==0) { 
    startGame();
  }
  if (mainGame==2) {
    restart();
  };
};



/********* SCREEN CONTENTS *********/



void mainGame() {
  background(#90EE90);
  dRac();
  wRacB();
  draB();
  aGra();
  aHorpace();
  Inscr();
  healRate();
  printresult();
  wallAdder();
  wallHandler();
}
void gameOverScreen() {
  background(44, 62, 80);
  textAlign(CENTER);
  fill(236, 240, 241);
  textSize(12);
  text("Your result", width/2, height/2 - 120);
  textSize(130);
  text(result, width/2, height/2);
  textSize(15);
  text("Click to Restart", width/2, height-30);
}


/********* INPUTS *********/



/********* OTHER FUNCTIONS *********/

// This method sets the necessery variables to start the game  
void startGame() {
  mainGame=2;
}
void gameOver() {
  mainGame=2;
}

void restart() {
  result = 0;
  Heal = mHeal;
  tPaperX=width/4;
  tPaperY=height/5;
  ltime = 0;
  walls.clear();
  mainGame = 1;
}

void draB() {
  fill(#FFFFFF);
  rect (tPaperX, tPaperY,20,40 );
}
void dRac() {
  fill(#FFFF00);
  rectMode(CENTER);
  rect(mouseX, mouseY, rwidth, rheight, 5);
}

void wallAdder() {
  if (millis()-ltime > winterval) {
    int randHeight = round(random(minheight, maxheight));
    int randY = round(random(0, height-randHeight));
    // {gapWallX, gapWallY, gapwallw, gapWallHeight, resultd}
    int[] randWall = {width, randY, wallw, randHeight, 0}; 
    walls.add(randWall);
    ltime = millis();
  }
}
void wallHandler() {
  for (int i = 0; i < walls.size(); i++) {
    wallRemover(i);
    wallMover(i);
    wallDrawer(i);
    watchWallCollision(i);
  }
}
void wallDrawer(int index) {
  int[] wall = walls.get(index);
  // get gap wall settings 
  int gapWallX = wall[0];
  int gapWallY = wall[1];
  int gapwallw = wall[2];
  int gapWallHeight = wall[3];
  // draw actual walls
  ellipseMode(CORNER);
  noStroke();
  strokeCap(ROUND);
  fill(wallcoloure);
ellipse(gapWallX, 40, gapwallw, gapWallY);
rect(gapWallX, gapWallY+gapWallHeight, gapwallw, height-(gapWallY+gapWallHeight), 15, 15, 0, 0);
}
void wallMover(int index) {
  int[] wall = walls.get(index);
  wall[0] -= wsped;
}
void wallRemover(int index) {
  int[] wall = walls.get(index);
  if (wall[0]+wall[2] <= 0) {
    walls.remove(index);
  }
}

void watchWallCollision(int index) {
  int[] wall = walls.get(index);
  // get gap wall settings 
  int gapWallX = wall[0];
  int gapWallY = wall[1];
  int gapwallw = wall[2];
  int gapWallHeight = wall[3];
  int wallresultd = wall[4];
  int wallTopX = gapWallX;
  int wallTopY = 0;
  int wallTopWidth = gapwallw;
  int wallTopHeight = gapWallY;
  int wallBottomX = gapWallX;
  int wallBottomY = gapWallY+gapWallHeight;
  int wallBottomWidth = gapwallw;
  int wallBottomHeight = height-(gapWallY+gapWallHeight);

  if (
    (tPaperX+(tPaperSize/2)>wallTopX) &&
    (tPaperX-(tPaperSize/2)<wallTopX+wallTopWidth) &&
    (tPaperY+(tPaperSize/2)>wallTopY) &&
    (tPaperY-(tPaperSize/2)<wallTopY+wallTopHeight)
    ) {
    decreaseHeal();
  }
  if (
    (tPaperX+(tPaperSize/2)>wallBottomX) &&
    (tPaperX-(tPaperSize/2)<wallBottomX+wallBottomWidth) &&
    (tPaperY+(tPaperSize/2)>wallBottomY) &&
    (tPaperY-(tPaperSize/2)<wallBottomY+wallBottomHeight)
    ) {
    decreaseHeal();
  }

  if (tPaperX > gapWallX+(gapwallw/2) && wallresultd==0) {
    wallresultd=1;
    wall[4]=1;
    result();
  }
}

void healRate() {
  noStroke();
  fill(189, 195, 199);
  rectMode(CORNER);
  rect(tPaperX-(HealBWidth/2), tPaperY - 30, HealBWidth, 5);
  if (Heal > 60) {
    fill(46, 204, 113);
  } else if (Heal > 30) {
    fill(230, 126, 34);
  } else {
    fill(231, 76, 60);
  }
  rectMode(CORNER);
  rect(tPaperX-(HealBWidth/2), tPaperY - 30, HealBWidth*(Heal/mHeal), 5);
}
void decreaseHeal() {
  Heal -= dHeal;
  if (Heal <= 0) {
    gameOver();
  }
}
void result() {
  result++;
}
void printresult() {
  textAlign(CENTER);
  fill(0);
  textSize(30); 
  text(result, height/2, 50);
}

void wRacB() {
  float overhead = mouseY - pmouseY;
  if ((tPaperX+(tPaperSize/2) > mouseX-(rwidth/2)) && (tPaperX-(tPaperSize/2) < mouseX+(rwidth/2))) {
    if (dist(tPaperX, tPaperY, tPaperX, mouseY)<=(tPaperSize/2)+abs(overhead)) {
      makeBounceBottom(mouseY);
      tPaperSHizon = (tPaperX - mouseX)/10;
      // racket moving up
      if (overhead<0) {
        tPaperY+=(overhead/2);
        tPaperSvert+=(overhead/2);
      }
    }
  }
}
void aGra() {
  tPaperSvert += gra;
  tPaperY += tPaperSvert;
  tPaperSvert -= (tPaperSvert * AFic);
}
void aHorpace() {
  tPaperX += tPaperSHizon;
  tPaperSHizon -= (tPaperSHizon * AFic);
}
// ball falls and hits the floor (or other surface) 
void makeBounceBottom(float surface) {
  tPaperY = surface-(tPaperSize/2);
  tPaperSvert*=-1;
  tPaperSvert -= (tPaperSvert * Fic);
}
// ball rises and hits the ceiling (or other surface)
void makeBounceTop(float surface) {
  tPaperY = surface+(tPaperSize/2);
  tPaperSvert*=-1;
  tPaperSvert -= (tPaperSvert * Fic);
}
// ball hits object from left side
void makeBounceLeft(float surface) {
  tPaperX = surface+(tPaperSize/2);
  tPaperSHizon*=-1;
  tPaperSHizon -= (tPaperSHizon * Fic);
}
// ball hits object from right side
void makeBounceRight(float surface) {
  tPaperX = surface-(tPaperSize/2);
  tPaperSHizon*=-1;
  tPaperSHizon -= (tPaperSHizon * Fic);
}
// keep ball in the screen
void Inscr() {
  // ball hits floor
  if (tPaperY+(tPaperSize/2) > height) { 
    makeBounceBottom(height);
  }
  // ball hits ceiling
  if (tPaperY-(tPaperSize/2) < 0) {
    makeBounceTop(0);
  }
  // ball hits left of the screen
  if (tPaperX-(tPaperSize/2) < 0) {
    makeBounceLeft(0);
  }
  // ball hits right of the screen
  if (tPaperX+(tPaperSize/2) > width) {
    makeBounceRight(width);
  }
}
