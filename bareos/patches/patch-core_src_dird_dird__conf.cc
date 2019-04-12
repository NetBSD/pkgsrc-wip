$NetBSD$

	Add dumping of Honor No Dump Flag

--- core/src/dird/dird_conf.cc.orig	2019-01-19 22:29:21.418231855 +0000
+++ core/src/dird/dird_conf.cc
@@ -2043,6 +2043,9 @@ bool FilesetResource::PrintConfig(PoolMe
                   case 'M':                 /* MD5 */
                      IndentConfigItem(cfg_str, 3, "Signature = MD5\n");
                      break;
+                  case 'N':                 /* Honor No Dump Flag */
+                     IndentConfigItem(cfg_str, 3, "Honor No Dump Flag = Yes\n");
+                     break;
                   case 'n':
                      IndentConfigItem(cfg_str, 3, "Replace = Never\n");
                      break;
