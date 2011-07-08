# $NetBSD: buildlink3.mk,v 1.2 2011/07/08 09:07:45 phonohawk Exp $

BUILDLINK_TREE+=	hs-derive

.if !defined(HS_DERIVE_BUILDLINK3_MK)
HS_DERIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-derive+=	hs-derive>=2.5
BUILDLINK_PKGSRCDIR.hs-derive?=	../../wip/hs-derive

.include "../../wip/hs-haskell-src-exts/buildlink3.mk"
.include "../../wip/hs-syb/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../wip/hs-uniplate/buildlink3.mk"
.endif	# HS_DERIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-derive
