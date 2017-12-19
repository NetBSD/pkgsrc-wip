$NetBSD$

`fpos_t' can be a complex object, use `off64_t' instead.

This fixes:

 fopencookie.c: In function 'seekfn':
 fopencookie.c:55:3: error: aggregate value used where an integer was expected
    return (fpos_t)(c->seek(c->cookie, (off64_t)offset, whence));
    ^
 fopencookie.c:55:3: error: conversion to non-scalar type requested

at least on NetBSD.

--- fopencookie.c.orig	2017-11-24 09:41:14.000000000 +0000
+++ fopencookie.c
@@ -49,10 +49,10 @@ static int writefn(void *sc, const char 
 }
 
 /* seekfn -- callback that in turn calls sc->seek with proper typecasts */
-static fpos_t seekfn(void *sc, fpos_t offset, int whence)
+static off64_t seekfn(void *sc, off64_t offset, int whence)
 {
   cookiewrapper *c = (cookiewrapper*)sc;
-  return (fpos_t)(c->seek(c->cookie, (off64_t)offset, whence));
+  return (off64_t)(c->seek(c->cookie, (off64_t)offset, whence));
 }
 
 /* closefn -- callback that in turn calls sc->close and then frees memory */
