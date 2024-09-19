# $NetBSD: buildlink3.mk,v 1.14 2015/01/28 18:49:31 szptvlfn Exp $

BUILDLINK_TREE+=	hs-derive

.if !defined(HS_DERIVE_BUILDLINK3_MK)
HS_DERIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-derive+=	hs-derive>=2.5.16
BUILDLINK_ABI_DEPENDS.hs-derive+=	hs-derive>=2.5.16
BUILDLINK_PKGSRCDIR.hs-derive?=		../../wip/hs-derive

.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.endif	# HS_DERIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-derive
