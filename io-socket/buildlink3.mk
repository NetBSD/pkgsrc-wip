# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:43 jsonn Exp $

BUILDLINK_TREE+=	io-socket

.if !defined(IOSOCKET_BUILDLINK3_MK)
IOSOCKET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.io-socket+=	io-socket>=2013.12.04
BUILDLINK_PKGSRCDIR.io-socket?=		../../wip/io-socket

BUILDLINK_LIBDIRS.io-socket+=		lib/io/addons/Socket/_build/dll
BUILDLINK_INCDIRS.io-socket+=		include/io/Socket
.endif # IOSOCKET_BUILDLINK3_MK

BUILDLINK_TREE+=	-io-socket
