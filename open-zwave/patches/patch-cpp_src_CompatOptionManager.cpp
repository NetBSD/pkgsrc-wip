$NetBSD$

Avoid compiler warning about possibly-uninitialized variable.

Not yet sent upstream.

--- cpp/src/CompatOptionManager.cpp.orig	2019-05-03 14:49:45.000000000 +0000
+++ cpp/src/CompatOptionManager.cpp
@@ -255,6 +255,9 @@ void CompatOptionManager::WriteXML
 				snprintf(str, sizeof(str), "%d", m_CompatVals[it->second].valInt);
 				text = new TiXmlText(str);
 				break;
+			default:
+				text = new TiXmlText("UNMATCHED");
+				break;
 		}
 		valElement->LinkEndChild(text);
 		compatElement->LinkEndChild( valElement );
