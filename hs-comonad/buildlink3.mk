# $NetBSD: buildlink3.mk,v 1.4 2013/10/14 10:37:34 szptvlfn Exp $

BUILDLINK_TREE+=	hs-comonad

.if !defined(HS_COMONAD_BUILDLINK3_MK)
HS_COMONAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-comonad+=	hs-comonad>=4.0
BUILDLINK_PKGSRCDIR.hs-comonad?=	../../wip/hs-comonad

.include "../../wip/hs-contravariant/buildlink3.mk"
.include "../../wip/hs-distributive/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-semigroups/buildlink3.mk"
.include "../../wip/hs-tagged/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_COMONAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-comonad
