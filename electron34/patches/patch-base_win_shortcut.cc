$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/win/shortcut.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/win/shortcut.cc
@@ -289,14 +289,22 @@ bool ResolveShortcutProperties(const Fil
         return false;
       }
       switch (pv_app_id.get().vt) {
-        case VT_EMPTY:
+        case VT_EMPTY: {
           properties->set_app_id(std::wstring());
           break;
-        case VT_LPWSTR:
+        }
+        case VT_LPWSTR: {
           properties->set_app_id(pv_app_id.get().pwszVal);
           break;
-        default:
+        }
+        case VT_BSTR: {
+          BSTR bs = pv_app_id.get().bstrVal;
+          properties->set_app_id(std::wstring(bs, ::SysStringLen(bs)));
+          break;
+        }
+        default: {
           NOTREACHED() << "Unexpected variant type: " << pv_app_id.get().vt;
+        }
       }
     }
 
@@ -334,8 +342,9 @@ bool ResolveShortcutProperties(const Fil
               *(pv_toast_activator_clsid.get().puuid));
           break;
         default:
-          NOTREACHED() << "Unexpected variant type: "
-                       << pv_toast_activator_clsid.get().vt;
+          // Shortcuts may use strings to represent the CLSID. This case is
+          // ignored.
+          break;
       }
     }
   }
