# $NetBSD: buildlink3.mk,v 1.2 2013/08/31 06:56:55 szptvlfn Exp $

BUILDLINK_TREE+=	hs-comonad-transformers

.if !defined(HS_COMONAD_TRANSFORMERS_BUILDLINK3_MK)
HS_COMONAD_TRANSFORMERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-comonad-transformers+=	hs-comonad-transformers>=3.1
BUILDLINK_PKGSRCDIR.hs-comonad-transformers?=	../../wip/hs-comonad-transformers

.include "../../wip/hs-comonad/buildlink3.mk"
.include "../../wip/hs-contravariant/buildlink3.mk"
.include "../../wip/hs-distributive/buildlink3.mk"
.include "../../wip/hs-semigroupoids/buildlink3.mk"
.include "../../wip/hs-semigroups/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_COMONAD_TRANSFORMERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-comonad-transformers
