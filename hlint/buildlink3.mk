# $NetBSD: buildlink3.mk,v 1.18 2014/07/26 21:52:51 szptvlfn Exp $

BUILDLINK_TREE+=	hlint

.if !defined(HLINT_BUILDLINK3_MK)
HLINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hlint+=	hlint>=1.8.61
BUILDLINK_PKGSRCDIR.hlint?=	../../wip/hlint

.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-cpphs/buildlink3.mk"
.include "../../wip/hs-haskell-src-exts/buildlink3.mk"
.include "../../wip/hs-hscolour/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.endif	# HLINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hlint
