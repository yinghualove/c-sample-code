#!/bin/sh
    gcc script_test.c -o script_test
    first(){
        ./script_test 1
        echo "first num"
    }
    second(){
        ./script_test 2
        echo "second num"
    }
    third(){
        ./script_test 3
        echo "third num"
    }