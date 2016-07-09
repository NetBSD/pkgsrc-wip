$NetBSD$

Disable CPU Throttling detection, it can lower down performance of the executable.

--- CONFIG/src/config.c.orig	2014-07-10 16:22:02.000000000 +0000
+++ CONFIG/src/config.c
@@ -711,6 +711,8 @@ int ProbePtrbits(int verb, char *targarg
 
 int ProbeCPUThrottle(int verb, char *targarg, enum OSTYPE OS, enum ASMDIA asmb)
 {
+   return 0;
+
    int i, iret;
    char *ln;
    i = strlen(targarg) + 22 + 12;
