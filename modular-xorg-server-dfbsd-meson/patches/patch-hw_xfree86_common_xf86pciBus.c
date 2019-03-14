$NetBSD$

From OpenBSD 6.5 xenocara

--- hw/xfree86/common/xf86pciBus.c.orig	2019-03-05 16:34:21.000000000 +0000
+++ hw/xfree86/common/xf86pciBus.c
@@ -1174,9 +1174,38 @@ xf86VideoPtrToDriverList(struct pci_devi
 		case 0x0bef:
 			/* Use fbdev/vesa driver on Oaktrail, Medfield, CDV */
 			break;
+#if defined(MODESETTING_ON_INTEL)
+		case 0x3577:
+		case 0x2562:
+		case 0x3582:
+		case 0x358e: /* 854 */
+		case 0x2572:
+		case 0x2582:
+		case 0x258a:
+		case 0x2592:
+		case 0x2772:
+		case 0x27a2:
+		case 0x27ae:
+		case 0x2972:
+		case 0x29b2:
+		case 0x29c2:
+		case 0x29d2:
+		case 0xa001:
+		case 0xa011:
+		case 0x0042: /* XXX Ironlake is unstable with modesetting */
+		case 0x0046:
+			/* Use intel driver on 2nd and 3rd generation */
+ 			driverList[0] = "intel";
+ 			break;
+		default:
+			/* Use modesetting driver on 4th generation and up */
+			driverList[0] = "modesetting";
+			break;
+#else
 		default:
 			driverList[0] = "intel";
 			break;
+#endif
         }
         break;
     case 0x102b:
