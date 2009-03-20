# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	haskell-src-exts

.if !defined(HASKELL_SRC_EXTS_BUILDLINK3_MK)
HASKELL_SRC_EXTS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.haskell-src-exts?=	build
BUILDLINK_API_DEPENDS.haskell-src-exts+=	haskell-src-exts>=0.4.8
BUILDLINK_PKGSRCDIR.haskell-src-exts?=	../../wip/haskell-src-exts

.include "../../wip/cpphs/buildlink3.mk"
.endif # HASKELL_SRC_EXTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-haskell-src-exts
