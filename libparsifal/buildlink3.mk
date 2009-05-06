# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:08:37 cheusov Exp $

BUILDLINK_TREE+=	libparsifal

.if !defined(LIBPARSIFAL_BUILDLINK3_MK)
LIBPARSIFAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libparsifal+=	libparsifal>=0.9.0
BUILDLINK_PKGSRCDIR.libparsifal?=	../../wip/libparsifal
.endif # LIBPARSIFAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libparsifal
