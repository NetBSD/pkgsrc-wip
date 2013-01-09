# $NetBSD: buildlink3.mk,v 1.2 2013/01/09 23:17:36 szptvlfn Exp $

BUILDLINK_TREE+=	hs-x11-xft

.if !defined(HS_X11_XFT_BUILDLINK3_MK)
HS_X11_XFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-x11-xft+=	hs-x11-xft>=0.3
BUILDLINK_PKGSRCDIR.hs-x11-xft?=	../../wip/hs-x11-xft

.endif # HS_X11_XFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-x11-xft
