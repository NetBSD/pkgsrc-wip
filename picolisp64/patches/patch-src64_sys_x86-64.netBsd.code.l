$NetBSD$

Add support for NetBSD

--- src64/sys/x86-64.netBsd.code.l.orig	2017-03-16 20:57:05.344048655 +0000
+++ src64/sys/x86-64.netBsd.code.l
@@ -0,0 +1,61 @@
+# 07jan13abu
+# Mansur Mamkin <mmamkin@mail.ru>
+
+# System macros
+(code 'errno_A 0)
+   call __errno  # Get address of 'errno'
+   ld A (A)  # Load value
+   ret
+
+(code 'errnoC 0)
+   call __errno  # Get address of 'errno'
+   ld (A) C  # Store new value
+   ret
+
+#define>_WSTATUS(x)<--->(_W_INT(x) & 0177)
+#define>_WSTOPPED<----->0177<--><------>/* _WSTATUS if process is stopped */
+#define _WCONTINUED	0xffffU
+#define>WIFSTOPPED(x)<->(_WSTATUS(x) == _WSTOPPED)
+#define WIFSTOPPED(x)	(_WSTATUS(x) == _WSTOPPED && !WIFCONTINUED(x))
+#define WIFCONTINUED(x)	(_W_INT(x) == _WCONTINUED)
+#define WSTOPSIG(x)	((int)(((unsigned int)_W_INT(x)) >> 8) & 0xff)
+#define WIFSIGNALED(x)	(!WIFSTOPPED(x) && !WIFCONTINUED(x) && !WIFEXITED(x))
+#define>WIFSIGNALED(x)<>(_WSTATUS(x) != _WSTOPPED && _WSTATUS(x) != 0)
+#define>WTERMSIG(x)<--->(_WSTATUS(x))
+#define WIFEXITED(x)	(_WSTATUS(x) == 0)
+#define WEXITSTATUS(x)	((int)(((unsigned int)_W_INT(x)) >> 8) & 0xff)
+
+# ((status & 0177) == 0177 && !(x == 0x0000ffffU))
+
+(code 'wifstoppedS_F 0)  # WIFSTOPPED
+   ld A (S I)  # Get status
+   and B `(oct "0177")
+   cmp B `(oct "0177")  # (((status) & 0177) == 0177)
+   ret
+
+(code 'wifsignaledS_F 0)  # WIFSIGNALED
+   ld A (S I)  # Get status
+   and B `(oct "0177")  # ((((status) & 0177) != 0177) && ((status) & 0177) != 0)
+   cmp B `(oct "0177")
+   if ne
+      nul B
+   end
+   ret
+
+(code 'wtermsigS_A 0)  # WTERMSIG
+   ld A (S I)  # Get status
+   and B `(oct "0177")  # ((status) & 0177)
+   zxt
+   ret
+
+(code 'sigprocmask 0)
+   jmp __sigprocmask14
+
+(code 'sigaction 0)
+   jmp __libc_sigaction14
+
+(code 'stat 0)
+   jmp __stat50
+
+(code 'readdir 0)
+   jmp __readdir30
