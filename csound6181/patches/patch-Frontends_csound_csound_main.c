$NetBSD$

Port to NetBSD and DragonFly.

--- Frontends/csound/csound_main.c.orig 2022-11-23 19:53:55.000000000 +0000
+++ Frontends/csound/csound_main.c
@@ -76,6 +76,8 @@ static void nomsg_callback(CSOUND *csoun
 #if defined(ANDROID) || (!defined(LINUX) && !defined(SGI) && \
                          !defined(__HAIKU__) && !defined(__BEOS__) && \
                          !defined(__MACH__) && !defined(__EMSCRIPTEN__))
+·························!defined(__MACH__)·&&·!defined(__EMSCRIPTEN__)·&&·\
+·························!defined(__NetBSD__)·&&·!defined(__DragonFly__))
 static char *signal_to_string(int sig)
 {
     switch(sig) {

