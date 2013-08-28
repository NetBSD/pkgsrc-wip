# $NetBSD: buildlink3.mk,v 1.1 2013/08/28 13:00:52 fhajny Exp $

BUILDLINK_TREE+=	libeio

.if !defined(LIBEIO_BUILDLINK3_MK)
LIBEIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libeio+=libeio>=4
BUILDLINK_ABI_DEPENDS.libeio+=libev>=4
BUILDLINK_PKGSRCDIR.libeio?=	../../wip/libeio

BUILDLINK_LIBDIRS.libeio+=	lib/eio
BUILDLINK_RPATHDIRS.libeio+=	lib/eio
BUILDLINK_INCDIRS.libeio+=	include/eio

.endif # LIBEIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libeio
