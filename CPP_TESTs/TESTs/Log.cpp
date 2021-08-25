/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Log.h"

Log* Log::_instance = 0;

Log* Log::getInstance() {
    if (_instance == 0) {
        _instance = new Log();
    }

    return _instance;
}

Log::Log() {
}

void Log::argsEcho(int argc, char** argv) {
    println("____ARGS____");
    if (argc == 0) {
        println("NO ARGS");
    } else {
        for (int i = 0; i < argc; i++) {
            println(argv[i]);
        }
    }
    println("____________\n");
}

/*
void Logs::LOG_BLURT() {
    printf("This is line %d of file %s (function %s)\n",\
                      __LINE__, __FILE__, __func__);
};
*/