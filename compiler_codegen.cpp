#include "compiler_headings.hpp"

vector<int>    scope_stack      = {0};
vector<string> block_name_stack,
               var_labels_stack,
               assembly_stack;

int scope_counter = 0,
    if_counter    = 0,
    loop_counter  = 0,
    comp_counter  = 0;

void codegen_expressions (string &acc, int start);

int codegen (void) {

    ifstream ifs (parser_tree_path, ifstream::in);
    ofstream ofs (mips_code_path,   ofstream::out);
    string   acc ("");

    vars_stack.clear();
    current_func = -1;

    getline(ifs, acc);
    codegen_expressions(acc, 0);

    //cout << assembly_stack.back() << endl;
    ofs << assembly_stack.back() << endl;

    ofs.close();
    ifs.close();

    return 0;
}

bool has_only_digits (string s) {
    return (s.find_first_not_of("0123456789") == string::npos);
}

bool is_operator (string s) {
    return ((s == "+") ||
            (s == "-") ||
            (s == "*") ||
            (s == "/") );
}

bool is_comparator (string s) {
    return ((s == ">")  ||
            (s == ">=") ||
            (s == "<")  ||
            (s == "<=") ||
            (s == "==") ||
            (s == "!=") );
}

string codegen_integer (string number) {

    string full_text ("");

    full_text +=
        string(
        "##################\n") +
        "#start cgen(NUM):#\n" +
        "li $a0, " + number + "\n" +
        "##end cgen(NUM)###\n" +
        "##################\n";

    return full_text;
}

string codegen_operation (string op, string e1, string e2) {

    string assembly_operation (""),
           full_text          ("");

    if      (op == "+")  { assembly_operation = "add"; }
    else if (op == "-")  { assembly_operation = "sub"; }
    else if (op == "*")  { assembly_operation = "mul"; }
    else if (op == "/")  { assembly_operation = "div"; }

    full_text +=
        string(
        "#######################\n") +
        "#start cgen(E1 op E2):#\n" +
        e1 +
        "sw $a0, 0($sp)\n" +
        "addiu $sp, $sp, -4\n" +
        e2 +
        "lw $t0, 4($sp)\n" +
        assembly_operation + " $a0, $t0, $a0\n" +
        "addiu $sp, $sp, 4\n" +
        "##end cgen(E1 op E2)###\n" +
        "#######################\n";

    return full_text;
};

string codegen_comparison (string op, string e1, string e2) {

    string assembly_comparison (""),
           full_text           ("");

    if      (op == ">")   { assembly_comparison = "bgt"; }
    else if (op == ">=")  { assembly_comparison = "bge"; }
    else if (op == "<")   { assembly_comparison = "blt"; }
    else if (op == "<=")  { assembly_comparison = "ble"; }
    else if (op == "==")  { assembly_comparison = "beq"; }
    else if (op == "!=")  { assembly_comparison = "bne"; }

    full_text +=
        string(
        "#########################\n") +
        "#start cgen(E1 comp E2):#\n" +
        e1 +
        "sw $a0, 0($sp)\n" +
        "addiu $sp, $sp, -4\n" +
        e2 +
        "lw $t0, 4($sp)\n" +
        "addiu $sp, $sp, 4\n" +
        assembly_comparison + " $t0, $a0, true_comp_" + to_string(comp_counter) + "\n" +
        "li $a0, 0\n" +
        "b end_comp_" + to_string(comp_counter) + "\n" +
        "true_comp_" + to_string(comp_counter) + ":\n" +
        "li $a0, 1\n" +
        "end_comp_" + to_string(comp_counter) + ":\n" +
        "##end cgen(E1 comp E2)###\n" +
        "#########################\n";

    comp_counter++;

    return full_text;
};

string codegen_func_decl (string type, string name, string num_params, string compd_stmt) {

    string full_text ("");

    //cout << "func type: " << type << endl;
    //cout << "func name: " << name << endl;
    //cout << "func num_params: " << num_params << endl;
    //cout << "func compd_stmt: \n" << compd_stmt << endl;

    full_text +=
        "\n" +
        string(
        "#########################################\n") +
        "#start cgen(declare func ID(params) E1):#\n" +
        "func_" + name + ":\n" +
        "move $fp, $sp\n" +
        "sw $ra, 0($sp)\n" +
        "addiu $sp, $sp, -4\n" +
        compd_stmt +
        "lw $ra, 4($sp)\n" +
        "addiu $sp, $sp, " + to_string((4 * stoi(num_params)) + 8) + "\n" +
        "lw $fp, 0($sp)\n" +
        "jr $ra\n" +
        "##end cgen(declare func ID(params) E1)###\n" +
        "#########################################\n" +
        "\n";

    return full_text;
}

string codegen_args (vector<string> args_seq) {

    string full_text ("");

    full_text +=
    string(
    "########################\n") +
    "#start cgen(load args):#\n";
    for (unsigned int i = 0, len = args_seq.size(); i < len; i++) {
        full_text +=
            args_seq[i] +
            "sw $a0, 0($sp)\n" +
            "addiu $sp, $sp, -4\n";
    }
    full_text +=
    string(
    "##end cgen(load args)###\n") +
    "########################\n";

    return full_text;
}

string codegen_func_call (string name, string args) {

    string full_text ("");

    if (name == "input") {
        full_text +=
            string(
            "################################\n") +
            "#start cgen(call func input()):#\n" +
            "jal func_input\n" +
            "##end cgen(call func input())###\n" +
            "################################\n";
    }
    else if (name == "println") {
        full_text +=
            string(
            "#####################################\n") +
            "#start cgen(call func println(arg)):#\n" +
            args +
            "jal func_println\n" +
            "##end cgen(call func println(arg))###\n" +
            "#####################################\n";
    }
    else {
        full_text +=
            string(
            "#################################\n") +
            "#start cgen(call func ID(args)):#\n" +
            "sw $fp, 0($sp)\n" +
            "addiu $sp, $sp, -4\n" +
            args +
            "jal func_" + name + "\n" +
            "##end cgen(call func ID(args))###\n" +
            "#################################\n";
    }

    return full_text;
}

string codegen_var_decl (string type, string name) {

    string full_text     (""),
           assembly_type (""),
           init_value    ("");

    if (type == "int") { assembly_type = ".word"; init_value = "0"; }

    create_var("var", name);

    full_text +=
        string(
        "#############################\n") +
        "#start cgen(declare var ID):#\n" +
        "var_" + name + "_" + to_string(scope_stack.back()) +
        ": " + assembly_type + " " + init_value + "\n" +
        "##end cgen(declare var ID)###\n" +
        "#############################\n";

        return full_text;
}

string codegen_arr_decl (string type, string name, string size) {

    string full_text           (""),
           assembly_type_size  (""),
           init_values         ("");

    if (type == "int") { assembly_type_size = ".word"; }

    create_var("arr[" + size + "]", name);

    //cout << "type: " << type       << endl;
    //cout << "name: " << name       << endl;
    //cout << "size: " << stoi(size) << endl;

    if(stoi(size) > 0) {
        for (int i = 0, len = stoi(size) - 1; i < len; i++) {
            init_values += "0, ";
        }
        init_values += "0";
    }

    full_text +=
        string(
        "##################################\n") +
        "#start cgen(declare var ID[NUM]):#\n" +
        "var_" + name + "_" + to_string(scope_stack.back()) +
        ": " + assembly_type_size + " " + size + ", " + init_values + "\n" +
        "##end cgen(declare var ID[NUM])###\n" +
        "##################################\n";

        return full_text;
}

string codegen_var_access (string name) {

    string full_text ("");
    name_t var;

    if (codegen_get_var(name, var)) {

        string var_scope = closest_scope_var(name);
        if (var_scope == "global") { var_scope = "0"; }

        //cout << "var name: " << var.name << endl;
        //cout << "var type: " << var.type << endl;

        if (var.type == "var") {
            full_text +=
                string(
                "############################\n") +
                "#start cgen(get ID as var):#\n" +
                "lw $a0, var_" + name + "_" + var_scope + "\n" +
                "la $t0, var_" + name + "_" + var_scope + "\n" +
                "##end cgen(get ID as var)###\n" +
                "############################\n";
        }
        else if (var.type.find("arr") != string::npos) {
            full_text +=
                string(
                "############################\n") +
                "#start cgen(get ID as var):#\n" +
                "la $a0, var_" + name + "_" + var_scope + "\n" +
                "##end cgen(get ID as var)###\n" +
                "############################\n";
        }
        else if ((var.type == "param") && (current_func >= 0)) {

            func_t func    = funcs_stack[current_func];
            int    arg_num = 1;

            for (auto i:func.args) {
                if (i.name == name) {
                    full_text +=
                    string(
                    "##############################\n") +
                    "#start cgen(get ID as param):#\n" +
                    "lw $a0, " + to_string(4 * arg_num) + "($fp)\n" +
                    "la $t0, " + to_string(4 * arg_num) + "($fp)\n" +
                    "##end cgen(get ID as param)###\n" +
                    "##############################\n";
                }
                arg_num++;
            }
        }
    } 

    return full_text;
}

string codegen_arr_access (string name, string index) {

    string full_text ("");
    name_t var;

    if (codegen_get_var(name, var)) {

        //cout << "var name: " << var.name << endl;
        //cout << "var type: " << var.type << endl;

        if (var.type != "param") {

            string var_scope = closest_scope_var(name);
            if (var_scope == "global") { var_scope = "0"; }

            full_text +=
                string(
                "#################################\n") +
                "#start cgen(get ID[NUM] as var):#\n" +
                index +
                "lw $t0, var_" + name + "_" + var_scope + "\n" +
                "blt $a0, $zero, exit_program\n" +
                "bge $a0, $t0, exit_program\n" +
                "addi $a0, $a0, 1\n" +
                "li $t0, 4\n" +
                "mul $a0, $a0, $t0\n" +
                "la $t0, var_" + name + "_" + var_scope + "\n" +
                "addu $t0, $t0, $a0\n" + 
                "lw $a0, ($t0)\n" +
                "##end cgen(get ID[NUM] as var)###\n" +
                "#################################\n";
        }
        else if (current_func >= 0) {

            func_t func    = funcs_stack[current_func];
            int    arg_num = 1;

            for (auto i:func.args) {
                if (i.name == name) {
                    full_text +=
                    string(
                    "###################################\n") +
                    "#start cgen(get ID[NUM] as param):#\n" +
                    index +
                    "lw $t0, " + to_string(4 * arg_num) + "($fp)\n" +
                    "lw $t0, ($t0)\n" +
                    "blt $a0, $zero, exit_program\n" +
                    "bge $a0, $t0, exit_program\n" +
                    "addi $a0, $a0, 1\n" +
                    "li $t0, 4\n" +
                    "mul $a0, $a0, $t0\n" +
                    "lw $t0, " + to_string(4 * arg_num) + "($fp)\n" +
                    "addu $t0, $t0, $a0\n" +
                    "lw $a0, ($t0)\n" +
                    "##end cgen(get ID[NUM] as param)###\n" +
                    "###################################\n";
                }
                arg_num++;
            }
        }
    }

    return full_text;
}


string codegen_assign (string e1, string e2) {

    string full_text ("");

    full_text +=
        string(
        "######################\n") +
        "#start cgen(E1 = E2):#\n" +
        e1 +
        "sw $t0, 0($sp)\n" +
        "addiu $sp, $sp, -4\n" +
        e2 +
        "lw $t0, 4($sp)\n" +
        "addiu $sp, $sp, 4\n" +
        "sw $a0, ($t0)\n" +
        "##end cgen(E1 = E2)###\n" +
        "######################\n";

    return full_text;
}

string codegen_selection (string e1, string e2, string e3) {

    string full_text ("");

    full_text +=
        string(
        "####################################\n") +
        "#start cgen(if E1 then E2 else E3):#\n" +
        e1 +
        "li $t0, 0\n" +
        "bgt $a0, $t0, true_block_" + to_string(if_counter) + "\n" +
        "false_block_" + to_string(if_counter) + ":\n" +
        e3 +
        "b end_if_" + to_string(if_counter) + "\n" +
        "true_block_" + to_string(if_counter) + ":\n" +
        e2 +
        "end_if_" + to_string(if_counter) + ":\n" +
        "##end cgen(if E1 then E2 else E3)###\n" +
        "####################################\n";

    if_counter++;

    return full_text;
}

string codegen_while (string e1, string e2) {

    string full_text ("");

    full_text +=
        string(
        "#############################\n") +
        "#start cgen(while E1 do E2):#\n" +
        "loop_" + to_string(loop_counter) + ":\n" +
        "sw $a0, 0($sp)\n" +
        "addiu $sp, $sp, -4\n" +
        e1 +
        "li $t0, 0\n" +
        "ble $a0, $t0, end_loop_" + to_string(loop_counter) + "\n" +
        "addiu $sp, $sp, 4\n" +
        e2 +
        "b loop_" + to_string(loop_counter) + "\n" +
        "end_loop_" + to_string(loop_counter) + ":\n" +
        "lw $a0, 4($sp)\n" +
        "addiu $sp, $sp, 4\n" +
        "##end cgen(while E1 do E2)###\n" +
        "#############################\n";
    
    loop_counter++;

    return full_text;
}

string codegen_return (string e1) {

    string full_text  ("");
    int    num_params = 0;

    if (current_func >= 0) {

        func_t func = funcs_stack[current_func];

        num_params = func.args.size();
    }

    full_text +=
        string(
        "########################\n") +
        "#start cgen(return E1):#\n" +
        e1 +
        "lw $ra, 4($sp)\n" +
        "addiu $sp, $sp, " + to_string((4 * num_params) + 8) + "\n" +
        "lw $fp, 0($sp)\n" +
        "jr $ra\n" +
        "##end cgen(return E1)###\n" +
        "########################\n";

    return full_text;
}

string codegen_program (string program_seq) {

    string full_text  (""),
           var_labels (""),
           call_main  ("");

    if (funcs_stack.size() > 2) {
        call_main +=
            string(
            "sw $fp, 0($sp)\n") +
            "addiu $sp, $sp, -4\n" + 
            "jal func_main\n";
    }

    for (auto i:var_labels_stack) {
        var_labels += i;
    }

    full_text +=
        string(
        "########################################################\n") +
        "#program file " + mips_code_path + " for MIPS Assembly:#\n" +
        "\n" +
        ".data\n" +
        var_labels +
        "\n" +
        ".text\n" +
        "b main\n" +
        "\n" +
        "# int input() {...} and void println(x) {...} declarations\n" +
        "\n" +
        "func_input:\n" +
        "li $v0, 5\n" +
        "syscall\n" +
        "move $a0, $v0\n" +
        "jr $ra\n" +
        "\n" +
        "func_println:\n" +
        "lw $a0, 4($sp)\n" +
        "li $v0, 1\n" +
        "syscall\n" +
        "li $v0, 11\n" +
        "li $a0, 0x0a\n" +
        "syscall\n" +
        "addiu $sp, $sp, 4\n" +
        "li $a0, 0\n" +
        "jr $ra\n" +
        "\n" +
        "# terminate program" +
        "\n" +
        "exit_program:\n" +
        "li $v0, 10\n" +
        "syscall\n" +
        "\n" +
        program_seq +
        "main:\n" +
        call_main +
        "b exit_program\n" +
        "#####################end of program#####################\n" +
        "########################################################";

    return full_text;
}

void codegen_choose_block (int prev_stack_size) {

    string block_name = block_name_stack.back();
    block_name_stack.pop_back();

    if (has_only_digits(block_name)) {
        if (block_name_stack.back() != "var-declaration") {

            assembly_stack.push_back(codegen_integer(block_name));
        }
        else {
            assembly_stack.push_back(block_name);
        }
    }
    else if (is_operator(block_name)) {

        string val1, val2;

        val2 = assembly_stack.back();
        assembly_stack.pop_back();
        val1 = assembly_stack.back();
        assembly_stack.pop_back();

        assembly_stack.push_back(codegen_operation(block_name, val1, val2));
    }
    else if (is_comparator(block_name)) {

        string val1, val2;

        val2 = assembly_stack.back();
        assembly_stack.pop_back();
        val1 = assembly_stack.back();
        assembly_stack.pop_back();

        assembly_stack.push_back(codegen_comparison(block_name, val1, val2));
    }
    else if (block_name == "=") {

        string val1, val2;

        val2 = assembly_stack.back();
        assembly_stack.pop_back();
        val1 = assembly_stack.back();
        assembly_stack.pop_back();

        assembly_stack.push_back(codegen_assign(val1, val2));
    }
    else if (block_name == "compound-stmt") {

        string decl_seq ("");

        for (unsigned int i = prev_stack_size, len = assembly_stack.size(); i < len; i++) {
            decl_seq = assembly_stack.back() + decl_seq;
            assembly_stack.pop_back();
        }

        if (block_name_stack.back() == "fun-declaration") { current_func = -1; }
        assembly_stack.push_back(decl_seq);
        scope_stack.pop_back();
        close_scope();
        //cout << "closed scope" << endl;
        //cout << "scope_stack.back(): " << scope_stack.back() << endl;
    }
    else if (block_name == "var-declaration") {

        string var_decl ("");

        if ((assembly_stack.size() - prev_stack_size) == 2) {

            string type, name;

            name = assembly_stack.back();
            assembly_stack.pop_back();
            type = assembly_stack.back();
            assembly_stack.pop_back();

            var_decl = codegen_var_decl(type, name);
        }
        else {

            string type, name, size;

            size = assembly_stack.back();
            assembly_stack.pop_back();
            name = assembly_stack.back();
            assembly_stack.pop_back();
            type = assembly_stack.back();
            assembly_stack.pop_back();

            var_decl = codegen_arr_decl(type, name, size);
        }

        var_labels_stack.push_back(var_decl);
    }
    else if (block_name == "var") {

        string var_access ("");

        if ((assembly_stack.size() - prev_stack_size) == 1) {

            string name;

            name = assembly_stack.back();
            assembly_stack.pop_back();

            var_access = codegen_var_access(name);
        }
        else {

            string name, size;

            size = assembly_stack.back();
            assembly_stack.pop_back();
            name = assembly_stack.back();
            assembly_stack.pop_back();

            var_access = codegen_arr_access(name, size);
        }

        assembly_stack.push_back(var_access);
    }
    else if (block_name == "param") {

        string name ("");

        if ((assembly_stack.size() - prev_stack_size) == 2) {

            //string type, name;

            name = assembly_stack.back();
            assembly_stack.pop_back();
            //type = assembly_stack.back();
            assembly_stack.pop_back();
        }
        else {

            //string type, name, size;

            //size = assembly_stack.back();
            assembly_stack.pop_back();
            name = assembly_stack.back();
            assembly_stack.pop_back();
            //type = assembly_stack.back();
            assembly_stack.pop_back();
        }

        assembly_stack.push_back(name);
    }
    else if (block_name == "params") {

        int num_params = assembly_stack.size() - prev_stack_size;

        open_scope("params"); // push params names
        for (int i = 0, len = num_params; i < len; i++) {
            create_var("param", assembly_stack.back());
            assembly_stack.pop_back();
        }

        current_func = get_func_index(assembly_stack.back());
        assembly_stack.push_back(to_string(num_params));
    }
    else if (block_name == "args") {

        vector<string> args_seq; //assembly_stack has "a,b,...,x", args_seq will end up with "x,...,b,a"

        for (unsigned int i = prev_stack_size, len = assembly_stack.size(); i < len; i++) {
            args_seq.push_back(assembly_stack.back());
            assembly_stack.pop_back();
        }

        assembly_stack.push_back(codegen_args(args_seq));
    }
    else if (block_name == "fun-declaration") {

        string type, name, num_params, compd_stmt;

        compd_stmt = assembly_stack.back();
        assembly_stack.pop_back();
        num_params = assembly_stack.back();
        assembly_stack.pop_back();
        name = assembly_stack.back();
        assembly_stack.pop_back();
        type = assembly_stack.back();
        assembly_stack.pop_back();

        assembly_stack.push_back(codegen_func_decl(type, name, num_params, compd_stmt));
        close_scope(); // pop params names
    }
    else if (block_name == "call") {
        
        string name, args;

        args = assembly_stack.back();
        assembly_stack.pop_back();
        name = assembly_stack.back();
        assembly_stack.pop_back();

        assembly_stack.push_back(codegen_func_call(name, args));
    }
    else if (block_name == "selection-stmt") {

        string v1, v2, v3;

        if (assembly_stack.size() - prev_stack_size == 2) { //if v1 then v2

            v2 = assembly_stack.back();
            assembly_stack.pop_back();
            v1 = assembly_stack.back();
            assembly_stack.pop_back();

            v3 = "";
        }
        else { //if v1 then v2 else v3

            v3 = assembly_stack.back();
            assembly_stack.pop_back();
            v2 = assembly_stack.back();
            assembly_stack.pop_back();
            v1 = assembly_stack.back();
            assembly_stack.pop_back();
        }

        assembly_stack.push_back(codegen_selection(v1, v2, v3));
    }
    else if (block_name == "iteration-stmt") {

        string v1, v2;

        v2 = assembly_stack.back();
        assembly_stack.pop_back();
        v1 = assembly_stack.back();
        assembly_stack.pop_back();

        assembly_stack.push_back(codegen_while(v1, v2));
    }
    else if (block_name == "return-stmt") {

        string v1 ("");

        if ((assembly_stack.size() - prev_stack_size) > 0) {
            v1 = assembly_stack.back();
            assembly_stack.pop_back();
        }

        assembly_stack.push_back(codegen_return(v1));
    }
    else if (block_name == "program") {

        string program_seq ("");

        for (unsigned int i = prev_stack_size, len = assembly_stack.size(); i < len; i++) {
            program_seq = assembly_stack.back() + program_seq;
            assembly_stack.pop_back();
        }

        assembly_stack.push_back(codegen_program(program_seq));
    }
    else {
        assembly_stack.push_back(block_name);
    }

    //cout << "close " << block_name << endl;
}

void codegen_expressions (string &acc, int start) {

    string acc_ret          ("");
    int    curr_stack_size  = assembly_stack.size(),
           curr_labels_size = var_labels_stack.size();

    acc[start] = '#';
    //cout << "start: " << start << endl;
    //cout << "curr_stack_size: " << curr_stack_size << endl;

    for (int i = start + 1, len = acc.length(); i < len; i++) {

        if (acc[i] != '#') {

            if (acc[i] == '[') {
                //cout << acc_ret << endl;
                block_name_stack.push_back(acc_ret);
                if ((acc_ret                                     == "compound-stmt") &&
                   ((assembly_stack.size() - curr_stack_size)    == 0)               &&
                   ((var_labels_stack.size() - curr_labels_size) == 0)              ) {

                    scope_counter++;
                    scope_stack.push_back(scope_counter);
                    open_scope(to_string(scope_counter));
                    //cout << "opened scope" << endl;
                    //cout << "scope_stack.back(): " << scope_stack.back() << endl;
                }
                codegen_expressions(acc, i);
            }
            else if (acc[i] == ']') {
                acc[i] = '#';
                if (acc_ret != block_name_stack.back()) {
                    //cout << acc_ret << endl;
                    block_name_stack.push_back(acc_ret);
                }
                codegen_choose_block(curr_stack_size);
                break;
            }
            else if (acc[i] == '\\') {
                //cout << acc[i + 1] << endl;
                acc_ret    += acc[i + 1];
                acc[i]      = '#';
                acc[i + 1]  = '#';
            }
            else if (acc[i] != ' ') {
                //cout << acc[i] << endl;
                acc_ret += acc[i];
                acc[i] = '#';
            }
            else {
                acc[i] = '#';
            }
        }
    }

    return;
}