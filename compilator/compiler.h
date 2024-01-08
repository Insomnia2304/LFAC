#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <stdbool.h>
#define LENMAX 1024
#define DMAX 16

char domain[LENMAX] = "global";
char functionDomain[LENMAX] = "global";
char paramTemp[LENMAX] = "-";
char args[LENMAX];
char lvalue[LENMAX];
char identif[LENMAX], indexStr[DMAX];

struct clasa
{
    char name[LENMAX];
} classes[LENMAX];
int classNumber = 0;

struct var
{
    char type[LENMAX];
    char name[LENMAX];
    char value[LENMAX];
    char domain[LENMAX];
    bool isConst;
} vars[LENMAX];
int varsNumber = 0;

struct func
{
    char returnType[LENMAX];
    char name[LENMAX];
    char paramList[LENMAX];
    char domain[LENMAX];
} func[LENMAX];
int funcNumber = 0;

enum categoryEnum
{
    NUMBER_FLOAT,
    NUMBER_INT,
    NUMBER_BOOL,
    CHAR,
    STRING,
    OPERATOR,
    IDENTIFIER,
    OTHER
};

struct AST
{
    char label[LENMAX];
    categoryEnum category, treeType;
    AST *left;
    AST *right;
};

struct resultAST
{
    const char *resultStr;
    categoryEnum treeType;
};

// Conversion functions

char *itoaCustom(int value)
{
    char buffer[DMAX];
    sprintf(buffer, "%d", value);
    return strdup(buffer);
}

char *ftoaCustom(float value)
{
    char buffer[DMAX];
    sprintf(buffer, "%f", value);
    return strdup(buffer);
}

int atob(const char *valueStr)
{
    if (strcmp(valueStr, "true") == 0)
        return 1;
    return 0;
}

categoryEnum convertStringToEnum(const char *type)
{
    if (strstr(type, "int"))
        return NUMBER_INT;
    if (strstr(type, "float"))
        return NUMBER_FLOAT;
    if (strstr(type, "bool"))
        return NUMBER_BOOL;
    if (strstr(type, "char"))
        return CHAR;
    if (strstr(type, "string"))
        return STRING;
    return OTHER;
}

const char *convertEnumToString(categoryEnum category)
{
    if (category == NUMBER_FLOAT)
        return "float";
    if (category == NUMBER_INT)
        return "int";
    if (category == NUMBER_BOOL)
        return "bool";
    if (category == STRING)
        return "string";
    if (category == CHAR)
        return "char";
    return "user defined type";
}

// check

int checkSize(resultAST dim, int yylineno)
{
    if (dim.treeType != NUMBER_INT)
    {
        printf("[Line %d] Error: Incorrect array dimension.\n", yylineno);
        exit(0);
    }
    int dimInt = atoi(dim.resultStr);
    if (dimInt < 1)
    {
        printf("[Line %d] Error: Incorrect array dimension.\n", yylineno);
        exit(0);
    }
    return dimInt;
}

void checkClass(const char *name, int yylineno)
{
    int i;
    for (i = 0; i < classNumber; i++)
        if (strcmp(classes[i].name, name) == 0)
        {
            break;
        }
    if (i == classNumber)
    {
        printf("[Line %d] Error: Class %s is not defined\n", yylineno, name);
        exit(0);
    }
}

void checkValidIndex(const char *name, int size, int yylineno)
{
    for (int i = 0; i < varsNumber; i++)
        if (strcmp(vars[i].name, name) == 0)
        {
            char copy[LENMAX];
            strcpy(copy, vars[i].type);
            char *p = strchr(copy, '[') + 1;
            p[strlen(p) - 1] = 0;
            int dimInt = atoi(p);

            if (!(0 <= size && size < dimInt))
            {
                printf("[Line %d] Error: Invalid vector index\n", yylineno);
                exit(0);
            }
        }
}

void compareParamWithArgs(const char *functionName, char args[1024], const char *domain, int yylineno)
{

    for (int i = 0; i < funcNumber; i++)
        if (strcmp(func[i].name, functionName) == 0 && strcmp(func[i].domain, domain) == 0)
        {
            if (strcmp(func[i].paramList, args) != 0)
            {
                printf("[Line %d] Error: Incorrect parameters passed to the function %s.\n", yylineno, functionName);
                exit(0);
            }
            args[0] = 0;
            return;
        }
    printf("[Line %d] Error: Undefined function %s called.\n", yylineno, functionName);
    exit(0);
}

// add-to
void addVar(const char *type, const char *name, resultAST value, const char *domain, bool isConst, int yylineno)
{
    for (int i = 0; i < varsNumber; i++)
        if (strcmp(vars[i].name, name) == 0 && strcmp(vars[i].domain, domain) == 0)
        {
            printf("[Line %d] Error: Variable %s has already been declared\n", yylineno, name);
            exit(0);
        }
    if (value.treeType != OTHER && value.treeType != convertStringToEnum(type))
    {
        printf("[Line %d] Error: The language does not support casting for variable %s\n", yylineno, name);
        exit(0);
    }
    strcpy(vars[varsNumber].type, type);
    strcpy(vars[varsNumber].name, name);
    strcpy(vars[varsNumber].value, value.resultStr);
    strcpy(vars[varsNumber].domain, domain);
    vars[varsNumber].isConst = isConst;
    varsNumber++;
}

void addArray(const char *type, const char *name, int size, const char *domain, bool isConst, int yylineno)
{
    for (int i = 0; i < varsNumber; i++)
        if (strcmp(vars[i].name, name) == 0 && strcmp(vars[i].domain, domain) == 0)
        {
            printf("[Line %d] Error: Variable %s has already been declared\n", yylineno, name);
            exit(0);
        }

    sprintf(vars[varsNumber].type, "%s[%d]", type, size);
    strcpy(vars[varsNumber].name, name);

    char values[LENMAX], initValue[10];
    values[0] = 0;
    initValue[0] = 0;
    strcmp(type, "bool") == 0 ? strcpy(initValue, "false") : strcpy(initValue, "0");
    for (int i = 0; i < size; i++)
    {
        strcat(values, initValue);
        strcat(values, " ");
    }
    values[strlen(values) - 1] = 0;

    strcpy(vars[varsNumber].value, values);
    strcpy(vars[varsNumber].domain, domain);
    vars[varsNumber].isConst = isConst;
    varsNumber++;
}

void addParameter()
{
    if (strcmp(paramTemp, "-") == 0)
        paramTemp[0] = 0;
    else
        strcat(paramTemp, ", ");
    strcat(paramTemp, vars[varsNumber - 1].type);
}

void addFunction(const char *returnType, const char *name, const char *domain, int yylineno)
{
    for (int i = 0; i < funcNumber; i++)
        if (strcmp(func[i].name, name) == 0 && strcmp(func[i].domain, domain) == 0)
        {
            printf("[Line %d] Error: Function %s has already been declared\n", yylineno, name);
            exit(0);
        }
    strcpy(func[funcNumber].returnType, returnType);
    strcpy(func[funcNumber].name, name);
    strcpy(func[funcNumber].paramList, paramTemp);
    strcpy(func[funcNumber].domain, domain);
    strcpy(paramTemp, "-");
    funcNumber++;
}

void addClass(const char *name, int yylineno)
{
    for (int i = 0; i < classNumber; i++)
        if (strcmp(classes[i].name, name) == 0)
        {
            printf("[Line %d] Error: Class %s has already been defined\n", yylineno, name);
            exit(0);
        }
    strcpy(classes[classNumber].name, name);
    classNumber++;
}

// get

void extract_Id_And_Index(const char *element, int yylineno)
{
    int i, j;
    identif[0] = indexStr[0] = 0;
    for (i = 0; element[i] != '['; i++)
        identif[i] = element[i];
    identif[i++] = 0;
    for (j = 0; element[i] != ']'; j++, i++)
    {
        if (!(element[i] >= '0' && element[i] <= '9')) // is not digit
        {
            printf("[Line %d] Error: Invalid vector index\n", yylineno);
            exit(0);
        }
        indexStr[j] = element[i];
    }

    indexStr[j] = 0;
}

const char *getFuncType(const char *name)
{
    for (int i = 0; i < funcNumber; i++)
        if (strcmp(func[i].name, name) == 0)
            return func[i].returnType;
    return "?";
}

const char *getVarValue(const char *name, int yylineno)
{
    if (strchr(name, '[') == 0) // simple variable
    {
        // first, try to find something local
        for (int i = 0; i < varsNumber; i++)
            if (strcmp(vars[i].name, name) == 0 && strcmp(vars[i].domain, domain) == 0)
            {
                return vars[i].value;
            }

        // nothing local, try global
        for (int i = 0; i < varsNumber; i++)
            if (strcmp(vars[i].name, name) == 0 && strcmp(vars[i].domain, "global") == 0)
            {
                return vars[i].value;
            }
    }
    else // element of an array
    {
        extract_Id_And_Index(name, yylineno);
        int index = atoi(indexStr);
        checkValidIndex(identif, index, yylineno);

        // first, try to find something local
        for (int i = 0; i < varsNumber; i++)
            if (strcmp(vars[i].name, identif) == 0 && strcmp(vars[i].domain, domain) == 0)
            {
                char newValues[LENMAX];
                strcpy(newValues, vars[i].value);
                char *q = strtok(newValues, " ");
                int contor = 0;
                while (q)
                {
                    if (contor == index)
                    {
                        return q;
                    }
                    q = strtok(NULL, " ");
                    contor++;
                }
            }
        // nothing local, try global
        for (int i = 0; i < varsNumber; i++)
            if (strcmp(vars[i].name, identif) == 0 && strcmp(vars[i].domain, "global") == 0)
            {
                char newValues[LENMAX];
                strcpy(newValues, vars[i].value);
                char *q = strtok(newValues, " ");
                int contor = 0;
                while (q)
                {
                    if (contor == index)
                    {
                        return q;
                    }
                    q = strtok(NULL, " ");
                    contor++;
                }
            }
    }

    return "?";
}

const char *getVarType(const char *name)
{
    if (strchr(name, '[') == 0) // simple variable
    {
        // first, try to find something local
        for (int i = 0; i < varsNumber; i++)
            if (strcmp(vars[i].name, name) == 0 && strcmp(vars[i].domain, domain) == 0)
            {
                return vars[i].type;
            }
        // nothing local, try global
        for (int i = 0; i < varsNumber; i++)
            if (strcmp(vars[i].name, name) == 0 && strcmp(vars[i].domain, "global") == 0)
            {
                return vars[i].type;
            }
    }
    else // element of an array
    {
        char identif[LENMAX];
        int i;
        identif[0] = 0;
        for (i = 0; name[i] != '['; i++)
            identif[i] = name[i];
        identif[i] = 0;

        // first, try to find something local
        for (int i = 0; i < varsNumber; i++)
            if (strcmp(vars[i].name, identif) == 0 && strcmp(vars[i].domain, domain) == 0)
            {
                if (strstr(vars[i].type, "int"))
                    return "int";
                if (strstr(vars[i].type, "float"))
                    return "float";
                if (strstr(vars[i].type, "bool"))
                    return "bool";
            }
        // nothing local, try global
        for (int i = 0; i < varsNumber; i++)
            if (strcmp(vars[i].name, identif) == 0 && strcmp(vars[i].domain, "global") == 0)
            {
                if (strstr(vars[i].type, "int"))
                    return "int";
                if (strstr(vars[i].type, "float"))
                    return "float";
                if (strstr(vars[i].type, "bool"))
                    return "bool";
            }
    }

    return "?";
}

void updateVarValue(char *name, resultAST value, int yylineno)
{
    if (strchr(name, '[') == 0) // simple variable
    {
        // first, try to find something local
        for (int i = 0; i < varsNumber; i++)
            if (strcmp(vars[i].name, name) == 0 && strcmp(vars[i].domain, domain) == 0)
            {
                if (vars[i].isConst)
                {
                    printf("[Line %d] Error: The value of constant variable %s cannot be modified\n", yylineno, name);
                    exit(0);
                }
                if (value.treeType != OTHER && convertStringToEnum(vars[i].type) != value.treeType)
                {
                    printf("[Line %d] Error: The language does not support casting for variable %s\n", yylineno, name);
                    exit(0);
                }
                strcpy(vars[i].value, value.resultStr);
                return;
            }

        // nothing local, try global
        for (int i = 0; i < varsNumber; i++)
            if (strcmp(vars[i].name, name) == 0 && strcmp(vars[i].domain, "global") == 0)
            {
                if (vars[i].isConst)
                {
                    printf("[Line %d] Error: The value of constant variable %s cannot be modified\n", yylineno, name);
                    exit(0);
                }
                if (value.treeType != OTHER && convertStringToEnum(vars[i].type) != value.treeType)
                {
                    printf("[Line %d] Error: The language does not support casting for variable %s\n", yylineno, name);
                    exit(0);
                }
                strcpy(vars[i].value, value.resultStr);
                return;
            }
    }
    else // element of an aray
    {
        // check index
        extract_Id_And_Index(name, yylineno);
        int index = atoi(indexStr);
        checkValidIndex(identif, index, yylineno);
        // first, try to find something local
        for (int i = 0; i < varsNumber; i++)
            if (strcmp(vars[i].name, identif) == 0 && strcmp(vars[i].domain, domain) == 0)
            {
                if (value.treeType != OTHER && convertStringToEnum(vars[i].type) != value.treeType)
                {
                    printf("[Line %d] Error: The language does not support casting for variable %s\n", yylineno, name);
                    exit(0);
                }
                // update
                char newValues[LENMAX];
                newValues[0] = 0;
                char *q = strtok(vars[i].value, " ");
                int contor = 0;
                while (q)
                {
                    if (contor == index)
                        strcat(newValues, value.resultStr);
                    else
                        strcat(newValues, q);
                    strcat(newValues, " ");
                    q = strtok(NULL, " ");
                    contor++;
                }
                newValues[strlen(newValues) - 1] = 0;
                strcpy(vars[i].value, newValues);
                return;
            }

        // nothing local, try global
        for (int i = 0; i < varsNumber; i++)
            if (strcmp(vars[i].name, identif) == 0 && strcmp(vars[i].domain, "global") == 0)
            {
                if (value.treeType != OTHER && convertStringToEnum(vars[i].type) != value.treeType)
                {
                    printf("[Line %d] Error: The language does not support casting for variable %s\n", yylineno, name);
                    exit(0);
                }
                // update
                char newValues[LENMAX];
                newValues[0] = 0;
                char *q = strtok(vars[i].value, " ");
                int contor = 0;
                while (q)
                {
                    if (contor == index)
                        strcat(newValues, value.resultStr);
                    else
                        strcat(newValues, q);
                    strcat(newValues, " ");
                    q = strtok(NULL, " ");
                    contor++;
                }
                newValues[strlen(newValues) - 1] = 0;
                strcpy(vars[i].value, newValues);
                return;
            }
    }

    printf("[Line %d] Error: Undeclared variable %s used in expression\n", yylineno, name);
    exit(0);
}

// AST

AST *buildTree(const char *label, categoryEnum category, AST *left, AST *right, int yylineno)
{
    AST *node = new AST;
    strcpy(node->label, label);
    node->category = category;
    node->left = left;
    node->right = right;

    // decide AST tree type
    if (node->left == NULL && node->right == NULL) // leaf: constant number, identifier, array element, function call etc.
    {
        if (category == IDENTIFIER)
        {

            const char *type = getVarType(label);
            if (strcmp(type, "?") == 0)
            {
                printf("[Line %d] Error: Undeclared variable %s used in expression\n", yylineno, label);
                exit(0);
            }
            else
            {
                node->treeType = convertStringToEnum(type);
            }
        }
        else
        {
            node->treeType = node->category;
        }
    }
    else // operator (+,-,/,*,>,<,&&,||, not etc.)
    {
        if (node->category == NUMBER_BOOL) // relational/logical operators
        {
            node->treeType = NUMBER_BOOL;
            return node;
        }

        if (node->right != NULL && (node->left)->treeType != (node->right)->treeType) // left !=right
        {
            if ((node->left)->treeType == OTHER)
            {
                node->treeType = (node->right)->treeType;
                return node;
            }
            if ((node->right)->treeType == OTHER)
            {
                node->treeType = (node->left)->treeType;
                return node;
            }
            printf("[Line %d] Error: Operand types are different\n", yylineno);
            exit(0);
        }
        else
        {
            node->treeType = (node->left)->treeType;
        }
    }
    return node;
}

resultAST evaluateTree(AST *root, int yylineno)
{
    resultAST res;
    if (root->left && root->right) // opeator
    {

        resultAST left = evaluateTree(root->left, yylineno);
        resultAST right = evaluateTree(root->right, yylineno);
        if (left.treeType == OTHER)
            left.resultStr = "0";
        if (right.treeType == OTHER)
            right.resultStr = "0";

        if (root->treeType == NUMBER_FLOAT)
        {
            float leftValue = atof(left.resultStr);
            float rightValue = atof(right.resultStr);
            float resultValue;
            if (strcmp(root->label, "+") == 0)
                resultValue = leftValue + rightValue;
            if (strcmp(root->label, "-") == 0)
                resultValue = leftValue - rightValue;
            if (strcmp(root->label, "*") == 0)
                resultValue = leftValue * rightValue;
            if (strcmp(root->label, "/") == 0)
            {
                if (rightValue == 0)
                {
                    printf("[Line %d] Error: Division by zero is not possible\n", yylineno);
                    exit(0);
                }
                resultValue = leftValue / rightValue;
            }
            if (strcmp(root->label, "%") == 0)
            {
                printf("[Line %d] Error: The modulo operator is not supported for this data type\n", yylineno);
                exit(0);
            }
            res.resultStr = ftoaCustom(resultValue);
        }
        else if (root->treeType == NUMBER_INT)
        {

            int leftValue = atoi(left.resultStr);
            int rightValue = atoi(right.resultStr);
            int resultValue;
            if (strcmp(root->label, "+") == 0)
                resultValue = leftValue + rightValue;
            if (strcmp(root->label, "-") == 0)
                resultValue = leftValue - rightValue;
            if (strcmp(root->label, "*") == 0)
                resultValue = leftValue * rightValue;
            if (strcmp(root->label, "/") == 0)
            {
                if (rightValue == 0)
                {
                    printf("[Line %d] Error: Division by zero is not possible\n", yylineno);
                    exit(0);
                }
                resultValue = leftValue / rightValue;
            }
            if (strcmp(root->label, "%") == 0)
            {
                if (rightValue == 0)
                {
                    printf("[Line %d] Error: Division by zero is not possible\n", yylineno);
                    exit(0);
                }
                resultValue = leftValue % rightValue;
            }

            res.resultStr = itoaCustom(resultValue);
        }
        else if (root->treeType == NUMBER_BOOL)
        {
            bool resultValue;

            if (left.treeType == NUMBER_FLOAT && right.treeType == NUMBER_FLOAT)
            {
                float leftValue = atof(left.resultStr);
                float rightValue = atof(right.resultStr);
                if (strcmp(root->label, "&&") == 0)
                    resultValue = leftValue && rightValue;
                if (strcmp(root->label, "||") == 0)
                    resultValue = leftValue || rightValue;
                if (strcmp(root->label, ">") == 0)
                    resultValue = leftValue > rightValue;
                if (strcmp(root->label, "<") == 0)
                    resultValue = leftValue < rightValue;
                if (strcmp(root->label, ">=") == 0)
                    resultValue = leftValue >= rightValue;
                if (strcmp(root->label, "<=") == 0)
                    resultValue = leftValue <= rightValue;
                if (strcmp(root->label, "==") == 0)
                    resultValue = leftValue == rightValue;
                if (strcmp(root->label, "!=") == 0)
                    resultValue = leftValue != rightValue;
            }
            if (left.treeType == NUMBER_FLOAT && right.treeType != NUMBER_FLOAT)
            {
                float leftValue = atof(left.resultStr);
                int rightValue = (right.treeType == NUMBER_INT) ? atoi(right.resultStr) : atob(right.resultStr);
                if (strcmp(root->label, "&&") == 0)
                    resultValue = leftValue && rightValue;
                if (strcmp(root->label, "||") == 0)
                    resultValue = leftValue || rightValue;
                if (strcmp(root->label, ">") == 0)
                    resultValue = leftValue > rightValue;
                if (strcmp(root->label, "<") == 0)
                    resultValue = leftValue < rightValue;
                if (strcmp(root->label, ">=") == 0)
                    resultValue = leftValue >= rightValue;
                if (strcmp(root->label, "<=") == 0)
                    resultValue = leftValue <= rightValue;
                if (strcmp(root->label, "==") == 0)
                    resultValue = leftValue == rightValue;
                if (strcmp(root->label, "!=") == 0)
                    resultValue = leftValue != rightValue;
            }
            if (left.treeType != NUMBER_FLOAT && right.treeType == NUMBER_FLOAT)
            {
                int leftValue = (left.treeType == NUMBER_INT) ? atoi(left.resultStr) : atob(left.resultStr);
                float rightValue = atof(right.resultStr);
                if (strcmp(root->label, "&&") == 0)
                    resultValue = leftValue && rightValue;
                if (strcmp(root->label, "||") == 0)
                    resultValue = leftValue || rightValue;
                if (strcmp(root->label, ">") == 0)
                    resultValue = leftValue > rightValue;
                if (strcmp(root->label, "<") == 0)
                    resultValue = leftValue < rightValue;
                if (strcmp(root->label, ">=") == 0)
                    resultValue = leftValue >= rightValue;
                if (strcmp(root->label, "<=") == 0)
                    resultValue = leftValue <= rightValue;
                if (strcmp(root->label, "==") == 0)
                    resultValue = leftValue == rightValue;
                if (strcmp(root->label, "!=") == 0)
                    resultValue = leftValue != rightValue;
            }
            if (left.treeType != NUMBER_FLOAT && right.treeType != NUMBER_FLOAT)
            {
                int leftValue = (left.treeType == NUMBER_INT) ? atoi(left.resultStr) : atob(left.resultStr);
                int rightValue = (right.treeType == NUMBER_INT) ? atoi(right.resultStr) : atob(right.resultStr);
                if (strcmp(root->label, "&&") == 0)
                    resultValue = leftValue && rightValue;
                if (strcmp(root->label, "||") == 0)
                    resultValue = leftValue || rightValue;
                if (strcmp(root->label, ">") == 0)
                    resultValue = leftValue > rightValue;
                if (strcmp(root->label, "<") == 0)
                    resultValue = leftValue < rightValue;
                if (strcmp(root->label, ">=") == 0)
                    resultValue = leftValue >= rightValue;
                if (strcmp(root->label, "<=") == 0)
                    resultValue = leftValue <= rightValue;
                if (strcmp(root->label, "==") == 0)
                    resultValue = leftValue == rightValue;
                if (strcmp(root->label, "!=") == 0)
                    resultValue = leftValue != rightValue;
                if (strcmp(root->label, "+") == 0)
                    resultValue = leftValue + rightValue;
                if (strcmp(root->label, "-") == 0)
                    resultValue = leftValue - rightValue;
                if (strcmp(root->label, "*") == 0)
                    resultValue = leftValue * rightValue;
                if (strcmp(root->label, "/") == 0)
                {
                    if (rightValue == 0)
                    {
                        printf("[Line %d] Error: Division by zero is not possible\n", yylineno);
                        exit(0);
                    }
                    resultValue = leftValue / rightValue;
                }
                if (strcmp(root->label, "%") == 0)
                {
                    if (rightValue == 0)
                    {
                        printf("[Line %d] Error: Division by zero is not possible\n", yylineno);
                        exit(0);
                    }
                    resultValue = leftValue % rightValue;
                }
            }
            if (!resultValue)
                res.resultStr = "false";
            else
                res.resultStr = "true";
        }
        else if (root->treeType == CHAR || root->treeType == STRING)
        {
            printf("[Line %d] Error: The operation is undefined\n", yylineno);
            exit(0);
        }
    }
    else if (root->left == NULL) // leaf
    {
        if (root->category == NUMBER_INT || root->category == NUMBER_FLOAT || root->category == NUMBER_BOOL || root->category == CHAR || root->category == STRING)
        {
            res.resultStr = root->label;
        }
        else if (root->category == IDENTIFIER)
        {
            res.resultStr = getVarValue(root->label, yylineno);
        }
    }
    else // operator not
    {

        bool resultValue;
        resultAST left = evaluateTree(root->left, yylineno);
        if (left.treeType == NUMBER_FLOAT)
        {
            float leftValue = atof(left.resultStr);
            resultValue = !leftValue;
        }
        else
        {
            int leftValue = (left.treeType == NUMBER_INT) ? atoi(left.resultStr) : atob(left.resultStr);
            resultValue = !leftValue;
        }
        if (!resultValue)
            res.resultStr = "false";
        else
            res.resultStr = "true";
    }

    if (root->treeType == OTHER)
        res.resultStr = root->label;

    res.treeType = root->treeType;
    return res;
}

// Others

void Eval(resultAST expr, int yylineno)
{
    printf("Function Eval was called at line %d. The result is: %s\n", yylineno, expr.resultStr);
}

void TypeOf(resultAST expr, int yylineno)
{
    printf("Function TypeOf was called at line %d. The type is: %s\n", yylineno, convertEnumToString(expr.treeType));
}

void print()
{
    for (int i = 0; i < varsNumber; i++)
        printf("%d. Name: %s, Type: %s, Value: %s, Domain: %s, Constant: %s\n", i + 1, vars[i].name, vars[i].type, vars[i].value, vars[i].domain, vars[i].isConst ? "yes" : "no");
    for (int i = 0; i < funcNumber; i++)
        printf("%d. Name: %s, Returned type: %s, Parameters: %s, Domain: %s\n", i + 1, func[i].name, func[i].returnType, func[i].paramList, func[i].domain);
}

const char *getTypeOfObject(const char *name, int yylineno)
{
    for (int i = 0; i < varsNumber; i++)
        if (strcmp(vars[i].name, name) == 0)
        {
            return vars[i].type;
        }
    printf("[Line %d] Error: Variable %s is not declared\n", yylineno, name);
    exit(0);
}
void isIdInClass(const char *object, const char *id, int yylineno)
{
    const char *clasa = getTypeOfObject(object, yylineno);
    for (int i = 0; i < varsNumber; i++)
        if (strcmp(vars[i].domain, clasa) == 0 && strcmp(vars[i].name, id) == 0)
        {
            return;
        }
    printf("[Line %d] Error: Variable %s is not declared in class %s\n", yylineno, id, clasa);
    exit(0);
}

void isMemberInClass(const char *object, const char *function, int yylineno)
{
    const char *clasa = getTypeOfObject(object, yylineno);
    for (int i = 0; i < funcNumber; i++)
        if (strcmp(func[i].domain, clasa) == 0 && strcmp(func[i].name, function) == 0)
        {
            return;
        }
    printf("[Line %d] Error: Function %s is not declared in class %s\n", yylineno, function, clasa);
    exit(0);
}