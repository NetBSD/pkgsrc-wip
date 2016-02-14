$NetBSD$

--- src/pal/src/include/pal/palinternal.h.orig	2016-02-06 02:05:27.000000000 +0000
+++ src/pal/src/include/pal/palinternal.h
@@ -199,7 +199,6 @@ function_name() to call the system's imp
 #define srand DUMMY_srand
 #define atoi DUMMY_atoi
 #define atof DUMMY_atof
-#define time DUMMY_time
 #define tm PAL_tm
 #define size_t DUMMY_size_t
 #define time_t PAL_time_t
