# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:09 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cabal-query

.if !defined(HS_CABAL_QUERY_BUILDLINK3_MK)
HS_CABAL_QUERY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cabal-query+=	hs-cabal-query>=0.1
BUILDLINK_ABI_DEPENDS.hs-cabal-query+=	hs-cabal-query>=0.1
BUILDLINK_PKGSRCDIR.hs-cabal-query?=	../../wip/hs-cabal-query

.include "../../lang/ghc7/buildlink3.mk"
.include "../../wip/hs-MissingH/buildlink3.mk"
.include "../../wip/hs-derive/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../archivers/hs-tar/buildlink3.mk"
.include "../../devel/hs-uniplate/buildlink3.mk"
.endif	# HS_CABAL_QUERY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cabal-query
