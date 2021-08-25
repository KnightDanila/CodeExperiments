/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   logs.h
 * Author: KnightDanila
 *
 * Created on 8 ноября 2019 г., 2:18
 */

#ifndef LOG_H
#define LOG_H

// Create a log class in future - like I made in JS and Knight3D Engine
// https://www.lemoda.net/c/line-file-func/

#include <iostream>
#include <string>

// I named it log - but it find logarithm in 

// v1.0
class Log {
public:

    template < typename T>
    void println(T t) {
        std::cout << t << std::endl;
    };

    template <typename T, typename ...U>
    void println(T t, U ...u) {
        std::cout << t << ", ";
        println(u...);
    };

    void argsEcho(int argc, char** argv);


    //void LOG_BLURT();
    static Log* getInstance();

private:
    static Log* _instance;
    Log();

};

#define LOG_BLURT() printf("This is line %d of file %s (function %s)\n",\
                      __LINE__, __FILE__, __func__);

#endif /* LOG_H */

