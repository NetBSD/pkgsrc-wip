$NetBSD$

Let readline be handled by buildlink from editline.

--- dnsdist-console.cc.orig	2020-07-28 07:39:28.000000000 +0000
+++ dnsdist-console.cc
@@ -24,14 +24,10 @@
 #include <pwd.h>
 #include <thread>
 
-#if defined (__OpenBSD__) || defined(__NetBSD__)
 // If this is not undeffed, __attribute__ wil be redefined by /usr/include/readline/rlstdc.h
 #undef __STRICT_ANSI__
 #include <readline/readline.h>
 #include <readline/history.h>
-#else
-#include <editline/readline.h>
-#endif
 
 #include "ext/json11/json11.hpp"
 
