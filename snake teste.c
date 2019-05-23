#include<graphics.h>
#include<time.h>

int main ()
{
	int i,X[100],Y[100],rx,ry,gA,gm,l,A=2,B=16;
	srand(time(NULL));
	detectgraph(&gA,&gm);
	initgraph(&gA,&gm,NULL);
	setfillstyle(1,1);
	bar(B-B/2,B-B/2,(B/2)+B*(1350/B),B+B/2); //topo
	bar(B-B/2,(-B/2)+B*(700/B),(B/2)+B*(1350/B),(B/2)+B*(700/B));	//baixo
	bar(B-B/2,B-B/2,B+B/2,(B/2)+B*(700/B)); //esquerda
	bar((-B/2)+B*(1350/B),B-B/2,(B/2)+B*(1350/B),(B/2)+B*(700/B)); //direta
	X[0]=B*(1350/(2*B)); Y[0]=B*(700/(2*B));
	bar(X[0]-B/2,Y[0]-B/2,X[0]+B/2,Y[0]+B/2);
	l=5;
	for(i=1;i<l;i++)
		{
			X[i]=X[0]-(i*B);
			Y[i]=Y[0];
			bar(X[i]-B/2,Y[i]-B/2,X[i]+B/2,Y[i]+B/2);
		}
		rx=B; ry=B;
		setfillstyle(1,2);
		while(getpixel(rx,ry)!=0)
		{
			rx=B*(1+rand()%(1350/B-1));
			ry=B*(1+rand()%(700/B-1));
		}
		bar(rx-B/2,ry-B/2,rx+B/2,ry+B/2);
		delay(2000);
		while(1)
		{
			//atualizar Snake
			setfillstyle(1,0);
			bar(X[l-1]-B/2,Y[l-1]-B/2,X[l-1]+B/2,Y[l-1]+B/2);
			for(i=l;i>0;i--)
			{
				X[i]=X[i-1];
				Y[i]=Y[i-1];
			}
			//atualizar a parte superior
			if(A==0)
				X[0]=X[0]-B;
			else if(A==1)
				Y[0]=Y[0]-B;
			else if(A==2)
				X[0]=X[0]+B;
			else if(A==3)
				Y[0]=Y[0]+B;
				//condição término
				if(getpixel(X[0],Y[0])==1)
				break;
			//atualizar direção
			if(GetAsyncKeyState(VK_RIGHT)&&A!=0)
				A=2;
			else if(GetAsyncKeyState(VK_UP)&&A!=3)
				A=1;
			else if(GetAsyncKeyState(VK_LEFT)&&A!=2)
				A=0;
			else if(GetAsyncKeyState(VK_DOWN)&&A!=1)
				A=3;
			if(getpixel(X[0],Y[0])==2) //condição caso a comida seja pega
			{
				rx=B; ry=B;
				setfillstyle(1,2);
				while(getpixel(rx,ry)!=0)
				{
					rx=B*(1+rand()%(1350/B-1));
					ry=B*(1+rand()%(700/B-1));
				}
				bar(rx-B/2,ry-B/2,rx+B/2,ry+B/2);
				l=l+1;
			}
			//Fazer Snake surgir
			setfillstyle(1,1);
			for(i=0;i<l;i++)
				bar(X[i]-B/2,Y[i]-B/2,X[i]+B/2,Y[i]+B/2);
			delay(100);
		}
		printf("score : %A",l-5); //record
		while(!GetAsyncKeyState(VK_RETURN));
		closegraph();
		getch();
		return 0;
}
