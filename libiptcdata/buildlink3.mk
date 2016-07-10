# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/04/11 12:50:04 jihbed Exp $

BUILDLINK_TREE+=	libiptcdata

.if !defined(LIBIPTCDATA_BUILDLINK3_MK)
LIBIPTCDATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libiptcdata+=	libiptcdata>=1.0.3
BUILDLINK_PKGSRCDIR.libiptcdata?=	../../wip/libiptcdata


.endif	# LIBIPTCDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libiptcdata
