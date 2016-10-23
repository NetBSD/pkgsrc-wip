$NetBSD$

--- regress/repository.sh.orig	2016-08-09 06:49:56.000000000 +0000
+++ regress/repository.sh
@@ -58,12 +58,12 @@ fi
 
 # get a source and header file list so we only walk the sources once
 
-SRCFILES="`find src -type f \( -name \*.c -o -name \*.cpp -o -name \*.cxx -o -name \*.cc -o -name \*.h -o -name \*.y -o -name \*.l \) -not -regex '.*src/other.*' -not -regex '.*misc/tools.*' -not -regex '.*misc/svn2git.*' -not -regex '.*~' -not -regex '.*\.log' -not -regex '.*Makefile.*' -not -regex '.*cache.*' -not -regex '.*\.svn.*' -not -regex '.*src/libpkg.*' -not -regex '.*/shapelib/.*'`"
+SRCFILES="`find src -type f \( -name \*.c -o -name \*.cpp -o -name \*.cxx -o -name \*.cc -o -name \*.h -o -name \*.y -o -name \*.l \) '!' -regex '.*src/other.*' '!' -regex '.*misc/tools.*' '!' -regex '.*misc/svn2git.*' '!' -regex '.*~' '!' -regex '.*\.log' '!' -regex '.*Makefile.*' '!' -regex '.*cache.*' '!' -regex '.*\.svn.*' '!' -regex '.*src/libpkg.*' '!' -regex '.*/shapelib/.*'`"
 
-INCFILES="`find include -type f \( -name \*.c -o -name \*.cpp -o -name \*.cxx -o -name \*.cc -o -name \*.h -o -name \*.y -o -name \*.l \) -not -regex '.*src/other.*' -not -regex '.*misc/tools.*' -not -regex '.*misc/svn2git.*' -not -regex '.*~' -not -regex '.*\.log' -not -regex '.*Makefile.*' -not -regex '.*cache.*' -not -regex '.*\.svn.*' -not -regex '.*pkg.h'`"
+INCFILES="`find include -type f \( -name \*.c -o -name \*.cpp -o -name \*.cxx -o -name \*.cc -o -name \*.h -o -name \*.y -o -name \*.l \) '!' -regex '.*src/other.*' '!' -regex '.*misc/tools.*' '!' -regex '.*misc/svn2git.*' '!' -regex '.*~' '!' -regex '.*\.log' '!' -regex '.*Makefile.*' '!' -regex '.*cache.*' '!' -regex '.*\.svn.*' '!' -regex '.*pkg.h'`"
 
-BLDFILES="`find src -type f \( -name \*.cmake -o -name CMakeLists.txt \) -not -regex '.*src/other.*' -not -regex '.*misc/tools.*' -not -regex '.*misc/svn2git.*' -not -regex '.*~' -not -regex '.*cache.*' -not -regex '.*\.svn.*'`
-`find misc -type f \( -name \*.cmake -o -name CMakeLists.txt \) -not -regex '.*src/other.*' -not -regex '.*misc/tools.*' -not -regex '.*misc/svn2git.*' -not -regex '.*~' -not -regex '.*cache.*' -not -regex '.*\.svn.*' -not -regex '.*autoheader.*'`
+BLDFILES="`find src -type f \( -name \*.cmake -o -name CMakeLists.txt \) '!' -regex '.*src/other.*' '!' -regex '.*misc/tools.*' '!' -regex '.*misc/svn2git.*' '!' -regex '.*~' '!' -regex '.*cache.*' '!' -regex '.*\.svn.*'`
+`find misc -type f \( -name \*.cmake -o -name CMakeLists.txt \) '!' -regex '.*src/other.*' '!' -regex '.*misc/tools.*' '!' -regex '.*misc/svn2git.*' '!' -regex '.*~' '!' -regex '.*cache.*' '!' -regex '.*\.svn.*' '!' -regex '.*autoheader.*'`
 CMakeLists.txt"
 
 
