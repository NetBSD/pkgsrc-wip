# $NetBSD: buildlink3.mk,v 1.5 2009/05/20 00:58:41 thomasklausner Exp $

BUILDLINK_TREE+=	hs-x11

.if !defined(HS_X11_BUILDLINK3_MK)
HS_X11_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-x11?=	build
BUILDLINK_API_DEPENDS.hs-x11+=	hs-x11>=1.4.1
BUILDLINK_ABI_DEPENDS.hs-x11?=	hs-x11>=1.4.1nb1
BUILDLINK_PKGSRCDIR.hs-x11?=	../../wip/hs-x11

.include "../../lang/ghc/buildlink3.mk"
.endif # HS_X11_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-x11
