# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:48 jsonn Exp $

BUILDLINK_TREE+=	libparsifal

BUILDLINK_API_DEPENDS.libparsifal+=	libparsifal>=0.9.0
BUILDLINK_PKGSRCDIR.libparsifal?=	../../wip/libparsifal
.endif # LIBPARSIFAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libparsifal
