$NetBSD$

--- coregrind/launcher-linux.c.orig	2018-07-13 08:52:05.000000000 +0000
+++ coregrind/launcher-linux.c
@@ -53,6 +53,16 @@
 #include <string.h>
 #include <unistd.h>
 
+#if defined(VGO_netbsd)
+#include <sys/param.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
+#ifndef VKI_BINPRM_BUF_SIZE
+#define VKI_BINPRM_BUF_SIZE VKI_PATH_MAX
+#endif
+
 #ifndef EM_X86_64
 #define EM_X86_64 62    // elf.h doesn't define this on some older systems
 #endif
@@ -276,6 +286,13 @@ static const char *select_platform(const
                platform = "amd64-solaris";
             }
             else
+#           elif defined(VGO_netbsd)
+            if (header.ehdr64.e_machine == EM_X86_64 &&
+                (header.ehdr64.e_ident[EI_OSABI] == ELFOSABI_SYSV ||
+                 header.ehdr64.e_ident[EI_OSABI] == ELFOSABI_NETBSD)) {
+               platform = "amd64-netbsd";
+            }
+            else
 #           endif
             if (header.ehdr64.e_machine == EM_X86_64 &&
                 (header.ehdr64.e_ident[EI_OSABI] == ELFOSABI_SYSV ||
@@ -338,7 +355,9 @@ int main(int argc, char** argv, char** e
    const char *cp;
    const char *linkname;
    char *toolfile;
+#if !defined(VGO_netbsd)
    const char *launcher_name;
+#endif
    char* new_line;
    char** new_env;
 
@@ -397,6 +416,9 @@ int main(int argc, char** argv, char** e
    if ((0==strcmp(VG_PLATFORM,"x86-solaris")) ||
        (0==strcmp(VG_PLATFORM,"amd64-solaris")))
       default_platform = SOLARIS_LAUNCHER_DEFAULT_PLATFORM;
+#  elif defined(VGO_netbsd)
+   if ((0==strcmp(VG_PLATFORM,"amd64-netbsd")))
+      default_platform = NETBSD_LAUNCHER_DEFAULT_PLATFORM;
 #  else
 #    error Unknown OS
 #  endif
@@ -422,6 +444,18 @@ int main(int argc, char** argv, char** e
    /* Figure out the name of this executable (viz, the launcher), so
       we can tell stage2.  stage2 will use the name for recursive
       invocations of valgrind on child processes. */
+#if defined(VGO_netbsd)
+    static const int name[] = {
+        CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME,
+    };
+    char launcher_name[MAXPATHLEN];
+    size_t len;
+
+    len = sizeof(launcher_name);
+    if (sysctl(name, __arraycount(name), launcher_name, &len, NULL, 0) == -1) {
+      abort();
+    }
+#else
 #  if defined(VGO_linux)
    linkname = "/proc/self/exe";
 #  elif defined(VGO_solaris)
@@ -458,7 +492,7 @@ int main(int argc, char** argv, char** e
       launcher_name = buf;
       break;
    }
-
+#endif
    /* tediously augment the env: VALGRIND_LAUNCHER=launcher_name */
    new_line = malloc(strlen(VALGRIND_LAUNCHER) + 1 
                      + strlen(launcher_name) + 1);
