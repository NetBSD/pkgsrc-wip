# $NetBSD: buildlink3.mk,v 1.4 2011/11/16 17:37:51 phonohawk Exp $

BUILDLINK_TREE+=	hs-uniplate

.if !defined(HS_UNIPLATE_BUILDLINK3_MK)
HS_UNIPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-uniplate+=	hs-uniplate>=1.6.5
BUILDLINK_PKGSRCDIR.hs-uniplate?=	../../wip/hs-uniplate

.include "../../wip/hs-syb/buildlink3.mk"
.endif	# HS_UNIPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-uniplate
