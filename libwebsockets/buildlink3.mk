# $NetBSD$

BUILDLINK_TREE+=	libwebsockets

.if !defined(LIBWEBSOCKETS_BUILDLINK3_MK)
LIBWEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwebsockets+=	libwebsockets>=1.7.2
BUILDLINK_PKGSRCDIR.libwebsockets?=	../../wip/libwebsocket

.include "../../security/openssl/buildlink3.mk"
.endif	# LIBWEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwebsockets
