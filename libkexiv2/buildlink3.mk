# $NetBSD: buildlink3.mk,v 1.1 2012/01/23 10:11:29 mwdavies Exp $

BUILDLINK_TREE+=	libkexiv2

.if !defined(LIBKEXIV2_BUILDLINK3_MK)
LIBKEXIV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkexiv2+=	libkexiv2>=4.8.0
BUILDLINK_PKGSRCDIR.libkexiv2?=	../../wip/libkexiv2

.endif	# LIBKEXIV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkexiv2
