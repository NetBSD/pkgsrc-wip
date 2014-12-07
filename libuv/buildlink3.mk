# $NetBSD: buildlink3.mk,v 1.1 2014/12/07 21:55:50 jonthn Exp $

BUILDLINK_TREE+=	libuv

.if !defined(LIBUV_BUILDLINK3_MK)
LIBUV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libuv+=	libuv>=1.0.0
BUILDLINK_PKGSRCDIR.libuv?=	../../wip/libuv
.endif	# LIBUV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libuv
