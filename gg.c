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
void setup(){
  size(600,600);
frameRate(60);}

         void draw(){

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
    	
  };
	  
	  
if(game_over==true){
	player_color=#ffff00;
	 textSize(50);
         fill(255,255,255);
   	text("gameover!!",height/2,weidth/2);
	move_x=0;
	move_y=0;
	
		
	}	  
 

}

		 



void mousePressed() {
 if(key_press>15 && !game_over){
    x = mouseX;
    y = mouseY; 
 };


}
      
