#! /bin/sh
# unix (unix) script created by SLIB/batch Fri Oct 11 05:26:56 2002
# ================ Write file with C defines
rm -f scmflags.h
echo '#define IMPLINIT "%%PREFIX%%/share/scm/Init5d6.scm"'>>scmflags.h
echo '#define INITS init_sc2();init_ramap();init_crs();init_ioext();init_posix();init_record();init_rgx();init_socket();init_unix();'>>scmflags.h
echo '#define COMPILED_INITS init_edline();'>>scmflags.h
echo '#define ARRAYS'>>scmflags.h
echo '#define BIGNUMS'>>scmflags.h
echo '#define CAUTIOUS'>>scmflags.h
echo '#define CHEAP_CONTINUATIONS'>>scmflags.h
echo '#define CAN_DUMP'>>scmflags.h
echo '#define FLOATS'>>scmflags.h
echo '#define MACRO'>>scmflags.h
echo '#define CCLO'>>scmflags.h
# ================ Compile C source files
cc -O -c -I%%LOCALBASE%%/include sc2.c dynl.c ramap.c crs.c edline.c ioext.c posix.c record.c rgx.c socket.c unix.c continue.c scm.c scmmain.c findexec.c script.c time.c repl.c scl.c eval.c sys.c subr.c debug.c unif.c rope.c unexelf.c
# ================ Link C object files
mv -f scm scm~
cc -o scm sc2.o dynl.o ramap.o crs.o edline.o ioext.o posix.o record.o rgx.o socket.o unix.o continue.o scm.o scmmain.o findexec.o script.o time.o repl.o scl.o eval.o sys.o subr.o debug.o unif.o rope.o unexelf.o -ltermcap -lm -ledit -Wl,-rpath -Wl,%%LOCALBASE%%/lib -L%%LOCALBASE%%/lib -lncurses

