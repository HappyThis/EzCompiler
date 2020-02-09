%{
#include"Type.h"
#include"EzCompiler.h"
#include"string.h"
%}
%s comment
%%

\/\/.*
"/*"	BEGIN(comment);

<comment>[^*\n]*
<comment>"*"+[^*/\n]*
<comment>"*"+"/"	BEGIN(INITIAL);

[0-9]+\.[0-9]+	{
//	printf("V_DOUBLE:%s\n",yytext);
	yylval.V_DOUBLE=atof(yytext);
	return V_DOUBLE;
}
[0-9]+	{
//	printf("V_INT:%s\n",yytext);
	yylval.V_INT=atoi(yytext);
	return V_INT;
}
\"(\\[abfnrtv\\\"\'?0]|[^\\^\"])*\"	{
//	printf("V_STRING:%s\n",yytext);
	int leng=0;
	for(int i=1;i<yyleng-1;i++){
	if(yytext[i]=='\\'){

		switch(yytext[++i]){

		case 'a':
		yylval.V_STRING[leng++]='\a';
		break;
		case 'b':
		yylval.V_STRING[leng++]='\b';
		break;
		case 'f':
		yylval.V_STRING[leng++]='\f';
		break;
		case 'n':
		yylval.V_STRING[leng++]='\n';
		break;
		case 'r':
		yylval.V_STRING[leng++]='\r';
		break;
		case 't':
		yylval.V_STRING[leng++]='\t';
		break;
		case 'v':
		yylval.V_STRING[leng++]='\v';
		break;
		case '\\':
		yylval.V_STRING[leng++]='\\';
		break;
		case '\"':
		yylval.V_STRING[leng++]='\"';
		break;
		case '\'':
		yylval.V_STRING[leng++]='\'';
		break;
		case '?':
		yylval.V_STRING[leng++]='\?';
		break;
		case '0':
		yylval.V_STRING[leng++]='\0';

		}

	}else{
	yylval.V_STRING[leng++]=yytext[i];
	}

	}
//	printf("LENTH:%d\n",leng);
	yylval.V_STRING[leng]='\0';
	return V_STRING;
}
(_|[a-zA-Z])[a-zA-Z0-9_]* {

if(strcmp(yytext,"int")==0){
//	printf("K_INT:%s\n",yytext);
	return K_INT;
}else if(strcmp(yytext,"char")==0){
//	printf("K_CHAR:%s\n",yytext);
	return K_CHAR;
}else if(strcmp(yytext,"double")==0){
//	printf("K_DOUBLE:%s\n",yytext);
	return K_DOUBLE;
}else if(strcmp(yytext,"bool")==0){
//	printf("K_BOOL:%s\n",yytext);
	return K_BOOL;
}else if(strcmp(yytext,"true")==0){
//	printf("K_TRUE:%s\n",yytext);
	yylval.K_TRUE=true;
	return K_TRUE;
}else if(strcmp(yytext,"false")==0){
//	printf("K_FALSE:%s\n",yytext);
	yylval.K_FALSE=false;
	return K_FALSE;
}else if(strcmp(yytext,"class")==0){
//	printf("K_CLASS:%s\n",yytext);
	return K_CLASS;
}else if(strcmp(yytext,"def")==0){
//	printf("K_PRIVATE:%s\n",yytext);
	return K_DEF;
}else if(strcmp(yytext,"if")==0){
//	printf("K_IF:%s\n",yytext);
	return K_IF;
}else if(strcmp(yytext,"else")==0){
//	printf("K_ELSE:%s\n",yytext);
	return K_ELSE;
}else if(strcmp(yytext,"break")==0){
//	printf("K_ELSE:%s\n",yytext);
	return K_BREAK;
}else if(strcmp(yytext,"return")==0){
//	printf("K_RETURN:%s\n",yytext);
	return K_RETURN;
}else if(strcmp(yytext,"continue")==0){
//	printf("K_CONTINUE:%s\n",yytext);
	return K_CONTINUE;
}else if(strcmp(yytext,"while")==0){
//	printf("K_WHILE:%s\n",yytext);
	return K_WHILE;
}else if(strcmp(yytext,"new")==0){
//	printf("K_WHILE:%s\n",yytext);
	return K_NEW;
}else{
//	printf("V_ID:%s\n",yytext);
	strcpy(yylval.V_ID,yytext);
	return V_ID;
}


}
'(\\[abfnrtv\\\"\'?0]|[^\\])' {
//	printf("V_CHAR:%s\n",yytext);
	if(yyleng<=3){
	yylval.V_CHAR=yytext[1];
	return V_CHAR;
	}
	switch(yytext[2]){

	case 'a':
	yylval.V_CHAR='\a';
	break;
	case 'b':
	yylval.V_CHAR='\b';
	break;
	case 'f':
	yylval.V_CHAR='\f';
	break;
	case 'n':
	yylval.V_CHAR='\n';
	break;
	case 'r':
	yylval.V_CHAR='\r';
	break;
	case 't':
	yylval.V_CHAR='\t';
	break;
	case 'v':
	yylval.V_CHAR='\v';
	break;
	case '\\':
	yylval.V_CHAR='\\';
	break;
	case '\"':
	yylval.V_CHAR='\"';
	break;
	case '\'':
	yylval.V_CHAR='\'';
	break;
	case '?':
	yylval.V_CHAR='\?';
	break;
	case '0':
	yylval.V_CHAR='\0';

	}
	return V_CHAR;
}
\{	{
//	printf("S_LBRACE:%s\n",yytext);
	return S_LBRACE;	
}
\}	{
//	printf("S_RBRACE:%s\n",yytext);
	return S_RBRACE;
}
\(	{
//	printf("S_LPAREN:%s\n",yytext);
	return S_LPAREN;
}
\)	{
//	printf("S_RPAREN:%s\n",yytext);
	return S_RPAREN;
}
\.	{
//	printf("S_POINT:%s\n",yytext);
	return S_POINT;
}
\;	{
//	printf("S_SEM:%s\n",yytext);
	return S_SEM;
}
\,	{
//	printf("S_COM:%s\n",yytext);
	return S_COM;
}
\>	{
//	printf("S_GT:%s\n",yytext);
	return S_LGT;
}
\>\=	{
//	printf("S_GE:%s\n",yytext);
	return S_LGE;
}
\<	{
//	printf("S_LT:%s\n",yytext);
	return S_LLT;
}
\<\=	{
//	printf("S_LE:%s\n",yytext);
	return S_LLE;
}
\=\=	{
//	printf("S_EQ:%s\n",yytext);
	return S_LEQ;
}
\!\=	{
//	printf("S_NE:%s\n",yytext);
	return S_LNE;
}
\&\&	{
//	printf("S_LAND:%s\n",yytext);
	return S_LAND;
}
\|\|	{
//	printf("S_LOR:%s\n",yytext);
	return S_LOR;
}
\!	{
//	printf("S_LNOT:%s\n",yytext);
	return S_LNOT;
}
\+	{
//	printf("S_ADD:%s\n",yytext);
	return S_ADD;
}
\-	{
	//printf("S_SUB:%s\n",yytext);
	return S_SUB;
}
\*	{
//	printf("S_MUL:%s\n",yytext);
	return S_MUL;
}
\/	{
//	printf("S_DIV:%s\n",yytext);
	return S_DIV;
}
\^	{
//	printf("S_XOR:%s\n",yytext);
	return S_XOR;
}
\~	{
//	printf("S_NOT:%s\n",yytext);
	return S_NOT;
}
\%	{
	return S_MOD;
}
\=	{
//	printf("S_ASSIGN:%s\n",yytext);
	return S_ASSIGN;
}
\&	{
//	printf("S_AND:%s\n",yytext);
	return S_AND;
}
\|	{
//	printf("S_OR:%s\n",yytext);
	return S_OR;
}
.
\n
%%

