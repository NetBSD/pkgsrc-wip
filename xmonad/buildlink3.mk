# $NetBSD: buildlink3.mk,v 1.7 2014/02/21 10:39:03 szptvlfn Exp $

BUILDLINK_TREE+=	xmonad

.if !defined(XMONAD_BUILDLINK3_MK)
XMONAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmonad+=	xmonad>=0.11
BUILDLINK_PKGSRCDIR.xmonad?=	../../wip/xmonad

.include "../../x11/libX11/buildlink3.mk"
.include "../../wip/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../wip/hs-x11/buildlink3.mk"
.endif	# XMONAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmonad
