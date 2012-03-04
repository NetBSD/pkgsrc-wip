# $NetBSD: buildlink3.mk,v 1.5 2012/03/04 06:53:25 phonohawk Exp $

BUILDLINK_TREE+=	hs-uniplate

.if !defined(HS_UNIPLATE_BUILDLINK3_MK)
HS_UNIPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-uniplate+=	hs-uniplate>=1.6.6
BUILDLINK_PKGSRCDIR.hs-uniplate?=	../../wip/hs-uniplate

.include "../../wip/hs-hashable/buildlink3.mk"
.include "../../wip/hs-syb/buildlink3.mk"
.include "../../wip/hs-unordered-containers/buildlink3.mk"
.endif	# HS_UNIPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-uniplate
