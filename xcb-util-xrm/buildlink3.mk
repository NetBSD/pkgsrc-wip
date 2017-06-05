# $NetBSD$

BUILDLINK_TREE+=	xcb-util-xrm

.if !defined(XCB_UTIL_XRM_BUILDLINK3_MK)
XCB_UTIL_XRM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-util-xrm+=	xcb-util-xrm>=1.0
BUILDLINK_PKGSRCDIR.xcb-util-xrm?=	../../local/xcb-util-xrm

.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.endif	# XCB_UTIL_XRM_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-util-xrm
