//Pariya Palizban
//poroje barname nevisi  -  faz nahai
//-------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <conio.h>
#define r 1000
//tavabe barname
using namespace std;
void sum(int num1[],int num2[], int result[]);//----------------------//tabe jam 
void multiply(int num1[],int num2[], int result[]);//-----------------//tabe zarb
void mine(int num1[],int num2[], int result[]);//---------------------//tabe menha
void divide(int num1[],int num2[], int result[]);//-------------------//tabe taghsim
void remainder(int num1[],int num2[], int result[]);//----------------//tabe baghimande
void expo(int num1[],int num2[],  int result[]);//--------------------//tabe tavan
void sqrt(char problem[]);//------------------------------------------//tabe jazr
void mabna(int n,int ar[],int num1[],int num2[],int result[]);//------//tabe tabdil mabna--- ghabeliat ezafe barname
void separate_solve(char problem[]);//--------------------------------//tabe joda kardan adad va be hal bekomak tavabe digar
void show(int result[],int p);//--------------------------------------//tabe neshan dadan adad haye barname
void clean(char problem[]);//-----------------------------------------//tabe pak kardan fasele ha
//-------------------------------------------------------------------
int main()
{
	string ad;
	ad="in.txt";//voroodi
	fstream i;
	i.open(ad.c_str(),ios::in);
	fstream o;
	ad="out.txt";//khorooji
	//file sakhte shavad va khali shavad
	o.open(ad.c_str(),ios::out);
	o.close();
	//baraye neveshtan az akhar file
	o.open(ad.c_str(),ios::app);
	int num1[r];
	int num2[r];
	int statement_nu=0;
	while(true)
	{
		statement_nu++;
		char str[r]={0};
		i.getline(str, r);
		if(str[0]=='e' || str[0]=='E')//exit
			break;
		clean(str);
		o<<"-------------------statement "<<statement_nu<<endl;
		if(str[0]=='s' || str[0]=='S')//sqrt
			sqrt(str);
		else
			separate_solve(str);
		o<<endl;
	}
	return 0;
}
//-------------------------------------------------------------------
void sum(int num1[],int num2[], int result[])
{	//shive kar tabe: deraye haye motanazer ra ba ham jam mikonad  -  hame deraye haye javab ra 5 raghami mikonad
	for(int j=0;j<r;j++)
		result[j]=0;

	for(int j=0;j<r;j++)
		result[j]=num1[j]+num2[j];

	for(int j=0;j<r;j++)       
	{
			result[j+1]+=(result[j]/10000);
			result[j]%=10000;
	}
}
//-------------------------------------------------------------------
void multiply(int num1[],int num2[], int result[])
{	//shive kar tabe: hame deraye haye adad ha ra be tartib dar ham zarb mikonad va dar jaye sahih javab jam mikonad - hame deraye haye javab ra 5 raghami mikonad
	for(int j=0;j<r;j++)
		result[j]=0;

	for(int i=0;i<r;i++)
		for(int j=0;j<r;j++)
			 result[i+j]+=num1[i]*num2[j];

	for(int j=r-1;j>=0;j--)
	{
			result[j+1]+=(result[j]/10000);
			result[j]%=10000;
	}
	for(int j=0;j<r;j++)
	{
			result[j+1]+=(result[j]/10000);
			result[j]%=10000;
	}
}
//-------------------------------------------------------------------
void mine(int num1[],int num2[],  int result[])
{	//shive kar tabe: avalin adad tamam deraye hayash ra 6 raghami mikonad - deraya haye motanazer ra az ham kam mikonad - hame deraye haye javab ra 5 raghami mikonad
	for(int j=0; j<r;j++){

       if(num1[j]<num2[j]){
            num1[j]+=10000;
            num1[j+1]-=1;
       }
    }

   for(int j=0;j<20;j++)
    result[j]=num1[j]-num2[j];

    for(int j=0;j<20;j++)
  {
      result[j+1]+=(result[j]/10000);
      result[j]%=10000;
  }
}
//-------------------------------------------------------------------
void divide(int num1[],int num2[],  int result[])
{	//shive kar tabe: dar yek halghe adad dovam ra az adad aval ta jai kam mikonad ke adad dovam az aval bishtar shavad - dar har dor halghe yek ra ba javab jam mikonad
	int num3[r];
	int num4[r];
	int num5[r];

	for(int i=0;i<r;i++)
	{//num3 va num5 be onvan araye komaki tarif mishvand chon agar yek araye ra be onvan do ta az voroodi ha be tabe menha bedahim amalkardash kharab mishavad
		num3[i]=0;
		num4[i]=0;
		num5[i]=0;
		result[i]=0;
	}
	num4[0]=1;//adad 1 be soorat arayei
	result[0]=1;
	while(1)
	{
		int a=0;//in motaghayer dar moghayese ye adaad arayei komak mikonad
		for(int i=0;i<r;i++)//az in halghe agar num1 az num2 bozorg tar bashad a=1, agar koochaktar bashad a=-1 va agar mosavi bashand a=0(tebgh tarif avalie) biroon miayad
		{
			if(num1[i]>num2[i])
				a=1;
			if(num1[i]<num2[i])
				a=-1;
		}
		if(a==1)
		{
			mine(num1,num2,num3);
			for(int i=0;i<r;i++)
			{
				num1[i]=num3[i];
				num3[i]=0;
			}
			sum(result,num4,num5);
			for(int i=0;i<r;i++)
			{
				result[i]=num5[i];
				num5[i]=0;
			}
		}
		if(a==-1)
		{
			mine(result,num4,num5);
			for(int i=0;i<r;i++)
				result[i]=num5[i];
			break;
		}
		if(a==0)
			break;
	}
}
//-------------------------------------------------------------------
void remainder(int num1[],int num2[],  int result[])
{	//shive kar tabe: mesl tabe taghsim amal mikonad faghat javab nahai meghdarist ke vaghti num1 az num2 kamtar shod azash mande ast
	int num3[r];

	while(1)
	{
		int a=0;
		for(int i=0;i<r;i++)
		{
			if(num1[i]>num2[i])
				a=1;
			if(num1[i]<num2[i])
				a=-1;
		}
		if(a==1)
		{
			mine(num1,num2,num3);
			for(int i=0;i<r;i++)
			{
				num1[i]=num3[i];
				num3[i]=0;
			}
		}
		else
		{
			if(num1[0]==num2[0])
			{
				mine(num1,num2,num3);
				for(int i=0;i<r;i++)
				{
					num1[i]=num3[i];
					num3[i]=0;
				}
			}
			break;
		}

	}
	for(int i=0;i<r;i++)
		result[i]=num1[i];
}
//-------------------------------------------------------------------
void expo(int num1[],int num2[],  int result[])
{	//shive kar tabe: be tedad adad dovam adad aval ra dar khodash zarb mikonad
	int num3[r];
	for(int i=0; i<r; i++)
	{
		num3[i]=0;
		result[i]=0;
	}
	num3[0]=1;// adad 1

	for(int k=0;k<r;k++)
	{
		for(int j=0;j<num2[k];j++)
		{
			multiply(num1,num3,result);
			for(int i=0;i<r;i++)
			{
				num3[i]=result[i];
				result[i]=0;
			}
		}

		for(int j=0;j<k;j++)
		{
			for(int a=0;a<1000;a++)
			{
				for(int b=0;b<num2[k];b++)
				{
                    multiply(num1,num3,result);
				    for(int i=0;i<r;i++)
				    {
					  num3[i]=result[i];
					  result[i]=0;
				    }
				}
			}
		}

		int op=0;
		for(int j=k;j<r;j++)
		{
			if(num2[j]>0)
				op++;
		}
		if(op==0)
			break;
	}

	for(int i=0;i<r;i++)
			result[i]=num3[i];
}
//-------------------------------------------------------------------
void sqrt(char problem[])
{	//shive kar tabe: az adadi ke taghriban nesf tedad ragham adademan ra darad shoroo mikonad va yeki yeki ezafe mishavad ta jayi ke morabash az adademan bishtar shavad
	int a,c;//a-->shomare parantez baz --------- c-->shomare parantez baste
	int num[r];//adad voroodi
	int num1[r];//adad 1
	int num2[r];//adad 2
	int num3[r];//araye komaki
	for(int j=0;j<r;j++)
	{
		num[j]=0;
		num1[j]=0;
		num2[j]=0;
		num3[j]=0;
	}
	num1[0]=1;
	num2[0]=2;
	for(int i=0;i<1000;i++)//peyda kardan adad
	{
		if(char(problem[i])==40)
			a=i;
		if(char(problem[i])==41 || char(problem[i])==46)
		{	
			c=i;	
			int k=0;
			i--;
				for(int j=1;i>a;i--)
				{
					if(char(problem[i])==-2)
						i--;
					num[k/4]+=(j*problem[i]);
					j*=10;
					k++;
					if(k%4==0)
						j=1;
				}
			break;
		}
		problem[i]-=48;
	}
	c-=a;
	c--;
	int b=1;//dar ghesmati az barname agar adad chap shode bashad sefr mishavad ke dobare badan chap nashaved
	int num4[r];
	//chao soorat soal
	fstream o;
	string ad="out.txt";
	o.open(ad.c_str(),ios::app);
	o<<"sqrt(";
	o.close();
	show(num,0);
	o.open(ad.c_str(),ios::app);
	o<<")"<<endl<<"="<<endl;
	//in ghesmat be nazdik shodane shorooeman be adad komak mikonad
	if(c%4==1 || c%4==2)
		num3[(c-1)/8]=1;
	if(c%4==3 || c%4==0)
		num3[(c-1)/8]=10;
		
	while(1)
	{
		for(int j=0;j<r;j++)
			num4[j]=0;
		expo(num3,num2,num4);//num4 morabae num3 ast
		a=0;
		for(int i=0;i<r;i++)
		{
			if(num[i]<num4[i])
				a=1;
			if(num[i]>num4[i])
				a=-1;
		}
		if(a==0)
		{
			b=0;
			show(num3,0);
			break;
		}
		int num5[r];
		for(int i=0;i<r;i++)
			num5[i]=0;
		if(a==1)
		{
			mine(num3,num1,num5);
			for(int i=0;i<r;i++)
				num3[i]=num5[i];
			break;
		}
		if(a==-1)
		{
			sum(num3,num1,num5);
			for(int i=0;i<r;i++)
				num3[i]=num5[i];
		}
	}
	if(b)
	{
		show(num3,0);
	}
}
//-------------------------------------------------------------------
void mabna(int qw,int ar[],int num1[],int num2[],int result[])
{
	fstream o;
	string ad="out.txt";
	o.open(ad.c_str(),ios::app);
	
    int javab[r];
    int javab_nahii[r];
    int num1_1[r];

    for(int i=0;i<r;i++)
    {
        num1_1[i]=num1[i];
    }

    remainder(num1,num2,javab_nahii);

    ar[qw]=javab_nahii[0];

    divide(num1_1 ,num2 ,javab);

    for(int i=0;i<r;i++)
    {
        num1_1[i]=javab[i];
    }

    if(javab[0]>=num2[0])
    {
       qw++;
       mabna(qw,ar,num1_1,num2,javab_nahii);
    }
    else
    {
        o<<num1_1[0];

        for(int i=qw;i>=0;i--)
        {
            if(ar[i]<10)
                o<<ar[i];
            else
            {
              if(ar[i]==10)
                o<<"A";

              if(ar[i]==11)
                o<<"B";

              if(ar[i]==12)
                o<<"C";

              if(ar[i]==13)
                o<<"D";

              if(ar[i]==14)
                o<<"E";

              if(ar[i]==15)
                o<<"F";
            }

        }

    }
}
//-------------------------------------------------------------------
void separate_solve(char problem[])
{
	int num1[r];//adad ghabl operator
	int num2[r];//adad bade operator
	//true-->mosbat - false-->manfi     ------    be tor pishfarz adad ha ra mosbat dar nazar migirim chon adade bi alamat, mosbat ast
	bool alamat1=true;
	bool alamat2=true;
	bool c=true;//in motaghayer komak mikonad ke agar dar soorat soal eshkali bood, hal nakonad va error neshan dahad
	for(int j=0;j<r;j++)
	{
		num1[j]=0;
		num2[j]=0;
	}
	int a,b=0;// moshakas konande ye jaye shoroo adaad (ba tavajoh be in ke momken ast alamat dashte ya nadashte bashand)
	int op,opp;// op-->moshakhas konanade ye jaye operator vasat adaad   -----   opp-->moshakhas konanade ye jaye mosavi
	if(char(problem[0])==43||char(problem[0])==45)
	{
		a=1;
		if(char(problem[0])==43)
			alamat1=true;
		else
			alamat1=false;
	}	
	int p1=0;//tedad ragham ashaar avalin adad
	int p2=0;//tedad ragham ashaar dovomin adad
	
	for(int i=0;i<1000;i++)//------------------------//joda kardan adad aval  va dovom va tashkhis alamat hayeshan va alamat beyneshan
	{
		if(char(problem[i])==42||char(problem[i])==43||char(problem[i])==45||char(problem[i])==47||char(problem[i])==37||char(problem[i])==94||char(problem[i])==64)
		{
			if(char(problem[i+1])==43||char(problem[i+1])==45)
			{
				b=1;
				if(char(problem[i+1])==43)
					alamat2=true;
				else
					alamat2=false;
			}
			int k=0;
			op=i;
			i--;
				for(int j=1;i>=a;i--)
				{
					if(char(problem[i])==-2)
					{
						p1=k;
						i--;
					}
					num1[k/4]+=(j*problem[i]);
					j*=10;
					k++;
					if(k%4==0)
						j=1;
				}
			i=op+1;
		}
		else
		{
			if(char(problem[i])!=61 && char(problem[i])!=46)
				if(char(problem[i])<48 || char(problem[i])>57 )
				{
					c=false;
				}	
		}
		if(char(problem[i])==61)
		{
			int k=0;
			opp=i;
			i--;
				for(int j=1;i>op+b;i--)
				{
					if(char(problem[i])==-2)
					{
						p2=k;
						i--;
					}
					num2[k/4]+=(j*problem[i]);
					j*=10;
					k++;
					if(k%4==0)
						j=1;
				}
			i=opp;
			break;
		}
		problem[i]-=48;
	}

	if(char(problem[op])==45 || char(problem[op])==43) //baraye amaliat jam va menha jaye momayez do adad (dar soorat vojood) ra montabegh mikonim
	{
		if(p1>p2)
		{
			int k=p1-p2;
			for(int i=(op/4+1);i>=0;i--)
				num2[i+(k/4)]=num2[i];
			for(int i=0;i<(k/4);i++)
				num2[i]=0;
			if(k%4==1)
				for(int i=(op+k)/4+1;i>=0;i--)
				{
					num2[i+1]+=(num2[i]/1000);
					num2[i]=num2[i]%1000*10;
				}
			if(k%4==2)
				for(int i=(op+k)/4+1;i>=0;i--)
				{
					num2[i+1]+=(num2[i]/100);
					num2[i]=num2[i]%100*100;
				}
			if(k%4==3)
				for(int i=(op+k)/4+1;i>=0;i--)
				{
					num2[i+1]+=(num2[i]/10);
					num2[i]=num2[i]%10*1000;
				}
			p2=p1;
		}
		if(p2>p1)
		{
			int k=p2-p1;
			for(int i=(op/4+1);i>=0;i--)
				num1[i+(k/4)]=num1[i];
			for(int i=0;i<(k/4);i++)
				num1[i]=0;
			if(k%4==1)
				for(int i=(op+k)/4+1;i>=0;i--)
				{
					num1[i+1]+=(num1[i]/1000);
					num1[i]=num1[i]%1000*10;
				}
			if(k%4==2)
				for(int i=(op+k)/4+1;i>=0;i--)
				{
					num1[i+1]+=(num1[i]/100);
					num1[i]=num1[i]%100*100;
				}
			if(k%4==3)
				for(int i=(op+k)/4+1;i>=0;i--)
				{
					num1[i+1]+=(num1[i]/10);
					num1[i]=num1[i]%10*1000;
				}
			p1=p2;
		}
	}
	op=problem[op];	
	//az in ja be bad ba tavajoh be code aski operator ha vared yeki az shart ha mishavad 
	//amaliat jam va menha ba tavajoh ba alamat adad mitavanand be ham tabdil shavand pas dar ghesmat op==43 va op==45 dar halaat mokhtalef be tabe sahih erja dade mishavad
	//dar zarb va taghsim alamat rooye amaliat tasiri nadarad pas faghat dar soorat niaz alamat chap mishavad
	//bazi tavabe faghat baraye adad mosbat javab midahand pas dar soorat manfi boodan be jaye javab error chap mikonand
	fstream o;
	string ad="out.txt";
	o.open(ad.c_str(),ios::app);
	
	if(c)//c dar soorati ke hich caracter nashenasi yaft nashode bashad true ast
	{
	//chap soorat soal
	if(!alamat1)
		o<<"-";
	o.close();
	show(num1,p1);
	o.open(ad.c_str(),ios::app);
	o<<endl<<char(op)<<endl;
	if(!alamat2)
		o<<"-";
	o.close();
	show(num2,p2);
	o.open(ad.c_str(),ios::app);
	o<<endl<<"="<<endl;
	//----------------
	int result[r];
	int p;//tedad ragham ashaar javab
	//dar (op==43) va (op==45) har ja (int a) tarif kardam baraye komak be tashkis adad bozorgtar ast
	if(op==43)
	{
		p=p1;
		if(alamat1==alamat2)
			sum(num1 , num2 , result);
		if(!alamat1 & !alamat2)
			o<<"-";
		if(alamat1!=alamat2)
		{
			int a=0;
			for(int i=0;i<r;i++)
			{
				if(num1[i]>num2[i])
					a=1;
				if(num1[i]<num2[i])
					a=-1;
			}
		if(a==1)
		{
			if(alamat1==1)
				mine(num1 , num2 , result);
			else
			{
				mine(num1 , num2 , result);
				o<<"-";
			}
		}
		else
			mine(num2 , num1 , result);
		}
		o.close();
		show(result,p);
	}
	if(op==42)
	{
		p=p1+p2;
		if(alamat1!=alamat2)
			o<<"-";	
		multiply(num1 , num2 , result);
		o.close();
		show(result,p);
	}
	if(op==45)
	{
		p=p1;
		if(alamat1!=alamat2)
		{
			sum(num1 , num2 , result);
			if(alamat2)
				o<<"-";	
		}
		else
		{
			int a=0;
			for(int i=0;i<r;i++)
			{
				if(num1[i]>num2[i])
					a=1;
				if(num1[i]<num2[i])
					a=-1;
			}
			if(a==1)
			{
				if(alamat1==1)
					mine(num1 , num2 , result);
				else
				{
					mine(num1 , num2 , result);
					o<<"-";
				}
			}
			else
			{
				mine(num2 , num1 , result);
				o<<"-";
			}	
		}
		o.close();
		show(result,p);
	}
	if(op==47)
	{
		p=p1-p2;
		if(alamat1!=alamat2)
			o<<"-";	
		divide(num1 , num2 , result);
		o.close();
		show(result,p);
	}
	if(op==37)
	{
		if(p1!=0 ||p2!=0)
			o<<"error: this operator is used only for int. ";
		else if(!alamat1 | !alamat2)
			o<<"error: operator '%' is used only for positive numbers in this calculator. ";
		else
		{
			remainder(num1 , num2 , result);
			o.close();
			show(result,p);
		}
	}
	if(op==94)
	{
		if(p1!=0 ||p2!=0)
			o<<"error: this operator is used only for int. ";
		else if(!alamat2)
			o<<"error: this calculator can only take positive numbers after operator '^'.";
		else
		{
			if(!alamat1)
				if(num2[0]%2)
					o<<"-";
			expo(num1 , num2 , result);
			o.close();
			show(result,p);
		}
	}
	if(op==64)
    {
    	if(p1!=0 ||p2!=0)
			o<<"error: this operator is used only for int. ";
    	else if(!alamat1 | !alamat2)
			o<<"error: operator '@' is used only for positive numbers in this calculator. ";
		else
		{
			int qw=0;
			int ar[1000];
       		mabna (qw,ar,num1 , num2 , result);
		}
    }
	}
	else
		o<<"error: you  are using an undifined operator or symbol.";
}
//-------------------------------------------------------------------       
void show(int result[],int p)
{	//kar in tabe: chap adad  :)
	fstream o;
	string ad="out.txt";
	o.open(ad.c_str(),ios::app);
	
	if(p>0)
		if(!(p%4) && p!=4)
			p-=4;
	int i=0;//amalkard in moteghayer komak mikonad ke sefr haye ezafe samt chap adad chap nashavand
	for(int j=999;j>=0;j--)
	{
		//ghesmat chaap momayes
		if(p>0 && (((p/4)==j && p!=4) || ((p/4)-1==j && p==4)) )
		{
			if((p/4)==j && p!=4)
			{
				if(!(p%4))
					{
						if(i==0)
							o<<"0";
						o<<".";
						int k=1000;
						while(result[j]<k)
						{
							o<<"0";
							k/=10;
						}
						if(result[j])
							o<<result[j];
					}
				if((p%4)==1)
					{
						int k=100;
						while((result[j]/10)<k)
						{
							o<<"0";
							k/=10;
						}
						if(result[j]/10)
							o<<(result[j]/10);
						o<<".";
						o<<(result[j]%10);
					}
				if((p%4)==2)
					{
						if(result[j]/100<10)
							o<<"0";
						o<<(result[j]/100);
						o<<".";
						if(result[j]%100<10)
							o<<"0";
						o<<(result[j]%100);
					}
				if((p%4)==3)
					{
						o<<(result[j]/1000);	
						o<<".";
						int k=100;
						while((result[j]%1000)<k)
						{
							o<<"0";
							k/=10;
						}
						if(result[j]%1000)
							o<<(result[j]%1000);
					}
			}
			if((p/4)-1==j && p==4)
			{
				if(i==0)
						o<<"0";
					o<<".";
					int k=1000;
					while(result[j]<k)
					{
						o<<"0";
						k/=10;
					}
					if(result[j])
						o<<result[j];
			}
			i+=2;
		}
		//gesmat chap adad	
		else
		{
			if(result[j]>0)
				i++;
			if(i>0)
			{
				if(i>1)
				{
					int k=1000;
					while(result[j]<k)
					{
						o<<"0";
						k/=10;
					}
					if(result[j])
						o<<result[j];
				}
				if(i==1)
				{
					i++;
					o<<result[j];
				}
			}
		}
	}
	if(p<0)//manfi boodan tedad adaad bad az momayez be manie yek tedadi sefr jeloye addad hast - inja in sefr ha ra chap mikonim
	{
		p=-p;
		for(;p>0;p--)
			o<<"0";
	}
	if(i==0)
		o<<0;
}
//-------------------------------------------------------------------
void clean(char problem[])
{
	for(int i=0;i<1000;i++)
	{
		if(char(problem[i])==32)
			for(int j=i;j<(1000-i);j++)
			{
				problem[j]=problem[j+1];
				if(char(problem[i])==61)
					break;
			}
		if(char(problem[i])==61)
			break;
	}
}
//-------------------------------------------------------------------
