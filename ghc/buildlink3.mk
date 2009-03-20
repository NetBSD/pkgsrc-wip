# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:43:41 jsonn Exp $

BUILDLINK_TREE+=	ghc

.if !defined(GHC_BUILDLINK3_MK)
GHC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghc+=	ghc>=6.10.1
BUILDLINK_ABI_DEPENDS.ghc?=	ghc>=6.10.1
BUILDLINK_PKGSRCDIR.ghc?=	../../wip/ghc

BUILDLINK_DEPMETHOD.ghc?=	build
.endif # GHC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghc

# We include gmp/buildlink3.mk here so that "gmp" is registered as a
# direct dependency for any package that includes this buildlink3.mk
# to get ghc as a build dependency.  This is needed since software
# built by ghc requires routines from the "gmp" shared library.
#
.include "../../devel/gmp/buildlink3.mk"
