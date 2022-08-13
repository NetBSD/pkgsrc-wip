$NetBSD$

S_IREAD, S_IWRITE handling on __NetBSD__ is same as that on DARWIN

https://sourceforge.net/p/xsb/patches/9/

--- ../emu/system_xsb.c.orig	2022-05-12 20:54:07.000000000 +0000
+++ ../emu/system_xsb.c
@@ -228,7 +228,7 @@ int sys_syscall(CTXTdeclc int callno)
   }
   case SYS_create: {
     // TES: need to use different macro forms with clang when updating the POSIX vzaersion
-#if defined(DARWIN)
+#if defined(DARWIN) || defined(__NetBSD__)
     result = open(ptoc_longstring(CTXTc 3),O_CREAT|O_EXCL,S_IRUSR|S_IWUSR);
 #else
     result = open(ptoc_longstring(CTXTc 3),O_CREAT|O_EXCL,S_IREAD|S_IWRITE);
