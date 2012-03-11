# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/11 05:49:07 phonohawk Exp $

BUILDLINK_TREE+=	hs-concrete-typerep

.if !defined(HS_CONCRETE_TYPEREP_BUILDLINK3_MK)
HS_CONCRETE_TYPEREP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-concrete-typerep+=	hs-concrete-typerep>=0.1.0
BUILDLINK_PKGSRCDIR.hs-concrete-typerep?=	../../wip/hs-concrete-typerep

.include "../../wip/hs-hashable/buildlink3.mk"
.endif	# HS_CONCRETE_TYPEREP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-concrete-typerep
