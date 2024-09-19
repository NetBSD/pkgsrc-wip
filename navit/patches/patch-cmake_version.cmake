$NetBSD$

date commad on BSD needs the format to be the last argument

--- cmake/version.cmake.orig	2018-04-20 17:02:39.000000000 +0000
+++ cmake/version.cmake
@@ -39,7 +39,7 @@ string(REGEX MATCH "^[0-9]+" VERSION_NUM
 set(VERSION ${GIT_OUTPUT_HASH})
 
 EXECUTE_PROCESS(
-   COMMAND ${DATE_EXECUTABLE} "+%y%m%d%H%M" "-d \@${VERSION_NUM}" # output as unix timestamp
+   COMMAND ${DATE_EXECUTABLE} "-d \@${VERSION_NUM}" "+%y%m%d%H%M" # output as unix timestamp
    WORKING_DIRECTORY "${SOURCE_DIR}"
    OUTPUT_VARIABLE DATE_CONVERT_OUTPUT
    ERROR_VARIABLE DATE_CONVERT_ERROR
