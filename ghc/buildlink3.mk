# $NetBSD: buildlink3.mk,v 1.7 2009/07/02 08:57:03 phonohawk Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=6.10.3
BUILDLINK_PKGSRCDIR.ghc?=	../../wip/ghc

.include "../../devel/gmp/buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
