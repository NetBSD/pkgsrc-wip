# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:57 jsonn Exp $

BUILDLINK_TREE+=	xmonad

.if !defined(XMONAD_BUILDLINK3_MK)
XMONAD_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.xmonad?=	build
BUILDLINK_API_DEPENDS.xmonad+=	xmonad>=0.7
BUILDLINK_PKGSRCDIR.xmonad?=	../../wip/xmonad

.include "../../lang/ghc/buildlink3.mk"
.endif # XMONAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmonad
