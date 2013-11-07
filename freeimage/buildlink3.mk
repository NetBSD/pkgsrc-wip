# $NetBSD: buildlink3.mk,v 1.1 2013/11/07 18:42:18 nros Exp $

BUILDLINK_TREE+=	freeimage

.if !defined(FREEIMAGE_BUILDLINK3_MK)
FREEIMAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freeimage+=	freeimage>=3.15.4
BUILDLINK_PKGSRCDIR.freeimage?=	../../wip/freeimage
.endif	# FREEIMAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-freeimage
