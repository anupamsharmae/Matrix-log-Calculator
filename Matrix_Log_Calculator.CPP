#include<iostream.h>                  					//Header files.
#include<time.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>
#include<math.h>

class Calculator                                        // Calculator class
{
	float det,a11,a12,a13,a21,a22,a23,a31,a32,a33,adj1,adj2,adj3,adj4,adj5,adj6,adj7,adj8,adj9;
	int val;
	float result;
	
	public:
	Calculator()     									//Constructor.
	{
		delay(1000);
		gotoxy(28,5);
		cout<<"MATRIX AND LOG CALCULATOR\n";
	}

	void draw_line(int, char);
	void matrix();
	void logval();
};

void Calculator::matrix()								// Matrix Calculator (2x2 & 3x3)
{
	int i;
	delay(100);
	cout<<" " ;
	clrscr();
	cout<<"\nEnter the order no. 2 for 2x2 matrix or 3 for 3x3 matrix\n";
	cin>>i;
	if(i==2)
	{
		cout<<"\n\t\t\t2X2 Matrices\nEnter the Matrices:\n\n";

		cout<<"a11=";cin>>a11;cout<<"\n";
		cout<<"a12=";cin>>a12;cout<<"\n";
		cout<<"a21=";cin>>a21;cout<<"\n";
		cout<<"a22=";cin>>a22;cout<<"\n";

		cout<<"\t|~\t~|\n";
		cout<<"\t|"<<a11<<"\t"<<a12<<"|\n";
		cout<<"\t|"<<a21<<"\t"<<a22<<"|\n";
		cout<<"\t|_\t_|\n";
		
		det=(a22*a11)-(a21*a12);
		cout<<"determinent="<<det<<"\n";
		adj1=(a22)/det;adj2=-(a12)/det;adj3=-(a21)/det;adj4=(a11)/det; cout<<"\nA Inverse==";

		if(det==0)
		{
			cout<<"  Inverse is impossible..!!";
	  	}
		else
		{
			cout<<"\n\t|~\t   ~|\n\t|"<<adj1<<"\t "<<adj2<<"  |\n\t|"<<adj3<<"\t"<<adj4<<"|\n";
			cout<<"\t|_\t   _|\n";
	  	}

	}
	else
	if(i==3)
	{
		cout<<"\t\t\t3X3 Matrices\nEnter the Matrices\n\n" ;
		cout<<"a11=";cin>>a11;cout<<"\n";
		cout<<"a12=";cin>>a12;cout<<"\n";
		cout<<"a13=";cin>>a13;cout<<"\n";
		cout<<"a21=";cin>>a21;cout<<"\n";
		cout<<"a22=";cin>>a22;cout<<"\n";
		cout<<"a23=";cin>>a23;cout<<"\n";
		cout<<"a31=";cin>>a31;cout<<"\n";
		cout<<"a32=";cin>>a32;cout<<"\n";
		cout<<"a33=";cin>>a33;cout<<"\n";

		det=a11*(a22*a33-a32*a23)-a12*(a33*a21-a31*a23)+a13*(a32*a21-a31*a22);
		cout<<"Determinent="<<det<<"\n";
		adj1=(a33*a22-a32*a23)/det;
		adj2=-(a33*a12-a32*a13)/det;
		adj3=(a23*a12-a22*a13)/det;
		adj4=-(a33*a21-a31*a23)/det;
		adj5=(a33*a11-a31*a13)/det;
		adj6=-(a23*a11-a21*a13)/det;
		adj7=(a32*a21-a31*a22)/det;
		adj8=-(a32*a11-a31*a12)/det;
		adj9=(a22*a11-a21*a12)/det;
		if(det==0)
		{
			cout<<"  Inverse is impossible..!!";
		}
		else
		{
			cout<<"\n\t|~\t\t\t\t\t ~|\n\t|"<<adj1<<"\t "<<adj2<<" \t"<<adj3<<"  |\n\t|"<<adj4<<"\t "<<adj5<<"\t"<<adj6<<"  |";
			cout<<"\n\t|"<<adj7<<"\t "<<adj8<<"\t"<<adj9<<" |"<<"\n\t|_\t  \t\t\t\t _|\n";
		}
	}
	else
		cout<<"not valid....!!";

}

void Calculator::draw_line(int n,char ch)                    // To print special character.
{
    for(int i=0;i<n;i++)
    {
    	delay(20);
    	cout<<ch;
    }
}

void Calculator::logval()                           		// Calculate Log values.
{
	cout<<"Enter the value for log"<<endl;
	cin>>val;
	result=log(val);
	cout<<"LOG value of "<<val<<" is "<<result<<endl;
}

void main()                 //Main started.
{
	clrscr();
	Calculator ob;
	gotoxy(28,6);
	ob.draw_line(25,'~');
	cout<<"\n";
  	
	clock_t t1,t2;
	
	ob.draw_line(80,'!');
	cout<<"\n";
	ob.draw_line(80,'~');


	cout<<"\n";
	gotoxy(3,20);
	ob.draw_line(10,'-');
	cout<<"BY ANUPAM"<<"\n";
	cout<<"St. Marys Convent School Vikasnagar\n "<<endl;

	float tStart;
	time_t now=time(0);
	char* dt=ctime(&now);
	    gotoxy(40,23);
	    cout<<dt<<endl;
	    gotoxy(40,24);
	    ob.draw_line(24,'-');
	    tm *gmtm = gmtime(&now);
	    dt= asctime(gmtm);
	    cout<<"\n\n\t\t\tTHE UTC DATE AND TIME IS-- "<<dt<<endl;

	delay(2000);
	
	int ch;
	clrscr();

	while(ch!=3)
    {
	   	clrscr();
	   	t1=clock();
		cout<<"1.Calculating the inverse\n2.For Logarithmic value\n3.Exit\n\nEnter choice: ";
		cin>>ch;
		switch(ch)
		{
	    	case 1: ob.matrix(); break;
	    	case 2: ob.logval(); break;
	    	case 3: gotoxy(17,14);
		    		ob.draw_line(57,'-');
		     		gotoxy(17,15);
		    		cout<<"Program is going to Sleep....Have nice day.....!!.   ";
		    		gotoxy(17,16);
		     		ob.draw_line(57,'-');
		    		break;
	    	default: cout<<"Invalid Option\n";
		}
		t2=clock();
	    float diff=((float)t2-(float)t1)/100;
		
		gotoxy(40,22);
		cout<<"Time Taken == "<<diff<<" s"<<endl;
		gotoxy(40,23);
  		ob.draw_line(20,'-');
  		cout<<"\n";
		
		system("pause");
    }

	getch();
}