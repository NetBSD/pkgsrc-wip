$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/stdc/stdio.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/stdc/stdio.d
@@ -25,6 +25,10 @@ private
   {
     import core.sys.posix.sys.types;
   }
+  version (NetBSD)
+  {
+    import core.sys.posix.sys.types;
+  }
 }
 
 extern (C):
@@ -166,6 +170,37 @@ else version ( FreeBSD )
         long        _mbstateL;
     }
 }
+else version ( NetBSD )
+{
+    enum
+    {
+        ///
+        BUFSIZ       = 1024,
+        ///
+        EOF          = -1,
+        ///
+        FOPEN_MAX    = 20,
+        ///
+        FILENAME_MAX = 1024,
+        ///
+        TMP_MAX      = 308915776,
+        ///
+        L_tmpnam     = 1024
+    }
+
+    struct __sbuf
+    {
+        ubyte *_base;
+        int _size;
+    }
+
+    union __mbstate_t // <sys/_types.h>
+    {
+        char[128]   _mbstate8;
+        long        _mbstateL;
+    }
+}
+
 else version (Solaris)
 {
     enum
@@ -392,6 +427,50 @@ else version( FreeBSD )
     ///
     alias shared(__sFILE) FILE;
 }
+else version( NetBSD )
+{
+    ///
+    alias off_t fpos_t;
+
+    ///
+    struct __sFILE
+    {
+        ubyte*          _p;
+        int             _r;
+        int             _w;
+        ushort           _flags;
+        short           _file;
+        __sbuf          _bf;
+        int             _lbfsize;
+
+        void*           _cookie;
+        int     function(void*)                 _close;
+        ssize_t     function(void*, char*, size_t)     _read;
+        fpos_t  function(void*, fpos_t, int)    _seek;
+        ssize_t     function(void*, in char*, size_t)  _write;
+
+        __sbuf          _ub;
+        ubyte*          _up;
+        int             _ur;
+
+        ubyte[3]        _ubuf;
+        ubyte[1]        _nbuf;
+
+        int     function(void *)    _flush;
+        /* Formerly used by fgetln/fgetwln; kept for binary compatibility */
+        char[__sbuf.sizeof - _flush.sizeof]    _lb_unused;
+
+
+        int             _blksize;
+        off_t          _offset;
+        static assert(off_t.sizeof==8);
+    }
+
+    ///
+    alias __sFILE _iobuf;
+    ///
+    alias shared(__sFILE) FILE;
+}
 else version (Solaris)
 {
     ///
@@ -637,6 +716,29 @@ else version( FreeBSD )
     ///
     alias __stderrp stderr;
 }
+else version( NetBSD )
+{
+    enum
+    {
+        ///
+        _IOFBF = 0,
+        ///
+        _IOLBF = 1,
+        ///
+        _IONBF = 2,
+    }
+
+    private extern __gshared FILE[3] __sF;
+    @property auto __stdin() { return &__sF[0]; }
+    @property auto __stdout() { return &__sF[1]; }
+    @property auto __stderr() { return &__sF[2]; }
+    ///
+    alias __stdin stdin;
+    ///
+    alias __stdout stdout;
+    ///
+    alias __stderr stderr;
+}
 else version (Solaris)
 {
     enum
@@ -1039,6 +1141,28 @@ else version( FreeBSD )
     ///
     int  vsnprintf(char* s, size_t n, in char* format, va_list arg);
 }
+else version( NetBSD )
+{
+  // No unsafe pointer manipulation.
+  @trusted
+  {
+      ///
+    void rewind(FILE*);
+    ///
+    pure void clearerr(FILE*);
+    ///
+    pure int  feof(FILE*);
+    ///
+    pure int  ferror(FILE*);
+    ///
+    int  fileno(FILE*);
+  }
+
+  ///
+    int  snprintf(char* s, size_t n, in char* format, ...);
+    ///
+    int  vsnprintf(char* s, size_t n, in char* format, va_list arg);
+}
 else version (Solaris)
 {
   // No unsafe pointer manipulation.
