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

struct name_t {
    string type;
    string name;
};

struct func_t {
    name_t         def;
    vector<name_t> args;
    bool           has_returned;
    int            return_counter;
};

const string tokens_path      = "compiler_tokens.out",
             parser_tree_path = "compiler_parse_tree.syn";

extern string         mips_code_path;
extern int            token_counter,
                      line_num,
                      current_func;
extern vector<name_t> vars_stack;
extern vector<func_t> funcs_stack;

int    gen_tokens_file    (string code_path);
int    yylex              (void);
int    yyparse            (void);
void   yyerror            (string message);
void   open_scope         (string t);
bool   create_var         (string t,         string n);
bool   codegen_get_var    (string n,         name_t &holder);
string closest_scope_var  (string n);
int    get_func_index     (string n);
bool   close_scope        ();
void   print_symbol_table ();
void   write_to_tree      (string s);
int    codegen            (void);

#endif