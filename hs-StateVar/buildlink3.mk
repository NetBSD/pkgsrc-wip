# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:02 szptvlfn Exp $

BUILDLINK_TREE+=	hs-StateVar

.if !defined(HS_STATEVAR_BUILDLINK3_MK)
HS_STATEVAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-StateVar+=	hs-StateVar>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-StateVar+=	hs-StateVar>=1.0.0.0
BUILDLINK_PKGSRCDIR.hs-StateVar?=	../../wip/hs-StateVar
.endif	# HS_STATEVAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-StateVar
