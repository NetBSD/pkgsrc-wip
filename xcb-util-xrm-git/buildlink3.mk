# $NetBSD$

BUILDLINK_TREE+=	xcb-util-xrm

.if !defined(XCB_UTIL_XRM_BUILDLINK3_MK)
XCB_UTIL_XRM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-util-xrm+=	xcb-util-xrm>=1.0
BUILDLINK_PKGSRCDIR.xcb-util-xrm?=	../../wip/xcb-util-xrm-git

.endif	# XCB_UTIL_XRM_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-util-xrm
