$NetBSD$

--- src/gcc3strm.cxx.orig	2006-09-28 09:01:54.000000000 +0000
+++ src/gcc3strm.cxx
@@ -308,13 +308,21 @@ static int G__G__stream_7_6_0(G__value* 
 
 static int G__G__stream_7_7_0(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
 {
+#if defined(__NetBSD__)
+//      G__letint(result7, 103, (long) ((fpos<mbstate_t>*) G__getstructoffset())->operator==(*(fpos<mbstate_t>*) libp->para[0].ref));
+#else
       G__letint(result7, 103, (long) ((fpos<mbstate_t>*) G__getstructoffset())->operator==(*(fpos<mbstate_t>*) libp->para[0].ref));
+#endif
    return(1 || funcname || hash || result7 || libp) ;
 }
 
 static int G__G__stream_7_8_0(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
 {
+#if defined(__NetBSD__)
+//      G__letint(result7, 103, (long) ((fpos<mbstate_t>*) G__getstructoffset())->operator!=(*(fpos<mbstate_t>*) libp->para[0].ref));
+#else
       G__letint(result7, 103, (long) ((fpos<mbstate_t>*) G__getstructoffset())->operator!=(*(fpos<mbstate_t>*) libp->para[0].ref));
+#endif
    return(1 || funcname || hash || result7 || libp) ;
 }
 
