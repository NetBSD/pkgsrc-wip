$NetBSD$

gcc -x c Control/Arrow.hc -o Control/Arrow.o -c -O  -fno-defer-pop -fomit-frame-pointer  -DNO_REGS -DUSE_MINIINTERPRETER  -DDONT_WANT_WIN32_DLL_SUPPORT -D__GLASGOW_HASKELL__=604  -O -I/export/WRKOBJDIR/wip/ghc68/work/ghc-6.4.2/ghc/includes -I/export/WRKOBJDIR/wip/ghc68/work/ghc-6.4.2/libraries/base/include -I/export/WRKOBJDIR/wip/ghc68/work/ghc-6.4.2/libraries/unix/include -I/export/WRKOBJDIR/wip/ghc68/work/ghc-6.4.2/libraries/parsec/include  -I/export/WRKOBJDIR/wip/ghc68/work/ghc-6.4.2/libraries/readline/include    -I.  `echo  | sed 's/^$/-DSTOLEN_X86_REGS=4/'`
In file included from Control/Arrow.hc:4:0:
/export/WRKOBJDIR/wip/ghc68/work/ghc-6.4.2/libraries/base/include/HsBase.h:144:12: error: conflicting types for 'execvpe'
 extern int execvpe(char *name, char *const argv[], char **envp);
            ^~~~~~~
In file included from /export/WRKOBJDIR/wip/ghc68/work/ghc-6.4.2/libraries/base/include/HsBase.h:33:0,
                 from Control/Arrow.hc:4:
/usr/include/unistd.h:334:6: note: previous declaration of 'execvpe' was here
 int  execvpe(const char *, char * const *, char * const *);



--- ghc-6.4.2/libraries/base/include/HsBase.h.orig	2006-02-02 01:15:56.000000000 +0900
+++ ../ghc-6.4.2/libraries/base/include/HsBase.h	2019-10-07 23:55:26.568530629 +0900
@@ -141,7 +141,7 @@ extern HsInt nocldstop;
 
 #if !defined(mingw32_HOST_OS)
 /* in execvpe.c */
-extern int execvpe(char *name, char *const argv[], char **envp);
+// extern int execvpe(char *name, char *const argv[], char **envp);
 extern void pPrPr_disableITimers (void);
 #endif
 
