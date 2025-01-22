$NetBSD$

Removed INLINE to fix unresolved symbols.

--- src/ts/scheme.c.orig	2014-06-21 21:24:07.000000000 +0000
+++ src/ts/scheme.c
@@ -202,8 +202,8 @@ INTERFACE double rvalue(pointer p)    { 
 INTERFACE  long charvalue(pointer p)  { return ivalue_unchecked(p); }
 
 INTERFACE INLINE int is_port(pointer p)     { return (type(p)==T_PORT); }
-INTERFACE INLINE int is_inport(pointer p)  { return is_port(p) && p->_object._port->kind & port_input; }
-INTERFACE INLINE int is_outport(pointer p) { return is_port(p) && p->_object._port->kind & port_output; }
+INTERFACE int is_inport(pointer p)  { return is_port(p) && p->_object._port->kind & port_input; }
+INTERFACE int is_outport(pointer p) { return is_port(p) && p->_object._port->kind & port_output; }
 
 INTERFACE INLINE int is_pair(pointer p)     { return (type(p)==T_PAIR); }
 #define car(p)           ((p)->_object._cons._car)
@@ -228,7 +228,7 @@ INTERFACE INLINE char *syntaxname(pointe
 static const char *procname(pointer x);
 
 INTERFACE INLINE int is_closure(pointer p)  { return (type(p)==T_CLOSURE); }
-INTERFACE INLINE int is_macro(pointer p)    { return (type(p)==T_MACRO); }
+INTERFACE int is_macro(pointer p)    { return (type(p)==T_MACRO); }
 INTERFACE INLINE pointer closure_code(pointer p)   { return car(p); }
 INTERFACE INLINE pointer closure_env(pointer p)    { return cdr(p); }
 
