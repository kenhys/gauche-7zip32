#!/bin/bash
# -*- coding: utf-8-unix -*-

GOSH=gosh
CFLAGS="-DHAVE_BOOL"

CB_BUILD=0
CB_CLEAN=0
CB_TEST=0
CB_TEST_SCM=""
CB_LIBTEST=0

function cb_build ()
{
    mkdir -p log/
    $GAUCHE_CONFIG --fixup-extension gauche_7zip32lib 7zip32
        $GOSH $GENSTUB gauche_7zip32lib.stub
        if [ $? -ne 0 ]; then
            exit
        fi
        com="gcc -c gauche_7zip32lib_head.c -I$GDIST_INCDIR"
        echo $com
        eval $com
        if [ $? -ne 0 ]; then
            exit
        fi
        com="gcc -c gauche_7zip32lib_tail.c -I$GDIST_INCDIR"
        echo $com
        eval $com
        if [ $? -ne 0 ]; then
            exit
        fi
        com="LANG=C gcc -c gauche_7zip32lib.c -I$GDIST_INCDIR $CFLAGS 2>&1 | tee log/7zip32lib.c.log"
        echo $com
        eval $com
        if [ $? -ne 0 ]; then
            exit
        fi
        com="LANG=C gcc -c gauche_7zip32.c -I$GDIST_INCDIR $CFLAGS 2>&1 | tee log/7zip32.c.log"
        echo $com
        eval $com
        if [ $? -ne 0 ]; then
            exit
        fi
        com="LANG=C gcc -lmingw32 `gauche-config --dylib-ldflags` gauche-7zip32.dll *.o  -L. -L$GDIST_LIBDIR -lgauche-0.9"
        echo $com
        eval $com
        if [ $? -ne 0 ]; then
            exit
        fi
}

function cb_clean ()
{

    rm -f *.o
    rm -f 7zip32lib.c
    rm -f config.status
    rm -f configure
    rm -f *.exe
    rm -f 7zip32.dll
    rm -f *.log
    rm -fr autom4te.*
    rm -f *_head.*
    rm -f *_tail.*

}

function cb_test ()
{
        #$GOSH -I. test/test-demon.scm
    #$GOSH -I. test/test-nqueen.scm
    if [ ! -z "$CB_TEST_SCM" ]; then
        $GOSH -I. $CB_TEST_SCM
    else
        sh test/run-test.sh
    fi 
}

function cb_libtest ()
{
LANG=C g++ -o test/iz_gtest.exe test/iz_gtest.cpp -I. -L. -liz -lgtest
./test/iz_gtest.exe
LANG=C g++ -g -o test/nqueen.exe test/nqueen.cpp -I. -L. -liz 
#./test/nqueen.exe
}

while [ $# -gt 0 ]; do
    case "$1" in
        -g|debug)
            shift
            CFLAGS="$CFLAGS -DHAVE_BOOL -DDEBUG"
            ;;
        -gf|debugfunc)
            shift
            CFLAGS="$CFLAGS -DHAVE_BOOL -DDEBUG -DDEBUG_FUNC"
            ;;
        -t|test)
            shift
            CB_TEST=1
            if [ ! -z "$1" ]; then
                if [ -f "$1" ]; then
                    # each
                    CB_TEST_SCM=$1
                    shift
                fi
            fi
            ;;
        -lt|libtest)
            shift
            CB_LIBTEST=1
            ;;
        -c|clean)
            shift
            CB_CLEAN=1
            ;;
        -b|build)
            CB_BUILD=1
            shift
            ;;
        *)
            shift
            ;;
    esac
done

if [ -f "$GOSH_PATH" ]; then
    GOSH_BIN_DIR=`dirname $GOSH_PATH`
    GOSH_DIR=`dirname $GOSH_BIN_DIR`
    GDIST_INCDIR=`gauche-config --sysincdir`
    GDIST_INCDIR=`echo $GDIST_INCDIR|sed -e 's|\\\\|/|g'`
    
    GDIST_LIBDIR=$GOSH_DIR/bin
    GAUCHE_CONFIG=$GOSH_DIR/bin/gauche-config
    GENSTUB=`gauche-config --syslibdir`/genstub
fi

if [ $CB_BUILD -eq 1 ]; then
    cb_build
fi
if [ $CB_CLEAN -eq 1 ]; then
    cb_clean
fi
if [ $CB_TEST -eq 1 ]; then
    cb_test
fi
if [ $CB_LIBTEST -eq 1 ]; then
    cb_libtest
fi
