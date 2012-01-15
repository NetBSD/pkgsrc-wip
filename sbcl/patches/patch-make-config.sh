$NetBSD: patch-make-config.sh,v 1.1 2012/01/15 22:21:53 asau Exp $

Let it build on DragonFly. Additional DFBSD-specific quirks may need to be added in future.
Use sed'ing instead of per-file patches for easily maintaining, because SBCL evolves quickly
and hence, it's code too.
- Config.arch: There is no libthr in DF, use libthread for now (although it mentioned
as non-working in SBCL for now)

- fd-stream.lisp: Cures kernel panic seen at least in SBCL interactive debugger. In DF, fd
may not cause poll(2) to return to you with an error. So, poll'ing for checking fd for block
in loop, as far as i see, will cause kqueue(2) floodage and crossing of callouts limit, which
will led to kernel panic. Instead, it will just enough for now to rely on errors straight while
doing read op. on fd
For more info see:
DF kernel mail list message http://leaf.dragonflybsd.org/mailarchive/kernel/2010-08/msg00015.html
Commit in DF git repo http://gitweb.dragonflybsd.org/dragonfly.git/commit/34e191bd0

--- make-config.sh.orig	2012-01-15 22:18:46.000000000 +0000
+++ make-config.sh
@@ -273,6 +273,27 @@ case `uname` in
                 ;;
         esac
         ;;
+    DragonFly)
+        sbcl_os="freebsd"
+        mv ./src/runtime/GNUmakefile ./src/runtime/GNUmakefile.orig
+        sed '/>>sbcl.h/ a\
+                \'$'\techo "#define __FreeBSD__ 4" >>sbcl.h
+                ' ./src/runtime/GNUmakefile.orig > ./src/runtime/GNUmakefile
+        if [ `uname -m` = "i386" ]; then
+                mv ./src/runtime/Config.x86-freebsd ./src/runtime/Config.x86-freebsd.orig
+                sed -e '/[^#]OS_LIBS.*/d' -e 's/#\(OS_LIBS.*\)/\1/' \
+                        ./src/runtime/Config.x86-freebsd.orig > ./src/runtime/Config.x86-freebsd
+        fi
+        if [ `uname -m` = "x86_64" ]; then
+                mv ./src/runtime/Config.x86-64-freebsd ./src/runtime/Config.x86-64-freebsd.orig
+                sed -e '/[^#]OS_LIBS.*/d' -e 's/#\(OS_LIBS.*\)/\1/' \
+                        ./src/runtime/Config.x86-64-freebsd.orig > ./src/runtime/Config.x86-64-freebsd
+        fi
+        mv ./src/code/fd-stream.lisp ./src/code/fd-stream.lisp.orig
+        sed -e "/(if (and (neq :regular (fd-stream-fd-type stream))/{N; s/\\n//; s/.*//g;}" \
+                -e "/(go :wait-for-input)/{N; s/\\n//; s/.*\((go :main)\))/\1/g;}" \
+                ./src/code/fd-stream.lisp.orig > ./src/code/fd-stream.lisp
+        ;;
     Darwin)
         sbcl_os="darwin"
         ;;
