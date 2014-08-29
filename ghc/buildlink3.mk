# $NetBSD: buildlink3.mk,v 1.14 2014/08/29 14:09:59 szptvlfn Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=7.6.2
BUILDLINK_ABI_DEPENDS.ghc+=	ghc>=7.6.2
BUILDLINK_PKGSRCDIR.ghc?=	../../wip/ghc

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
