$NetBSD$

* Move struct xmlnode_t from xmlnode.cc to xmlnode.hh to appease g++.

--- jabberd/lib/xmlnode.cc.orig	2019-09-29 18:37:09.000000000 +0000
+++ jabberd/lib/xmlnode.cc
@@ -44,34 +44,6 @@
 #include <sstream>
 #include <stdexcept>
 
-//----[ internal types ]-------------------------------------------------------
-
-struct xmlnode_t {
-    char *name;          /**< local name of the xmlnode */
-    char *prefix;        /**< namespace prefix for this xmlnode */
-    char *ns_iri;        /**< namespace IRI for this xmlnode */
-    unsigned short type; /**< type of the xmlnode, one of ::NTYPE_TAG,
-                            ::NTYPE_ATTRIB, ::NTYPE_CDATA, or ::NTYPE_UNDEF */
-    char *data;  /**< data of the xmlnode, for attributes this is the value, for
-                    text nodes this is the text */
-    int data_sz; /**< length of the data in the xmlnode */
-                 /*     int                 complete; */
-    pool p; /**< memory pool used by this xmlnode (the same as for all other
-               xmlnode in a tree) */
-    struct xmlnode_t
-        *parent; /**< parent node for this node, or NULL for the root element */
-    struct xmlnode_t *firstchild; /**< first child element of this node, or NULL
-                                     for no child elements */
-    struct xmlnode_t *lastchild;  /**< last child element of this node, or NULL
-                                     for no child elements */
-    struct xmlnode_t *prev;       /**< previous sibling */
-    struct xmlnode_t *next;       /**< next sibling */
-    struct xmlnode_t *firstattrib; /**< first attribute node of this node */
-    struct xmlnode_t *lastattrib;  /**< last attribute node of this node */
-};
-
-//-----------------------------------------------------------------------------
-
 #ifdef POOL_DEBUG
 std::map<pool, std::list<xmlnode>> existing_xmlnodes;
 #endif
