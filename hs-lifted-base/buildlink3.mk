# $NetBSD: buildlink3.mk,v 1.1 2013/08/17 08:00:20 szptvlfn Exp $

BUILDLINK_TREE+=	hs-lifted-base

.if !defined(HS_LIFTED_BASE_BUILDLINK3_MK)
HS_LIFTED_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lifted-base+=	hs-lifted-base>=0.2.1.0
BUILDLINK_PKGSRCDIR.hs-lifted-base?=	../../wip/hs-lifted-base

.endif	# HS_LIFTED_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lifted-base
