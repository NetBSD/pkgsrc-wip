# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:48 jsonn Exp $

BUILDLINK_TREE+=	libpciaccess

.if !defined(LIBPCIACCESS_BUILDLINK3_MK)
LIBPCIACCESS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpciaccess+=	libpciaccess>=0.10.3
BUILDLINK_PKGSRCDIR.libpciaccess?=	../../wip/libpciaccess
.endif # LIBPCIACCESS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpciaccess
