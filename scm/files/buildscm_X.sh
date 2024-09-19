#! /bin/sh
# unix (unix) script created by SLIB/batch Fri Oct 11 05:24:29 2002
# ================ Write file with C defines
rm -f scmflags.h
echo '#define IMPLINIT "%%PREFIX%%/share/scm/Init5d6.scm"'>>scmflags.h
echo '#define INITS init_sc2();init_ramap();init_ioext();init_posix();init_record();init_rgx();init_socket();init_unix();'>>scmflags.h
echo '#define COMPILED_INITS init_edline();init_x();'>>scmflags.h
echo '#define ARRAYS'>>scmflags.h
echo '#define BIGNUMS'>>scmflags.h
echo '#define CAUTIOUS'>>scmflags.h
echo '#define CHEAP_CONTINUATIONS'>>scmflags.h
echo '#define CAN_DUMP'>>scmflags.h
echo '#define FLOATS'>>scmflags.h
echo '#define MACRO'>>scmflags.h
echo '#define CCLO'>>scmflags.h
# ================ Compile C source files
cc -O -c -I/usr/X11R6/include -DX11 sc2.c dynl.c ramap.c edline.c ioext.c posix.c record.c rgx.c socket.c unix.c x.c continue.c scm.c scmmain.c findexec.c script.c time.c repl.c scl.c eval.c sys.c subr.c debug.c unif.c rope.c unexelf.c
# ================ Link C object files
mv -f scm scm~
cc -o scm sc2.o dynl.o ramap.o edline.o ioext.o posix.o record.o rgx.o socket.o unix.o x.o continue.o scm.o scmmain.o findexec.o script.o time.o repl.o scl.o eval.o sys.o subr.o debug.o unif.o rope.o unexelf.o -ltermcap -lm -ledit -Wl,-rpath -Wl,/usr/X11R6/lib -L/usr/X11R6/lib -lX11 

