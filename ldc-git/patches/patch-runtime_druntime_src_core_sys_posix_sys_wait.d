$NetBSD$

--- runtime/druntime/src/core/sys/posix/sys/wait.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/wait.d
@@ -113,6 +113,30 @@ else version( FreeBSD )
     extern (D) int  WSTOPSIG( int status )     { return status >> 8;                     }
     extern (D) int  WTERMSIG( int status )     { return _WSTATUS( status );              }
 }
+else version( NetBSD )
+{
+    enum WNOHANG         = 0x00000001;	/* don't hang in wait */
+    enum WUNTRACED       = 0x00000002;	/* tell about stopped,
+ 					   untraced children */
+    enum WALTSIG         = 0x00000004;	/* wait for processes that exit
+ 					   with an alternate signal (i.e.
+ 					   not SIGCHLD) */
+    enum WALLSIG         = 0x00000008;	/* wait for processes that exit
+ 					   with any signal, i.e. SIGCHLD
+ 					   and alternates */
+
+    pure nothrow int _WSTATUS(int x)    { return x & 0x7f; }
+    enum	_WSTOPPED      = 0x7f;		/* _WSTATUS if process is stopped */
+    pure nothrow int WIFSTOPPED(int x)	{ return _WSTATUS(x) == _WSTOPPED; }
+    pure nothrow int WSTOPSIG(int x)	{ return x >>> 8 & 0xff; }
+    pure nothrow int WIFSIGNALED(int x)	{ return _WSTATUS(x) != _WSTOPPED && _WSTATUS(x) != 0; }
+    pure nothrow int WTERMSIG(int x)	{ return _WSTATUS(x); }
+    pure nothrow int WIFEXITED(int x)	{ return _WSTATUS(x) == 0; }
+    pure nothrow int WEXITSTATUS(int x)	{ return x >>> 8 & 0xff; }
+/* MISSING:
+WIFCONTINUED
+*/
+}
 else version (Solaris)
 {
     enum WNOHANG        = 64;
@@ -205,6 +229,10 @@ else version (FreeBSD)
 
     // http://www.freebsd.org/projects/c99/
 }
+else version( NetBSD )
+{
+    // Empty for now.
+}
 else version (Solaris)
 {
     enum WEXITED = 1;
