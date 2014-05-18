# $NetBSD: buildlink3.mk,v 1.8 2014/05/18 21:33:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-husk-scheme

.if !defined(HS_HUSK_SCHEME_BUILDLINK3_MK)
HS_HUSK_SCHEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-husk-scheme+=	hs-husk-scheme>=3.17
BUILDLINK_PKGSRCDIR.hs-husk-scheme?=	../../wip/hs-husk-scheme

.include "../../wip/hs-ghc-paths/buildlink3.mk"
.include "../../wip/hs-haskeline/buildlink3.mk"
.include "../../wip/hs-knob/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.endif	# HS_HUSK_SCHEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-husk-scheme
