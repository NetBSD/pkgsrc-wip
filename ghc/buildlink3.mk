# $NetBSD: buildlink3.mk,v 1.8 2009/09/24 08:12:58 phonohawk Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=6.10.4
BUILDLINK_PKGSRCDIR.ghc?=	../../wip/ghc

.include "../../devel/gmp/buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
