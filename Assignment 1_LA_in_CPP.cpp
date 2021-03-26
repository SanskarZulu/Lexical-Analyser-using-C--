//Lexical Analyser implementation in C++ for C++ tokens analysis

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//this is a function which returns 1 if buffer is one of the following function
int isFunction(string buffer)
{
	//Pre-defined functions
	string funName[5] = {"printf","scanf", "cin", "cout"};
	int flag = 0;
	for(int i = 0; i < 5; ++i)
	{
		if(funName[i] == buffer)
		{
			flag = 1;//buffer is a pre-defined function
			break;
		}
	}
	return flag;
}

//this is a function which returns 1 if buffer is one of the following keyword
int isKeyword(string buffer)
{
	//Buffer is a Keyword in C++
	string keywords[63] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while",
							"asm",	"dynamic_cast",	"namespace","reinterpret_cast",	"bool"
							"explicit",	"new",	"static_cast",	"false",	"catch",
							"operator",	"template",	"friend",	"private",	"class",
							"this",	"inline",	"public",	"throw",	"const_cast",
							"delete",	"mutable",	"protected",	"true",	"try",
							"typeid",	"typename",	"using",	"virtual",	"wchar_t"
						};
	int flag = 0;
	
	for(int i = 0; i < 63; ++i)
	{
		if(keywords[i] == buffer)
		{
			flag = 1;//keyword found
			break;
		}
	}
	
	return flag;
}

//this is a function which returns 1 if buffer is one of the following prefix
int isPrefix(string buffer)
{
	
	string prefix[3] = {"std","chrono"};
	int flag = 0;
	
	for(int i = 0; i < 2; ++i)
	{
		if(prefix[i] == buffer)
		{
			flag = 1;//prefix found
			break;
		}
	}
	
	return flag;
}
 
int main()
{
	char ch;
	string buffer = "";//iterate over tokens of the text file
	string operators = "+-*/%=";//operators
	string num = "0123456789";//numbers
	ifstream fin("program.txt");

	int j=0;
	cout<<"\n\t\tCOMPILER DESIGN: Assignment 1\n\t";
	cout<<"Lexical Analyser implementation in C++ for C++ tokens analysis\n\n";
	if(!fin.is_open())
	{
		cout<<"\tError occured while opening the file!\n";
		exit(0);
	}
	
	int stringFlag = 0;

	while(!fin.eof())
	{
   		ch = fin.get();
   		
		for(int i = 0; i < 6; i++)
		{
   			if(ch == operators[i])
			{
   			   	cout<<"\t"<<ch<<"\t\t\t is a OPERATOR\n";
   				continue;
   			}
   		}

   		for(int i = 0; i < 10; i++)
		{
   			if(ch == num[i])
			{
   			   	cout<<"\t"<<ch<<"\t\t\t is a NUMBER\n";
   				continue;
   			}
   		}
   		
   		if(ch == ';')
		{
   			cout<<"\t"<<ch<<"\t\t\t is a SEPARATOR\n";
   			continue;
   		}

   		if(ch == '{')
		{
   			cout<<"\t"<<ch<<"\t\t\t is a OPEN CURLY BRACKET\n";
   			continue;
   		}

   		if(ch == '}')
		{
   			cout<<"\t"<<ch<<"\t\t\t is a CLOSE CURLY BRACKET\n";
   			continue;
   		}

   		if(ch == '(')
		{
   			cout<<"\t"<<ch<<"\t\t\t is a OPEN BRACKET\n";
   			continue;
   		}

   		if(ch == ')')
		{
   			cout<<"\t"<<ch<<"\t\t\t is a CLOSED BRACKET\n";
   			continue;
   		}


   		if(ch == '\"' || ch == '#' || ch == '<'|| ch == '>'|| ch == '.' || isalnum(ch))
		{
   			buffer += ch;
   		}
   		else if((ch == ' ' || ch == '\n' || ch == ';') && (buffer.length() != 0))
		{
   				// buffer += '\0';
   				// j = 0;
   				if(isKeyword(buffer) == 1)
				{
   					cout<<"\t"<<buffer<<"\t\t\t is a KEYWORD\n";
   				}
   				else if(isPrefix(buffer) == 1)
				{
   					cout<<"\t"<<buffer<<"\t\t\t is a PREFIX\n";
   				}
   				else if(isFunction(buffer) == 1)
				{
   					cout<<"\t"<<buffer<<"\t\t\t is a FUNCTION\n";
   				}
   				else if(buffer[0] == '\"')
				{
   					cout<<"\t"<<buffer<<"\t\t\t is a STRING\n";
   				}
   				else if(buffer[0] == '#')
				{
   					cout<<"\t"<<buffer<<"\t\t\t is a HEADER FILE\n";
   				}
   				else
				{
   					cout<<"\t"<<buffer<<"\t\t\t is a IDENTIFIER/VARIABLE\n";
   				}
   				buffer = "";
   		}
   		
	}
	
	fin.close();
	
	return 0;
}
