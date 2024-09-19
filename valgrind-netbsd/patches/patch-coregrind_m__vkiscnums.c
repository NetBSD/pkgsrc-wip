$NetBSD$

--- coregrind/m_vkiscnums.c.orig	2018-07-13 08:52:05.000000000 +0000
+++ coregrind/m_vkiscnums.c
@@ -69,6 +69,18 @@ STATIC_ASSERT(__NR_pipe2 == 5287);
 #endif
 
 //---------------------------------------------------------------------------
+#elif defined(VGO_netbsd)
+//---------------------------------------------------------------------------
+
+const HChar* VG_(sysnum_string)(Word sysnum)
+{
+   static HChar buf[20+1];   // large enough
+
+   VG_(snprintf)(buf, sizeof(buf), "%3ld", sysnum);
+   return buf;
+}
+
+//---------------------------------------------------------------------------
 #elif defined(VGO_darwin)
 //---------------------------------------------------------------------------
 
