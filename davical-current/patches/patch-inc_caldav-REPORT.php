$NetBSD: patch-inc_caldav-REPORT.php,v 1.1 2013/07/13 11:47:21 hfath Exp $

According to
  <http://sourceforge.net/mailarchive/message.php?msg_id=30486311>

--- inc/caldav-REPORT.php.orig	2013-02-27 13:08:43.000000000 +0000
+++ inc/caldav-REPORT.php
@@ -154,11 +154,11 @@ function component_to_xml( $properties, 
         $prop->NewElement($base_tag, ISODateToHTTPDate($item->modified) );
         break;
       case 'urn:ietf:params:xml:ns:caldav:calendar-data':
-        if ( $type == 'calendar' ) $reply->CalDAVElement($prop, $base_tag, $caldav_data );
+        if ( $type == 'calendar' ) $reply->CalDAVElement($prop, $base_tag, '<![CDATA['.$caldav_data.']]>' );
         else $unsupported[] = $base_tag;
         break;
       case 'urn:ietf:params:xml:ns:carddav:address-data':
-        if ( $type == 'vcard' ) $reply->CardDAVElement($prop, $base_tag, $caldav_data );
+        if ( $type == 'vcard' ) $reply->CardDAVElement($prop, $base_tag, '<![CDATA['.$caldav_data.']]>' );
         else $unsupported[] = $base_tag;
         break;
       case 'DAV::getcontenttype':
