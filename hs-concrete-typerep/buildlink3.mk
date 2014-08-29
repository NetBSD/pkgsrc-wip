# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:10 szptvlfn Exp $

BUILDLINK_TREE+=	hs-concrete-typerep

.if !defined(HS_CONCRETE_TYPEREP_BUILDLINK3_MK)
HS_CONCRETE_TYPEREP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-concrete-typerep+=	hs-concrete-typerep>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-concrete-typerep+=	hs-concrete-typerep>=0.1.0.2
BUILDLINK_PKGSRCDIR.hs-concrete-typerep?=	../../wip/hs-concrete-typerep

.include "../../devel/hs-hashable/buildlink3.mk"
.endif	# HS_CONCRETE_TYPEREP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-concrete-typerep
