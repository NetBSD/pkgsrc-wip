$NetBSD: patch-programs_dtexec_Main.c,v 1.1 2012/10/01 06:41:29 jellehermsen Exp $

--- programs/dtexec/Main.c.orig	2012-09-28 21:26:31.000000000 +0000
+++ programs/dtexec/Main.c
@@ -323,7 +323,7 @@ Help(
  *****************************************************************************/
 
 static void
-#if defined(__aix) || defined (__osf__) || defined(__FreeBSD__) || defined(linux)
+#if defined(__aix) || defined (__osf__) || defined(CSRG_BASED) || defined(linux)
 PanicSignal(int s)
 #else
 PanicSignal(void)
@@ -360,7 +360,7 @@ PanicSignal(void)
  *****************************************************************************/
 
 static void
-#if defined(__aix) || defined (__osf__) || defined(__FreeBSD__) || defined(linux)
+#if defined(__aix) || defined (__osf__) || defined(CSRG_BASED) || defined(linux)
 IgnoreSignal(int i)
 #else
 IgnoreSignal(void)
@@ -402,7 +402,7 @@ IgnoreSignal(void)
  *****************************************************************************/
 
 static void
-#if defined(__aix) || defined (__osf__) || defined(__FreeBSD__) || defined(linux)
+#if defined(__aix) || defined (__osf__) || defined(CSRG_BASED) || defined(linux)
 UrgentSignal(int i)
 #else
 UrgentSignal(void)
@@ -453,7 +453,7 @@ UrgentSignal(void)
  *
  *****************************************************************************/
 static void
-#if defined(__aix) || defined (__osf__) || defined(__FreeBSD__) || defined(linux)
+#if defined(__aix) || defined (__osf__) || defined(CSRG_BASED) || defined(linux)
 SigCld(int i)
 #else
 SigCld(void)
@@ -1525,7 +1525,7 @@ main (
 		 * a SIGCLD, give up and exit.
 		 */
 		if (rediscoverUrgentSigG > ((1000/SHORT_SELECT_TIMEOUT)*5) ) {
-#if defined(__aix) || defined (__osf__) || defined(__FreeBSD__) || defined(linux)
+#if defined(__aix) || defined (__osf__) || defined(CSRG_BASED) || defined(linux)
 		    PanicSignal(0);
 #else
 		    PanicSignal();
