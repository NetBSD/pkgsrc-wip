$NetBSD$

Trying to work around further Boost breakage. To be pushed upstream?
Actually, requiring C++11 and using std::bind could be another path.
Or using lambdas, which everyone tells you are much easier. C++ is great!
Muahahahahahahahahahahahahha!

--- src/header.cpp.orig	2016-08-22 13:06:34.000000000 +0000
+++ src/header.cpp
@@ -610,7 +610,7 @@ void Header::DeleteVLRs(std::string cons
 
     m_vlrs.erase( std::remove_if( m_vlrs.begin(),
                                   m_vlrs.end(),
-                                  boost::bind( &SameVLRs, name, id, _1 ) ),
+                                  boost::bind( &SameVLRs, name, id, boost::placeholders::_1 ) ),
                   m_vlrs.end());
 
     m_recordsCount = static_cast<uint32_t>(m_vlrs.size());
