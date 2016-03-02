$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sys/wait.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/wait.d
@@ -113,6 +113,28 @@ else version( FreeBSD )
     extern (D) int  WSTOPSIG( int status )     { return status >> 8;                     }
     extern (D) int  WTERMSIG( int status )     { return _WSTATUS( status );              }
 }
+else version( NetBSD )
+{
+    enum WNOHANG        = 1;
+    enum WUNTRACED      = 2;
+
+    private
+    {
+        enum _WSTOPPED = 0x7F; // octal 0177
+    }
+
+    extern (D) int _WSTATUS(int status)         { return (status & 0x7F);           }
+    extern (D) int  WEXITSTATUS( int status )   { return (status >> 8);             }
+    extern (D) int  WIFCONTINUED( int status )  { return status == 0x13;            }
+    extern (D) bool WIFEXITED( int status )     { return _WSTATUS(status) == 0;     }
+    extern (D) bool WIFSIGNALED( int status )
+    {
+        return _WSTATUS( status ) != _WSTOPPED && _WSTATUS( status ) != 0;
+    }
+    extern (D) bool WIFSTOPPED( int status )   { return _WSTATUS( status ) == _WSTOPPED; }
+    extern (D) int  WSTOPSIG( int status )     { return status >> 8;                     }
+    extern (D) int  WTERMSIG( int status )     { return _WSTATUS( status );              }
+}
 else version (Solaris)
 {
     enum WNOHANG        = 64;
@@ -205,6 +227,12 @@ else version (FreeBSD)
 
     // http://www.freebsd.org/projects/c99/
 }
+else version (NetBSD)
+{
+    enum WSTOPPED       = WUNTRACED;
+    //enum WCONTINUED     = 4;
+    enum WNOWAIT        = 0x00010000;
+}
 else version (Solaris)
 {
     enum WEXITED = 1;
