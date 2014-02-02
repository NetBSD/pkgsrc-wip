# $NetBSD: buildlink3.mk,v 1.1 2014/02/02 14:01:40 makoto Exp $

BUILDLINK_TREE+=	libeio

.if !defined(LIBEIO_BUILDLINK3_MK)
LIBEIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libeio+=	libeio
BUILDLINK_ABI_DEPENDS.libeio+=	libeio
BUILDLINK_PKGSRCDIR.libeio?=	../../wip/libeio-cvs

BUILDLINK_LIBDIRS.libeio+=	lib/eio
BUILDLINK_RPATHDIRS.libeio+=	lib/eio
BUILDLINK_INCDIRS.libeio+=	include/eio

.endif # LIBEIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libeio
