$NetBSD$

NetBSD is POSIXy.
NetBSD has no need for 64 suffix to structs and functions.

--- vendor/spdlog/spdlog/details/os.h.orig	2017-02-11 12:34:50.000000000 +0000
+++ vendor/spdlog/spdlog/details/os.h
@@ -212,7 +212,7 @@ inline size_t filesize(FILE *f)
 #else // unix
     int fd = fileno(f);
     //64 bits(but not in osx, where fstat64 is deprecated)
-#if !defined(__FreeBSD__) && !defined(__APPLE__) && (defined(__x86_64__) || defined(__ppc64__))
+#if !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__APPLE__) && (defined(__x86_64__) || defined(__ppc64__))
     struct stat64 st;
     if (fstat64(fd, &st) == 0)
         return st.st_size;
@@ -343,7 +343,7 @@ inline std::string errno_str(int err_num
         return "Unkown error";
 
 #elif defined(__FreeBSD__) || defined(__APPLE__) || defined(ANDROID) || \
-      ((_POSIX_C_SOURCE >= 200112L) && ! _GNU_SOURCE) // posix version
+      defined(__NetBSD__) || ((_POSIX_C_SOURCE >= 200112L) && ! _GNU_SOURCE) // posix version
 
     if (strerror_r(err_num, buf, buf_size) == 0)
         return std::string(buf);
