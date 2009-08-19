# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/08/19 18:09:29 udontknow Exp $

BUILDLINK_TREE+=	libzdb

.if !defined(LIBZDB_BUILDLINK3_MK)
LIBZDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzdb+=	libzdb>=2.6
BUILDLINK_PKGSRCDIR.libzdb?=	../../wip/libzdb
.endif	# LIBZDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzdb
