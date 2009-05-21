# $NetBSD: buildlink3.mk,v 1.6 2009/05/21 04:49:21 phonohawk Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=6.10.1
BUILDLINK_PKGSRCDIR.ghc?=	../../wip/ghc

.include "../../devel/gmp/buildlink3.mk"
.include "../../wip/editline/buildlink3.mk"
.endif	# GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc
