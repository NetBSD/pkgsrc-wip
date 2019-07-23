$NetBSD$

Patches from NetBSD xsrc 1.20.5

Option for wskbd.

--- hw/xfree86/common/xf86Configure.c.orig	2019-05-30 18:27:34.000000000 +0000
+++ hw/xfree86/common/xf86Configure.c
@@ -100,6 +100,10 @@ xf86AddBusDeviceToConfigure(const char *
             ret = xf86SbusConfigure(busData, DevToConfig[i].sVideo);
             break;
 #endif
+#if (defined(__arm32__) || defined(__arm__)) && defined(__NetBSD__)
+        case BUS_ISA:
+            break;
+#endif
         default:
             return NULL;
         }
@@ -138,6 +142,12 @@ xf86AddBusDeviceToConfigure(const char *
                                 &DevToConfig[i].GDev);
         break;
 #endif
+#if (defined(__arm32__) || defined(__arm__)) && defined(__NetBSD__)
+    case BUS_ISA:
+	DevToConfig[i].GDev.busID = xnfalloc(6);
+	strcpy((char *)DevToConfig[i].GDev.busID, "ISA");
+	break;
+#endif
     default:
         break;
     }
@@ -163,6 +173,12 @@ configureInputSection(void)
     ptr->inp_identifier = xnfstrdup("Keyboard0");
     ptr->inp_driver = xnfstrdup("kbd");
     ptr->list.next = NULL;
+#if defined(WSCONS_SUPPORT) && ((!defined(__i386__) && !defined(__amd64__) && defined(__NetBSD__)) || defined(TRY_DEV_WSKBD))
+    ptr->inp_option_lst = xf86addNewOption(ptr->inp_option_lst,
+        xstrdup("Protocol"), "wskbd");
+    ptr->inp_option_lst = xf86addNewOption(ptr->inp_option_lst,
+        xstrdup("Device"), "/dev/wskbd");
+#endif
 
     /* Crude mechanism to auto-detect mouse (os dependent) */
     {
