# $NetBSD: buildlink3.mk,v 1.3 2009/05/20 00:58:43 thomasklausner Exp $

BUILDLINK_TREE+=	xmonad

.if !defined(XMONAD_BUILDLINK3_MK)
XMONAD_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.xmonad?=	build
BUILDLINK_API_DEPENDS.xmonad+=	xmonad>=0.7
BUILDLINK_ABI_DEPENDS.xmonad?=	xmonad>=0.7nb1
BUILDLINK_PKGSRCDIR.xmonad?=	../../wip/xmonad

.include "../../lang/ghc/buildlink3.mk"
.endif # XMONAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmonad
