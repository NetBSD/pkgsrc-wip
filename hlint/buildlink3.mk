# $NetBSD: buildlink3.mk,v 1.11 2013/11/29 14:01:37 szptvlfn Exp $

BUILDLINK_TREE+=	hlint

.if !defined(HLINT_BUILDLINK3_MK)
HLINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hlint+=	hlint>=1.8.55
BUILDLINK_PKGSRCDIR.hlint?=	../../wip/hlint

.include "../../wip/hs-cpphs/buildlink3.mk"
.include "../../wip/hs-haskell-src-exts/buildlink3.mk"
.include "../../wip/hs-hscolour/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../wip/hs-uniplate/buildlink3.mk"
.endif	# HLINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hlint
