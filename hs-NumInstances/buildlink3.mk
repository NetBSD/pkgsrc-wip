# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:01 szptvlfn Exp $

BUILDLINK_TREE+=	hs-NumInstances

.if !defined(HS_NUMINSTANCES_BUILDLINK3_MK)
HS_NUMINSTANCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-NumInstances+=	hs-NumInstances>=1.3
BUILDLINK_ABI_DEPENDS.hs-NumInstances+=	hs-NumInstances>=1.3
BUILDLINK_PKGSRCDIR.hs-NumInstances?=	../../wip/hs-NumInstances
.endif	# HS_NUMINSTANCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-NumInstances
