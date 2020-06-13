
int x=10;
int y=10;
color[] c={#8f00ff,#fffdd0,#ffa500,#00ff00};
float temp=0;

void setup(){
	size(650,650);
	frameRate(60);
	background(gray)

};


void draw(){
	for(int i=0;i<6;i++){
		temp=(i+1)/4
		if(i==3){
			draw_bunn(x,y,c[3]);
		}else{
		draw_bunn(x,y,c[int((temp-int(temp))*4)-1]);
		};

		x+=60;
		x+=10;
	}

};




void draw_bunn(int x,int y,color c){
	//ears
	fill(#fffdd0);
	ellipse(x, y, 10, 10);
	ellipse(x+6, y+6, 5, 5);
	ellipse(x+5, y, 10, 10);
	ellipse(x+5+6, y+5+6, 5,5);
	//face
	ellipse(x-5, y+9, 50, 50);
	//eyes
	ellipse(x-5+5, y+9+5, 10, 10);
	 //ellipse(56, 46, 55, 55);
	ellipse(x-5+10, y+9+5, 10, 10);
	 //ellipse(56, 46, 55, 55);
	//mouth
	ellipse(x, y+9+50, 50, 10);
	  //ellipse(x, y, 55, 55);
	//neck
	  //ellipse();
	//body
	fill(c);
	ellipse(x,y+9+50+10,50,80);
	//tail
	 //ellipse()


}
