$NetBSD$

Conditionally use RFC3678 socket options.

--- dlls/ntdll/unix/socket.c.orig	2022-01-07 21:03:02.000000000 +0000
+++ dlls/ntdll/unix/socket.c
@@ -1693,11 +1693,15 @@ NTSTATUS sock_ioctl( HANDLE handle, HAND
         case IOCTL_AFD_WINE_SET_IP_ADD_MEMBERSHIP:
             return do_setsockopt( handle, io, IPPROTO_IP, IP_ADD_MEMBERSHIP, in_buffer, in_size );
 
+#ifdef IP_ADD_SOURCE_MEMBERSHIP
         case IOCTL_AFD_WINE_SET_IP_ADD_SOURCE_MEMBERSHIP:
             return do_setsockopt( handle, io, IPPROTO_IP, IP_ADD_SOURCE_MEMBERSHIP, in_buffer, in_size );
+#endif
 
+#ifdef IP_BLOCK_SOURCE
         case IOCTL_AFD_WINE_SET_IP_BLOCK_SOURCE:
             return do_setsockopt( handle, io, IPPROTO_IP, IP_BLOCK_SOURCE, in_buffer, in_size );
+#endif
 
         case IOCTL_AFD_WINE_GET_IP_DONTFRAGMENT:
         {
@@ -1761,8 +1765,10 @@ NTSTATUS sock_ioctl( HANDLE handle, HAND
         case IOCTL_AFD_WINE_SET_IP_DROP_MEMBERSHIP:
             return do_setsockopt( handle, io, IPPROTO_IP, IP_DROP_MEMBERSHIP, in_buffer, in_size );
 
+#ifdef IP_DROP_SOURCE_MEMBERSHIP
         case IOCTL_AFD_WINE_SET_IP_DROP_SOURCE_MEMBERSHIP:
             return do_setsockopt( handle, io, IPPROTO_IP, IP_DROP_SOURCE_MEMBERSHIP, in_buffer, in_size );
+#endif
 
 #ifdef IP_HDRINCL
         case IOCTL_AFD_WINE_GET_IP_HDRINCL:
@@ -1896,8 +1902,10 @@ NTSTATUS sock_ioctl( HANDLE handle, HAND
         case IOCTL_AFD_WINE_SET_IP_TTL:
             return do_setsockopt( handle, io, IPPROTO_IP, IP_TTL, in_buffer, in_size );
 
+#ifdef IP_UNBLOCK_SOURCE
         case IOCTL_AFD_WINE_SET_IP_UNBLOCK_SOURCE:
             return do_setsockopt( handle, io, IPPROTO_IP, IP_UNBLOCK_SOURCE, in_buffer, in_size );
+#endif
 
 #ifdef IP_UNICAST_IF
         case IOCTL_AFD_WINE_GET_IP_UNICAST_IF:
