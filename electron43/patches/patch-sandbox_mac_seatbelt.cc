$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- sandbox/mac/seatbelt.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ sandbox/mac/seatbelt.cc
@@ -4,12 +4,14 @@
 
 #include "sandbox/mac/seatbelt.h"
 
+#include "electron/mas.h"
+
 #include <errno.h>
 #include <unistd.h>
 
 extern "C" {
 #include <sandbox.h>
-
+#if !IS_MAS_BUILD()
 int sandbox_init_with_parameters(const char* profile,
                                  uint64_t flags,
                                  const char* const parameters[],
@@ -40,13 +42,13 @@ sandbox_profile_t* sandbox_compile_strin
                                           char** error);
 int sandbox_apply(sandbox_profile_t*);
 void sandbox_free_profile(sandbox_profile_t*);
-
+#endif
 }  // extern "C"
 
 namespace sandbox {
 
 namespace {
-
+#if !IS_MAS_BUILD()
 bool HandleSandboxResult(int rv, char* errorbuf, std::string* error) {
   if (rv == 0) {
     if (error)
@@ -74,36 +76,48 @@ bool HandleSandboxErrno(int rv, const ch
   }
   return false;
 }
-
+#endif
 }  // namespace
 
 // static
 Seatbelt::Parameters Seatbelt::Parameters::Create() {
   Parameters params;
+#if !IS_MAS_BUILD()
   params.params_ = ::sandbox_create_params();
+#endif
   return params;
 }
 
 Seatbelt::Parameters::Parameters() = default;
 
 Seatbelt::Parameters::Parameters(Seatbelt::Parameters&& other) {
+#if !IS_MAS_BUILD()
   params_ = std::exchange(other.params_, nullptr);
+#endif
 }
 
 Seatbelt::Parameters& Seatbelt::Parameters::operator=(
     Seatbelt::Parameters&& other) {
+#if !IS_MAS_BUILD()
   params_ = std::exchange(other.params_, nullptr);
+#endif
   return *this;
 }
 
 bool Seatbelt::Parameters::Set(const char* key, const char* value) {
+#if !IS_MAS_BUILD()
   return ::sandbox_set_param(params_, key, value) == 0;
+#else
+  return true;
+#endif
 }
 
 Seatbelt::Parameters::~Parameters() {
+#if !IS_MAS_BUILD()
   if (params_) {
     ::sandbox_free_params(params_);
   }
+#endif
 }
 
 // Initialize the static member variables.
@@ -114,6 +128,7 @@ const char* Seatbelt::kProfilePureComput
 
 // static
 bool Seatbelt::Init(const char* profile, uint64_t flags, std::string* error) {
+#if !IS_MAS_BUILD()
 // OS X deprecated these functions, but did not provide a suitable replacement,
 // so ignore the deprecation warning.
 #pragma clang diagnostic push
@@ -122,6 +137,9 @@ bool Seatbelt::Init(const char* profile,
   int rv = ::sandbox_init(profile, flags, &errorbuf);
   return HandleSandboxResult(rv, errorbuf, error);
 #pragma clang diagnostic pop
+#else
+  return true;
+#endif
 }
 
 // static
@@ -129,10 +147,14 @@ bool Seatbelt::InitWithParams(const char
                               uint64_t flags,
                               const char* const parameters[],
                               std::string* error) {
+#if !IS_MAS_BUILD()
   char* errorbuf = nullptr;
   int rv =
       ::sandbox_init_with_parameters(profile, flags, parameters, &errorbuf);
   return HandleSandboxResult(rv, errorbuf, error);
+#else
+  return true;
+#endif
 }
 
 // static
@@ -140,6 +162,7 @@ bool Seatbelt::Compile(const char* profi
                        const Seatbelt::Parameters& params,
                        std::string& compiled_profile,
                        std::string* error) {
+#if !IS_MAS_BUILD()
   char* errorbuf = nullptr;
   sandbox_profile_t* sandbox_profile =
       ::sandbox_compile_string(profile, params.params(), &errorbuf);
@@ -149,33 +172,44 @@ bool Seatbelt::Compile(const char* profi
   compiled_profile.assign(reinterpret_cast<const char*>(sandbox_profile->data),
                           sandbox_profile->size);
   ::sandbox_free_profile(sandbox_profile);
+#endif
   return true;
 }
 
 // static
 bool Seatbelt::ApplyCompiledProfile(const std::string& profile,
                                     std::string* error) {
+#if !IS_MAS_BUILD()
   sandbox_profile_t sbox_profile = {
       .builtin = nullptr,
       .data = reinterpret_cast<const uint8_t*>(profile.data()),
       .size = profile.size()};
   return HandleSandboxErrno(::sandbox_apply(&sbox_profile),
                             "sandbox_apply: ", error);
+#else
+  return true;
+#endif
 }
 
 // static
 void Seatbelt::FreeError(char* errorbuf) {
+#if !IS_MAS_BUILD()
 // OS X deprecated these functions, but did not provide a suitable replacement,
 // so ignore the deprecation warning.
 #pragma clang diagnostic push
 #pragma clang diagnostic ignored "-Wdeprecated-declarations"
   return ::sandbox_free_error(errorbuf);
 #pragma clang diagnostic pop
+#endif
 }
 
 // static
 bool Seatbelt::IsSandboxed() {
+#if !IS_MAS_BUILD()
   return ::sandbox_check(getpid(), NULL, 0);
+#else
+  return true;
+#endif
 }
 
 }  // namespace sandbox
