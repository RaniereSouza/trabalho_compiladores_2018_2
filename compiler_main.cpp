#include "compiler_headings.hpp"

string mips_code_path;

int main(int argc, char **argv) {

    if (argc < 3) {
        cout << "Not enough arguments to run code\n";
        exit(EXIT_FAILURE);
    }

    if (gen_tokens_file(argv[1]) == 0) {

        if (yyparse() == 0) {

            mips_code_path = argv[2];

            if (codegen() == 0) {
                exit(EXIT_SUCCESS);
            }
        }
    }

    exit(EXIT_FAILURE);
}