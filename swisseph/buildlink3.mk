# $NetBSD: buildlink3.mk,v 1.1 2013/01/08 03:55:32 othyro Exp $

BUILDLINK_TREE+=	swisseph

.if !defined(SWISSEPH_BUILDLINK3_MK)
SWISSEPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swisseph+=	swisseph>=1.78.00
BUILDLINK_PKGSRCDIR.swisseph?=		../../wip/swisseph
.endif	# SWISSEPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-swisseph
