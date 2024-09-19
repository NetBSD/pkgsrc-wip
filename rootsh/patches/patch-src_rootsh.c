$NetBSD$

--- src/rootsh.c.orig	2008-05-14 20:10:00.000000000 +0000
+++ src/rootsh.c
@@ -680,7 +680,7 @@ int beginlogging(void) {
     //  Open the logfile 
     */
     if ((logFile = open(logFileName, O_RDWR|O_CREAT|O_SYNC|O_CREAT|O_APPEND|
-        S_IRUSR|S_IWUSR)) == -1) {
+        S_IRUSR|S_IWUSR, 0640)) == -1) {
       perror(logFileName);
       return(0);
     }
