//Muhammad Farrukh Naveed       01-134211-056
//Muhammad Zain-Ul-Abideen      01-134211-072
//Muhammad Umer Ibrar           01-134211-096
//BS(CS)-5A
#include<iostream>
#include<fstream>
#include<string>

using namespace std;


char key;                            //char to read from file
string toCheck;                      //var and keyword check string
bool flag = 0;



fstream file("demo.txt", ios::in);                //file to be read
fstream symbol("table.txt", ios::out | ios::in);  //symbol table file to be created


//All the toke types
enum TokenType
{
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	LONG = 4,
	CHAR = 5,
	STRING = 6,
	BOOL = 7,
	VOID = 8,
	MAIN = 9,
	CLASS = 10,
	STRUCT = 11,
	ENUM = 12,
	PUBLIC = 13,
	PRIVATE = 14,
	PROTECTED = 15,
	UNSIGNED = 16,
	SIGNED = 17,
	TYPEDEF = 18,
	CONSTANT = 19,
	LITERAL = 20,
	USING = 21,
	NAMESPACE = 22,
	STD = 23,
	SCOPE_RESOLUTION = 24,
	DELETE = 25,
	VECTOR = 26,
	STACK = 27,
	LIST = 29,
	DEQUE = 30,
	THIS = 31,
	STATIC = 32,
	NEW = 33,
	FRIEND = 34,
	WHILE = 35,
	DO = 36,
	FOR = 37,
	CONST = 38,
	CONTINUE = 39,
	RETURN = 40,
	IDENTIFIER = 41,
	SEMICOLON = 42,
	COLON = 43,
	IF = 44,
	ELSE = 45,
	SWITCH = 46,
	CASE = 47,
	LESS_THAN = 48,
	GREATER_THAN = 49,
	LESS_THAN_EQUALS_TO = 50,
	GREATER_THAN_EQUALS_TO = 51,
	DEFAULT = 52,
	EQUAL = 53,
	EQUAL_EQUAL = 54,
	NOT = 55,
	NOT_EQUALS_TO = 56,
	INSERTION = 57,
	EXERTION = 58,
	AND = 59,
	OR = 60,
	BITWISE_AND = 61,
	BITWISE_OR = 62,
	PLUS = 63,
	MULTIPLY = 64,
	ADDITION = 65,
	DOT = 66,
	MINUS = 67,
	INCREMENT = 68,
	DECREMENT = 69,
	DIVIDE = 70,
	BREAK = 71,
	LEFT_ROUND_BRACES = 72,
	RIGHT_ROUND_BRACES = 73,
	LEFT_CURLY_BRACES = 74,
	RIGHT_CURLY_BRACES = 75,
	LEFT_SQUARE_BRACES = 76,
	RIGHT_SQUARE_BRACES = 77,
	COUT = 78,
	CIN = 79,
	MODULUS = 80,
	GARBAGE = 81
};

struct Token
{
	int value = 0;
	string Token_name = "";
	TokenType tok = GARBAGE;
};

Token ret;

Token lexical()
{
	Token mytoken;

	if (!file.is_open() && !symbol.is_open())
	{
		cout << "\nFiles Do Not exist\n";
		exit(0);
	}

	while (file.get(key))
	{
		if (key == ' ' || key == '\n' || key == 9)
		{
			if (file.eof()) exit(0);
			else continue;
		}


		else if (key == '(')
		{
			mytoken.Token_name = "Left Round Braces";
			mytoken.tok = LEFT_ROUND_BRACES;
			return mytoken;
		}

		else if (key == ')')
		{
			mytoken.Token_name = "Right Round Braces";
			mytoken.tok = RIGHT_ROUND_BRACES;
			return mytoken;
		}

		else if (key == '[')
		{
			mytoken.Token_name = "Left Square Braces";
			mytoken.tok = LEFT_SQUARE_BRACES;
			return mytoken;
		}

		else if (key == ']')
		{
			mytoken.Token_name = "Right Square Braces";
			mytoken.tok = RIGHT_SQUARE_BRACES;
			return mytoken;
		}

		else if (key == '{')
		{
			mytoken.Token_name = "Left Curly Braces";
			mytoken.tok = LEFT_CURLY_BRACES;
			return mytoken;
		}

		else if (key == '}')
		{
			mytoken.Token_name = "Right Curly Braces";
			mytoken.tok = RIGHT_CURLY_BRACES;
			file.get(key);
			return mytoken;
		}

		else if (key == '<')
		{
			file.get(key);
			if (key == '<')
			{
				mytoken.Token_name = "Exertion";
				mytoken.tok = EXERTION;
				return mytoken;
			}
			else if (key == '=')
			{
				mytoken.Token_name = "Less than equals to";
				mytoken.tok = LESS_THAN_EQUALS_TO;
				return mytoken;
			}
			else
			{
				mytoken.tok = LESS_THAN;
				mytoken.Token_name = "Less than";
				return mytoken;
			}

		}

		else if (key == '>')
		{
			file.get(key);
			if (key == '>')
			{
				mytoken.Token_name = "Insertion";
				mytoken.tok = INSERTION;
				return mytoken;
			}
			else if (key == '=')
			{
				mytoken.Token_name = "Greater than equals to";
				mytoken.tok = GREATER_THAN_EQUALS_TO;
				return mytoken;
			}
			else
			{
				mytoken.tok = GREATER_THAN;
				mytoken.Token_name = "Greater than";
				return mytoken;
			}

		}

		else if (key == '!')
		{
			file.get(key);
			if (key == '=')
			{
				mytoken.Token_name = "Not Equals to";
				mytoken.tok = NOT_EQUALS_TO;
				return mytoken;
			}
			mytoken.tok = NOT;
			mytoken.Token_name = "NOT";
			return mytoken;
		}

		else if (key == '=')
		{
			file.get(key);
			if (key == '=')
			{
				mytoken.Token_name = "Equals Equals";
				mytoken.tok = EQUAL_EQUAL;
				return mytoken;
			}
			mytoken.tok = EQUAL;
			mytoken.Token_name = "Equal";
			return mytoken;
		}


		else if (key == '&')
		{
			file.get(key);
			if (key == '&')
			{
				mytoken.Token_name = "AND";
				mytoken.tok = AND;
				return mytoken;
			}
			mytoken.tok = BITWISE_AND;
			mytoken.Token_name = "Bitwise AND";
			return mytoken;
		}

		else if (key == '|')
		{
			file.get(key);
			if (key == '|')
			{
				mytoken.Token_name = "OR";
				mytoken.tok = OR;
				return mytoken;
			}
			mytoken.tok = BITWISE_OR;
			mytoken.Token_name = "Bitwise OR";
			return mytoken;
		}


		else if (key == '/')
		{
			file.get(key);
			if (key == '/')
			{
				while (key != '\n')
				{
					file.get(key);
				}
			}
			else
			{
				file.unget();
				mytoken.tok = DIVIDE;
				mytoken.Token_name = "Divide";
				return mytoken;
			}


		}

		else if (key == ';')
		{
			mytoken.tok = SEMICOLON;
			mytoken.Token_name = "Semi-Colon";
			return mytoken;
		}

		else if (key == ':')
		{
			file.get(key);
			if (key == ':')
			{
				mytoken.Token_name = "Scope Resolution Operator";
				mytoken.tok = SCOPE_RESOLUTION;
				return mytoken;
			}
			else
			{
				file.unget();
				mytoken.Token_name = "COLON";
				mytoken.tok = COLON;
				return mytoken;
			}

		}

		else if (key == '+')
		{
			file.get(key);
			if (key == '+')
			{
				mytoken.Token_name = "Increment";
				mytoken.tok = INCREMENT;
				return mytoken;
			}
			else
			{
				file.unget();
				mytoken.Token_name = "PLUS";
				mytoken.tok = PLUS;
				return mytoken;
			}

		}


		else if (key == '-')
		{
			file.get(key);
			if (key == '-')
			{
				mytoken.Token_name = "Decrement";
				mytoken.tok = DECREMENT;
				return mytoken;
			}
			mytoken.Token_name = "MINUS";
			mytoken.tok = MINUS;
			return mytoken;
		}



		else if (key == '*')
		{
			mytoken.Token_name = "MULTIPLY";
			mytoken.tok = MULTIPLY;
			return mytoken;
		}

		else if (key == '%')
		{
			mytoken.Token_name = "MODULUS";
			mytoken.tok = MODULUS;
			return mytoken;
		}

		else if (isdigit(key))
		{
			string val = "";
			file.unget();
			if (!isalpha(key))
			{
				file.get(key);
				while (isdigit(key))
				{
					val += key;
					file.get(key);
				}
				file.unget();
				mytoken.value = stoi(val);
				mytoken.tok = CONSTANT;
				mytoken.Token_name = "Constant";
				return mytoken;
			}
		}


		else if (key == '"')
		{
			file.get(key);
			while (key != '"')
			{
				file.get(key);
			}
			mytoken.tok = LITERAL;
			mytoken.Token_name = "literal";
			return mytoken;
		}


		else
		{

			while (isalpha(key) || isdigit(key))
			{
				toCheck.push_back(key);
				file.get(key);
			}
			file.unget();
			if (toCheck == "float")
			{
				mytoken.Token_name = "float";
				mytoken.tok = FLOAT;
				toCheck.clear();
				return mytoken;
			}
			else if (toCheck == "int")
			{
				mytoken.Token_name = "int";
				mytoken.tok = INT;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "cout")
			{
				mytoken.Token_name = "cout";
				mytoken.tok = COUT;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "cin")
			{
				mytoken.Token_name = "cin";
				mytoken.tok = CIN;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "char")
			{
				mytoken.Token_name = "char";
				mytoken.tok = CHAR;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "double")
			{
				mytoken.Token_name = "double";
				mytoken.tok = DOUBLE;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "long")
			{
				mytoken.Token_name = "long";
				mytoken.tok = LONG;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "if")
			{
				mytoken.Token_name = "if";
				mytoken.tok = IF;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "main")
			{
				mytoken.Token_name = "main";
				mytoken.tok = MAIN;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "return")
			{
				mytoken.Token_name = "return";
				mytoken.tok = RETURN;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "else")
			{
				mytoken.Token_name = "else";
				mytoken.tok = ELSE;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "do")
			{
				mytoken.Token_name = "do";
				mytoken.tok = DO;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "while")
			{
				mytoken.Token_name = "while";
				mytoken.tok = WHILE;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "default")
			{
				mytoken.Token_name = "default";
				mytoken.tok = DEFAULT;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "case")
			{
				mytoken.Token_name = "case";
				mytoken.tok = CASE;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "bool")
			{
				mytoken.Token_name = "bool";
				mytoken.tok = BOOL;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "string")
			{
				mytoken.Token_name = "string";
				mytoken.tok = STRING;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "using")
			{
				mytoken.Token_name = "using";
				mytoken.tok = USING;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "namespace")
			{
				mytoken.Token_name = "namespace";
				mytoken.tok = NAMESPACE;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "std")
			{
				mytoken.Token_name = "std";
				mytoken.tok = STD;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "this")
			{
				mytoken.Token_name = "this";
				mytoken.tok = THIS;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "unsigned")
			{
				mytoken.Token_name = "unsigned";
				mytoken.tok = UNSIGNED;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "signed")
			{
				mytoken.Token_name = "signed";
				mytoken.tok = UNSIGNED;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "switch")
			{
				mytoken.Token_name = "switch";
				mytoken.tok = SWITCH;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "void")
			{
				mytoken.Token_name = "void";
				mytoken.tok = VOID;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "class")
			{
				mytoken.Token_name = "class";
				mytoken.tok = CLASS;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "enum")
			{
				mytoken.Token_name = "enum";
				mytoken.tok = ENUM;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "struct")
			{
				mytoken.Token_name = "struct";
				mytoken.tok = STRUCT;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "public")
			{
				mytoken.Token_name = "public";
				mytoken.tok = PUBLIC;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "protected")
			{
				mytoken.Token_name = "protected";
				mytoken.tok = PROTECTED;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "public")
			{
				mytoken.Token_name = "public";
				mytoken.tok = PUBLIC;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "private")
			{
				mytoken.Token_name = "private";
				mytoken.tok = PRIVATE;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "friend")
			{
				mytoken.Token_name = "friend";
				mytoken.tok = FRIEND;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "new")
			{
				mytoken.Token_name = "new";
				mytoken.tok = NEW;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "delete")
			{
				mytoken.Token_name = "delete";
				mytoken.tok = DELETE;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "VECTOR")
			{
				mytoken.Token_name = "VECTOR";
				mytoken.tok = VECTOR;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "DEQUE")
			{
				mytoken.Token_name = "DEQUE";
				mytoken.tok = DEQUE;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "LIST")
			{
				mytoken.Token_name = "LIST";
				mytoken.tok = LIST;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "const")
			{
				mytoken.Token_name = "const";
				mytoken.tok = CONST;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "typedef")
			{
				mytoken.Token_name = "typedef";
				mytoken.tok = TYPEDEF;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "continue")
			{
				mytoken.Token_name = "continue";
				mytoken.tok = CONTINUE;
				toCheck.clear();
				return mytoken;
			}

			else if (toCheck == "break")
			{
				mytoken.Token_name = "break";
				mytoken.tok = BREAK;
				toCheck.clear();
				return mytoken;
			}

			else
			{

				mytoken.Token_name = "identifier";
				mytoken.tok = IDENTIFIER;
				symbol << toCheck << endl;
				toCheck.clear();
				return mytoken;
			}

		}


	}


}

void ungettoken()
{
	flag = 1;
}



Token gettoken()
{
	if (!flag)
	{
		ret = lexical();
		return ret;
	}
	else return ret;

}

bool farrukhH()
{
	Token t;
	t = gettoken();
	if (t.tok == IDENTIFIER || t.tok == CONSTANT) return true;
	else return false;
}


bool farrukhG()
{
	Token t;
	do
	{
		if (!farrukhH())
		{
			return false;
		}

		t = gettoken();
	} while (t.tok == MULTIPLY || t.tok == DIVIDE || t.tok == MODULUS);
	ungettoken();
	return true;
}

bool farrukhF()
{
	Token t;
	do
	{
		if (!farrukhG())
		{
			return false;
		}

		t = gettoken();
	} while (t.tok == PLUS || t.tok == MINUS);
	ungettoken();
	return true;
}

bool farrukhE()
{
	Token t;
	do
	{
		if (!farrukhF())
		{
			return false;
		}

		t = gettoken();
	} while (t.tok == INSERTION || t.tok == EXERTION);
	ungettoken();
	return true;
}

bool farrukhD()
{
	Token t;
	do
	{
		if (!farrukhE())
		{
			return false;
		}

		t = gettoken();
	} while (t.tok == LESS_THAN || t.tok == LESS_THAN_EQUALS_TO || t.tok == GREATER_THAN || t.tok == GREATER_THAN_EQUALS_TO);
	ungettoken();
	return true;
}

bool farrukhC()
{
	Token t;
	do
	{
		if (!farrukhD())
		{
			return false;
		}

		t = gettoken();
	} while (t.tok == EQUAL_EQUAL || t.tok == NOT_EQUALS_TO);
	ungettoken();
	return true;
}

bool farrukhB()
{
	Token t;
	do
	{
		if (!farrukhC())
		{
			return false;
		}

		t = gettoken();
	} while (t.tok == AND);
	ungettoken();
	return true;

}


bool farrukhA()
{
	Token t;
	do
	{
		if (!farrukhB())
		{
			return false;
		}
		t = gettoken();

	} while (t.tok == OR);
	ungettoken();
	return true;
}


int main()
{
	if (farrukhA())
	{
		cout << "\nSyntax Correct";
	}

	else cout << "\nIncorrect syntax";

	cout << endl << endl;
	system("pause");
	return 0;
}
