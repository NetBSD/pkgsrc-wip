$NetBSD$

* Support older ELFOSABI_LINUX that has been replaced with ELFOSABI_GNU.
  Needed on NetBSD 9.

--- src/corelib/plugin/qelfparser_p.cpp.orig	2022-10-04 19:58:26.404142170 +0000
+++ src/corelib/plugin/qelfparser_p.cpp
@@ -329,7 +329,11 @@ Q_DECL_UNUSED Q_DECL_COLD_FUNCTION stati
     case ELFOSABI_SYSV:     d << " (SYSV"; break;
     case ELFOSABI_HPUX:     d << " (HP-UX"; break;
     case ELFOSABI_NETBSD:   d << " (NetBSD"; break;
-    case ELFOSABI_GNU:      d << " (GNU/Linux"; break;
+#if defined(ELFOSABI_LINUX)
+    case ELFOSABI_LINUX:    d << " (GNU/Linux"; break;
+#else
+    case ELFOSABI_GNU:      d << " (GNU/Linux"; break;   
+#endif
     case ELFOSABI_SOLARIS:  d << " (Solaris"; break;
     case ELFOSABI_AIX:      d << " (AIX"; break;
     case ELFOSABI_IRIX:     d << " (IRIX"; break;
