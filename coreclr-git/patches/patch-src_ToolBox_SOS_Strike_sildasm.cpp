$NetBSD$

--- src/ToolBox/SOS/Strike/sildasm.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/ToolBox/SOS/Strike/sildasm.cpp
@@ -774,7 +774,7 @@ PCCOR_SIGNATURE PrettyPrintType(
 // set Reiterate to true, so we only execute through the loop once!
 #pragma warning(disable:6263) // "Suppress PREfast warnings about stack overflow due to _alloca in a loop."
 #endif
-                    int* lowerBounds = (int*) _alloca(sizeof(int)*2*rank);
+                    int* lowerBounds = (int*) alloca(sizeof(int)*2*rank);
                     int* sizes       = &lowerBounds[rank];  
                     memset(lowerBounds, 0, sizeof(int)*2*rank); 
                     
@@ -899,7 +899,7 @@ PCCOR_SIGNATURE PrettyPrintType(
 const char *const szStdNamePrefix[] = {"MO","TR","TD","","FD","","MD","","PA","II","MR","","CA","","PE","","","SG","","","EV",
 "","","PR","","","MOR","TS","","","","","AS","","","AR","","","FL","ET","MAR"};
 
-#define MAKE_NAME_IF_NONE(psz, tk) { if(!(psz && *psz)) { char* sz = (char*)_alloca(16); \
+#define MAKE_NAME_IF_NONE(psz, tk) { if(!(psz && *psz)) { char* sz = (char*)alloca(16); \
 sprintf_s(sz,16,"$%s$%X",szStdNamePrefix[tk>>24],tk&0x00FFFFFF); psz = sz; } }
 
 const char* PrettyPrintClass(
