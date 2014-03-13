# $NetBSD: buildlink3.mk,v 1.4 2014/03/13 12:14:01 szptvlfn Exp $

BUILDLINK_TREE+=	hs-husk-scheme

.if !defined(HS_HUSK_SCHEME_BUILDLINK3_MK)
HS_HUSK_SCHEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-husk-scheme+=	hs-husk-scheme>=3.16.1
BUILDLINK_PKGSRCDIR.hs-husk-scheme?=	../../wip/hs-husk-scheme

.include "../../wip/hs-ghc-paths/buildlink3.mk"
.include "../../wip/hs-haskeline/buildlink3.mk"
.include "../../wip/hs-knob/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.endif	# HS_HUSK_SCHEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-husk-scheme
