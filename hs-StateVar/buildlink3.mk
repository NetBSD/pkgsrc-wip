# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/09/22 13:53:08 phonohawk Exp $

BUILDLINK_TREE+=	hs-StateVar

.if !defined(HS_STATEVAR_BUILDLINK3_MK)
HS_STATEVAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-StateVar+=	hs-StateVar>=1.0.0.0
BUILDLINK_PKGSRCDIR.hs-StateVar?=	../../wip/hs-StateVar
.endif	# HS_STATEVAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-StateVar
