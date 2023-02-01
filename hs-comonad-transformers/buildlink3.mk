# $NetBSD: buildlink3.mk,v 1.6 2014/09/02 21:00:52 szptvlfn Exp $

BUILDLINK_TREE+=	hs-comonad-transformers

.if !defined(HS_COMONAD_TRANSFORMERS_BUILDLINK3_MK)
HS_COMONAD_TRANSFORMERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-comonad-transformers+=	hs-comonad-transformers>=3.1
BUILDLINK_ABI_DEPENDS.hs-comonad-transformers+=	hs-comonad-transformers>=3.1
BUILDLINK_PKGSRCDIR.hs-comonad-transformers?=	../../wip/hs-comonad-transformers

.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-contravariant/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_COMONAD_TRANSFORMERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-comonad-transformers
