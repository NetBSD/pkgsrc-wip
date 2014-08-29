# $NetBSD: buildlink3.mk,v 1.21 2014/08/29 14:09:59 szptvlfn Exp $

BUILDLINK_TREE+=	hlint

.if !defined(HLINT_BUILDLINK3_MK)
HLINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hlint+=	hlint>=1.9.3
BUILDLINK_ABI_DEPENDS.hlint+=	hlint>=1.9.3
BUILDLINK_PKGSRCDIR.hlint?=	../../wip/hlint

.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-cpphs/buildlink3.mk"
.include "../../wip/hs-haskell-src-exts/buildlink3.mk"
.include "../../textproc/hs-hscolour/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.endif	# HLINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hlint
