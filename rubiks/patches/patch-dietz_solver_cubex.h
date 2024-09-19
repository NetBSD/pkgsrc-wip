$NetBSD$

--- dietz/solver/cubex.h.orig	2008-04-14 21:09:53.000000000 +0000
+++ dietz/solver/cubex.h
@@ -13,8 +13,6 @@
 
 // required includes/namespace
 #include <string>
-// gcc 4.3 needs cstdlib for rand() to compile
-#include <cstdlib>
 using namespace std;
 
 // Class declaration - class members/methods, some encapsulated
