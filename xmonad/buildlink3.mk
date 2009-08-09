# $NetBSD: buildlink3.mk,v 1.4 2009/08/09 18:18:43 zul_ Exp $

BUILDLINK_TREE+=	xmonad

.if !defined(XMONAD_BUILDLINK3_MK)
XMONAD_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.xmonad?=	build
BUILDLINK_API_DEPENDS.xmonad+=	xmonad>=0.8.1
BUILDLINK_ABI_DEPENDS.xmonad?=	xmonad>=0.8.1
BUILDLINK_PKGSRCDIR.xmonad?=	../../wip/xmonad

.include "../../lang/ghc/buildlink3.mk"
.endif # XMONAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmonad
