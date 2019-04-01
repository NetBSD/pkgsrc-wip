$NetBSD$

--- coregrind/m_ume/main.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_ume/main.c
@@ -51,7 +51,7 @@ typedef struct {
 } ExeHandler;
 
 static ExeHandler exe_handlers[] = {
-#  if defined(VGO_linux) || defined(VGO_solaris)
+#  if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
    { VG_(match_ELF),    VG_(load_ELF) },
 #  elif defined(VGO_darwin)
    { VG_(match_macho),  VG_(load_macho) },
@@ -97,8 +97,9 @@ VG_(pre_exec_check)(const HChar* exe_nam
    }
 
    fsz = (SizeT)VG_(fsize)(fd);
-   if (fsz < bufsz)
+   if (fsz < bufsz) {
       bufsz = fsz;
+   }
 
    res = VG_(pread)(fd, buf, bufsz, 0);
    if (sr_isError(res) || sr_Res(res) != bufsz) {
@@ -141,8 +142,9 @@ Int VG_(do_exec_inner)(const HChar* exe,
    Int ret;
 
    res = VG_(pre_exec_check)(exe, &fd, False/*allow_setuid*/);
-   if (sr_isError(res))
+   if (sr_isError(res)) {
       return sr_Err(res);
+   }
 
    vg_assert2(sr_Res(res) >= 0 && sr_Res(res) < EXE_HANDLER_COUNT, 
               "invalid VG_(pre_exec_check) result");
@@ -249,7 +251,6 @@ static Int do_exec_shell_followup(Int re
       if (sr_isError(res) && sr_Err(res) == VKI_ENOENT) {
          VG_(fmsg)("%s: %s\n", exe_name, VG_(strerror)(ret));
          exit_code = 127;     // 127 == NOTFOUND (bash)
-
       // Was it a directory?
       } else if (!sr_isError(res) && VKI_S_ISDIR(st.mode)) {
          VG_(fmsg)("%s: is a directory\n", exe_name);
@@ -258,11 +259,9 @@ static Int do_exec_shell_followup(Int re
       } else if (0 != VG_(check_executable)(NULL, exe_name, 
                                             False/*allow_setuid*/)) {
          VG_(fmsg)("%s: %s\n", exe_name, VG_(strerror)(ret));
-
       // Did it start with "#!"?  If so, it must have been a bad interpreter.
       } else if (is_hash_bang_file(exe_name)) {
          VG_(fmsg)("%s: bad interpreter: %s\n", exe_name, VG_(strerror)(ret));
-
       // Otherwise it was something else.
       } else {
          VG_(fmsg)("%s: %s\n", exe_name, VG_(strerror)(ret));
