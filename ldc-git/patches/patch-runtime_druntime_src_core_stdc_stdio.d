$NetBSD$

--- runtime/druntime/src/core/stdc/stdio.d.orig	2016-01-21 15:39:03.000000000 +0000
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
@@ -166,6 +170,36 @@ else version ( FreeBSD )
         long        _mbstateL;
     }
 }
+else version( NetBSD )
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
+    union __mbstate_t // <sys/ansi.h>
+    {
+        long        _mbstateL; // for alignment
+	char[128]   _mbstate8;
+    }
+}
 else version (Solaris)
 {
     enum
@@ -392,6 +426,57 @@ else version( FreeBSD )
     ///
     alias shared(__sFILE) FILE;
 }
+else version( NetBSD )
+{
+    ///
+    struct __sfpos {
+        off_t _pos;
+        __mbstate_t _mbstate_in, _mbstate_out;
+    }
+
+    ///
+    alias __sfpos fpos_t;
+
+    ///
+    struct __sFILE {
+        ubyte*          _p;       /* current position in (some) buffer */
+        int             _r;       /* read space left for getc() */
+        int             _w;       /* write space left for putc() */
+        ushort          _flags;   /* flags, below; this FILE is free if 0 */
+        short           _file;    /* fileno, if Unix descriptor, else -1 */
+        __sbuf          _bf;      /* the buffer (at least 1 byte, if !NULL) */
+        int             _lbfsize; /* 0 or -_bf._size, for inline putc */
+ 
+        /* operations */
+        void*           _cookie;  /* cookie passed to io functions */
+        int     function(void*)                      _close;
+        ssize_t function(void*, void*, size_t)       _read;
+        off_t   function(void*, off_t, int)          _seek;
+        ssize_t function(void*, in void*, size_t)    _write;
+ 
+        /* file extension */
+        __sbuf          _ext;
+ 
+        /* separate buffer for long sequences of ungetc() */
+        ubyte*          _up;      /* saved _p when _p is doing ungetc data */
+        int             _ur;      /* saved _r when _r is counting ungetc data */
+ 
+        /* tricks to meet minimum requirements even when malloc() fails */
+        ubyte[3]        _ubuf;    /* guarantee an ungetc() buffer */
+        ubyte[1]        _nbuf;    /* guarantee a getc() buffer */
+ 
+        int     function(void*)                      _flush;
+        /* Formerly used by fgetln/fgetwln; kept for binary compatibility */
+        byte[__sbuf.sizeof - (int function(void *)).sizeof] _lb_unused;
+ 
+        /* Unix stdio files get aligned to block boundaries on fseek() */
+        int             _blksize; /* stat.st_blksize (may be != _bf._size) */
+        off_t           _offset;  /* current lseek offset */
+    }
+
+    ///
+    alias shared(__sFILE) FILE;
+}
 else version (Solaris)
 {
     ///
@@ -637,6 +722,22 @@ else version( FreeBSD )
     ///
     alias __stderrp stderr;
 }
+else version( NetBSD )
+{
+    enum
+    {
+        ///
+        _IOFBF,
+        ///
+        _IOLBF,
+        ///
+        _IONBF,
+    }
+
+    extern shared FILE* stdin;
+    extern shared FILE* stdout;
+    extern shared FILE* stderr;
+}
 else version (Solaris)
 {
     enum
@@ -1039,6 +1140,29 @@ else version( FreeBSD )
     ///
     int  vsnprintf(char* s, size_t n, in char* format, va_list arg);
 }
+else version( NetBSD )
+{
+  // TODO: verify duplicated code
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
