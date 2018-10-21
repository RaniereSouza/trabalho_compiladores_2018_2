#include "compiler_headings.hpp"
#include "compiler_parser.tab.hpp"

const string TOKEN_TYPES [] = {"ID", "NUM", "KEY", "SYM", "ERROR"};
const string KEYWORDS    [] = {"void", "int", "if", "else", "return", "while"};

int line_num      = 0,
    token_counter = 0;

bool is_valid_symbol (char c) {
    return ((c == '+') ||
            (c == '-') ||
            (c == '*') ||
            (c == '/') ||
            (c == '>') ||
            (c == '<') ||
            (c == '=') ||
            (c == '!') ||
            (c == ';') ||
            (c == ',') ||
            (c == '(') ||
            (c == ')') ||
            (c == '{') ||
            (c == '}') ||
            (c == '[') ||
            (c == ']') );
}

bool is_whitespace (char c, int &line_num) {

    if (c == '\n') line_num++;

    return ((c == '\n') ||
            (c == '\t') ||
            (c ==  ' ') );
}

bool is_keyword (string word) {
    return ((word == KEYWORDS[0]) ||
            (word == KEYWORDS[1]) ||
            (word == KEYWORDS[2]) ||
            (word == KEYWORDS[3]) ||
            (word == KEYWORDS[4]) ||
            (word == KEYWORDS[5]) );
}

void write_token (ofstream &ofs, int line_num, int token_type, string &lexem) {
    //cout << "(" << line_num << "," << TOKEN_TYPES[token_type] << ",\"" << lexem << "\")\n";
    ofs << "(" << line_num << "," << TOKEN_TYPES[token_type] << ",\"" << lexem << "\")\n";
    lexem = "";
}

void handle_error (ifstream &ifs, ofstream &ofs, int line_num, string lexem, string error_message) {
    cout << "line: " << line_num << " ERROR: " << error_message << "\n";
    write_token(ofs, line_num, 4, lexem);
    ifs.close();
    ofs.close();
    exit(EXIT_FAILURE);
}

int gen_tokens_file (string code_path) {

    ifstream ifs (code_path, ifstream::in);
    if (!ifs.is_open()) {
        cout << "Could not open input file\n";
        exit(EXIT_FAILURE);
    }

    ofstream ofs      (tokens_path, ofstream::out);
    string   lexem    = "";
    int      line_num = 1;
    char     chunk;

    do {
        
        chunk = ifs.get();

        if (isdigit(chunk)) {

            //cout << "line: " << line_num << " digit: " << chunk << "\n";
            lexem += chunk;

            //getting the whole Number
            do {

                chunk = ifs.peek(); //look ahead

                if (isdigit(chunk)) {
                    //cout << "line: " << line_num << " digit: " << chunk << "\n";
                    lexem += ifs.get();
                }
                else if (isalpha(chunk)) {

                    lexem += ifs.get();

                    do {
                        chunk = ifs.get();
                        if (isalnum(chunk)) lexem += chunk;
                    } while (isalnum(chunk));
                    
                    handle_error(ifs, ofs, line_num, lexem, "illegal number or ID construction");
                }
                else {
                    write_token(ofs, line_num, 1, lexem);
                }
            } while (isdigit(chunk));

            continue;
        }
        else if (isalpha(chunk)) {

            //cout << "line: " << line_num << " letter: " << chunk << "\n";
            lexem += chunk;

            //getting the whole word first
            do {

                chunk = ifs.peek(); //look ahead

                if (isalnum(chunk)) {
                    //cout << "line: " << line_num << " letter or number: " << chunk << "\n";
                    lexem += ifs.get();
                }
            } while (isalnum(chunk));

            //test if is Keyword or ID
            if (is_keyword(lexem)) {
                write_token(ofs, line_num, 2, lexem);
            }
            else {
                write_token(ofs, line_num, 0, lexem);
            }

            continue;
        }
        else if (is_valid_symbol(chunk)) {

            //cout << "line: " << line_num << " symbol: " << chunk << "\n";
            lexem += chunk;

            chunk = ifs.peek(); //look ahead

            //skipping comments
            if ((chunk == '*') &&
                (lexem == "/")) {

                //cout << "line: " << line_num << " symbol: " << chunk << "\n";
                lexem += ifs.get();

                //cout << "/* START OF COMMENT \n";

                bool comment_has_ended  = false;
                int  comment_start_line = line_num;

                do {

                    chunk = ifs.get();

                    if ((ifs.peek() == '/') && //look ahead
                        (chunk      == '*')) {

                        //cout << "\nEND OF COMMENT */\n";
                        ifs.get();
                        lexem = "";
                        comment_has_ended = true;
                    }
                    else if (chunk == EOF) {
                        handle_error(ifs, ofs, comment_start_line, lexem, "comment was never closed");
                    }
                    else if (chunk == '\n') {
                        line_num++;
                    }
                } while (!comment_has_ended);

                continue;
            }

            //doesn't accept illegal ! (not) operator
            if ((chunk != '=') &&
                (lexem == "!")) {
                    handle_error(ifs, ofs, line_num, lexem, "illegal \"not\" operator");
            }

            //checking special Symbols with more than one character (==, <=, >=, !=)
            if ((chunk == '=') &&
               ((lexem == ">") ||
                (lexem == "<") ||
                (lexem == "=") ||
                (lexem == "!") )) {

                //cout << "line: " << line_num << " symbol: " << chunk << "\n";
                lexem += ifs.get();
            }

            write_token(ofs, line_num, 3, lexem);

            continue;
        }
        else if (is_whitespace(chunk, line_num) ||
                (chunk == EOF)) {
            //cout << "whitespace or end of file\n";
            continue;
        }
        else {
            lexem += chunk;
            handle_error(ifs, ofs, line_num, lexem, "illegal character");
        }
    } while (ifs.good());

    ifs.close();
    ofs.close();

    return 0;
}



/* compiler_scanner.cpp MUST DEFINE "YY_DECL" AND IMPLEMENT "yylex()" */
#ifndef YY_DECL
#define YY_DECL

void yylex_handle_error (string message, ifstream &tokens) {
    cerr << message << endl;
    yyerror(message);
    token_counter = 0;
    tokens.close();
};

void yylex_split_token (string token_text, string (&token_rep)[3]) {

    string buff   ("");
    int    count  = 0;     // which position of token_rep to fill
    bool   tk_val = false; // wether it's reading the token literal lexem value or not

    for (auto i:token_text) {
        if (i == '"') {
            tk_val = !tk_val;
        }
        else if ( tk_val     ||
                ((i != '(')  &&
                 (i != ',')  &&
                 (i != ')')  &&
                 (i != '"'))) {
            
            buff += i;
        }
        else if (buff != "") {
            token_rep[count] = buff;
            buff             = "";
            count++;
        };
    }

    if (buff != "") token_rep[count] = buff; 
}

/* IMPLEMENTS THE "yylex()" USED BY THE PARSER (NORMALLY GENERATED BY FLEX) */
int yylex (void) {

    ifstream      tokens      (tokens_path, ifstream::in); // file with the stream of tokens (each line is a token "TOKEN_TYPE token_val")
    string        line_buffer (""),
                  token_rep   [3];  // {token_line, token_type, token_value}
    int           token_num;

    if (token_counter == 0) { // check if it's not the first reading on the token stream
        //cout << "start feeding the parser" << endl;
        ofstream tree_file(parser_tree_path, ofstream::out);
        tree_file << "[program ";
        tree_file.close();
    }

    if (tokens.is_open()) { // if token stream file exists

        for (int i = 0; i < token_counter; i++) { // discarding all the tokens already read
            getline(tokens, line_buffer);
        }

        if (tokens.peek() == EOF) { // if exhausted all the tokens
            //cout << "end of token stream" << endl;
            //print_symbol_table();
            token_counter = 0;
            tokens.close();
            return 0; // YYEOF token
        }

        //cout << "passing token #" << (token_counter + 1) << endl;

        getline(tokens, line_buffer); // getting next token to deliver to the parser
        yylex_split_token(line_buffer, token_rep); // splitting token line, token type and token value

        //cout << "\ttoken line: "  << token_rep[0] << endl;
        //cout << "\ttoken type: "  << token_rep[1] << endl;
        //cout << "\ttoken value: " << token_rep[2] << endl;
        //print_symbol_table();

        line_num = stoi(token_rep[0]);

        if (token_rep[1] == "NUM") {
            yylval.number = stol(token_rep[2]);
            token_num = NUM;
        }
        else if (token_rep[1] == "ID") {
            yylval.identifier = strdup(token_rep[2].c_str());
            token_num = ID;
        }
        else if (token_rep[1] == "KEY") {

            yylval.keyword = strdup(token_rep[2].c_str());

            if      (token_rep[2] == KEYWORDS[0]) { token_num = VOID;  }
            else if (token_rep[2] == KEYWORDS[1]) { token_num = INT;   }
            else if (token_rep[2] == KEYWORDS[2]) { token_num = IF;    }
            else if (token_rep[2] == KEYWORDS[3]) { token_num = ELSE;  }
            else if (token_rep[2] == KEYWORDS[4]) { token_num = RET;   }
            else if (token_rep[2] == KEYWORDS[5]) { token_num = WHILE; }
            else { yylex_handle_error("unrecognized token value on stream", tokens); }
        }
        else if (token_rep[1] == "SYM") {

            yylval.symbol = strdup(token_rep[2].c_str());

            if      (token_rep[2] == "," ) { token_num = COMMA; }
            else if (token_rep[2] == ";" ) { token_num = SEMIC; }
            else if (token_rep[2] == "+" ) { token_num = ADD;   }
            else if (token_rep[2] == "-" ) { token_num = SUB;   }
            else if (token_rep[2] == "*" ) { token_num = MUL;   }
            else if (token_rep[2] == "/" ) { token_num = DIV;   }
            else if (token_rep[2] == "<" ) { token_num = LT;    }
            else if (token_rep[2] == ">" ) { token_num = GT;    }
            else if (token_rep[2] == "<=") { token_num = LTE;   }
            else if (token_rep[2] == ">=") { token_num = GTE;   }
            else if (token_rep[2] == "==") { token_num = EQ;    }
            else if (token_rep[2] == "!=") { token_num = NEQ;   }
            else if (token_rep[2] == "=" ) { token_num = ASGN;  }
            else if (token_rep[2] == "(" ) { token_num = L_PAR; }
            else if (token_rep[2] == ")" ) { token_num = R_PAR; }
            else if (token_rep[2] == "{" ) { token_num = L_CUR; }
            else if (token_rep[2] == "}" ) { token_num = R_CUR; }
            else if (token_rep[2] == "[" ) { token_num = L_BRA; }
            else if (token_rep[2] == "]" ) { token_num = R_BRA; }
            else { yylex_handle_error("unrecognized token value on stream", tokens); }
        }
        else {
            yylex_handle_error("unrecognized token type on stream", tokens);
        }
    }
    else {
        yylex_handle_error("tokens' stream file didn't open", tokens);
    }

    token_counter++; // saving the line of the token read in this iteration

    tokens.close();
    return token_num;
}

#endif