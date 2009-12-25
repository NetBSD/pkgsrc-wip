# $NetBSD: buildlink3.mk,v 1.9 2009/12/25 05:49:51 phonohawk Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=6.12.1
BUILDLINK_PKGSRCDIR.ghc?=	../../wip/ghc

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
