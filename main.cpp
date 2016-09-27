#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
struct abc{
		 char x;
		 abc * next;
};

abc* add (abc *last, char a)
{
		  last->x = a;
		  last->next = new (abc);
		  last = last->next;
		  last->next = NULL;
		  return last;
}
abc* del(abc *first)
{    abc * temp;
	  temp= first->next;
	  abc * previous;
	  while (temp->next!=NULL){
					previous=temp;
					temp=temp->next;
					}

	 delete(temp);

	 previous->next=new (abc);
	 previous->next=NULL;
	 printf("\b \b");
	 return(previous);
}
void file(){

		  gotoxy(13,7);
		  textcolor(RED);
		  cprintf("F");

		  gotoxy(14,7);
		  printf("ile");
		  for(int i=11;i<70;i++)
		 {                gotoxy(i,8);
								printf("%c",196);
		 }
		 gotoxy(10,8);
		 printf("%c",195);
		 gotoxy(70,8);
		 printf("%c",180);
}
void save(abc *);
/*void help(){
	int x=wherex(),y=wherey();
	char buf[20][20];
	gettext(30,20,47,26,buf);
	for(int i=30;i<48;i++)
		for(int j=20;j<27;j++){
			gotoxy(i,j);
			printf(" ");
		}
		gotoxy(32,22);
		printf("Use Alt n");
		gotoxy(36,23);
		printf("Highlighted");
		gotoxy(36,24);
		printf("Keys...");
		for(i= 31;i<48;i++){
			gotoxy(i,20);
			printf("%c",196);
			gotoxy(i,26);
			printf("%c",196);
		 }
		for(i=21;i<26;i++){
			gotoxy(30,i);
			printf("%c",179);
			gotoxy(47,i);
			printf("%c",179);
		 }
		gotoxy(30,20);
		printf("%c",218);
		gotoxy(47,20);
		printf("%c",191);
		gotoxy(30,26);
		printf("%c",192);
		gotoxy(47,26);
		printf("%c",217);
		while(1){
			int p=getch();
			if(p==27){
				puttext(30,20,47,26,buf);
				break;
			}
		}
		gotoxy(11,9);
}*/
char *otab(){
	int x=wherex(),y=wherey();
	char buf[20][20];
	gettext(30,20,47,26,buf);
	for(int i=30;i<48;i++)
		for(int j=20;j<27;j++){
			gotoxy(i,j);
			printf(" ");
		}
		gotoxy(32,22);
		printf("Press Y to Open");
		gotoxy(36,23);
		printf("The Name");
		gotoxy(36,24);
		printf("of File...");
		for(i= 31;i<48;i++){
			gotoxy(i,20);
			printf("%c",196);
			gotoxy(i,26);
			printf("%c",196);
		 }
		for(i=21;i<26;i++){
			gotoxy(30,i);
			printf("%c",179);
			gotoxy(47,i);
			printf("%c",179);
		 }
		gotoxy(30,20);
		printf("%c",218);
		gotoxy(47,20);
		printf("%c",191);
		gotoxy(30,26);
		printf("%c",192);
		gotoxy(47,26);
		printf("%c",217);
		while(1){
			int p=getch();
			if(p==121){
				gotoxy(32,22);
				printf("               ");
				gotoxy(36,23);
				printf("         ");
				gotoxy(36,24);
				printf("          ");
				gotoxy(32,22);
				char *k;
				cin>>k;
				puttext(30,20,47,26,buf);
				gotoxy(x,y);
				return k;
			}
		}
}


void open(){
		char *p;
		int i=0,j=0;
		p=otab();
		strcat(p,".txt");
		ifstream fin(p);
		gotoxy(10,9);
		while(!fin.eof()){
			char ch=fin.get();
			i=i+1;
			if(i > 58){
				j++;
				i=1;
			}
			gotoxy(10+i,9+j);
			printf("%c",ch);
		}
}




void fcon(abc *first){
		int x = wherex(), y = wherey();
		char a, *buf;
		gettext(12, 8,18, 14, buf);
		for (int i = 12; i < 18; ++i)
			for (int j = 9; j < 14; ++ j){
				gotoxy(i , j );
				printf(" ");
			}
		gotoxy(13,9);
		textcolor(BLUE);
		cprintf("N");
		gotoxy(14,9);
		printf("ew");
		gotoxy(13,10);
		textcolor(BLUE);
		cprintf("O");
		gotoxy(14,10);
		printf("pen");
		textcolor(BLUE);
		gotoxy(13,11);
		cprintf("S");
		gotoxy(14,11);
		printf("ave");
		textcolor(BLUE);
		gotoxy(13,12);
		printf("c");
		textcolor(BLUE);
		gotoxy(14,12);
		cprintf("L");
		gotoxy(15,12);
		printf("ose");
		textcolor(BLUE);
		gotoxy(13,13);
		printf("e");
		gotoxy(14,13);
		cprintf("X");
		gotoxy(15,13);
		printf("it");
		textcolor(WHITE);
		for(i=13;i<18;i++)
		{
			gotoxy(i,8);
			cprintf("%c",196);
		}
		for(i=9;i<14;i++)
		{
			gotoxy(12,i);
			printf("%c",179);
		}
		for(i=9;i<14;i++)
		{
			gotoxy(18,i);
			cprintf("%c",179);
		}
		for(i=13;i<18;i++)
		{
			gotoxy(i,14);
			cprintf("%c",196);
		}
		gotoxy(12,8);
		printf("%c",194);
		gotoxy(18,8);
		printf("%c",194);
		gotoxy(12,14);
		cprintf("%c",192);
		gotoxy(18,14);
		cprintf("%c",217);
		while (1){
		int a = getch();
		 if (a == 27){
			puttext(12, 8, 18, 14, buf);
			break;
		 }
		 if(a==115){
			save(first);
			puttext(12, 8, 18, 14, buf);
			break;
		 }
		 if(a==110||a==99){
			save(first);
			for(int i=11;i<69;i++){
				for(int j=9;j<37;j++){
					gotoxy(i,j);
					printf(" ");
				}
			}
			gotoxy(18,8);
			printf("%c",196);
			gotoxy(12,8);
			printf("%c",196);
			break;
		}
		if(a==111){
			puttext(12,8,18,14,buf);
			open();
			break;
		}
	}
		gotoxy(x,y);

}
void search(abc*);
void edit(){
		 gotoxy(22,7);
		 textcolor(RED);
		 cprintf("E");
		 gotoxy(23,7);
		 printf("dit");
}
void cut(int x,int y){
	gotoxy(x-1,y);
	int a=getch(),b=getch();
	char buf[100];
	while(1){
		a=getch();
		b=getch();
		if(a==0&&b==20){
			break;
		}
		if(a==0 && b==72 && wherey()>9){
			int k=wherey();
			int l=wherex();
			gotoxy(l,k-1);
		}
		if(a==0 && b==80 && wherey()<36){
			int k=wherey();
			int l=wherex();
			gotoxy(l,k+1);
		}
		if(a==0 && b==77 && wherex()<68){
			int k=wherey();
			int l=wherex();
			gotoxy(l+1,k);
		}
		if(a==0 && b==75 && wherex()>11){
			int k=wherey();
			int l=wherex();
			gotoxy(l-1,k);
		}

	}
	int x1=wherex(),y1=wherey();
	a=getch(),b=getch();
	while(1){
		a=getch();
		b=getch();
		if(a==0&&b==20){
			break;
		}
		if(a==0 && b==72 && wherey()>9){
			int k=wherey();
			int l=wherex();
			gotoxy(l,k-1);
		}
		if(a==0 && b==80 && wherey()<36){
			int k=wherey();
			int l=wherex();
			gotoxy(l,k+1);
		}
		if(a==0 && b==77 && wherex()<68){
			int k=wherey();
			int l=wherex();
			gotoxy(l+1,k);
		}
		if(a==0 && b==75 && wherex()>11){
			int k=wherey();
			int l=wherex();
			gotoxy(l-1,k);
		}

	}
	int x2=wherex(),y2=wherey();
	gettext(x1,y1,x2,y2,buf);
	for(int i=x1;i<=x2;i++){
		for(int j=y1;j<=y2;j++){
			gotoxy(i,j);
			printf(" ");
		}
	}
		while(1){
		a=getch();
		if (a == 0)
			b=getch();
		if(a==0 && b==72 && wherey()>9){
			int k=wherey();
			int l=wherex();
			gotoxy(l,k-1);
		}
		if(a==0 && b==80 && wherey()<36){
			int k=wherey();
			int l=wherex();
			gotoxy(l,k+1);
		}
		if(a==0 && b==77 && wherex()<68){
			int k=wherey();
			int l=wherex();
			gotoxy(l+1,k);
		}
		if(a==0 && b==75 && wherex()>11){
			int k=wherey();
			int l=wherex();
			gotoxy(l-1,k);
		}
		if (a == 'p'){
			puttext(wherex(), wherey(), wherex() + (x2 - x1), wherey() + (y2 - y1), buf);
			break;
		}
	}



}
void copy(int x,int y){
	gotoxy(x-1,y);
	int a=getch(),b=getch();
	char buf[100];
	while(1){
		a=getch();
		b=getch();
		if(a==0&&b==46){
			break;
		}
		if(a==0 && b==72 && wherey()>9){
			int k=wherey();
			int l=wherex();
			gotoxy(l,k-1);
		}
		if(a==0 && b==80 && wherey()<36){
			int k=wherey();
			int l=wherex();
			gotoxy(l,k+1);
		}
		if(a==0 && b==77 && wherex()<68){
			int k=wherey();
			int l=wherex();
			gotoxy(l+1,k);
		}
		if(a==0 && b==75 && wherex()>11){
			int k=wherey();
			int l=wherex();
			gotoxy(l-1,k);
		}

	}

	int x1=wherex(),y1=wherey(), x2, y2;

	while(1){
		a=getch();
		if (a == 0)
			b=getch();
		if(a==0&&b==46){
			x2=wherex();y2=wherey();
			gettext(x1,y1,x2,y2,buf);
		}
		if(a==0 && b==72 && wherey()>9){
			int k=wherey();
			int l=wherex();
			gotoxy(l,k-1);
		}
		if(a==0 && b==80 && wherey()<36){
			int k=wherey();
			int l=wherex();
			gotoxy(l,k+1);
		}
		if(a==0 && b==77 && wherex()<68){
			int k=wherey();
			int l=wherex();
			gotoxy(l+1,k);
		}
		if(a==0 && b==75 && wherex()>11){
			int k=wherey();
			int l=wherex();
			gotoxy(l-1,k);
		}
		if (a == 'p'){
			puttext(wherex(), wherey(), wherex() + (x2 - x1), wherey() + (y2 - y1), buf);
			break;
		}
	}

}
void econ(abc*first){
		 int x = wherex(), y = wherey();
		 char a, *buf;
		 gettext(21, 7,28, 13, buf);
		 for (int i = 21; i < 28; ++i)
			for (int j = 9; j < 13; ++ j){
				gotoxy(i , j );
				printf(" ");
			}

		 textcolor(BLUE);
		 gotoxy(22,9);
		 cprintf("C");
		 gotoxy(23,9);
		 printf("opy");
		 gotoxy(22,10);
		 printf("c");
		 gotoxy(23,10);
		 printf("u");
		 gotoxy(24,10);
		 cprintf("T");
		 gotoxy(22,11);
		 cprintf("P");
		 gotoxy(23,11);
		 printf("aste");
		 gotoxy(22,12);
		 cprintf("S");
		 gotoxy(23,12);
		 printf("earch");
		 textcolor(WHITE);
		 for(i=9;i<13;i++)
		 {                gotoxy(28,i);
								printf("%c",179);
		 }

		 for(i=9;i<13;i++)
		 {                 gotoxy(21,i);
								 printf("%c",179);
		 }
		 for(i=22;i<28;i++)
		 {						gotoxy(i,13);
								printf("%c",196);
		 }
		 gotoxy(21,8);
		 printf("%c",194);
		 gotoxy(28,8);
		 printf("%c",194);
		 gotoxy(21,13);
		 printf("%c",192);
		 gotoxy(28,13);
		 printf("%c",217);
		 while (1){
			int a = getch();
			if (a == 27){
				puttext(21, 7, 28, 13, buf);
				break;
			}
			if(a==115){
				search(first);
				puttext(21, 7, 28, 13, buf);
				break;
			}
			if(a==116){
				puttext(21,7,28,13,buf);
				cut(x,y);
				break;
			}
			if(a==99){
				puttext(21,7,28,13,buf);
				copy(x,y);
				break;
			}
		 }
		 gotoxy(x , y);
}
int ser(char* ,abc*);
void search(abc *first){
	abc *temp;
	temp=first;
	int x=wherex(),y=wherey();
	char buf[20][20];
	gettext(30,20,47,26,buf);
	for(int i=30;i<48;i++)
		for(int j=20;j<27;j++){
			gotoxy(i,j);
			printf(" ");
		}
		gotoxy(32,22);
		printf("Press Y to Find");
		gotoxy(36,23);
		printf("the String");
		gotoxy(36,24);
		printf("in File???");
		for(i= 31;i<48;i++){
			gotoxy(i,20);
			printf("%c",196);
			gotoxy(i,26);
			printf("%c",196);
		 }
		for(i=21;i<26;i++){
			gotoxy(30,i);
			printf("%c",179);
			gotoxy(47,i);
			printf("%c",179);
		 }
		gotoxy(30,20);
		printf("%c",218);
		gotoxy(47,20);
		printf("%c",191);
		gotoxy(30,26);
		printf("%c",192);
		gotoxy(47,26);
		printf("%c",217);
		while(1){
			int p=getch();
			if(p==121){
				gotoxy(32,22);
				printf("               ");
				gotoxy(36,23);
				printf("          ");
				gotoxy(36,24);
				printf("          ");
				gotoxy(32,22);
				char* k;
				cin>>k;
				puttext(30,20,47,26,buf);
				gotoxy(x,y);
				int x=ser(k,temp);
				if(x==0){
					gotoxy(29,39);
					printf("Found");
					break;
				}
				else
					gotoxy(29,39);
					printf("Not Found");
					break;
			}
		}
}
int ser(char* k,abc*temp){

				int l=strlen(k);
				int i=0;
				while(temp!=NULL && i < l){
					if(temp->x==k[i]){
					  i=i+1;
					  temp=temp->next;
					}
					else
						if (ser(k,temp->next) == 0)
							return 0;
						else
							return 1;
				}
				if(i==l)
					return 0;
				else
					return 1;


}

char* stab(){
	int x=wherex(),y=wherey();
	char buf[20][20];
	gettext(30,20,47,26,buf);
	for(int i=30;i<48;i++)
		for(int j=20;j<27;j++){
			gotoxy(i,j);
			printf(" ");
		}
		gotoxy(32,22);
		printf("Press Y to Save");
		gotoxy(36,23);
		printf("The Name");
		gotoxy(36,24);
		printf("of File...");
		for(i= 31;i<48;i++){
			gotoxy(i,20);
			printf("%c",196);
			gotoxy(i,26);
			printf("%c",196);
		 }
		for(i=21;i<26;i++){
			gotoxy(30,i);
			printf("%c",179);
			gotoxy(47,i);
			printf("%c",179);
		 }
		gotoxy(30,20);
		printf("%c",218);
		gotoxy(47,20);
		printf("%c",191);
		gotoxy(30,26);
		printf("%c",192);
		gotoxy(47,26);
		printf("%c",217);
		while(1){
			int p=getch();
			if(p==121){
				gotoxy(32,22);
				printf("               ");
				gotoxy(36,23);
				printf("         ");
				gotoxy(36,24);
				printf("          ");
				gotoxy(32,22);
				char *k;
				cin>>k;
				puttext(30,20,47,26,buf);
				gotoxy(x,y);
				return k;
			}
		}
}

void save(abc* first)
{    char *p;
		p=stab();
		strcat(p,".txt");
	  ofstream fin(p,ios::in|ios::trunc);
	  abc * temp;
	  temp=first;
	  while(temp->next!=NULL){
							  fin.put(temp->x);
							  temp=temp->next;
	  }
	  fin.close();
}


void outLine()
{
	clrscr();
	highvideo();
	gotoxy(10,5);
	printf("%c",218);
	for(int i=11;i<70;i++)
	{
		gotoxy(i,5);
		printf("%c",196);
	}
	gotoxy(70,5);
	printf("%c",191);
	for(int k=6;k<40;k++)
	{
		gotoxy(10,k);
		printf("%c",179);
	}
	gotoxy(10,40);
	printf("%c",192);
	for( int l=11;l<70;l++)
	{
		gotoxy(l,40);
		printf("%c",196);
	}
	gotoxy(70,40);
	printf("%c",217);
	for( int m=6;m<40;m++)
	{
		gotoxy(70,m);
		printf("%c",179);
	}
	file();
	edit();
	gotoxy(66,7);
	textcolor(GREEN);
	cprintf("H");
	gotoxy(67,7);
	printf("elp");
	for( i=11;i<70;i++)
	{
		gotoxy(i,37);
		printf("%c",196);
	}
	gotoxy(10,37);
	printf("%c",195);
	gotoxy(70,37);
	printf("%c",180);
	gotoxy(12,39);
	printf("Status Message  :");
	gotoxy(44,39);
	printf("Line No:   Column No:");
	gotoxy(11,9);
}

void main()
{
	abc * first;
	abc * last;
	first = new (abc);
	first->next = NULL;
	last = first;

	outLine();

	while (1){
		int a=getch();
		int b;
		if (a == 0)
			b=getch();


		if(a==0 && b==45)
			exit(0);
		if (31 < a && a < 127 && wherex() < 70 && wherey()<37 ){

			printf("%c",a);
			last=add(last,a);
			int y=wherey();
			int x=wherex();
			gotoxy(52,39);
			printf("%d",y);
			gotoxy(65,39);
			printf("%d",x);
			gotoxy(x,y);

		}
		if(a==13 && wherey()<36){
			int q=wherey();
			gotoxy(11,q+1);
		}
		if(wherey()==36){
			gotoxy(wherex(),36);
		}
		if(a==8 && wherex()>=11){
			if (wherex() == 11 && wherey() == 9)
				;
			else if(wherex()==11 && wherey()>9){
				gotoxy(69,wherey()-1);
				last=del(first);
			} else
				last=del(first);
		}
		if(a==0 && b==33){
			fcon(first);
		}
		if(a==0 && b==18){
			econ(first);
		}
		if(a==0 && b==72 && wherey()>9){
			int k=wherey();
			int l=wherex();
			gotoxy(l,k-1);
		}
		if(a==0 && b==80 && wherey()<36){
			int k=wherey();
			int l=wherex();
			gotoxy(l,k+1);
		}
		if(a==0 && b==77 && wherex()<68){
			int k=wherey();
			int l=wherex();
			gotoxy(l+1,k);
		}
		if(a==0 && b==75 && wherex()>11){
			int k=wherey();
			int l=wherex();
			gotoxy(l-1,k);
		}
		if(wherex()>68){
			gotoxy(11,wherey()+1);
		}
	}

}







