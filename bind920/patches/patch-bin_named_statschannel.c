$NetBSD$

Apply patch from https://gitlab.isc.org/isc-projects/bind9/-/issues/5198
to work around core dump observed there.

--- bin/named/statschannel.c.orig	2025-02-11 17:35:30.652314501 +0000
+++ bin/named/statschannel.c
@@ -1606,9 +1606,13 @@ xfrin_xmlrender(dns_zone_t *zone, void *
 		isc_sockaddr_format(addrp, addr_buf, sizeof(addr_buf));
 		TRY0(xmlTextWriterWriteString(writer, ISC_XMLCHAR addr_buf));
 	} else if (is_presoa) {
-		addr = dns_zone_getprimaryaddr(zone);
-		isc_sockaddr_format(&addr, addr_buf, sizeof(addr_buf));
-		TRY0(xmlTextWriterWriteString(writer, ISC_XMLCHAR addr_buf));
+		if (dns_zone_getprimaryaddr(zone, &addr) == ISC_R_SUCCESS) {
+			isc_sockaddr_format(&addr, addr_buf, sizeof(addr_buf));
+			TRY0(xmlTextWriterWriteString(writer,
+						      ISC_XMLCHAR addr_buf));
+		} else {
+			TRY0(xmlTextWriterWriteString(writer, ISC_XMLCHAR "-"));
+		}
 	} else {
 		TRY0(xmlTextWriterWriteString(writer, ISC_XMLCHAR "-"));
 	}
@@ -2659,10 +2663,15 @@ xfrin_jsonrender(dns_zone_t *zone, void 
 		json_object_object_add(xfrinobj, "remoteaddr",
 				       json_object_new_string(addr_buf));
 	} else if (is_presoa) {
-		addr = dns_zone_getprimaryaddr(zone);
-		isc_sockaddr_format(&addr, addr_buf, sizeof(addr_buf));
-		json_object_object_add(xfrinobj, "remoteaddr",
-				       json_object_new_string(addr_buf));
+		if (dns_zone_getprimaryaddr(zone, &addr) == ISC_R_SUCCESS) {
+			isc_sockaddr_format(&addr, addr_buf, sizeof(addr_buf));
+			json_object_object_add(
+				xfrinobj, "remoteaddr",
+				json_object_new_string(addr_buf));
+		} else {
+			json_object_object_add(xfrinobj, "remoteaddr",
+					       json_object_new_string("-"));
+		}
 	} else {
 		json_object_object_add(xfrinobj, "remoteaddr",
 				       json_object_new_string("-"));
