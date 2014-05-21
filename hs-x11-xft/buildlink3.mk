# $NetBSD: buildlink3.mk,v 1.5 2014/05/21 21:04:46 szptvlfn Exp $

BUILDLINK_TREE+=	hs-x11-xft

.if !defined(HS_X11_XFT_BUILDLINK3_MK)
HS_X11_XFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-x11-xft+=	hs-x11-xft>=0.3.1
BUILDLINK_PKGSRCDIR.hs-x11-xft?=	../../wip/hs-x11-xft

.include "../../x11/libXft/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.endif	# HS_X11_XFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-x11-xft
