$NetBSD$

--- src/VBox/Frontends/VBoxManage/VBoxManageHelp.cpp.orig	2016-03-04 19:28:59.000000000 +0000
+++ src/VBox/Frontends/VBoxManage/VBoxManageHelp.cpp
@@ -570,6 +570,11 @@ void printUsage(USAGECATEGORY fCategory,
 #else
     bool fFreeBSD = false;
 #endif
+#ifdef RT_OS_NETBSD
+    bool fNetBSD = true;
+#else
+    bool fNetBSD = false;
+#endif
 #ifdef RT_OS_DARWIN
     bool fDarwin = true;
 #else
@@ -588,6 +593,7 @@ void printUsage(USAGECATEGORY fCategory,
         fWin = true;
         fSolaris = true;
         fFreeBSD = true;
+        fNetBSD = true;
         fDarwin = true;
         fVBoxSDL = true;
         fCategory = USAGE_ALL;
@@ -824,6 +830,20 @@ void printUsage(USAGECATEGORY fCategory,
             RTStrmPrintf(pStrm, "|pulse");
 #endif
         }
+        if (fNetBSD)
+        {
+            /* Get the line break sorted when dumping all option variants. */
+            if (fDumpOpts)
+            {
+                RTStrmPrintf(pStrm, "|\n"
+                     "                                     oss");
+            }
+            else
+                RTStrmPrintf(pStrm, "|oss");
+#ifdef VBOX_WITH_PULSE
+            RTStrmPrintf(pStrm, "|pulse");
+#endif
+        }
         if (fDarwin)
         {
             RTStrmPrintf(pStrm, "|coreaudio");
@@ -1523,4 +1543,3 @@ RTEXITCODE errorArgument(const char *psz
     va_end(args);
     return RTEXITCODE_SYNTAX;
 }
-
