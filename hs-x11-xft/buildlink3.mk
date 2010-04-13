# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/04/13 18:35:27 emil_s Exp $

BUILDLINK_TREE+=	hs-x11-xft

.if !defined(HS_X11_XFT_BUILDLINK3_MK)
HS_X11_XFT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-x11-xft?=	build
BUILDLINK_API_DEPENDS.hs-x11-xft+=	hs-x11-xft>=0.3
BUILDLINK_PKGSRCDIR.hs-x11-xft?=	../../wip/hs-x11-xft

.endif # HS_X11_XFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-x11-xft
