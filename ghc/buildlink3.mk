# $NetBSD: buildlink3.mk,v 1.10 2010/05/10 01:59:14 phonohawk Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=6.12.2
BUILDLINK_PKGSRCDIR.ghc?=	../../wip/ghc

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
