$NetBSD$

--- src/other/tcl/unix/tclUnixCompat.c.orig	2016-08-09 06:47:10.000000000 +0000
+++ src/other/tcl/unix/tclUnixCompat.c
@@ -101,7 +101,7 @@ static Tcl_ThreadDataKey dataKey;
      (!defined(HAVE_MTSAFE_GETHOSTBYNAME) || \
       !defined(HAVE_MTSAFE_GETHOSTBYADDR))) || \
       !defined(HAVE_GETPWNAM_R) || !defined(HAVE_GETPWUID_R) || \
-      !defined(HAVE_GETGRNAM_R) || !defined(HAVE_GETGRGID_R)
+      !defined(HAVE_GETGRNAM_R) || !defined(HAVE_GETGRGID_R) || defined(__NetBSD__)
 /*
  * Mutex to lock access to MT-unsafe calls. This is just to protect our own
  * usage. It does not protect us from others calling the same functions
@@ -382,13 +382,13 @@ TclpGetHostByName(
 #else
     ThreadSpecificData *tsdPtr = TCL_TSD_INIT(&dataKey);
 
-#if defined(HAVE_GETHOSTBYNAME_R_5)
+#if defined(HAVE_GETHOSTBYNAME_R_5) && !defined(__NetBSD__)
     int h_errno;
 
     return gethostbyname_r(name, &tsdPtr->hent, tsdPtr->hbuf,
 			   sizeof(tsdPtr->hbuf), &h_errno);
 
-#elif defined(HAVE_GETHOSTBYNAME_R_6)
+#elif defined(HAVE_GETHOSTBYNAME_R_6) && !defined(__NetBSD__)
     struct hostent *hePtr = NULL;
     int h_errno, result;
 
@@ -396,7 +396,7 @@ TclpGetHostByName(
 	    sizeof(tsdPtr->hbuf), &hePtr, &h_errno);
     return (result == 0) ? hePtr : NULL;
 
-#elif defined(HAVE_GETHOSTBYNAME_R_3)
+#elif defined(HAVE_GETHOSTBYNAME_R_3) && !defined(__NetBSD__)
     struct hostent_data data;
 
     return (gethostbyname_r(name, &tsdPtr->hent, &data) == 0)
@@ -452,13 +452,13 @@ TclpGetHostByAddr(
 #else
     ThreadSpecificData *tsdPtr = TCL_TSD_INIT(&dataKey);
 
-#if defined(HAVE_GETHOSTBYADDR_R_7)
+#if defined(HAVE_GETHOSTBYADDR_R_7) && !defined(__NetBSD__)
     int h_errno;
 
     return gethostbyaddr_r(addr, length, type, &tsdPtr->hent, tsdPtr->hbuf,
 	    sizeof(tsdPtr->hbuf), &h_errno);
 
-#elif defined(HAVE_GETHOSTBYADDR_R_8)
+#elif defined(HAVE_GETHOSTBYADDR_R_8) && !defined(__NetBSD__)
     struct hostent *hePtr;
     int h_errno;
 
