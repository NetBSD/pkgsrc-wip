# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	haskell-src

.if !defined(HASKELL_SRC_BUILDLINK3_MK)
HASKELL_SRC_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.haskell-src?=	build
BUILDLINK_API_DEPENDS.haskell-src+=	haskell-src>=1.0.1.3
BUILDLINK_PKGSRCDIR.haskell-src?=	../../wip/haskell-src
.endif # HASKELL_SRC_BUILDLINK3_MK

BUILDLINK_TREE+=	-haskell-src
