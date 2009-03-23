# $NetBSD: buildlink3.mk,v 1.4 2009/03/23 12:55:55 mstapelberg Exp $

BUILDLINK_TREE+=	xcb-util

.if !defined(XCB_UTIL_BUILDLINK3_MK)
XCB_UTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-util?=	xcb-util>=0.3.3
BUILDLINK_PKGSRCDIR.xcb-util?=		../../wip/xcb-util
BUILDLINK_DEPMETHOD.xcb-utl?=		build

.include "../../wip/libxcb/buildlink3.mk"
.endif # XCB_UTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-util
