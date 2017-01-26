$NetBSD$

* fix install target so that destdir is added when installing QMAKE_TARGET
* re-add compile_libtool support that was ripped out in qt 5.6

--- qmake/generators/unix/unixmake.cpp.orig	2016-12-01 08:17:04.000000000 +0000
+++ qmake/generators/unix/unixmake.cpp
@@ -45,6 +45,8 @@ UnixMakefileGenerator::init()
         project->values("ICON") = project->values("RC_FILE");
     if(project->isEmpty("QMAKE_EXTENSION_PLUGIN"))
         project->values("QMAKE_EXTENSION_PLUGIN").append(project->first("QMAKE_EXTENSION_SHLIB"));
+    if(project->isEmpty("QMAKE_LIBTOOL"))
+        project->values("QMAKE_LIBTOOL").append("libtool --silent");
 
     project->values("QMAKE_ORIG_TARGET") = project->values("TARGET");
 
@@ -150,6 +152,8 @@ UnixMakefileGenerator::init()
 
     if(project->isActiveConfig("GNUmake") && !project->isEmpty("QMAKE_CFLAGS_DEPS"))
         include_deps = true; //do not generate deps
+    if(project->isActiveConfig("compile_libtool"))
+        Option::obj_ext = ".lo"; //override the .o
 
     MakefileGenerator::init();
 
@@ -224,7 +228,7 @@ UnixMakefileGenerator::init()
             project->values(runCompImp).append(compilerExecutable + " " + compile_flag + " " + var("QMAKE_CC_O_FLAG") + "\"$@\" \"$<\"");
     }
 
-    if (project->isActiveConfig("mac") && !project->isEmpty("TARGET") &&
+    if (project->isActiveConfig("mac") && !project->isEmpty("TARGET") && !project->isActiveConfig("compile_libtool") &&
        ((project->isActiveConfig("build_pass") || project->isEmpty("BUILDS")))) {
         ProString bundle;
         if(project->isActiveConfig("bundle") && !project->isEmpty("QMAKE_BUNDLE_EXTENSION")) {
@@ -306,6 +310,51 @@ UnixMakefileGenerator::init()
             project->values("QMAKE_INTERNAL_PRL_LIBS") << "QMAKE_AR_SUBLIBS";
         }
     }
+
+    if(project->isActiveConfig("compile_libtool")) {
+        static const char * const libtoolify[] = {
+            "QMAKE_RUN_CC", "QMAKE_RUN_CC_IMP", "QMAKE_RUN_CXX", "QMAKE_RUN_CXX_IMP",
+            "QMAKE_LINK_THREAD", "QMAKE_LINK", "QMAKE_AR_CMD", "QMAKE_LINK_SHLIB_CMD", 0
+        };
+        for (int i = 0; libtoolify[i]; i++) {
+            ProStringList &l = project->values(libtoolify[i]);
+            if(!l.isEmpty()) {
+                QString libtool_flags, comp_flags;
+                if (!strncmp(libtoolify[i], "QMAKE_LINK", 10) || !strcmp(libtoolify[i], "QMAKE_AR_CMD")) {
+                    libtool_flags += " --mode=link";
+                    if(project->isActiveConfig("staticlib")) {
+                        comp_flags += " -static";
+                    } else {
+                        if(!project->isEmpty("QMAKE_LIB_FLAG")) {
+                          if(project->isActiveConfig("plugin"))
+                            comp_flags += " -avoid-version";
+                          else {
+                            int maj = project->first("VER_MAJ").toInt();
+                            int min = project->first("VER_MIN").toInt();
+                            int pat = project->first("VER_PAT").toInt();
+                            comp_flags += " -version-info " + QString::number(maj + min) +
+                                          ":" + QString::number(pat) +
+                                          ":" + QString::number(min);
+                          }
+                            if (strcmp(libtoolify[i], "QMAKE_AR_CMD")) {
+                                QString rpath = Option::fixPathToTargetOS(project->first("target.path").toQString(), false);
+                                if(rpath.right(1) != Option::dir_sep)
+                                    rpath += Option::dir_sep;
+                                comp_flags += " -rpath " + escapeFilePath(Option::fixPathToTargetOS(rpath, false));
+                            }
+                        }
+                    }
+                    if(project->isActiveConfig("plugin"))
+                        comp_flags += " -module";
+                } else {
+                    libtool_flags += " --mode=compile";
+                }
+                l.first().prepend("$(LIBTOOL)" + libtool_flags + " ");
+                if(!comp_flags.isEmpty())
+                    l.first() += comp_flags;
+            }
+        }
+    }
 }
 
 QStringList
@@ -410,6 +459,16 @@ UnixMakefileGenerator::findLibraries(boo
                                 goto found;
                         }
                     }
+                    if (project->isActiveConfig("compile_libtool")) {
+                        for (int dep_i = 0; dep_i < libdirs.size(); ++dep_i) {
+                            if (exists(libdirs[dep_i].local() + '/'
+                                       + project->first("QMAKE_PREFIX_SHLIB") + lib + Option::libtool_ext)) {
+                                (*it) = libdirs[dep_i].real() + Option::dir_sep
+                                        + project->first("QMAKE_PREFIX_SHLIB") + lib + Option::libtool_ext;
+                                goto found;
+                            }
+                        }
+                    }
                   found: ;
                 } else if (target_mode == TARG_MAC_MODE && opt.startsWith("-F")) {
                     QMakeLocalFileName f(opt.mid(2));
@@ -536,7 +595,7 @@ UnixMakefileGenerator::defaultInstall(co
     QString ret, destdir = project->first("DESTDIR").toQString();
     if(!destdir.isEmpty() && destdir.right(1) != Option::dir_sep)
         destdir += Option::dir_sep;
-    QString targetdir = fileFixify(project->first("target.path").toQString(), FileFixifyAbsolute);
+    QString targetdir = project->first("target.path").toQString();
     if(targetdir.right(1) != Option::dir_sep)
         targetdir += Option::dir_sep;
 
@@ -570,6 +629,25 @@ UnixMakefileGenerator::defaultInstall(co
         uninst.append("-$(DEL_FILE) " + dst);
     }
 
+    if (bundle == NoBundle && project->isActiveConfig("compile_libtool")) {
+        QString src_targ = escapeFilePath(target);
+        if(src_targ == "$(TARGET)")
+            src_targ = "$(TARGETL)";
+        QString dst_dir = targetdir;
+        if(QDir::isRelativePath(dst_dir))
+            dst_dir = Option::fixPathToTargetOS(dst_dir);
+            dst_dir = Option::fixPathToTargetOS(dst_dir);
+        if(!ret.isEmpty())
+            ret += "\n\t";
+        if(project->first("TEMPLATE") == "app") {
+            ret += "-$(LIBTOOL) --mode=install cp \"" + Option::fixPathToTargetOS(destdir + src_targ, false) + "\" \"" + filePrefixRoot(root, dst_dir) + "\"";
+        } else {
+            ret += "-$(LIBTOOL) --mode=install cp \"" + src_targ + "\" \"" + filePrefixRoot(root, dst_dir) + "\"";
+        }
+        if(!uninst.isEmpty())
+            uninst.append("\n\t");
+        uninst.append("-$(LIBTOOL) --mode=uninstall " + src_targ);
+    } else
     {
         QString src_targ = target;
         if(!destdir.isEmpty())
@@ -691,7 +769,7 @@ UnixMakefileGenerator::defaultInstall(co
             if(type == "prl" && project->isActiveConfig("create_prl") && !project->isActiveConfig("no_install_prl") &&
                !project->isEmpty("QMAKE_INTERNAL_PRL_FILE"))
                 meta = prlFileName(false);
-            if (type == "libtool" && project->isActiveConfig("create_libtool"))
+            if (type == "libtool" && project->isActiveConfig("create_libtool") && !project->isActiveConfig("compile_libtool"))
                 meta = libtoolFileName(false);
             if(type == "pkgconfig" && project->isActiveConfig("create_pc"))
                 meta = pkgConfigFileName(false);
