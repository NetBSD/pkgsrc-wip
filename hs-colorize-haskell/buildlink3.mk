# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/06 15:40:06 phonohawk Exp $

BUILDLINK_TREE+=	hs-colorize-haskell

.if !defined(HS_COLORIZE_HASKELL_BUILDLINK3_MK)
HS_COLORIZE_HASKELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-colorize-haskell+=	hs-colorize-haskell>=1.0
BUILDLINK_PKGSRCDIR.hs-colorize-haskell?=	../../wip/hs-colorize-haskell

.include "../../wip/hs-ansi-terminal/buildlink3.mk"
.include "../../wip/hs-haskell-lexer/buildlink3.mk"
.endif	# HS_COLORIZE_HASKELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-colorize-haskell
