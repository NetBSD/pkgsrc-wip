$NetBSD$

Fix compilation on NetBSD.
https://github.com/SerenityOS/serenity/issues/23375

--- Userland/Libraries/LibCore/Environment.cpp.orig	2024-02-27 18:09:19.633132086 +0000
+++ Userland/Libraries/LibCore/Environment.cpp
@@ -93,7 +93,7 @@ Optional<StringView> get(StringView name
     builder.append('\0');
     // Note the explicit null terminators above.
 
-#if defined(AK_OS_MACOS)
+#if defined(AK_OS_MACOS) || defined(AK_OS_NETBSD)
     char* result = ::getenv(builder.string_view().characters_without_null_termination());
 #else
     char* result;
@@ -153,7 +153,7 @@ ErrorOr<void> put(StringView env)
 
 ErrorOr<void> clear()
 {
-#if defined(AK_OS_MACOS)
+#if defined(AK_OS_MACOS) || defined(AK_OS_NETBSD)
     auto environment = raw_environ();
     for (size_t environ_size = 0; environment[environ_size]; ++environ_size) {
         environment[environ_size] = NULL;
