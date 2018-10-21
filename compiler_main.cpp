#include "compiler_headings.hpp"

string parser_tree_path;

int main(int argc, char **argv) {

    if (argc < 3) {
        cout << "Not enough arguments to run code\n";
        exit(EXIT_FAILURE);
    }

    if (gen_tokens_file(argv[1]) == 0) {

        parser_tree_path = argv[2];
        yyparse();

        exit(EXIT_SUCCESS);
    }

    exit(EXIT_FAILURE);
}