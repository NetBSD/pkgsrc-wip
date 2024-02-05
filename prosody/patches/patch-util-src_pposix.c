$NetBSD$

Provide mallinfo support for illumos. Fixing uname lookup on illumos (non Linux
distributions).

--- util-src/pposix.c.orig	2024-02-04 17:30:58.000000000 +0000
+++ util-src/pposix.c
@@ -70,9 +70,14 @@
 #include <linux/falloc.h>
 #endif
 
-#if !defined(WITHOUT_MALLINFO) && defined(__linux__) && defined(__GLIBC__)
-#include <malloc.h>
+#if !defined(WITHOUT_MALLINFO)
+#if ( defined(__linux__) && defined(__GLIBC__) ) || defined(__sun)
 #define WITH_MALLINFO
+#include <malloc.h>
+#endif
+
+#elif defined(__sun)
+#include <grp.h>
 #endif
 
 #if defined(__FreeBSD__) && defined(RFPROC)
@@ -657,7 +662,7 @@ static int lc_abort(lua_State *L) {
 static int lc_uname(lua_State *L) {
 	struct utsname uname_info;
 
-	if(uname(&uname_info) != 0) {
+	if(uname(&uname_info) < 0) {
 		luaL_pushfail(L);
 		lua_pushstring(L, strerror(errno));
 		return 2;
@@ -711,10 +716,15 @@ static int lc_setenv(lua_State *L) {
 
 #ifdef WITH_MALLINFO
 static int lc_meminfo(lua_State *L) {
+#if defined(__GLIBC__) 
 #if __GLIBC_PREREQ(2, 33)
 	struct mallinfo2 info = mallinfo2();
 #define MALLINFO_T size_t
 #else
+  struct mallinfo info = mallinfo();
+#define MALLINFO_T unsigned
+#endif
+#else
 	struct mallinfo info = mallinfo();
 #define MALLINFO_T unsigned
 #endif
