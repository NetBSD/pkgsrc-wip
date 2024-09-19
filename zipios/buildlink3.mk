# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/05/12 12:20:42 ryo-on Exp $

BUILDLINK_TREE+=	zipios

.if !defined(ZIPIOS_BUILDLINK3_MK)
ZIPIOS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zipios+=	zipios>=0.1.5.9.2007.04.28
BUILDLINK_PKGSRCDIR.zipios?=	../../wip/zipios
.endif	# ZIPIOS_BUILDLINK3_MK

BUILDLINK_TREE+=	-zipios
