$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/ime/init/input_method_initializer.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/base/ime/init/input_method_initializer.cc
@@ -8,7 +8,7 @@
 #include "base/functional/callback.h"
 #include "build/build_config.h"
 
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "ui/base/ime/linux/fake_input_method_context.h"
 #include "ui/base/ime/linux/linux_input_method_context_factory.h"
 #elif BUILDFLAG(IS_WIN)
@@ -31,7 +31,7 @@ void ShutdownInputMethod() {
 }
 
 void InitializeInputMethodForTesting() {
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   GetInputMethodContextFactoryForTest() =
       base::BindRepeating([](LinuxInputMethodContextDelegate* delegate)
                               -> std::unique_ptr<LinuxInputMethodContext> {
@@ -43,7 +43,7 @@ void InitializeInputMethodForTesting() {
 }
 
 void ShutdownInputMethodForTesting() {
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   // The function owns the factory (as a static variable that's returned by
   // reference), so setting this to an empty factory will free the old one.
   GetInputMethodContextFactoryForTest() = LinuxInputMethodContextFactory();
