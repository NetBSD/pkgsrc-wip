# $NetBSD: buildlink3.mk,v 1.2 2014/05/16 20:47:09 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cabal-query

.if !defined(HS_CABAL_QUERY_BUILDLINK3_MK)
HS_CABAL_QUERY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cabal-query+=	hs-cabal-query>=0.1
BUILDLINK_PKGSRCDIR.hs-cabal-query?=	../../wip/hs-cabal-query

.include "../../wip/ghc/buildlink3.mk"
.include "../../wip/hs-MissingH/buildlink3.mk"
.include "../../wip/hs-derive/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../wip/hs-tar/buildlink3.mk"
.include "../../wip/hs-uniplate/buildlink3.mk"
.endif	# HS_CABAL_QUERY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cabal-query
