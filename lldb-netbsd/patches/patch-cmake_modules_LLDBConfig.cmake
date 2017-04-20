$NetBSD$

--- cmake/modules/LLDBConfig.cmake.orig	2017-04-20 15:57:09.000000000 +0000
+++ cmake/modules/LLDBConfig.cmake
@@ -433,7 +433,9 @@ endif()
 
 find_package(Backtrace)
 
+include(CheckIncludeFile)
 check_include_file(termios.h HAVE_TERMIOS_H)
+check_include_file(sys/event.h HAVE_SYS_EVENT_H)
 
 # These checks exist in LLVM's configuration, so I want to match the LLVM names
 # so that the check isn't duplicated, but we translate them into the LLDB names
