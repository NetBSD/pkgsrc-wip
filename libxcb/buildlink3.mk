# $NetBSD: buildlink3.mk,v 1.7 2009/03/23 11:51:01 mstapelberg Exp $

BUILDLINK_TREE+=	libxcb

.if !defined(LIBXCB_BUILDLINK3_MK)
LIBXCB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxcb+=	libxcb>=1.1.93
BUILDLINK_PKGSRCDIR.libxcb?=	../../wip/libxcb

.include "../../wip/xcb-proto/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.endif # LIBXCB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxcb
