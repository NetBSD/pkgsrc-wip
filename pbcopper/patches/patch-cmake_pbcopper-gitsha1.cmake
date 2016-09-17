$NetBSD$

# wrksrc is not a git repo

--- cmake/pbcopper-gitsha1.cmake.orig	2016-09-13 09:43:00.051959348 -0500
+++ cmake/pbcopper-gitsha1.cmake	2016-09-13 09:43:10.461246575 -0500
@@ -7,7 +7,7 @@ set(__find_git_sha1 YES)
 function(find_git_sha1 _GIT_SHA1)
     find_package(Git QUIET REQUIRED)
     execute_process(COMMAND
-        "${GIT_EXECUTABLE}" "describe" "--always" "--dirty=*"
+        echo ce9a4b6
         WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
         RESULT_VARIABLE res
         OUTPUT_VARIABLE out
