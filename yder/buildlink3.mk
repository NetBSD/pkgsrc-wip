# $NetBSD$

BUILDLINK_TREE+=	yder

.if !defined(YDER_BUILDLINK3_MK)
YDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yder+=	yder>=1.4.17
BUILDLINK_PKGSRCDIR.yder?=	../../wip/yder

.include "../../wip/orcania/buildlink3.mk"
.endif	# YDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-yder
