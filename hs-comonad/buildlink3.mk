# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/02/01 16:03:07 phonohawk Exp $

BUILDLINK_TREE+=	hs-comonad

.if !defined(HS_COMONAD_BUILDLINK3_MK)
HS_COMONAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-comonad+=	hs-comonad>=1.1.1
BUILDLINK_PKGSRCDIR.hs-comonad?=	../../wip/hs-comonad

.include "../../wip/hs-semigroups/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_COMONAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-comonad
