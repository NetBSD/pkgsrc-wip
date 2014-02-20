# $NetBSD: buildlink3.mk,v 1.2 2014/02/20 05:44:55 makoto Exp $

BUILDLINK_TREE+=	libeio

.if !defined(LIBEIO_BUILDLINK3_MK)
LIBEIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libeio+=	libeio>=4.0
BUILDLINK_ABI_DEPENDS.libeio+=	libeio>=4.0
BUILDLINK_PKGSRCDIR.libeio?=	../../wip/libeio-cvs

BUILDLINK_LIBDIRS.libeio+=	lib/eio
BUILDLINK_RPATHDIRS.libeio+=	lib/eio
BUILDLINK_INCDIRS.libeio+=	include/eio

.endif # LIBEIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libeio
