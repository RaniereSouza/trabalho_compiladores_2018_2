#ifndef COMPILER_HEADINGS_HPP_INCLUDED
#define COMPILER_HEADINGS_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;

const string tokens_path = "compiler_tokens.out";

extern string parser_tree_path;
extern int    token_counter,
              line_num;

int  gen_tokens_file    (string code_path);
int  yylex              (void);
int  yyparse            (void);
void yyerror            (string message);
void print_symbol_table ();
void write_to_tree      (string s);

#endif