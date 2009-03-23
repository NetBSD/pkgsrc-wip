# $NetBSD: buildlink3.mk,v 1.7 2009/03/23 13:00:00 mstapelberg Exp $

BUILDLINK_TREE+=	xcb-proto

.if !defined(XCB_PROTO_BUILDLINK3_MK)
XCB_PROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-proto?=	xcb-proto>=1.4
BUILDLINK_PKGSRCDIR.xcb-proto?=	../../wip/xcb-proto
BUILDLINK_DEPMETHOD.xcb-proto?=	build
.endif # XCB_PROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-proto
