$NetBSD$

Use unversioned libxcb.so instead of hardcoded libxcb.so.1 (Linux).
NetBSD ships libxcb.so.2, so dlopen("libxcb.so.1") fails, all xcb
function pointers are null, and xcb_connection_has_error() dereferences
null → SIGSEGV at address 0x0.

--- Telegram/lib_base/base/platform/linux/base_linux_xcb_library.cpp.orig	2026-08-03 12:00:00.000000000 +0300
+++ Telegram/lib_base/base/platform/linux/base_linux_xcb_library.cpp
@@ -11,7 +11,7 @@
 namespace base::Platform::XCB::Library {
 
 void *LoadSymbol(const char *name) {
-	static const auto Handle = LoadLibrary("libxcb.so.1", RTLD_NODELETE);
+	static const auto Handle = LoadLibrary("libxcb.so", RTLD_NODELETE);
 	return Handle ? LoadSymbolGeneric(Handle, name) : nullptr;
 }
 
