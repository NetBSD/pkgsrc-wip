$NetBSD$

--- runtime/druntime/src/core/sys/posix/netdb.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/netdb.d
@@ -387,6 +387,74 @@ else version( FreeBSD )
     enum EAI_SYSTEM         = 11;
     enum EAI_OVERFLOW       = 14;
 }
+else version( NetBSD )
+{
+    struct hostent
+    {
+        char*   h_name;
+        char**  h_aliases;
+        int     h_addrtype;
+        int     h_length;
+        char**  h_addr_list;
+        extern (D) char* h_addr() @property { return h_addr_list[0]; } // non-standard
+    }
+    struct	netent
+    {
+ 	char*		n_name;	/*%< official name of net */
+ 	char**		n_aliases;	/*%< alias list */
+ 	int		n_addrtype;	/*%< net address type */
+      
+      version( SPARC64 )
+          int		__n_pad0;	/* ABI compatibility */
+      version( SH64 )
+      version( BigEndian)
+          int		__n_pad0;	/* ABI compatibility */
+
+        uint32_t	n_net;		/*%< network # */
+
+      version( Alpha )
+ 	  int		__n_pad0;	/* ABI compatibility */
+      version( X86_64 )
+ 	  int		__n_pad0;	/* ABI compatibility */
+      version( SH64 )
+      version( LittleEndian )
+ 	  int		__n_pad0;	/* ABI compatibility */
+    }
+ 
+    struct	servent {
+ 	char*	s_name;	/*%< official service name */
+ 	char**	s_aliases;	/*%< alias list */
+ 	int	s_port;		/*%< port # */
+ 	char*	s_proto;	/*%< protocol to use */
+    }
+ 
+    struct	protoent {
+ 	char*	p_name;	/*%< official protocol name */
+        char**	p_aliases;	/*%< alias list */
+ 	int	p_proto;	/*%< protocol # */
+    }
+
+    struct addrinfo {
+ 	int		ai_flags;	/*%< AI_PASSIVE, AI_CANONNAME */
+ 	int		ai_family;	/*%< PF_xxx */
+ 	int		ai_socktype;	/*%< SOCK_xxx */
+ 	int		ai_protocol;	/*%< 0 or IPPROTO_xxx for IPv4 and IPv6 */
+
+      version( SPARC64 )
+     	  int		__ai_pad0;	/* ABI compatibility */
+
+      socklen_t         ai_addrlen;	/*%< length of ai_addr */
+
+      version( Alpha )
+      	  int		__ai_pad0;	/* ABI compatibility */
+      version( X86_64 )
+  	  int		__ai_pad0;	/* ABI compatibility */
+
+ 	char*		ai_canonname;	/*%< canonical name for hostname */
+        sockaddr*       ai_addr; 	/*%< binary address */
+        addrinfo*       ai_next; 	/*%< next structure in linked list */
+    }
+}
 else version (Solaris)
 {
     struct hostent
