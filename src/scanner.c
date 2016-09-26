#include "scanner.h"

ArrToken X;

boolean IsVar(char CC)
{
	if ((CC=='+') || (CC=='-') || (CC=='*') || (CC=='<') || (CC=='>') || (CC=='='))
	{
		return false;
	}
	else
	{
		return true;
	}
}

boolean IsBilangan(char CC)
{
	if ((CC>='0') &&(CC<='9'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

boolean IsStringBilangan(char C[])
{
	boolean found;
	int i;
	i=0;
	found=false;
	while ((C[i]!='\0') && (!found))
	{
		if (!IsBilangan(C[i]))
		{
			found=true;
		} else
		{
			i++;
		}
	}
	if (found)
	{
		return false;
	}
	else
	{
		return true;
	}
}

boolean IsLogic(char C[])
{
	int num;
	num = strlen(C);
	if (num==2)
	{
		if ((((C[0]=='<')||(C[0]=='>')) && (C[1]=='=')) || ((C[0]=='<') && (C[1]=='>')))
		{
			return true;
		}
		else
		{
			return false;
		}
	} else if (num==1)
	{
		if ((C[0]=='<') || (C[0]=='>'))
		{
			return true;
		}
		else
		{
			return false;
		}
	} else
	{
		return false;
	}
}

void scanner()
{
	char Temp[30];
	int i,j,baris;
	START();
	i=0;
	baris=1;
	while (!EOP)
	{
		if (CC=='(')
		{
			X.Tab[i]='(';
			X.baris[i]=baris;
			i++;
			ADV();
		} else if (CC==')')
		{
			X.Tab[i]=')';
			X.baris[i]=baris;
			i++;
			ADV();
		}
		else if (CC=='\n')
		{
			baris++;
			ADV();
		} else if (CC=='b')
		{
			j=0;
			while ((CC!=' ') && (CC!='(')&& (CC!=')')&&(CC!='\n') && (CC!=EOF))
			{
				Temp[j]=CC;
				ADV();
				j++;
			}
			Temp[j]='\0';
			if (strcmp(Temp,"begin")==0)
			{
				X.Tab[i]='b';
				X.baris[i]=baris;
				i++;
			}
			else
			{
				X.Tab[i]='v';
				X.baris[i]=baris;
				i++;
			}
		} else if (CC=='e')
		{
			j=0;
			while ((CC!=' ') && (CC!='(') && (CC!=')') && (CC!='\n') && (CC!=EOF))
			{
				Temp[j]=CC;
				ADV();
				j++;
			}
			Temp[j]='\0';
			if (strcmp(Temp,"end")==0)
			{
				X.Tab[i]='e';
				X.baris[i]=baris;
				i++;
			}
			else if (strcmp(Temp,"else")==0)
			{
				X.Tab[i]='l';
				X.baris[i]=baris;
				i++;
			} else
			{
				X.Tab[i]='v';
				X.baris[i]=baris;
				i++;
			}
		} else if (CC=='i')
		{
			j=0;
			while ((CC!='(') && (CC!=' ') && (CC!=')') &&(CC!='\n') && (CC!=EOF))
			{
				Temp[j]=CC;
				ADV();
				j++;
			}
			Temp[j]='\0';
			if (strcmp(Temp,"if")==0)
			{
				X.Tab[i]='i';
				X.baris[i]=baris;
				i++;
			} else if (strcmp(Temp,"input")==0)
			{
				X.Tab[i]='n';
				X.baris[i]=baris;
				i++;
			} else
			{
				X.Tab[i]='v';
				X.baris[i]=baris;
				i++;
			}
		} 
		else if (CC=='d')
		{
			j=0;
			while ((CC!=' ') && (CC!='(') && (CC!=')') && (CC!='\n') && (CC!=EOF))
			{
				Temp[j]=CC;
				ADV();
				j++;
			}
			Temp[j]='\0';
			if (strcmp(Temp,"do")==0)
			{
				X.Tab[i]='d';
				X.baris[i]=baris;
				i++;
			} else
			{
				X.Tab[i]='v';
				X.baris[i]=baris;
				i++;
			}
		}
		else if (CC=='f')
		{
			j=0;
			while ((CC!=' ') && (CC!='(') && (CC!=')') && (CC!='\n') && (CC!=EOF))
			{
				Temp[j]=CC;
				ADV();
				j++;
			}
			Temp[j]='\0';
			if (strcmp(Temp,"for")==0)
			{
				X.Tab[i]='f';
				X.baris[i]=baris;
				i++;
			} else
			{
				X.Tab[i]='v';
				X.baris[i]=baris;
				i++;
			}
		}
		else if (CC=='o')
		{
			j=0;
			while ((CC!='(') && (CC!=')')&&(CC!=' ') && (CC!='\n') && (CC!=EOF))
			{
				Temp[j]=CC;
				ADV();
				j++;
			}
			Temp[j]='\0';
			if (strcmp(Temp,"output")==0)
			{
				X.Tab[i]='o';
				X.baris[i]=baris;
				i++;
			} else
			{
				X.Tab[i]='v';
				X.baris[i]=baris;
				i++;
			}
		}
		else if ((CC=='w'))
		{
			j=0;
			while ((CC!='(') && (CC!=')') &&(CC!=' ') && (CC!='\n') && (CC!=EOF))
			{
				Temp[j]=CC;
				ADV();
				j++;
			}
			Temp[j]='\0';
			if (strcmp(Temp,"while")==0)
			{
				X.Tab[i]='w';
				X.baris[i]=baris;
				i++;
			} else
			{
				X.Tab[i]='v';
				X.baris[i]=baris;
				i++;
			}
		}
		else if ((CC=='t'))
		{
			j=0;
			while ((CC!='(') && (CC!=')')&&(CC!=' ') && (CC!='\n') && (CC!=EOF))
			{
				Temp[j]=CC;
				ADV();
				j++;
			}
			Temp[j]='\0';
			if (strcmp(Temp,"to")==0)
			{
				X.Tab[i]='t';
				X.baris[i]=baris;
				i++;
			}
			else if (strcmp(Temp,"then")==0)
			{
				X.Tab[i]='h';
				X.baris[i]=baris;
				i++;
			} else
			{
				X.Tab[i]='v';
				X.baris[i]=baris;
				i++;
			}
		} 
		else if ((CC=='\t') || (CC==' '))
		{
			while (((CC=='\t') || (CC==' ')) && (CC!=EOF))
			{
				ADV();
			}
		} else if (CC=='{')
		{
			while ((CC!='}') && (CC!=EOF))
			{
				if (CC=='\n')
				{
					baris++;
				}
				ADV();
			}
			if (CC=='}')
			{
				ADV();
			}
		} else if(IsBilangan(CC))
		{
			j=0;
			while ((CC!=EOF)&&(CC!=' ') &&(CC!=')')&&(CC!='\n'))
			{
				Temp[j]=CC;
				ADV();
				j++;
			}
			Temp[j]='\0';
			if (IsStringBilangan(Temp))
			{
				X.Tab[i]='c';
				X.baris[i]=baris;
				i++;
			} else
			{
				X.Tab[i]='z'; // unknown identifier
				X.baris[i]=baris;
				i++;
			}
		} else if ((CC=='+')||(CC=='-')||(CC=='*'))
		{
			X.Tab[i]='a';
			X.baris[i]=baris;
			ADV();
			i++;
		} else if ((CC=='<') || (CC=='>'))
		{
			j=0;
			while ((CC=='<') || (CC=='>') || (CC=='='))
			{
				Temp[j]=CC;
				ADV();
				j++;
			}
			Temp[j]='\0';
			if (IsLogic(Temp))
			{
				X.Tab[i]='x';
				X.baris[i]=baris;
				i++;
			} else
			{
				X.Tab[i]='z'; //unknown var
				X.baris[i]=baris;
				i++;
			}
		} else if (CC=='=')
		{
			ADV();
			X.Tab[i]='=';
			X.baris[i]=baris;
			i++;
		}
		else
		{
			while((!EOP) && (CC!=' ') && (CC!='\n') && (CC!='(')&&(CC!=')') && (IsVar(CC)))
			{
				ADV();
			}
			X.Tab[i]='v';
			X.baris[i]=baris;
			i++;
		}
	}
}

void InitialToken()
{
	int i;
	for (i=0;i<=ELMAX-1;i++)
	{
		X.Tab[i]='|';
		X.baris[i]=1;
	}
}
