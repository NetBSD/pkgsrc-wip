# $NetBSD: buildlink3.mk,v 1.2 2015/04/14 19:04:39 nros Exp $

BUILDLINK_TREE+=	freeimage

.if !defined(FREEIMAGE_BUILDLINK3_MK)
FREEIMAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freeimage+=	freeimage>=3.15.4
BUILDLINK_ABI_DEPENDS.freeimage+=	freeimage>=3.17.0
BUILDLINK_PKGSRCDIR.freeimage?=	../../wip/freeimage
.endif	# FREEIMAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-freeimage
