%{
#include "lex.yy.c"
#include "SymbolTable.h"
#include "CodeContainer.h"
#include "FillBack.h"
#include "fstream"
static SymbolTable::SymbolTable* symbolTable;
static FillBack * fillBack;
static CodeContainer *codeContainer;
static int offset,preSize;
static bool createDomainTable;
void yyerror(char const *){
CodeContainer::codeContainer->Clear();
}
%}

%define api.value.type union
//         {	    }	     (	      )      ;	     .       ::    ,	
%token S_LBRACE S_RBRACE S_LPAREN S_RPAREN S_SEM S_POINT S_DCOLON S_COM
//	 +     -     *     /     &    |     ^    ~	=	%
%token S_ADD S_SUB S_MUL S_DIV S_AND S_OR S_XOR S_NOT S_ASSIGN S_MOD
//     == <  >  != <= >=  !   &&   ||	
%token S_LEQ S_LLT S_LGT S_LNE S_LLE S_LGE S_LNOT S_LAND S_LOR
// INTEGER
%token <int> V_INT
// DOUBLE
%token <double> V_DOUBLE
// CHAR
%token <char> V_CHAR
// BOOL
%token <bool> K_TRUE K_FALSE 
//STRING V_ID
%token <String> V_STRING V_ID
// CLASS PRIVATE PUBLIC FIELD STATIC
%token K_CLASS K_DEF K_CONTINUE K_BREAK K_RETURN K_IF K_WHILE K_ELSE K_INT K_DOUBLE K_BOOL K_CHAR K_STRING K_NEW

%right S_ASSIGN
%left S_LOR
%left S_LAND
%left S_OR
%left S_XOR
%left S_AND
%left S_LEQ S_LNE
%left S_LGE S_LGT S_LLE S_LLT
%left S_ADD S_SUB
%left S_MUL S_DIV S_MOD
%right NEGATIVE  S_NOT S_LNOT
%left S_POINT
%left S_LPAREN S_RPAREN
%left K_ELSE
%left K_NEW

%type <ExpInfo> exp

%type <String> val_type

%type <StringArray> id_list val_types informal_args

%type <ExpInfoArray> exps formal_args


%%
program:
	%empty
|
	program
	class
;

class:
	K_CLASS
	V_ID	{
    if (!symbolTable->CreateClassTable($2)) {
        printf("Error:Class <%s> already exists\n", $2);
        CodeContainer::codeContainer->Clear();YYERROR;
    }
}
	S_LBRACE
	dec_vars
	dec_funs
	S_RBRACE	{
}
;

dec_vars:
	%empty
|
	dec_vars
	dec_var

;
dec_var:
	val_type
	id_list	{
    if (symbolTable->InDomain()) {
        for (int i = 0; i < $2.size; i++) {
            if (symbolTable->InsertIntoCurrentDomainTable($2.strings[i], $1) == nullptr) {
		if(symbolTable->TestClass($1)){
		printf("Error:Domain variable <%s> already exists.\n",$2.strings[i]);
		}else{
                printf("Error:Class <%s> is not defined.\n",$1);
		}
                CodeContainer::codeContainer->Clear();YYERROR;
            }
        }
    } else {
        for (int i = 0; i < $2.size; i++) {
            if (symbolTable->InsertIntoCurrentVarTable($2.strings[i], SymbolTable::ClassTableItem::Field, $1) ==
                nullptr) {
		if(symbolTable->TestClass($1)){
		printf("Error:Class variable <%s> already exists.\n",$2.strings[i]);
		}else{
                printf("Error:Class <%s> is not defined.\n",$1);
		}
                CodeContainer::codeContainer->Clear();YYERROR;
            }
        }
    }
}
	S_SEM
;


id_list:
	
	id_list
	S_COM
	V_ID	{
    $$ = $1;
    strcpy($$.strings[$$.size++], $3);
}
|
	V_ID	{
    strcpy($$.strings[$$.size++],$1);
}
;

val_type:
	K_DOUBLE	{
    strcpy($$,"double");
}
|
	K_INT	{
    strcpy($$,"int");
}
|
	K_CHAR	{
    strcpy($$,"char");
}
|
	K_BOOL	{
    strcpy($$,"bool");
}
|
	K_STRING	{
    strcpy($$,"string");
}
|
	V_ID	{
    strcpy($$,$1);
}
;

dec_funs:
	%empty
|
	dec_funs
	dec_fun

;

dec_fun:
	K_DEF
	val_type
	V_ID
	S_LPAREN
	informal_args
	S_RPAREN	{
    symbolTable->CreateDomainTable();
    createDomainTable = false;
    SymbolTable::ClassTableItem *item = symbolTable->InsertIntoCurrentFunTable($3, SymbolTable::ClassTableItem::Field,
                                                                               $2, CodeContainer::codeContainer->Size());
    preSize=CodeContainer::codeContainer->Size();
    FillBack::fillBack->CreateReturnList(item);
    if (item == nullptr) {
        if(symbolTable->TestClass($2)){
            printf("Error:class function <%s> already exists.\n",$3);
        }else{
            printf("Error:class <%s> is not defined.\n",$2);
        }
        CodeContainer::codeContainer->Clear();YYERROR;
    }
    for (int i = 0; i < $5.size; i +=2) {
        if(strcmp($5.strings[i],"void")==0){
            printf("Error:<void> type cannot be used as a parameter type.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        item->AddArg($5.strings[i]);
        if (symbolTable->InsertIntoCurrentDomainTable($5.strings[i+1], $5.strings[i]) == nullptr) {
            if(symbolTable->TestClass($5.strings[i])){
                printf("Error:variable <%s> already exists in the formal parameter list.\n",$5.strings[i+1]);
            }else{
                printf("Error:class <%s> is not defined.\n",$5.strings[i]);
            }
            CodeContainer::codeContainer->Clear();YYERROR;
        }

    }	
}
	cmpd_stat	{
printf("func name %s\n",$3);
    if(strcmp($3,"main")==0){
	if (FillBack::fillBack->GetHeader() != nullptr) {
        printf("ERROR:main function redefinition.\n");
        CodeContainer::codeContainer->Clear();
        YYERROR;
    } else {
        FillBack::fillBack->SetHeader(symbolTable->FindFunFromClassTable("main")->GetEntryPoint(),symbolTable->GetClassSize());
    }

    }
    FillBack::fillBack->DistoryReturnList(CodeContainer::codeContainer->Size());
    if (CodeContainer::codeContainer->Size() == preSize ||
        CodeContainer::codeContainer->At(CodeContainer::codeContainer->Size() - 1)->op != RET) {
        printf("ERROR:missing return statement.\n");
        CodeContainer::codeContainer->Clear();YYERROR;

    }
}


;

informal_args:
	%empty{
$$.size=0;
}
|
	val_types	{
$$=$1;
}
;
val_types:
	val_type
	V_ID	{
    $$.size=0;
    strcpy($$.strings[$$.size++],$1);
    strcpy($$.strings[$$.size++],$2);
}
|
	
	val_types	
	S_COM	
	val_type
	V_ID	{
    $$=$1;
    strcpy($$.strings[$$.size++],$3);
    strcpy($$.strings[$$.size++],$4);
}
;


stat:
	S_SEM
|
	exp S_SEM	{symbolTable->ClearTempVarTable();}
|
	ctrl_stat
|
	cmpd_stat
;

ctrl_stat:
	K_WHILE
	S_LPAREN	{
    /*清空临时符号表*/
    symbolTable->ClearTempVarTable();
    /*开始进入翻译状态*/
    FillBack::fillBack->SetBoolTranslateState();
}
	exp	{
    /*如果不是过度表达式,将在此处被处理*/
    if ($4.expType != ETRANSIT) {
    	if ($4.expType == EUNKNOW) {
        if (!symbolTable->SearchVarInDomainAndClassTable($4.stringValue, &$4)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $4.stringValue);
            YYERROR;
        }
    	}
        Map newMap;
        newMap.startPointInReal = $4.startPoint + $4.length;
        /*因为要生成2条转换代码*/
        newMap.lengthInReal = 2;
        $4.length += 2;
        /*注意,不会在备份代码容器中生成代码*/
        $4.boolExpInfo = new BoolExpInfo();
        $4.boolExpInfo->mapStack.push(newMap);
        $4.boolExpInfo->tList.push_back(newMap.startPointInReal);
        $4.boolExpInfo->fList.push_back(newMap.startPointInReal + 1);
        CodeContainer::codeContainer->Insert(newMap.startPointInReal);
        CodeContainer::codeContainer->FillInOp(JNE, newMap.startPointInReal);
        switch ($4.expValueType) {
            case StringValue:
                printf("ERROR : while(string) is illegal.\n");
                YYERROR;
                break;
            case Void:
                printf("ERROR : while(void) is illegal.\n");
                YYERROR;
                break;
            case RefInStack:
                printf("ERROR : while(reference) is illegal.\n");
                YYERROR;
                break;
            case BoolInStack:
            case CharInStack:
            case IntInStack:
            case DoubleInStack:
            case BoolInHeap:
            case CharInHeap:
            case IntInHeap:
            case DoubleInHeap:
                CodeContainer::codeContainer->FillInArg1ParseMethod($4.agrParseMethod, newMap.startPointInReal);
                offset = $4.domainTableItem->GetOffsetInStack();
                CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *), newMap.startPointInReal);
                break;
            case BoolValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&$4.boolValue, sizeof(bool), newMap.startPointInReal);
                break;
            case CharValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&$4.charValue, sizeof(char), newMap.startPointInReal);
                break;
            case IntValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&$4.intValue, sizeof(int), newMap.startPointInReal);
                break;
            case DoubleValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&$4.doubleValue, sizeof(double), newMap.startPointInReal);
                break;
            default:;
        }
        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool, newMap.startPointInReal);
        offset = false;
        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(bool), newMap.startPointInReal);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal);
        CodeContainer::codeContainer->Insert(newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInOp(JMP, newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod, newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod, newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal + 1);
    }
}
	S_RPAREN	{
    /*关闭翻译状态*/
    FillBack::fillBack->ResetBoolTranslateState();
    FillBack::codeContainer->Clear();
    /*回填写表达式(真出口)*/
    for (int idx:$4.boolExpInfo->tList) {
        offset = CodeContainer::codeContainer->Size();
        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(int), idx);
    }
    /*启动break，continue翻译机制*/
    FillBack::fillBack->CreateBreakList();
    FillBack::fillBack->CreateContinueList();
}
	stat	{
    /*填入loop*/
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(JMP);
    CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
    CodeContainer::codeContainer->FillInArg3(&$4.startPoint, sizeof(int));
    /*回填表达式(假出口)*/
    for (int idx:$4.boolExpInfo->fList) {
        offset = CodeContainer::codeContainer->Size();
        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(int), idx);
    }
    /*回填break,continue*/
    FillBack::fillBack->DistoryBreakList(CodeContainer::codeContainer->Size());
    FillBack::fillBack->DistoryContinueList($4.startPoint);
}
|
	K_IF
	S_LPAREN	{
    /*清空临时符号表*/
    symbolTable->ClearTempVarTable();
    /*开始进入翻译状态*/
    FillBack::fillBack->SetBoolTranslateState();
}
	exp	{

    /*如果不是过度表达式,将在此处被处理*/

    if ($4.expType != ETRANSIT) {
        Map newMap;
        newMap.startPointInReal = $4.startPoint + $4.length;
        /*因为要生成2条转换代码*/
        newMap.lengthInReal = 2;
        $4.length += 2;
        /*注意,不会在备份代码容器中生成代码*/
        $4.boolExpInfo = new BoolExpInfo();
        $4.boolExpInfo->mapStack.push(newMap);
        $4.boolExpInfo->tList.push_back(newMap.startPointInReal);
        $4.boolExpInfo->fList.push_back(newMap.startPointInReal + 1);
        CodeContainer::codeContainer->Insert(newMap.startPointInReal);
        CodeContainer::codeContainer->FillInOp(JNE, newMap.startPointInReal);
        switch ($4.expValueType) {
            case StringValue:
                printf("ERROR : while(string) is illegal.\n");
                YYERROR;
                break;
            case Void:
                printf("ERROR : while(void) is illegal.\n");
                YYERROR;
                break;
            case RefInStack:
                printf("ERROR : while(reference) is illegal.\n");
                YYERROR;
                break;
            case BoolInStack:
            case CharInStack:
            case IntInStack:
            case DoubleInStack:
            case BoolInHeap:
            case CharInHeap:
            case IntInHeap:
            case DoubleInHeap:
                CodeContainer::codeContainer->FillInArg1ParseMethod($4.agrParseMethod, newMap.startPointInReal);
                offset = $4.domainTableItem->GetOffsetInStack();
                CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *), newMap.startPointInReal);
                break;
            case BoolValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&$4.boolValue, sizeof(bool), newMap.startPointInReal);
                break;
            case CharValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&$4.charValue, sizeof(char), newMap.startPointInReal);
                break;
            case IntValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&$4.intValue, sizeof(int), newMap.startPointInReal);
                break;
            case DoubleValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble, newMap.startPointInReal);
                CodeContainer::codeContainer->FillInArg1(&$4.doubleValue, sizeof(double), newMap.startPointInReal);
                break;
            default:;
        }
        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool, newMap.startPointInReal);
        offset = false;
        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(bool), newMap.startPointInReal);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal);
        CodeContainer::codeContainer->Insert(newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInOp(JMP, newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod, newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod, newMap.startPointInReal + 1);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal + 1);
    }

}
	S_RPAREN	{
    /*关闭翻译状态*/
    FillBack::fillBack->ResetBoolTranslateState();
    FillBack::codeContainer->Clear();
    /*回填写表达式(真出口)*/
    for (int idx:$4.boolExpInfo->tList) {
        offset = CodeContainer::codeContainer->Size();
        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(int), idx);
    }
    $4.boolExpInfo->tList.clear();
    
}
	stat	{
    /*生成一条jmp语句,并借用已经清空的tList*/
    $4.boolExpInfo->tList.push_back(CodeContainer::codeContainer->Size());
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(JMP);
    CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

}
	K_ELSE	{
    /*回填表达式(假出口)*/
    for (int idx:$4.boolExpInfo->fList) {
        offset = CodeContainer::codeContainer->Size();
        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(int), idx);
    }
}
	stat	{
    for (int idx:$4.boolExpInfo->tList) {
        offset = CodeContainer::codeContainer->Size();
        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(int), idx);
    }
}
|
	K_BREAK
	S_SEM	{
    if (!FillBack::fillBack->AddIntoBreakList(CodeContainer::codeContainer->Size())) {
        CodeContainer::codeContainer->Clear();
        printf("ERROR:The break statement must be in the while statement.\n");
        YYERROR;
    }
    /*语句生成*/
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(JMP);
    CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
}
|
	K_CONTINUE
	S_SEM	{
    if (!FillBack::fillBack->AddIntoContinueList(CodeContainer::codeContainer->Size())) {
        CodeContainer::codeContainer->Clear();
        printf("ERROR:The continue statement must be in the while statement.\n");
        YYERROR;
    }
    /*语句生成*/
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(JMP);
    CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
}
|
	K_RETURN {
symbolTable->ClearTempVarTable();
}
	exp	
	S_SEM	{
        if ($3.expType == EUNKNOW) {
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            YYERROR;
        }
    	}
    if (!FillBack::fillBack->AddIntoReturnList(CodeContainer::codeContainer->Size())) {
        CodeContainer::codeContainer->Clear();
        printf("ERROR:The return statement must be in the function.\n");
        YYERROR;
    }
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(RET);
    switch ($3.expValueType) {
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$3.boolValue, sizeof(bool));
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$3.charValue, sizeof(char));
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$3.intValue, sizeof(bool));
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&$3.doubleValue, sizeof(double));
            break;
        case StringValue:
            break;
        default:
            CodeContainer::codeContainer->FillInArg1ParseMethod($3.agrParseMethod);
            offset = $3.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
    }

    if (FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType() == "bool") {
        if ($3.expValueType == RefInStack) {
            printf("Unable to convert <%s> type to <bool> type.\n",
                   $3.domainTableItem->GetType().data());
            YYERROR;
        }
        CodeContainer::codeContainer->FillInArg2ParseMethod(CallToBool);

    } else if (FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType() == "char") {
        if ($3.expValueType == RefInStack) {
            printf("Unable to convert <%s> type to <char> type.\n",
                   $3.domainTableItem->GetType().data());
            YYERROR;
        }
        CodeContainer::codeContainer->FillInArg2ParseMethod(CallToChar);

    } else if (FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType() == "int") {
        if ($3.expValueType == RefInStack) {
            printf("Unable to convert <%s> type to <int> type.\n",
                   $3.domainTableItem->GetType().data());
            YYERROR;
        }
        CodeContainer::codeContainer->FillInArg2ParseMethod(CallToInt);

    } else if (FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType() == "double") {
        if ($3.expValueType == RefInStack) {
            printf("Unable to convert <%s> type to <double> type.\n",
                   $3.domainTableItem->GetType().data());
            YYERROR;
        }
        CodeContainer::codeContainer->FillInArg2ParseMethod(CallToDouble);

    } else if (FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType() == "void") {
        printf("ERROR:return value type is <void>.\n");
        YYERROR;
    } else {
        switch ($3.expValueType) {
            case RefInStack:
                if ($3.domainTableItem->GetType() != FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType()) {
                    printf("Unable to convert <%s> type to <%s> type.\n",
                           $3.domainTableItem->GetType().data(),
                           FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType().data());
                    YYERROR;
                    break;
                }
                CodeContainer::codeContainer->FillInArg2ParseMethod(CallToRef);
                break;
            case BoolValue:
            case BoolInStack:
            case BoolInHeap:
                printf("Unable to convert <bool> type to <%s> type.\n",
                       FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType().data());
                break;
            case CharValue:
            case CharInStack:
            case CharInHeap:
                printf("Unable to convert <char> type to <%s> type.\n",
                       FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType().data());
                break;
            case IntValue:
            case IntInStack:
            case IntInHeap:
                printf("Unable to convert <int> type to <%s> type.\n",
                       FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType().data());
                break;
            case DoubleValue:
            case DoubleInHeap:
            case DoubleInStack:
                printf("Unable to convert <double> type to <%s> type.\n",
                       FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType().data());
                break;
            case StringValue:
                break;
            default:

                YYERROR;
        }
    }
    CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
}
|
	K_RETURN {
    symbolTable->ClearTempVarTable();
    if (!FillBack::fillBack->AddIntoReturnList(CodeContainer::codeContainer->Size())) {
        CodeContainer::codeContainer->Clear();
        printf("ERROR:The return statement must be in the function.\n");
        YYERROR;
    }
    if(FillBack::fillBack->GetCurrentFuncInfo()->GetReturnType() != "void"){
        printf("ERROR:return value type is <void>.\n");
        CodeContainer::codeContainer->Clear();
        YYERROR;
    }
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(RET);
    CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
    CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
}	
	S_SEM
;

cmpd_stat:
	S_LBRACE	{
    if(createDomainTable==false){
        createDomainTable=true;
    } else {
        symbolTable->CreateDomainTable();
    }
}
	stats_decs
	S_RBRACE	{
    symbolTable->PopDomainTableStack();
}
;

stats_decs:
	%empty
|
	stats_decs
	stat
|
	stats_decs
	dec_var
;

exp:
	K_NEW	{
    FillBack::fillBack->SetNewTranslateState();
}
	exp	{
    FillBack::fillBack->ResetNewTranslateState();
    $$=$3;
    $$.expType=ENEW;
}
	
	
|
	exp
	S_ASSIGN
	exp	{
   int preLength = CodeContainer::codeContainer->Size();
    switch ($1.expType) {
        case EUNKNOW:

            if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
                printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            if (preLength < CodeContainer::codeContainer->Size()) {
                CodeContainer::codeContainer->Move($1.startPoint, preLength);
                $1.length++;
                $3.startPoint++;
                /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
                stack<Map> updateStack;
                while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                    $3.boolExpInfo->mapStack.top().startPointInReal++;
                    updateStack.push($3.boolExpInfo->mapStack.top());
                    $3.boolExpInfo->mapStack.pop();
                }
                while ($3.expType == ETRANSIT && !updateStack.empty()) {
                    $3.boolExpInfo->mapStack.push(updateStack.top());
                    updateStack.pop();
                }
                /*真假链条同时也需要更新*/
                if ($3.expType == ETRANSIT) {
                    list<int>::iterator it;
                    for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                        (*it)++;
                    }
                    for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                        (*it)++;
                    }
                }
            }
            break;
        case ECALL:
            printf("Error:left value of the = operation cannot be expression <call>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case ENEW:
            printf("Error:left value of the = operation cannot be expression <new>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case EARITH:
            printf("Error:left value of the = operation cannot be expression <arith>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case ETRANSIT:
            printf("Error:left value of the = operation cannot be expression <arith>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case EVALUE:
            printf("Error:left value of the = operation cannot be expression <value>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    if ($3.expType == EUNKNOW) {
        preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }
    if ($3.expType == ETRANSIT) {
        while (!$3.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                $3.boolExpInfo->mapStack.top().startPointInReal +
                                                $3.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $3.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                           $3.boolExpInfo->mapStack.top().startPointInBackup +
                                           $3.boolExpInfo->mapStack.top().lengthInBackup);
            $3.length -=
                    $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
            $3.boolExpInfo->mapStack.pop();

        }
    }
    $$.expType = EASSIGN;
    $$.length = $3.length + 1;
    $$.startPoint = $1.startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(ASG);
    offset = $1.domainTableItem->GetOffsetInStack();
    CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
    CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
    switch ($1.expValueType) {
        case RefInStack:
            switch ($3.expValueType) {
                case RefInStack:
                    if ($1.domainTableItem->GetType() != $3.domainTableItem->GetType()) {
                        printf("Error:If the lvalue type of the operation = is <reference>, the rvalue type of the operation = should be the same as the lvalue type.\n");
                        CodeContainer::codeContainer->Clear();YYERROR;
                        break;
                    }
                    $$.domainTableItem = symbolTable->CreateTempVar($3.domainTableItem->GetType(), &$$);
                    break;
                default:
                    printf("If the lvalue type of the operation = is <reference>, then the rvalue type of the operation = should be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
            }
            offset = $3.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
            break;
        case BoolInStack:
        case BoolInHeap:
            $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
            break;
        case CharInStack:
        case CharInHeap:
            $$.domainTableItem = symbolTable->CreateTempVar("char", &$$);
            break;
        case IntInStack:
        case IntInHeap:
            $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
            break;
        case DoubleInStack:
        case DoubleInHeap:
            $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
            break;
        default:;
    }

    switch ($3.expValueType) {
        case Void:
            printf("Error:the right value type of the = operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            if ($1.expValueType != RefInStack) {
                printf("Error:the right value type of the = operation cannot be <reference>.\n");
                CodeContainer::codeContainer->Clear();YYERROR;
            }

        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
        case DoubleInStack:
        case DoubleInHeap:
            offset = $3.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
            break;
        case StringValue:
            printf("Error:the right value type of the = operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
    offset = $$.domainTableItem->GetOffsetInStack();
    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));

}
|
	V_ID
	S_LPAREN	{
    FillBack::fillBack->SetInterruptState();
}
	formal_args
	S_RPAREN	{
    if (FillBack::fillBack->IsInterruptedTranslating()) {
        FillBack::fillBack->ResetInterrupt();
    }
    ExpInfo expInfo = symbolTable->GetExpItem();
    SymbolTable::DomainTableItem *domainTableItem = nullptr;
    SymbolTable::ClassTableItem *classTableItem = nullptr;
    $$.expType = ECALL;

    if (expInfo.length >= 0) {
        /*如果潜在环境是一个变量*/
        if (expInfo.expType == EUNKNOW) {

            if (!symbolTable->SearchVarInDomainAndClassTable(expInfo.stringValue, &expInfo)) {
                printf("ERROR:variable \"%s\" must be defined before use\n", expInfo.stringValue);
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            if (expInfo.startPoint + 1 == CodeContainer::codeContainer->Size()) {
                expInfo.length++;
                symbolTable->SetExpItem(expInfo);
            }
            domainTableItem=expInfo.domainTableItem;
            classTableItem = symbolTable->FindFunFromClassTable($1,
                                                                expInfo.domainTableItem->GetType());

            /*如果没找到,那么进行错误处理*/
            if (!classTableItem) {
                if (SymbolTable::JudgeTypeSize(expInfo.domainTableItem->GetType()) != -1) {
                    printf("ERROR:An expression of the form <%s>.%s(...) is not a call expression.\n",
                           expInfo.domainTableItem->GetType().data(), $1);
                    CodeContainer::codeContainer->Clear();YYERROR;
                } else if (!symbolTable->TestClass(expInfo.domainTableItem->GetType())) {
                    printf("ERROR:Class <%s> is not defined.\n", expInfo.domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                } else {
                    printf("ERROR:Member function <%s> is not found in class <%s>.\n", $1,
                           expInfo.domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                }
            }

        } else {

            domainTableItem = expInfo.domainTableItem;
            classTableItem = symbolTable->FindFunFromClassTable($1,
                                                                domainTableItem->GetType());
            if (!classTableItem) {
                if (SymbolTable::JudgeTypeSize(domainTableItem->GetType()) != -1) {
                    printf("ERROR:An expression of the form <%s>(...) is not a call expression.\n",
                           domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                } else if (!symbolTable->TestClass(domainTableItem->GetType())) {
                    printf("ERROR:Class <%s> is not defined.\n", domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                } else {
                    printf("ERROR:Member function <%s> is not found in class <%s>.\n", $1,
                           domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                }
            }
        }

    } else {
        /*没有潜在环境,但是也有可能是new表达式环境*/
        if (FillBack::fillBack->IsNewExpTranslating()) {
            if (!(classTableItem = symbolTable->FindFunFromClassTable($1, $1))) {
                printf("ERROR:Constructor function <%s> is not found\n", $1);
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            /*生成NEW表达式*/
            CodeContainer::codeContainer->PushBackCode();
            CodeContainer::codeContainer->FillInOp(NEW);
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            offset = symbolTable->GetClassSize($1);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(int));
            domainTableItem = symbolTable->CreateTempVar($1);
            offset = domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2ParseMethod(StackToRef_T);
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
        } else {
            if (!(classTableItem = symbolTable->FindFunFromClassTable($1))) {
                printf("ERROR:function <%s> is not found.\n", $1);
                CodeContainer::codeContainer->Clear();YYERROR;
            }
        }
    }
    if (classTableItem->GetAuth() == SymbolTable::ClassTableItem::Private) {
        printf("member function <%s> is of private and therefore cannot be accessed.\n", $1);
        CodeContainer::codeContainer->Clear();YYERROR;
    }

    if (classTableItem->GetArgc() != $4.size) {
        printf("The number of arguments to the <call> expression does not match.\n");
        CodeContainer::codeContainer->Clear();YYERROR;
    }
    if (expInfo.length < 0) {
        if (FillBack::fillBack->IsNewExpTranslating()) {
            $$.startPoint = CodeContainer::codeContainer->Size() - 1;
            $$.length = $4.size + 2;
        } else {
            $$.startPoint = CodeContainer::codeContainer->Size();
            $$.length = $4.size + 1;
        }

    } else {
        $$.startPoint = expInfo.startPoint;
        $$.length = $4.size + 1 + expInfo.length;
    }
    for (int i = 0; i < $4.size; i++) {

        if ($4.expInfos[i].expType == EUNKNOW &&
            !symbolTable->SearchVarInDomainAndClassTable($4.expInfos[i].stringValue,
                                                         &$4.expInfos[i])) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $4.expInfos[i].stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        }
        CodeContainer::codeContainer->PushBackCode();
        CodeContainer::codeContainer->FillInOp(PARAM);
        switch ($4.expInfos[i].expValueType) {
            case BoolValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
                CodeContainer::codeContainer->FillInArg1(&$4.expInfos[i].boolValue, sizeof(bool));
                break;
            case CharValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
                CodeContainer::codeContainer->FillInArg1(&$4.expInfos[i].charValue, sizeof(char));
                break;
            case IntValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
                CodeContainer::codeContainer->FillInArg1(&$4.expInfos[i].intValue, sizeof(bool));
                break;
            case DoubleValue:
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
                CodeContainer::codeContainer->FillInArg1(&$4.expInfos[i].doubleValue, sizeof(double));
                break;
            case StringValue:
                break;
            default:
                CodeContainer::codeContainer->FillInArg1ParseMethod($4.expInfos[i].agrParseMethod);
                offset = $4.expInfos[i].domainTableItem->GetOffsetInStack();
                CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
        }

        if (classTableItem->GetArg(i) == "bool") {
            if ($4.expInfos[i].expValueType == RefInStack) {
                printf("Unable to convert <%s> type to <bool> type.\n",
                       $4.expInfos[i].domainTableItem->GetType().data());
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(CallToBool);

        } else if (classTableItem->GetArg(i) == "char") {
            if ($4.expInfos[i].expValueType == RefInStack) {
                printf("Unable to convert <%s> type to <char> type.\n",
                       $4.expInfos[i].domainTableItem->GetType().data());
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(CallToChar);

        } else if (classTableItem->GetArg(i) == "int") {
            if ($4.expInfos[i].expValueType == RefInStack) {
                printf("Unable to convert <%s> type to <int> type.\n",
                       $4.expInfos[i].domainTableItem->GetType().data());
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(CallToInt);

        } else if (classTableItem->GetArg(i) == "double") {
            if ($4.expInfos[i].expValueType == RefInStack) {
                printf("Unable to convert <%s> type to <double> type.\n",
                       $4.expInfos[i].domainTableItem->GetType().data());
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(CallToDouble);

        } else if (classTableItem->GetArg(i) == "void") {
            printf("ERROR:<void> type cannot be used as a parameter type.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
        } else {
            switch ($4.expInfos[i].expValueType) {
                case RefInStack:
                    if ($4.expInfos[i].domainTableItem->GetType() != classTableItem->GetArg(i)) {
                        printf("Unable to convert <%s> type to <%s> type.\n",
                               $4.expInfos[i].domainTableItem->GetType().data(), classTableItem->GetArg(i).data());
                        CodeContainer::codeContainer->Clear();YYERROR;
                        break;
                    }
                    CodeContainer::codeContainer->FillInArg2ParseMethod(CallToRef);
                    break;
                case BoolValue:
                case BoolInStack:
                case BoolInHeap:
                    printf("Unable to convert <bool> type to <%s> type.\n", classTableItem->GetArg(i).data());
                    break;
                case CharValue:
                case CharInStack:
                case CharInHeap:
                    printf("Unable to convert <char> type to <%s> type.\n", classTableItem->GetArg(i).data());
                    break;
                case IntValue:
                case IntInStack:
                case IntInHeap:
                    printf("Unable to convert <int> type to <%s> type.\n", classTableItem->GetArg(i).data());
                    break;
                case DoubleValue:
                case DoubleInHeap:
                case DoubleInStack:
                    printf("Unable to convert <double> type to <%s> type.\n", classTableItem->GetArg(i).data());
                    break;
                case StringValue:
                    break;
                default:

                    CodeContainer::codeContainer->Clear();YYERROR;
            }
        }
    }

    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(CALL);
    CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
    offset = classTableItem->GetEntryPoint();
    CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
    offset = classTableItem->GetArgc();
    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
    if (FillBack::fillBack->IsNewExpTranslating()) {
        $$.domainTableItem = symbolTable->CreateTempVar($1, &$$);
    } else {
        if (classTableItem->GetReturnType() == "bool") {
            $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
        } else if (classTableItem->GetReturnType() == "char") {
            $$.domainTableItem = symbolTable->CreateTempVar("char", &$$);
        } else if (classTableItem->GetReturnType() == "int") {
            $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
        } else if (classTableItem->GetReturnType() == "double") {
            $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
        } else if (classTableItem->GetReturnType() == "void") {
            $$.domainTableItem = symbolTable->CreateTempVar("void", &$$);
        } else {
            $$.domainTableItem = symbolTable->CreateTempVar(classTableItem->GetReturnType(), &$$);
        }
    }
    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
    offset = $$.domainTableItem->GetOffsetInStack();
    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
    if (!domainTableItem) {
        CodeContainer::codeContainer->FillInArg4ParseMethod(StackToRef);
        CodeContainer::codeContainer->FillInArg4(0);
    } else {
        CodeContainer::codeContainer->FillInArg4ParseMethod(StackToRef_T);
        CodeContainer::codeContainer->FillInArg4(domainTableItem->GetOffsetInStack());
    }

}
|
	exp
	S_POINT	{
symbolTable->SetExpItem($1);
}
	exp	{

ExpInfo expInfo=symbolTable->GetExpItemAndClear();
    switch ($1.expType) {
        case EUNKNOW:
            if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
                printf("ERROR:variable <%s> must be defined before use\n", $1.stringValue);
                CodeContainer::codeContainer->Clear();YYERROR;
            }
	    if(expInfo.length==1){
		CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size()-1);
	    }
            break;
        case EARITH:
            printf("ERROR:left value of the . operation cannot be expression <arith>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case EVALUE:
            printf("ERROR:left value of the . operation cannot be expression <value>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    switch ($4.expType) {
        case EUNKNOW:
            $$.expType = EVISIT;
            $4.classTableItem = symbolTable->FindVarFromClassTable($4.stringValue, $1.domainTableItem->GetType());
            if ($4.classTableItem == nullptr) {
                if (SymbolTable::JudgeTypeSize($1.domainTableItem->GetType()) != -1) {
                    printf("ERROR:left value of the . operation cannot be Basic type <%s>.\n",
                           $1.domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                } else if (!symbolTable->TestClass($1.domainTableItem->GetType())) {
                    printf("ERROR:Class <%s> is not defined.\n", $1.domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                } else {
                    printf("ERROR:Member variable <%s> is not found in class <%s>.\n", $4.stringValue,
                           $1.domainTableItem->GetType().data());
                    CodeContainer::codeContainer->Clear();YYERROR;
                }
            }
            if ($4.classTableItem->GetAuth() == SymbolTable::ClassTableItem::Private) {
                printf("member variable <%s> is of private and therefore cannot be accessed.\n", $4.stringValue);
                CodeContainer::codeContainer->Clear();YYERROR;
            }
            CodeContainer::codeContainer->PushBackCode();
            CodeContainer::codeContainer->FillInOp(ADD);
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
            offset = $4.classTableItem->GetOffset();
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));

            if ($4.classTableItem->GetVarType() == "bool") {
                $$.domainTableItem = symbolTable->CreateTempVar("@r-bool", &$$);
                CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToBool_T);
            } else if ($4.classTableItem->GetVarType() == "char") {
                $$.domainTableItem = symbolTable->CreateTempVar("@r-char", &$$);
                CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToChar_T);
            } else if ($4.classTableItem->GetVarType() == "int") {
                $$.domainTableItem = symbolTable->CreateTempVar("@r-int", &$$);
                CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToInt_T);
            } else if ($4.classTableItem->GetVarType() == "double") {
                $$.domainTableItem = symbolTable->CreateTempVar("@r-double", &$$);
                CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToDouble_T);
            } else {
                $$.domainTableItem = symbolTable->CreateTempVar($4.classTableItem->GetVarType(), &$$);
                CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToRef_T);
            }

            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case ECALL:
            $$ = $4;
            $$.startPoint = $1.startPoint;
            $$.length += $1.length;
            break;
        default:
            printf("ERROR:right value of the . operation must be <identifier>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;

    }
}
|
	exp
	S_LLT
	exp	{
    if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        $$.expType = ETRANSIT;
        if ($3.expType == ETRANSIT) {
            while (!$3.boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                    $3.boolExpInfo->mapStack.top().startPointInReal +
                                                    $3.boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                     $3.boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                               $3.boolExpInfo->mapStack.top().startPointInBackup +
                                               $3.boolExpInfo->mapStack.top().lengthInBackup);
                $3.length -=
                        $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
                $3.boolExpInfo->mapStack.pop();

            }
        }
        if ($1.expType == ETRANSIT) {
            while (!$1.boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInReal,
                                                    $1.boolExpInfo->mapStack.top().startPointInReal +
                                                    $1.boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert($1.boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     $1.boolExpInfo->mapStack.top().startPointInBackup,
                                                     $1.boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInBackup,
                                               $1.boolExpInfo->mapStack.top().startPointInBackup +
                                               $1.boolExpInfo->mapStack.top().lengthInBackup);
                $1.length -=
                        $1.boolExpInfo->mapStack.top().lengthInReal - $1.boolExpInfo->mapStack.top().lengthInBackup;
                $1.boolExpInfo->mapStack.pop();
            }
        }
        $$.length = $1.length + $3.length + 2;
        $$.startPoint = $1.startPoint;
        /*实例化*/
        $$.boolExpInfo = new BoolExpInfo();
        /*填充信息,表示此表达式从CodeContainer的当前位置开始翻译,并且一定会生成两条代码*/
        Map newMap;
        newMap.startPointInReal = CodeContainer::codeContainer->Size();
        newMap.lengthInReal = 2;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        $$.boolExpInfo->mapStack.push(newMap);
        /*算术计算代码翻译到备用代码容器*/
        FillBack::codeContainer->PushBackCode();
        /*<=*/
        FillBack::codeContainer->FillInOp(LLT);
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(JLT);
        /*之后会再生成一条无条件转移指令*/

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        $$.expType = EARITH;
        $$.startPoint = $1.startPoint;
        $$.length = $1.length + $3.length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LLT);
        /*之后不会生成无条件转移指令*/
    }
    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the < operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the < operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the < operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the < operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the < operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
            offset = $$.domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the < operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the < operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue < $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue < $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue < $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }
                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue < $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the < operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the < operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the < operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue < $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue < $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue < $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue < $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the < operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the < operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the < operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue < $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue < $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue < $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue < $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the < operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the < operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the < operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue < $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue < $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue < $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue < $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the < operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the < operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    if (FillBack::fillBack->IsTranslating()) {
        /*真出口*/
        $$.boolExpInfo->tList.push_back($$.boolExpInfo->mapStack.top().startPointInReal);
        $$.boolExpInfo->fList.push_back($$.boolExpInfo->mapStack.top().startPointInReal + 1);
        /*生成无条件转移语句*/
        CodeContainer::codeContainer->PushBackCode();
        CodeContainer::codeContainer->FillInOp(JMP);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
    }
}
|
	exp
	S_LLE
	exp	{
   if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        $$.expType = ETRANSIT;
        if ($3.expType == ETRANSIT) {
            while (!$3.boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                    $3.boolExpInfo->mapStack.top().startPointInReal +
                                                    $3.boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                     $3.boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                               $3.boolExpInfo->mapStack.top().startPointInBackup +
                                               $3.boolExpInfo->mapStack.top().lengthInBackup);
                $3.length -=
                        $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
                $3.boolExpInfo->mapStack.pop();

            }
        }
        if ($1.expType == ETRANSIT) {
            while (!$1.boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInReal,
                                                    $1.boolExpInfo->mapStack.top().startPointInReal +
                                                    $1.boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert($1.boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     $1.boolExpInfo->mapStack.top().startPointInBackup,
                                                     $1.boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInBackup,
                                               $1.boolExpInfo->mapStack.top().startPointInBackup +
                                               $1.boolExpInfo->mapStack.top().lengthInBackup);
                $1.length -=
                        $1.boolExpInfo->mapStack.top().lengthInReal - $1.boolExpInfo->mapStack.top().lengthInBackup;
                $1.boolExpInfo->mapStack.pop();
            }
        }
        $$.length = $1.length + $3.length + 2;
        $$.startPoint = $1.startPoint;
        /*实例化*/
        $$.boolExpInfo = new BoolExpInfo();
        /*填充信息,表示此表达式从CodeContainer的当前位置开始翻译,并且一定会生成两条代码*/
        Map newMap;
        newMap.startPointInReal = CodeContainer::codeContainer->Size();
        newMap.lengthInReal = 2;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        $$.boolExpInfo->mapStack.push(newMap);
        /*算术计算代码翻译到备用代码容器*/
        FillBack::codeContainer->PushBackCode();
        /*<=*/
        FillBack::codeContainer->FillInOp(LLE);
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(JLE);
        /*之后会再生成一条无条件转移指令*/

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        $$.expType = EARITH;
        $$.startPoint = $1.startPoint;
        $$.length = $1.length + $3.length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LLE);
        /*之后不会生成无条件转移指令*/
    }
    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the <= operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the <= operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the <= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the <= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the <= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
            offset = $$.domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the <= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the <= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue <= $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue <= $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue <= $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }
                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue <= $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the <= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the <= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the <= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue <= $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue <= $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue <= $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue <= $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the <= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the <= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the <= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue <= $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue <= $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue <= $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue <= $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the <= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the <= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the <= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue <= $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue <= $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue <= $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue <= $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the <= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the <= operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    if (FillBack::fillBack->IsTranslating()) {
        /*真出口*/
        $$.boolExpInfo->tList.push_back($$.boolExpInfo->mapStack.top().startPointInReal);
        $$.boolExpInfo->fList.push_back($$.boolExpInfo->mapStack.top().startPointInReal + 1);
        /*生成无条件转移语句*/
        CodeContainer::codeContainer->PushBackCode();
        CodeContainer::codeContainer->FillInOp(JMP);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
    }

}
|
	exp
	S_LGT
	exp	{
   if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        $$.expType = ETRANSIT;
        if ($3.expType == ETRANSIT) {
            while (!$3.boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                    $3.boolExpInfo->mapStack.top().startPointInReal +
                                                    $3.boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                     $3.boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                               $3.boolExpInfo->mapStack.top().startPointInBackup +
                                               $3.boolExpInfo->mapStack.top().lengthInBackup);
                $3.length -=
                        $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
                $3.boolExpInfo->mapStack.pop();

            }
        }
        if ($1.expType == ETRANSIT) {
            while (!$1.boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInReal,
                                                    $1.boolExpInfo->mapStack.top().startPointInReal +
                                                    $1.boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert($1.boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     $1.boolExpInfo->mapStack.top().startPointInBackup,
                                                     $1.boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInBackup,
                                               $1.boolExpInfo->mapStack.top().startPointInBackup +
                                               $1.boolExpInfo->mapStack.top().lengthInBackup);
                $1.length -=
                        $1.boolExpInfo->mapStack.top().lengthInReal - $1.boolExpInfo->mapStack.top().lengthInBackup;
                $1.boolExpInfo->mapStack.pop();
            }
        }
        $$.length = $1.length + $3.length + 2;
        $$.startPoint = $1.startPoint;
        /*实例化*/
        $$.boolExpInfo = new BoolExpInfo();
        /*填充信息,表示此表达式从CodeContainer的当前位置开始翻译,并且一定会生成两条代码*/
        Map newMap;
        newMap.startPointInReal = CodeContainer::codeContainer->Size();
        newMap.lengthInReal = 2;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        $$.boolExpInfo->mapStack.push(newMap);
        /*算术计算代码翻译到备用代码容器*/
        FillBack::codeContainer->PushBackCode();
        /*<=*/
        FillBack::codeContainer->FillInOp(LGT);
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(JGT);
        /*之后会再生成一条无条件转移指令*/

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        $$.expType = EARITH;
        $$.startPoint = $1.startPoint;
        $$.length = $1.length + $3.length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LGT);
        /*之后不会生成无条件转移指令*/
    }
    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the > operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the > operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the > operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the > operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the > operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
            offset = $$.domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the > operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the > operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue > $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue > $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue > $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }
                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue > $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the > operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the > operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the > operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue > $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue > $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue > $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue > $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the > operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the > operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the > operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue > $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue > $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue > $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue > $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the > operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the > operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the > operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue > $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue > $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue > $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue > $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the > operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the > operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    if (FillBack::fillBack->IsTranslating()) {
        /*真出口*/
        $$.boolExpInfo->tList.push_back($$.boolExpInfo->mapStack.top().startPointInReal);
        $$.boolExpInfo->fList.push_back($$.boolExpInfo->mapStack.top().startPointInReal + 1);
        /*生成无条件转移语句*/
        CodeContainer::codeContainer->PushBackCode();
        CodeContainer::codeContainer->FillInOp(JMP);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
    }

}
|
	exp
	S_LGE
	exp	{

    if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        $$.expType = ETRANSIT;
        if ($3.expType == ETRANSIT) {
            while (!$3.boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                    $3.boolExpInfo->mapStack.top().startPointInReal +
                                                    $3.boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                     $3.boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                               $3.boolExpInfo->mapStack.top().startPointInBackup +
                                               $3.boolExpInfo->mapStack.top().lengthInBackup);
                $3.length -=
                        $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
                $3.boolExpInfo->mapStack.pop();

            }
        }
        if ($1.expType == ETRANSIT) {
            while (!$1.boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInReal,
                                                    $1.boolExpInfo->mapStack.top().startPointInReal +
                                                    $1.boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert($1.boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     $1.boolExpInfo->mapStack.top().startPointInBackup,
                                                     $1.boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInBackup,
                                               $1.boolExpInfo->mapStack.top().startPointInBackup +
                                               $1.boolExpInfo->mapStack.top().lengthInBackup);
                $1.length -=
                        $1.boolExpInfo->mapStack.top().lengthInReal - $1.boolExpInfo->mapStack.top().lengthInBackup;
                $1.boolExpInfo->mapStack.pop();
            }
        }
        $$.length = $1.length + $3.length + 2;
        $$.startPoint = $1.startPoint;
        /*实例化*/
        $$.boolExpInfo = new BoolExpInfo();
        /*填充信息,表示此表达式从CodeContainer的当前位置开始翻译,并且一定会生成两条代码*/
        Map newMap;
        newMap.startPointInReal = CodeContainer::codeContainer->Size();
        newMap.lengthInReal = 2;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        $$.boolExpInfo->mapStack.push(newMap);
        /*算术计算代码翻译到备用代码容器*/
        FillBack::codeContainer->PushBackCode();
        /*<=*/
        FillBack::codeContainer->FillInOp(LGE);
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(JGE);
        /*之后会再生成一条无条件转移指令*/

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        $$.expType = EARITH;
        $$.startPoint = $1.startPoint;
        $$.length = $1.length + $3.length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LGE);
        /*之后不会生成无条件转移指令*/
    }
    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the >= operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the >= operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the >= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the >= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the >= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
            offset = $$.domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the >= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the >= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue >= $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue >= $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue >= $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }
                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue >= $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the >= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the >= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the >= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue >= $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue >= $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue >= $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue >= $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the >= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the >= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the >= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue >= $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue >= $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue >= $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue >= $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the >= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the >= operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the >= operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue >= $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue >= $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue >= $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue >= $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the >= operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the >= operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    if (FillBack::fillBack->IsTranslating()) {
        /*真出口*/
        $$.boolExpInfo->tList.push_back($$.boolExpInfo->mapStack.top().startPointInReal);
        $$.boolExpInfo->fList.push_back($$.boolExpInfo->mapStack.top().startPointInReal + 1);
        /*生成无条件转移语句*/
        CodeContainer::codeContainer->PushBackCode();
        CodeContainer::codeContainer->FillInOp(JMP);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
    }
}
|
	exp
	S_LNE
	exp	{
    if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        $$.expType = ETRANSIT;
        if ($3.expType == ETRANSIT) {
            while (!$3.boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                    $3.boolExpInfo->mapStack.top().startPointInReal +
                                                    $3.boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                     $3.boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                               $3.boolExpInfo->mapStack.top().startPointInBackup +
                                               $3.boolExpInfo->mapStack.top().lengthInBackup);
                $3.length -=
                        $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
                $3.boolExpInfo->mapStack.pop();

            }
        }
        if ($1.expType == ETRANSIT) {
            while (!$1.boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInReal,
                                                    $1.boolExpInfo->mapStack.top().startPointInReal +
                                                    $1.boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert($1.boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     $1.boolExpInfo->mapStack.top().startPointInBackup,
                                                     $1.boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInBackup,
                                               $1.boolExpInfo->mapStack.top().startPointInBackup +
                                               $1.boolExpInfo->mapStack.top().lengthInBackup);
                $1.length -=
                        $1.boolExpInfo->mapStack.top().lengthInReal - $1.boolExpInfo->mapStack.top().lengthInBackup;
                $1.boolExpInfo->mapStack.pop();
            }
        }
        $$.length = $1.length + $3.length + 2;
        $$.startPoint = $1.startPoint;
        /*实例化*/
        $$.boolExpInfo = new BoolExpInfo();
        /*填充信息,表示此表达式从CodeContainer的当前位置开始翻译,并且一定会生成两条代码*/
        Map newMap;
        newMap.startPointInReal = CodeContainer::codeContainer->Size();
        newMap.lengthInReal = 2;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        $$.boolExpInfo->mapStack.push(newMap);
        /*算术计算代码翻译到备用代码容器*/
        FillBack::codeContainer->PushBackCode();
        /*<=*/
        FillBack::codeContainer->FillInOp(LNE);
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(JNE);
        /*之后会再生成一条无条件转移指令*/

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        $$.expType = EARITH;
        $$.startPoint = $1.startPoint;
        $$.length = $1.length + $3.length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LNE);
        /*之后不会生成无条件转移指令*/
    }
    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the != operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            if ($3.expValueType != RefInStack) {
                printf("ERROR:left value of the != operation is <reference> , but right value is not.\n");
                CodeContainer::codeContainer->Clear();YYERROR;
                break;
            }
            if ($1.domainTableItem->GetType() != $3.domainTableItem->GetType()) {
                printf("ERROR:left value of the != operation is <%s> , but right value is <%s>.\n",
                       $1.domainTableItem->GetType().data(), $3.domainTableItem->GetType().data());
                CodeContainer::codeContainer->Clear();YYERROR;
                break;
            }
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            offset = $3.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
            }
            $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
            offset = $$.domainTableItem->GetOffsetInStack();
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod($3.agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod($3.agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the != operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the != operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the != operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
            offset = $$.domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the != operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the != operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue != $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue != $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue != $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }
                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue != $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the != operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the != operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the != operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue != $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue != $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue != $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue != $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the != operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the != operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the != operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue != $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue != $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue != $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue != $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the != operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the != operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the != operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue != $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue != $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue != $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue != $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the != operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the != operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    if (FillBack::fillBack->IsTranslating()) {
        /*真出口*/
        $$.boolExpInfo->tList.push_back($$.boolExpInfo->mapStack.top().startPointInReal);
        $$.boolExpInfo->fList.push_back($$.boolExpInfo->mapStack.top().startPointInReal + 1);
        /*生成无条件转移语句*/
        CodeContainer::codeContainer->PushBackCode();
        CodeContainer::codeContainer->FillInOp(JMP);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
    }

}
|
	exp
	S_LEQ
	exp	{
    if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        $$.expType = ETRANSIT;
        if ($3.expType == ETRANSIT) {
            while (!$3.boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                    $3.boolExpInfo->mapStack.top().startPointInReal +
                                                    $3.boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                     $3.boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                               $3.boolExpInfo->mapStack.top().startPointInBackup +
                                               $3.boolExpInfo->mapStack.top().lengthInBackup);
                $3.length -=
                        $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
                $3.boolExpInfo->mapStack.pop();

            }
        }
        if ($1.expType == ETRANSIT) {
            while (!$1.boolExpInfo->mapStack.empty()) {
                /*真实容器中删除*/
                CodeContainer::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInReal,
                                                    $1.boolExpInfo->mapStack.top().startPointInReal +
                                                    $1.boolExpInfo->mapStack.top().lengthInReal);
                /*备用容器->真实容器*/
                CodeContainer::codeContainer->Insert($1.boolExpInfo->mapStack.top().startPointInReal,
                                                     FillBack::codeContainer,
                                                     $1.boolExpInfo->mapStack.top().startPointInBackup,
                                                     $1.boolExpInfo->mapStack.top().lengthInBackup);
                /*从备用容器中删除*/
                FillBack::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInBackup,
                                               $1.boolExpInfo->mapStack.top().startPointInBackup +
                                               $1.boolExpInfo->mapStack.top().lengthInBackup);
                $1.length -=
                        $1.boolExpInfo->mapStack.top().lengthInReal - $1.boolExpInfo->mapStack.top().lengthInBackup;
                $1.boolExpInfo->mapStack.pop();
            }
        }
        $$.length = $1.length + $3.length + 2;
        $$.startPoint = $1.startPoint;
        /*实例化*/
        $$.boolExpInfo = new BoolExpInfo();
        /*填充信息,表示此表达式从CodeContainer的当前位置开始翻译,并且一定会生成两条代码*/
        Map newMap;
        newMap.startPointInReal = CodeContainer::codeContainer->Size();
        newMap.lengthInReal = 2;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        $$.boolExpInfo->mapStack.push(newMap);
        /*算术计算代码翻译到备用代码容器*/
        FillBack::codeContainer->PushBackCode();
        /*<=*/
        FillBack::codeContainer->FillInOp(LEQ);
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(JEQ);
        /*之后会再生成一条无条件转移指令*/

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        $$.expType = EARITH;
        $$.startPoint = $1.startPoint;
        $$.length = $1.length + $3.length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LEQ);
        /*之后不会生成无条件转移指令*/
    }
    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the == operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            if ($3.expValueType != RefInStack) {
                printf("ERROR:left value of the == operation is <reference> , but right value is not.\n");
                CodeContainer::codeContainer->Clear();YYERROR;
                break;
            }
            if ($1.domainTableItem->GetType() != $3.domainTableItem->GetType()) {
                printf("ERROR:left value of the == operation is <%s> , but right value is <%s>.\n",
                       $1.domainTableItem->GetType().data(), $3.domainTableItem->GetType().data());
                CodeContainer::codeContainer->Clear();YYERROR;
                break;
            }
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            offset = $3.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
            }
            $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
            offset = $$.domainTableItem->GetOffsetInStack();
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod($3.agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod($3.agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the == operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the == operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    /*如果存在翻译模式中,那么也要给备用代码容器中翻译一份*/
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the == operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
            offset = $$.domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the == operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the == operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue == $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue == $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue == $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }
                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue == $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the == operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the == operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the == operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue == $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue == $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue == $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue == $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the == operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the == operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the == operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue == $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue == $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue == $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue == $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the == operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the == operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the == operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue == $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue == $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue == $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue == $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;;
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the == operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the == operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    if (FillBack::fillBack->IsTranslating()) {
        /*真出口*/
        $$.boolExpInfo->tList.push_back($$.boolExpInfo->mapStack.top().startPointInReal);
        $$.boolExpInfo->fList.push_back($$.boolExpInfo->mapStack.top().startPointInReal + 1);
        /*生成无条件转移语句*/
        CodeContainer::codeContainer->PushBackCode();
        CodeContainer::codeContainer->FillInOp(JMP);
        CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod);
        CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt);
    }
}
|
	exp
	S_LAND
	exp	{
    if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        $$.expType = ETRANSIT;
        /*实例化*/
        $$.boolExpInfo = new BoolExpInfo();
        /*检测左值与右值是否为过渡态,如果不是,那么需要转换*/
        if ($1.expType != ETRANSIT) {
            Map newMap;
            newMap.startPointInReal = $1.startPoint + $1.length;
            /*因为要生成2条转换代码*/
            newMap.lengthInReal = 2;
            $1.length += 2;
            /*注意,不会在备份代码容器中生成代码*/
            $1.boolExpInfo = new BoolExpInfo();
            $1.boolExpInfo->mapStack.push(newMap);
            $1.boolExpInfo->tList.push_back(newMap.startPointInReal);
            $1.boolExpInfo->fList.push_back(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal);
            CodeContainer::codeContainer->FillInOp(JNE, newMap.startPointInReal);
            switch ($1.expValueType) {
                case StringValue:
                    printf("ERROR:left value of the && operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case Void:
                    printf("ERROR:left value of the && operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:left value of the && operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod, newMap.startPointInReal);
                    offset = $1.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *), newMap.startPointInReal);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool), newMap.startPointInReal);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char), newMap.startPointInReal);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int), newMap.startPointInReal);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double), newMap.startPointInReal);
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool, newMap.startPointInReal);
            offset = false;
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(bool), newMap.startPointInReal);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInOp(JMP, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal + 1);
            /*因为生成了两条语句,$3的开始点需要向后推移*/
            $3.startPoint += 2;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal += 2;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it) += 2;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it) += 2;
                }
            }
        }
        if ($3.expType != ETRANSIT) {
            Map newMap;
            newMap.startPointInReal = $3.startPoint + $3.length;
            /*因为要生成2条转换代码*/
            newMap.lengthInReal = 2;
            $3.length += 2;
            /*注意,不会在备份代码容器中生成代码*/
            $3.boolExpInfo = new BoolExpInfo();
            $3.boolExpInfo->mapStack.push(newMap);
            $3.boolExpInfo->tList.push_back(newMap.startPointInReal);
            $3.boolExpInfo->fList.push_back(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal);
            CodeContainer::codeContainer->FillInOp(JNE, newMap.startPointInReal);
            switch ($3.expValueType) {
                case StringValue:
                    printf("ERROR:left value of the && operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case Void:
                    printf("ERROR:left value of the && operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:left value of the && operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    CodeContainer::codeContainer->FillInArg1ParseMethod($3.agrParseMethod, newMap.startPointInReal);
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *), newMap.startPointInReal);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$3.boolValue, sizeof(bool), newMap.startPointInReal);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$3.charValue, sizeof(char), newMap.startPointInReal);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$3.intValue, sizeof(int), newMap.startPointInReal);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$3.doubleValue, sizeof(double), newMap.startPointInReal);
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool, newMap.startPointInReal);
            offset = false;
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(bool), newMap.startPointInReal);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInOp(JMP, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal + 1);
        }
        /*填充信息,初始化*/
        $$.startPoint = $1.startPoint;
        $$.length = $1.length + $3.length;

        stack<Map> transitStack;

        while (!$1.boolExpInfo->mapStack.empty()) {
            transitStack.push($1.boolExpInfo->mapStack.top());
            $1.boolExpInfo->mapStack.pop();
        }
        while (!transitStack.empty()) {
            $$.boolExpInfo->mapStack.push(transitStack.top());
            transitStack.pop();
        }

        while (!$3.boolExpInfo->mapStack.empty()) {
            transitStack.push($3.boolExpInfo->mapStack.top());
            $3.boolExpInfo->mapStack.pop();
        }
        while (!transitStack.empty()) {
            $$.boolExpInfo->mapStack.push(transitStack.top());
            transitStack.pop();
        }

        Map newMap;

        newMap.startPointInReal = $$.startPoint + $$.length;
        newMap.lengthInReal = 0;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        $$.boolExpInfo->mapStack.push(newMap);
        FillBack::codeContainer->PushBackCode();
        /*||*/
        FillBack::codeContainer->FillInOp(LAND);

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        $$.expType = EARITH;
        $$.startPoint = $1.startPoint;
        $$.length = $1.length + $3.length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LAND);
        /*之后不会生成无条件转移指令*/
    }
    /*如果在翻译模式中,那么仅仅向备份代码容器中翻译.如果不是,那么就在真实代码容器中翻译*/
    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the && operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the && operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
                CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the && operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the && operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the && operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
            offset = $$.domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
                CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the && operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the && operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue && $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue && $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue && $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }
                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue && $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the && operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
                CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the && operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the && operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue && $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue && $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue && $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue && $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the && operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
                CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the && operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the && operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue && $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue && $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue && $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue && $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the && operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
                CodeContainer::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the && operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the && operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue && $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue && $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue && $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }
                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue && $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the && operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the && operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    //A&&B
    if (FillBack::fillBack->IsTranslating()) {
        for (int idx:$1.boolExpInfo->tList) {
            offset = $3.startPoint;
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(int), idx);
        }
        $$.boolExpInfo->tList.splice($$.boolExpInfo->tList.end(), $3.boolExpInfo->tList);
        $$.boolExpInfo->fList.splice($$.boolExpInfo->fList.end(), $1.boolExpInfo->fList);
        $$.boolExpInfo->fList.splice($$.boolExpInfo->fList.end(), $3.boolExpInfo->fList);
        /*资源释放*/
        delete $3.boolExpInfo;
        /*资源释放*/
        delete $1.boolExpInfo;
    }
}
|
	exp
	S_LOR
	exp	{


    if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }
    /*如果是翻译模式*/
    if (FillBack::fillBack->IsTranslating()) {
        /*表达式类型为过渡模式*/
        $$.expType = ETRANSIT;
        /*实例化*/
        $$.boolExpInfo = new BoolExpInfo();
        /*检测左值与右值是否为过渡态,如果不是,那么需要转换*/
        if ($1.expType != ETRANSIT) {
            Map newMap;
            newMap.startPointInReal = $1.startPoint + $1.length;
            /*因为要生成2条转换代码*/
            newMap.lengthInReal = 2;
            $1.length += 2;
            /*注意,不会在备份代码容器中生成代码*/
            $1.boolExpInfo = new BoolExpInfo();
            $1.boolExpInfo->mapStack.push(newMap);
            $1.boolExpInfo->tList.push_back(newMap.startPointInReal);
            $1.boolExpInfo->fList.push_back(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal);
            CodeContainer::codeContainer->FillInOp(JNE, newMap.startPointInReal);
            switch ($1.expValueType) {
                case StringValue:
                    printf("ERROR:left value of the || operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case Void:
                    printf("ERROR:left value of the || operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:left value of the || operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod, newMap.startPointInReal);
                    offset = $1.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *), newMap.startPointInReal);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool), newMap.startPointInReal);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char), newMap.startPointInReal);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int), newMap.startPointInReal);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double), newMap.startPointInReal);
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool, newMap.startPointInReal);
            offset = false;
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(bool), newMap.startPointInReal);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInOp(JMP, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal + 1);
            /*因为生成了两条语句,$3的开始点需要向后推移*/
            $3.startPoint += 2;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal += 2;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it) += 2;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it) += 2;
                }
            }
        }
        if ($3.expType != ETRANSIT) {
            Map newMap;
            newMap.startPointInReal = $3.startPoint + $3.length;
            /*因为要生成2条转换代码*/
            newMap.lengthInReal = 2;
            $3.length += 2;
            /*注意,不会在备份代码容器中生成代码*/
            $3.boolExpInfo = new BoolExpInfo();
            $3.boolExpInfo->mapStack.push(newMap);
            $3.boolExpInfo->tList.push_back(newMap.startPointInReal);
            $3.boolExpInfo->fList.push_back(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal);
            CodeContainer::codeContainer->FillInOp(JNE, newMap.startPointInReal);
            switch ($3.expValueType) {
                case StringValue:
                    printf("ERROR:left value of the || operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case Void:
                    printf("ERROR:left value of the || operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:left value of the || operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    CodeContainer::codeContainer->FillInArg1ParseMethod($3.agrParseMethod, newMap.startPointInReal);
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *), newMap.startPointInReal);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$3.boolValue, sizeof(bool), newMap.startPointInReal);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$3.charValue, sizeof(char), newMap.startPointInReal);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$3.intValue, sizeof(int), newMap.startPointInReal);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble, newMap.startPointInReal);
                    CodeContainer::codeContainer->FillInArg1(&$3.doubleValue, sizeof(double), newMap.startPointInReal);
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool, newMap.startPointInReal);
            offset = false;
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(bool), newMap.startPointInReal);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal);
            CodeContainer::codeContainer->Insert(newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInOp(JMP, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg1ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg2ParseMethod(NoMethod, newMap.startPointInReal + 1);
            CodeContainer::codeContainer->FillInArg3ParseMethod(ToInt, newMap.startPointInReal + 1);
        }
        /*填充信息,初始化*/
        $$.startPoint = $1.startPoint;
        $$.length = $1.length + $3.length;

        stack<Map> transitStack;

        while (!$1.boolExpInfo->mapStack.empty()) {
            transitStack.push($1.boolExpInfo->mapStack.top());
            $1.boolExpInfo->mapStack.pop();
        }
        while (!transitStack.empty()) {
            $$.boolExpInfo->mapStack.push(transitStack.top());
            transitStack.pop();
        }

        while (!$3.boolExpInfo->mapStack.empty()) {
            transitStack.push($3.boolExpInfo->mapStack.top());
            $3.boolExpInfo->mapStack.pop();
        }
        while (!transitStack.empty()) {
            $$.boolExpInfo->mapStack.push(transitStack.top());
            transitStack.pop();
        }

        Map newMap;

        newMap.startPointInReal = $$.startPoint + $$.length;
        newMap.lengthInReal = 0;
        newMap.startPointInBackup = FillBack::codeContainer->Size();
        newMap.lengthInBackup = 1;
        $$.boolExpInfo->mapStack.push(newMap);
        FillBack::codeContainer->PushBackCode();
        /*||*/
        FillBack::codeContainer->FillInOp(LOR);

    } else {
        /*如果不是翻译模式*/
        /*不需要计算表达式开始翻译的地点与长度*/
        /*表达式类型为算术表达式*/
        /*并且直接翻译到真实容器,不需要备用翻译*/
        $$.expType = EARITH;
        $$.startPoint = $1.startPoint;
        $$.length = $1.length + $3.length + 1;
        /*跳转代码翻译到真实代码容器*/
        CodeContainer::codeContainer->PushBackCode();
        /*j<*/
        CodeContainer::codeContainer->FillInOp(LOR);
        /*之后不会生成无条件转移指令*/
    }
    /*如果在翻译模式中,那么仅仅向备份代码容器中翻译.如果不是,那么就在真实代码容器中翻译*/
    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the || operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the || operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInHeap:
        case BoolInStack:
        case CharInHeap:
        case CharInStack:
        case IntInHeap:
        case IntInStack:
        case DoubleInStack:
        case DoubleInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
                FillBack::codeContainer->FillInArg1(&offset, sizeof(void *));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
                CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the || operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the || operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToBool);
                        FillBack::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                        CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    }
                    break;
                case CharValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToChar);
                        FillBack::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                        CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    }
                    break;
                case IntValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToInt);
                        FillBack::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                        CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    }
                    break;
                case DoubleValue:
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->FillInArg2ParseMethod(ToDouble);
                        FillBack::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    } else {
                        CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                        CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the || operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
            offset = $$.domainTableItem->GetOffsetInStack();
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));
            } else {
                CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            }
            break;
        case BoolValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToBool);
                FillBack::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
                CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the || operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the || operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue || $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue || $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue || $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }
                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.boolValue || $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the || operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToChar);
                FillBack::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
                CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the || operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the || operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue || $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue || $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue || $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }

                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.charValue || $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the || operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToInt);
                FillBack::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
                CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the || operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the || operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue || $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue || $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue || $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.intValue || $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }
                    break;
                case StringValue:
                    printf("ERROR:right value of the || operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            if (FillBack::fillBack->IsTranslating()) {
                FillBack::codeContainer->FillInArg1ParseMethod(ToDouble);
                FillBack::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            } else {
                CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
                CodeContainer::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            }
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the || operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the || operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInHeap:
                case BoolInStack:
                case CharInHeap:
                case CharInStack:
                case IntInHeap:
                case IntInStack:
                case DoubleInStack:
                case DoubleInHeap:
                    $$.domainTableItem = symbolTable->CreateTempVar("bool", &$$);
                    if (FillBack::fillBack->IsTranslating()) {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        FillBack::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        FillBack::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        FillBack::codeContainer->FillInArg3(&offset, sizeof(void *));

                    } else {
                        offset = $3.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                        offset = $$.domainTableItem->GetOffsetInStack();
                        CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                        CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    }
                    break;
                case BoolValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue || $3.boolValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case CharValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue || $3.charValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }

                    break;
                case IntValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue || $3.intValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;

                    }
                    break;
                case DoubleValue:
                    $$.expType = EVALUE;
                    $$.expValueType = BoolValue;
                    $$.agrParseMethod = ToBool;
                    $$.boolValue = $1.doubleValue || $3.doubleValue;
                    if (FillBack::fillBack->IsTranslating()) {
                        FillBack::codeContainer->Erase(FillBack::codeContainer->Size() - 1);
                        $$.boolExpInfo->mapStack.top().lengthInBackup--;
                        $$.expType = ETRANSIT;
                    } else {
                        CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                        $$.length--;
                    }

                    break;
                case StringValue:
                    printf("ERROR:right value of the || operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the || operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
    //A||B
    if (FillBack::fillBack->IsTranslating()) {
        for (int idx:$1.boolExpInfo->fList) {
            offset = $3.startPoint;
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(int), idx);
        }
        $$.boolExpInfo->tList.splice($$.boolExpInfo->tList.end(), $1.boolExpInfo->tList);
        $$.boolExpInfo->tList.splice($$.boolExpInfo->tList.end(), $3.boolExpInfo->tList);
        $$.boolExpInfo->fList.splice($$.boolExpInfo->fList.end(), $3.boolExpInfo->fList);
        /*资源释放*/
        delete $3.boolExpInfo;
        /*资源释放*/
        delete $1.boolExpInfo;
    }
}
|
	S_LNOT
	exp	{
}
|
	exp
	S_ADD
	exp	{
    if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }

    $$.expType = EARITH;
    if ($3.expType == ETRANSIT) {
        while (!$3.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                $3.boolExpInfo->mapStack.top().startPointInReal +
                                                $3.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $3.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                           $3.boolExpInfo->mapStack.top().startPointInBackup +
                                           $3.boolExpInfo->mapStack.top().lengthInBackup);
            $3.length -=
                    $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
            $3.boolExpInfo->mapStack.pop();

        }
    }
    if ($1.expType == ETRANSIT) {
        while (!$1.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInReal,
                                                $1.boolExpInfo->mapStack.top().startPointInReal +
                                                $1.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($1.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $1.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $1.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInBackup,
                                           $1.boolExpInfo->mapStack.top().startPointInBackup +
                                           $1.boolExpInfo->mapStack.top().lengthInBackup);
            $1.length -=
                    $1.boolExpInfo->mapStack.top().lengthInReal - $1.boolExpInfo->mapStack.top().lengthInBackup;
            $1.boolExpInfo->mapStack.pop();
        }
    }

    $$.length = $1.length + $3.length + 1;
    $$.startPoint = $1.startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(ADD);

    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the + operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the + operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the + operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the + operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case StringValue:
                    printf("ERROR:right value of the + operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case DoubleInStack:
        case DoubleInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the + operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the + operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case StringValue:
                    printf("ERROR:right value of the + operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the + operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                case RefInStack:
                    printf("ERROR:right value of the + operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue + $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue + $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue + $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.boolValue + $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the + operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the + operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the + operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue + $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue + $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue + $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.charValue + $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the + operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the + operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the + operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue + $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue + $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue + $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.intValue + $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the + operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the + operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the + operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue + $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue + $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue + $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue + $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the + operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the + operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
|
	exp
	S_SUB
	exp	{
    if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }

    $$.expType = EARITH;
    if ($3.expType == ETRANSIT) {
        while (!$3.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                $3.boolExpInfo->mapStack.top().startPointInReal +
                                                $3.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $3.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                           $3.boolExpInfo->mapStack.top().startPointInBackup +
                                           $3.boolExpInfo->mapStack.top().lengthInBackup);
            $3.length -=
                    $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
            $3.boolExpInfo->mapStack.pop();

        }
    }
    if ($1.expType == ETRANSIT) {
        while (!$1.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInReal,
                                                $1.boolExpInfo->mapStack.top().startPointInReal +
                                                $1.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($1.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $1.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $1.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInBackup,
                                           $1.boolExpInfo->mapStack.top().startPointInBackup +
                                           $1.boolExpInfo->mapStack.top().lengthInBackup);
            $1.length -=
                    $1.boolExpInfo->mapStack.top().lengthInReal - $1.boolExpInfo->mapStack.top().lengthInBackup;
            $1.boolExpInfo->mapStack.pop();
        }
    }

    $$.length = $1.length + $3.length + 1;
    $$.startPoint = $1.startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(SUB);

    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the - operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the - operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the - operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the - operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case StringValue:
                    printf("ERROR:right value of the - operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case DoubleInStack:
        case DoubleInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the - operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the - operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case StringValue:
                    printf("ERROR:right value of the - operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the - operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                case RefInStack:
                    printf("ERROR:right value of the - operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue - $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue - $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue - $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.boolValue - $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the - operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the - operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the - operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue - $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue - $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue - $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.charValue - $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the - operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the - operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the - operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue - $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue - $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue - $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.intValue - $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the - operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the - operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the - operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue - $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue - $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue - $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue - $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the - operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the - operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
|
	exp
	S_MUL
	exp	{
    if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }

    $$.expType = EARITH;
    if ($3.expType == ETRANSIT) {
        while (!$3.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                $3.boolExpInfo->mapStack.top().startPointInReal +
                                                $3.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $3.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                           $3.boolExpInfo->mapStack.top().startPointInBackup +
                                           $3.boolExpInfo->mapStack.top().lengthInBackup);
            $3.length -=
                    $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
            $3.boolExpInfo->mapStack.pop();

        }
    }
    if ($1.expType == ETRANSIT) {
        while (!$1.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInReal,
                                                $1.boolExpInfo->mapStack.top().startPointInReal +
                                                $1.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($1.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $1.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $1.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInBackup,
                                           $1.boolExpInfo->mapStack.top().startPointInBackup +
                                           $1.boolExpInfo->mapStack.top().lengthInBackup);
            $1.length -=
                    $1.boolExpInfo->mapStack.top().lengthInReal - $1.boolExpInfo->mapStack.top().lengthInBackup;
            $1.boolExpInfo->mapStack.pop();
        }
    }

    $$.length = $1.length + $3.length + 1;
    $$.startPoint = $1.startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(MUL);

    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the * operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the * operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the * operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the * operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case StringValue:
                    printf("ERROR:right value of the * operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case DoubleInStack:
        case DoubleInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the * operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the * operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case StringValue:
                    printf("ERROR:right value of the * operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the * operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                case RefInStack:
                    printf("ERROR:right value of the * operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue * $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue * $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue * $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.boolValue * $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the * operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the * operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the * operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue * $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue * $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue * $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.charValue * $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the * operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the * operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the * operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue * $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue * $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue * $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.intValue * $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the * operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the * operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the * operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue * $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue * $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue * $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue * $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the * operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the * operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
|
	exp
	S_DIV
	exp	{
    if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }

    $$.expType = EARITH;
    if ($3.expType == ETRANSIT) {
        while (!$3.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                $3.boolExpInfo->mapStack.top().startPointInReal +
                                                $3.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $3.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                           $3.boolExpInfo->mapStack.top().startPointInBackup +
                                           $3.boolExpInfo->mapStack.top().lengthInBackup);
            $3.length -=
                    $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
            $3.boolExpInfo->mapStack.pop();

        }
    }
    if ($1.expType == ETRANSIT) {
        while (!$1.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInReal,
                                                $1.boolExpInfo->mapStack.top().startPointInReal +
                                                $1.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($1.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $1.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $1.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInBackup,
                                           $1.boolExpInfo->mapStack.top().startPointInBackup +
                                           $1.boolExpInfo->mapStack.top().lengthInBackup);
            $1.length -=
                    $1.boolExpInfo->mapStack.top().lengthInReal - $1.boolExpInfo->mapStack.top().lengthInBackup;
            $1.boolExpInfo->mapStack.pop();
        }
    }

    $$.length = $1.length + $3.length + 1;
    $$.startPoint = $1.startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(DIV);

    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the / operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the / operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the / operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the / operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case StringValue:
                    printf("ERROR:right value of the / operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case DoubleInStack:
        case DoubleInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the / operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the / operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToDouble);
                    CodeContainer::codeContainer->FillInArg2(&$3.doubleValue, sizeof(double));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    break;
                case StringValue:
                    printf("ERROR:right value of the / operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the / operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                case RefInStack:
                    printf("ERROR:right value of the / operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue / $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue / $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue + $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.boolValue / $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the / operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the / operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the / operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue / $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue / $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue / $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.charValue / $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the / operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the / operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case RefInStack:
                    printf("ERROR:right value of the / operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue / $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue / $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue / $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.intValue / $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the / operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case DoubleValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToDouble);
            CodeContainer::codeContainer->FillInArg1(&$1.doubleValue, sizeof(double));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the / operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the / operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case DoubleInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                case DoubleInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("double", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue / $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue / $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue / $3.intValue;
                    break;
                case DoubleValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = DoubleValue;
                    $$.agrParseMethod = ToDouble;
                    $$.doubleValue = $1.doubleValue / $3.doubleValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the / operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the / operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
|
	exp
	S_XOR
	exp	{
    if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }

    $$.expType = EARITH;
    if ($3.expType == ETRANSIT) {
        while (!$3.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                $3.boolExpInfo->mapStack.top().startPointInReal +
                                                $3.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $3.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                           $3.boolExpInfo->mapStack.top().startPointInBackup +
                                           $3.boolExpInfo->mapStack.top().lengthInBackup);
            $3.length -=
                    $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
            $3.boolExpInfo->mapStack.pop();

        }
    }
    if ($1.expType == ETRANSIT) {
        while (!$1.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInReal,
                                                $1.boolExpInfo->mapStack.top().startPointInReal +
                                                $1.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($1.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $1.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $1.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInBackup,
                                           $1.boolExpInfo->mapStack.top().startPointInBackup +
                                           $1.boolExpInfo->mapStack.top().lengthInBackup);
            $1.length -=
                    $1.boolExpInfo->mapStack.top().lengthInReal - $1.boolExpInfo->mapStack.top().lengthInBackup;
            $1.boolExpInfo->mapStack.pop();
        }
    }

    $$.length = $1.length + $3.length + 1;
    $$.startPoint = $1.startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(XOR);

    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the  ^ operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the  ^ operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case DoubleInStack:
        case DoubleInHeap:
        case DoubleValue:
            printf("ERROR:left value of the  ^ operation cannot be <double>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the  ^ operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the  ^ operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the  ^ operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;

                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case StringValue:
                    printf("ERROR:right value of the  ^ operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the  ^ operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the  ^ operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the  ^ operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue ^ $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue ^ $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue ^ $3.intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the  ^ operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the  ^ operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the  ^ operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the  ^ operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue ^ $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue ^ $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue ^ $3.intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the  ^ operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the  ^ operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the  ^ operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the  ^ operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue ^ $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue ^ $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue ^ $3.intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the  ^ operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the  ^ operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
|
	exp
	S_OR
	exp	{

    if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }

    $$.expType = EARITH;
    if ($3.expType == ETRANSIT) {
        while (!$3.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                $3.boolExpInfo->mapStack.top().startPointInReal +
                                                $3.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $3.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                           $3.boolExpInfo->mapStack.top().startPointInBackup +
                                           $3.boolExpInfo->mapStack.top().lengthInBackup);
            $3.length -=
                    $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
            $3.boolExpInfo->mapStack.pop();

        }
    }
    if ($1.expType == ETRANSIT) {
        while (!$1.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInReal,
                                                $1.boolExpInfo->mapStack.top().startPointInReal +
                                                $1.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($1.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $1.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $1.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInBackup,
                                           $1.boolExpInfo->mapStack.top().startPointInBackup +
                                           $1.boolExpInfo->mapStack.top().lengthInBackup);
            $1.length -=
                    $1.boolExpInfo->mapStack.top().lengthInReal - $1.boolExpInfo->mapStack.top().lengthInBackup;
            $1.boolExpInfo->mapStack.pop();
        }
    }

    $$.length = $1.length + $3.length + 1;
    $$.startPoint = $1.startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(OR);

    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the | operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the | operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case DoubleInStack:
        case DoubleInHeap:
        case DoubleValue:
            printf("ERROR:left value of the | operation cannot be <double>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the | operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the | operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the | operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;

                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case StringValue:
                    printf("ERROR:right value of the | operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the | operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the | operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the | operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue | $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue | $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue | $3.intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the | operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the | operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the | operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the | operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue | $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue | $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue | $3.intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the | operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the | operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the | operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the | operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue | $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue | $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue | $3.intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the | operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the | operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}

|
	exp
	S_AND
	exp	{
    if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }

    $$.expType = EARITH;
    if ($3.expType == ETRANSIT) {
        while (!$3.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                $3.boolExpInfo->mapStack.top().startPointInReal +
                                                $3.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $3.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                           $3.boolExpInfo->mapStack.top().startPointInBackup +
                                           $3.boolExpInfo->mapStack.top().lengthInBackup);
            $3.length -=
                    $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
            $3.boolExpInfo->mapStack.pop();

        }
    }
    if ($1.expType == ETRANSIT) {
        while (!$1.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInReal,
                                                $1.boolExpInfo->mapStack.top().startPointInReal +
                                                $1.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($1.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $1.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $1.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInBackup,
                                           $1.boolExpInfo->mapStack.top().startPointInBackup +
                                           $1.boolExpInfo->mapStack.top().lengthInBackup);
            $1.length -=
                    $1.boolExpInfo->mapStack.top().lengthInReal - $1.boolExpInfo->mapStack.top().lengthInBackup;
            $1.boolExpInfo->mapStack.pop();
        }
    }

    $$.length = $1.length + $3.length + 1;
    $$.startPoint = $1.startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(AND);

    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the & operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the & operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case DoubleInStack:
        case DoubleInHeap:
        case DoubleValue:
            printf("ERROR:left value of the & operation cannot be <double>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the & operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the & operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the & operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;

                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case StringValue:
                    printf("ERROR:right value of the & operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the & operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the & operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the & operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue & $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue & $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue & $3.intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the & operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the & operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the & operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the & operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue & $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue & $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue & $3.intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the & operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the & operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the & operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the & operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue & $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue & $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue & $3.intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the & operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the & operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }

}
|
	exp
	S_MOD
	exp	{
    if ($1.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($1.stringValue, &$1)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $1.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($1.startPoint, preLength);
            $1.length++;
            $3.startPoint++;
            /*如果$3是过渡类型,那么需要同步推移映射栈中的映射*/
            stack<Map> updateStack;
            while ($3.expType == ETRANSIT && !$3.boolExpInfo->mapStack.empty()) {
                $3.boolExpInfo->mapStack.top().startPointInReal++;
                updateStack.push($3.boolExpInfo->mapStack.top());
                $3.boolExpInfo->mapStack.pop();
            }
            while ($3.expType == ETRANSIT && !updateStack.empty()) {
                $3.boolExpInfo->mapStack.push(updateStack.top());
                updateStack.pop();
            }
            /*真假链条同时也需要更新*/
            if ($3.expType == ETRANSIT) {
                list<int>::iterator it;
                for (it = $3.boolExpInfo->fList.begin(); it != $3.boolExpInfo->fList.end(); it++) {
                    (*it)++;
                }
                for (it = $3.boolExpInfo->tList.begin(); it != $3.boolExpInfo->tList.end(); it++) {
                    (*it)++;
                }
            }
        }
    }
    if ($3.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($3.stringValue, &$3)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $3.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($3.startPoint, preLength);
            $3.length++;
        }
    }

    $$.expType = EARITH;
    if ($3.expType == ETRANSIT) {
        while (!$3.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInReal,
                                                $3.boolExpInfo->mapStack.top().startPointInReal +
                                                $3.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($3.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $3.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $3.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($3.boolExpInfo->mapStack.top().startPointInBackup,
                                           $3.boolExpInfo->mapStack.top().startPointInBackup +
                                           $3.boolExpInfo->mapStack.top().lengthInBackup);
            $3.length -=
                    $3.boolExpInfo->mapStack.top().lengthInReal - $3.boolExpInfo->mapStack.top().lengthInBackup;
            $3.boolExpInfo->mapStack.pop();

        }
    }
    if ($1.expType == ETRANSIT) {
        while (!$1.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInReal,
                                                $1.boolExpInfo->mapStack.top().startPointInReal +
                                                $1.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($1.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $1.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $1.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($1.boolExpInfo->mapStack.top().startPointInBackup,
                                           $1.boolExpInfo->mapStack.top().startPointInBackup +
                                           $1.boolExpInfo->mapStack.top().lengthInBackup);
            $1.length -=
                    $1.boolExpInfo->mapStack.top().lengthInReal - $1.boolExpInfo->mapStack.top().lengthInBackup;
            $1.boolExpInfo->mapStack.pop();
        }
    }

    $$.length = $1.length + $3.length + 1;
    $$.startPoint = $1.startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(MOD);

    switch ($1.expValueType) {
        case Void:
            printf("ERROR:left value of the %% operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the %% operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case DoubleInStack:
        case DoubleInHeap:
        case DoubleValue:
            printf("ERROR:left value of the %% operation cannot be <double>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = $1.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($1.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the %% operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the %% operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the %% operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;

                case BoolValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToBool);
                    CodeContainer::codeContainer->FillInArg2(&$3.boolValue, sizeof(bool));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case CharValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToChar);
                    CodeContainer::codeContainer->FillInArg2(&$3.charValue, sizeof(char));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case IntValue:
                    CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                    CodeContainer::codeContainer->FillInArg2(&$3.intValue, sizeof(int));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    break;
                case StringValue:
                    printf("ERROR:right value of the %% operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
            break;
        case BoolValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToBool);
            CodeContainer::codeContainer->FillInArg1(&$1.boolValue, sizeof(bool));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the %% operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the %% operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the %% operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue % $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue % $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue % $3.intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the %% operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case CharValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToChar);
            CodeContainer::codeContainer->FillInArg1(&$1.charValue, sizeof(char));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the %% operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the %% operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the %% operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue % $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue % $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.charValue % $3.intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the %% operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case IntValue:

            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            CodeContainer::codeContainer->FillInArg1(&$1.intValue, sizeof(int));
            switch ($3.expValueType) {
                case Void:
                    printf("ERROR:right value of the %% operation cannot be <void>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case RefInStack:
                    printf("ERROR:right value of the %% operation cannot be <reference>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case DoubleInStack:
                case DoubleInHeap:
                case DoubleValue:
                    printf("ERROR:right value of the %% operation cannot be <double>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                case BoolInStack:
                case CharInStack:
                case IntInStack:
                case BoolInHeap:
                case CharInHeap:
                case IntInHeap:
                    offset = $3.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg2ParseMethod($3.agrParseMethod);
                    CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
                    $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
                    CodeContainer::codeContainer->FillInArg3ParseMethod($$.agrParseMethod);
                    offset = $$.domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                    break;
                case BoolValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue % $3.boolValue;
                    break;
                case CharValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue % $3.charValue;
                    break;
                case IntValue:
                    CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
                    $$.length--;
                    $$.expType = EVALUE;
                    $$.expValueType = IntValue;
                    $$.agrParseMethod = ToInt;
                    $$.intValue = $1.intValue % $3.intValue;
                    break;
                case StringValue:
                    printf("ERROR:right value of the %% operation cannot be <string>.\n");
                    CodeContainer::codeContainer->Clear();YYERROR;
                    break;
                default:;
            }
            break;
        case StringValue:
            printf("ERROR:left value of the %% operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
|
	S_SUB
	exp
	%prec NEGATIVE	{
    if ($2.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($2.stringValue, &$2)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $2.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($2.startPoint, preLength);
            $2.length++;
        }
    }
    $$.expType = EARITH;
    if ($2.expType == ETRANSIT) {
        while (!$2.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($2.boolExpInfo->mapStack.top().startPointInReal,
                                                $2.boolExpInfo->mapStack.top().startPointInReal +
                                                $2.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($2.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $2.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $2.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($2.boolExpInfo->mapStack.top().startPointInBackup,
                                           $2.boolExpInfo->mapStack.top().startPointInBackup +
                                           $2.boolExpInfo->mapStack.top().lengthInBackup);
            $2.length -=
                    $2.boolExpInfo->mapStack.top().lengthInReal - $2.boolExpInfo->mapStack.top().lengthInBackup;
            $2.boolExpInfo->mapStack.pop();

        }
    }

    $$.length = $2.length + 1;
    $$.startPoint = $2.startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(NEG);

    switch ($2.expValueType) {
        case Void:
            printf("ERROR:left value of the - operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the - operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = $2.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($2.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            $$.domainTableItem=symbolTable->CreateTempVar("int", &$$);
            CodeContainer::codeContainer->FillInArg2ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
            break;
        case DoubleInStack:
        case DoubleInHeap:
            offset = $2.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($2.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            $$.domainTableItem=symbolTable->CreateTempVar("double", &$$);
            CodeContainer::codeContainer->FillInArg2ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
            break;
        case BoolValue:
            $$.expType = EVALUE;
            $$.agrParseMethod = ToInt;
            $$.intValue = -$2.boolValue;
            $$.expValueType=IntValue;
            CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
            $$.length--;
        case CharValue:
            $$.expType = EVALUE;
            $$.agrParseMethod = ToInt;
            $$.intValue = -$2.charValue;
            $$.expValueType=IntValue;
            CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
            $$.length--;
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            $$.expType = EVALUE;
            $$.agrParseMethod = ToInt;
            $$.intValue = -$2.intValue;
            $$.expValueType=IntValue;
            CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
            $$.length--;
            break;
        case DoubleValue:
            $$.expType = EVALUE;
            $$.agrParseMethod = ToDouble;
            $$.doubleValue = -$2.doubleValue;
            $$.expValueType=DoubleValue;
            CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
            $$.length--;
            break;
        case StringValue:
            printf("ERROR:left value of the - operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
|
	S_NOT
	exp	{
    if ($2.expType == EUNKNOW) {
        int preLength = CodeContainer::codeContainer->Size();
        if (!symbolTable->SearchVarInDomainAndClassTable($2.stringValue, &$2)) {
            printf("ERROR:variable \"%s\" must be defined before use\n", $2.stringValue);
            CodeContainer::codeContainer->Clear();YYERROR;
        }
        if (preLength < CodeContainer::codeContainer->Size()) {
            CodeContainer::codeContainer->Move($2.startPoint, preLength);
            $2.length++;
        }
    }
    $$.expType = EARITH;
    if ($2.expType == ETRANSIT) {
        while (!$2.boolExpInfo->mapStack.empty()) {
            /*真实容器中删除*/
            CodeContainer::codeContainer->Erase($2.boolExpInfo->mapStack.top().startPointInReal,
                                                $2.boolExpInfo->mapStack.top().startPointInReal +
                                                $2.boolExpInfo->mapStack.top().lengthInReal);
            /*备用容器->真实容器*/
            CodeContainer::codeContainer->Insert($2.boolExpInfo->mapStack.top().startPointInReal,
                                                 FillBack::codeContainer,
                                                 $2.boolExpInfo->mapStack.top().startPointInBackup,
                                                 $2.boolExpInfo->mapStack.top().lengthInBackup);
            /*从备用容器中删除*/
            FillBack::codeContainer->Erase($2.boolExpInfo->mapStack.top().startPointInBackup,
                                           $2.boolExpInfo->mapStack.top().startPointInBackup +
                                           $2.boolExpInfo->mapStack.top().lengthInBackup);
            $2.length -=
                    $2.boolExpInfo->mapStack.top().lengthInReal - $2.boolExpInfo->mapStack.top().lengthInBackup;
            $2.boolExpInfo->mapStack.pop();

        }
    }

    $$.length = $2.length + 1;
    $$.startPoint = $2.startPoint;
    CodeContainer::codeContainer->PushBackCode();
    CodeContainer::codeContainer->FillInOp(NOT);

    switch ($2.expValueType) {
        case Void:
            printf("ERROR:left value of the ~ operation cannot be <void>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case RefInStack:
            printf("ERROR:left value of the ~ operation cannot be <reference>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case DoubleInStack:
        case DoubleInHeap:
        case DoubleValue:
            printf("ERROR:left value of the ~ operation cannot be <double>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        case BoolInStack:
        case CharInStack:
        case IntInStack:
        case BoolInHeap:
        case CharInHeap:
        case IntInHeap:
            offset = $2.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg1ParseMethod($2.agrParseMethod);
            CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
            $$.domainTableItem = symbolTable->CreateTempVar("int", &$$);
            CodeContainer::codeContainer->FillInArg2ParseMethod($$.agrParseMethod);
            offset = $$.domainTableItem->GetOffsetInStack();
            CodeContainer::codeContainer->FillInArg2(&offset, sizeof(void *));
            break;

        case BoolValue:
            $$.expType = EVALUE;
            $$.agrParseMethod = ToInt;
            $$.intValue = -$2.boolValue;
            $$.expValueType = IntValue;
            CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
            $$.length--;
        case CharValue:
            $$.expType = EVALUE;
            $$.agrParseMethod = ToInt;
            $$.intValue = -$2.charValue;
            $$.expValueType = IntValue;
            CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
            $$.length--;
            break;
        case IntValue:
            CodeContainer::codeContainer->FillInArg1ParseMethod(ToInt);
            $$.expType = EVALUE;
            $$.agrParseMethod = ToInt;
            $$.intValue = -$2.intValue;
            $$.expValueType = IntValue;
            CodeContainer::codeContainer->Erase(CodeContainer::codeContainer->Size() - 1);
            $$.length--;
            break;
        case StringValue:
            printf("ERROR:left value of the ~ operation cannot be <string>.\n");
            CodeContainer::codeContainer->Clear();YYERROR;
            break;
        default:;
    }
}
|
	S_LPAREN
	exp
	S_RPAREN	{
	$$=$2;
}
|
	V_INT	{
$$.expType=EVALUE;
$$.intValue=$1;
$$.expValueType=IntValue;
$$.agrParseMethod=ToInt;
$$.startPoint = CodeContainer::codeContainer->Size();
$$.length = 0;
}
|
	V_DOUBLE	{
$$.expType=EVALUE;
$$.doubleValue=$1;
$$.expValueType=DoubleValue;
$$.agrParseMethod=ToDouble;
$$.startPoint = CodeContainer::codeContainer->Size();
$$.length = 0;
}
|
	V_STRING	{
$$.expType=EVALUE;
strcpy($$.stringValue,$1);
$$.expValueType=StringValue;
$$.agrParseMethod=ToString;
$$.startPoint = CodeContainer::codeContainer->Size();
$$.length = 0;
}
|
	V_CHAR	{
$$.expType=EVALUE;
$$.charValue=$1;
$$.expValueType=CharValue;
$$.agrParseMethod=ToChar;
$$.startPoint = CodeContainer::codeContainer->Size();
$$.length = 0;
}
|
	K_TRUE	{
$$.expType=EVALUE;
$$.boolValue=true;
$$.expValueType=BoolValue;
$$.agrParseMethod=ToBool;
$$.startPoint = CodeContainer::codeContainer->Size();
$$.length = 0;
}
|
	K_FALSE	{
$$.expType=EVALUE;
$$.boolValue=false;
$$.expValueType=BoolValue;
$$.agrParseMethod=ToBool;
$$.startPoint = CodeContainer::codeContainer->Size();
$$.length = 0;
}
|
	V_ID	{
$$.expType=EUNKNOW;
strcpy($$.stringValue,$1);
$$.startPoint = CodeContainer::codeContainer->Size();
$$.length = 0;

}
;
formal_args:
	%empty	{
$$.size=0;
}
|
	exps	{
$$=$1;
}
;
exps:
	exp	{
$$.size=0;
$$.expInfos[$$.size++]=$1;
}
|
	exps
	S_COM
	exp	{
$$=$1;
$$.expInfos[$$.size++]=$3;
}
;
%%

int main(int argc,char** argv){

    if(argc<=1){
        printf("Please enter the file\n");
        return 0;
    }

    string inputFileName(argv[1]);
    string outputFileName;
    int pos = inputFileName.rfind('.');
    if (pos == string::npos) {
        cout << "File format is incorrect." << endl;
        return 0;
    } else {
        outputFileName = inputFileName.substr(0, pos);

        string suffix = inputFileName.substr(pos + 1, inputFileName.length() - pos - 1);

        if (suffix != "ez" && suffix != "EZ" && suffix != "eZ" && suffix != "Ez") {
            cout << "File format is incorrect." << endl;
            return 0;
        }
        outputFileName.append(".EzClass");
    }

    symbolTable=new SymbolTable::SymbolTable();
    fillBack = new FillBack();
    yyin=fopen(argv[1], "r");
    yyparse();
    if(FillBack::fillBack->GetHeader() == nullptr){
    printf("ERROR:main function is undefined.\n");
    CodeContainer::codeContainer->Clear();
    return 0;
    }
    printf("CodeContainer:\n");
    CodeContainer::codeContainer->Debug();
    printf("FillBack:\n");
    FillBack::codeContainer->Debug();

    ofstream outPutFile;

#ifdef _WIN32

#elif __linux__
    string cmd("touch ");
    cmd.append(outputFileName);
    system(cmd.data());
#endif
    outPutFile.open(outputFileName, ios::out | ios::binary);
    if (outPutFile) {
	outPutFile.write((char*)FillBack::fillBack->GetHeader(),sizeof(Header));
        for (int i = 0; i < CodeContainer::codeContainer->Size(); i++) {
            Code *item = CodeContainer::codeContainer->At(i);
            outPutFile.write((char*)item,sizeof(Code));
        }
    } else {
        cout << "Fail to open the file.";
        return 0;
    }
	
}
