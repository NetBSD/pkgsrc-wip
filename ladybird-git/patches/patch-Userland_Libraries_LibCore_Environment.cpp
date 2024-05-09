$NetBSD$

Fix NetBSD & FreeBSD compatibility.
https://github.com/SerenityOS/serenity/pull/24273

--- Userland/Libraries/LibCore/Environment.cpp.orig	2024-05-09 18:56:01.000000000 +0000
+++ Userland/Libraries/LibCore/Environment.cpp
@@ -13,7 +13,7 @@
 #if defined(AK_OS_MACOS) || defined(AK_OS_IOS)
 #    include <crt_externs.h>
 #else
-extern char** environ;
+extern "C" char** environ;
 #endif
 
 namespace Core::Environment {
@@ -93,7 +93,8 @@ Optional<StringView> get(StringView name
     builder.append('\0');
     // Note the explicit null terminators above.
 
-#if defined(AK_OS_MACOS) || defined(AK_OS_ANDROID)
+    // FIXME: FreeBSD >= 14 has secure_getenv(3)
+#if defined(AK_OS_BSD_GENERIC) || defined(AK_OS_ANDROID)
     char* result = ::getenv(builder.string_view().characters_without_null_termination());
 #else
     char* result;
@@ -153,7 +154,9 @@ ErrorOr<void> put(StringView env)
 
 ErrorOr<void> clear()
 {
-#if defined(AK_OS_MACOS)
+#if defined(__FreeBSD__) && __FreeBSD__ < 14
+    environ = nullptr;
+#elif defined(AK_OS_BSD_GENERIC)
     auto environment = raw_environ();
     for (size_t environ_size = 0; environment[environ_size]; ++environ_size) {
         environment[environ_size] = NULL;
