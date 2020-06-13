
int x=10;
int y=10;
color[] c={#8f00ff,#fffdd0,#ffa500,#00ff00};
float temp=0;

void setup(){
	size(650,650);
	frameRate(60);
	background(gray);
	

};


void draw(){
	x=40;y=40;
	for(int i=0;i<6;i++){
		temp=(i+1)/4;
		if(i==3){
			draw_bunn(x,y,c[3]);
		}
		else{
		draw_bunn(x,y,c[int((temp-int(temp))*4)-1]);
		};

		x+=60;
		y+=20;
	

};




void draw_head(int x,int y,color c){
	smooth();
  	stroke(0);
  	fill(#F2ECBA);
  	ellipse(x,y,20,21);//ears
  	ellipse(x+40,y,20,21);
 
	stroke(0);
	fill(#F5CB9E);
 	 ellipse(x+3,y+3,12,13);//inner ear
	ellipse(x+37,y+3,12,13);

	stroke(0);
  	rect(x+13.5,y+63.5,15,15);//neck

	stroke(0);
  	fill(#F2ECBA);
  	ellipse(x+20,y+53,60,25);//mouth

	fill(255,0,0);//lips
	noStroke();
	ellipse(x+20,y+52,20,7);

	noStroke();
	fill(#F5F1A6);
	ellipse(x+20,y+25,45,45);//face

	stroke(0);
	fill(255);
	ellipse(x+10,y+25,10,19);//eyes
	ellipse(x+30,y+25,10,19);

	fill(0);
	ellipse(x+10,y+28,8,10);//pupil
	ellipse(x+30,y+28,8,10);

};


