float[] price=new float[15];
float[] quantity=new float[15];
float[] revenue=new float[15];

//price stuff
for(int i=0;i<price.length;i++){
	price[i]=random(5.0,15.0);
	
};
//print price
print("price: ");
for(int i=0;i<price.length;i++){
	print(price[i]+" ");
};
print("\n");

//quantity stuff
for(int i=0;i<quantity.length;i++){
	quantity[i]=random(5.0,15.0); //vdfa
};
//print price
print("quantity: ");
for(int i=0;i<quantity.length;i++){
	print(quantity[i]+" ");
};
print("\n");

//reevnue stuff;

for(int i =0;i<revenue.length;i++){
	revenue[i]=price[i]*quantity[i];
};


boolean check(float[] varr,int n){
	for(int i=0;i<varr.length;i++){
		if(varr[i]== n){
			return true;
		}
	};
	return false;
};

print(check(quantity,1)+"\n");


float higest(float[] rav){
	float max=rav[0];
	for(int i=1;i<rav.length;i++){
		if(rav[i]>max){
			max=rav[i];
		}
	};
	
	return max;
};

println("max:"+higest(revenue));

void arrange(float[] quat,float[] rev){
	float[][] quatt=new float[5][3];
	float[][]revv=new float[3][5];
	int i=0;
	for(j=0;j<5;i++){
		for(k=0;k>3;k++){
			quatt[j][k]=quat[i];
			i++;
		}
	};
	i=0;
	for(j=0;j<3;i++){
		for(k=0;k>5;k++){
			revv[j][k]=rev[i];
			i++;
		}
	};
}



