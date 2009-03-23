# $NetBSD: buildlink3.mk,v 1.8 2009/03/23 12:59:13 mstapelberg Exp $

BUILDLINK_TREE+=	libxcb

.if !defined(LIBXCB_BUILDLINK3_MK)
LIBXCB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxcb?=	libxcb>=1.1.93
BUILDLINK_PKGSRCDIR.libxcb?=	../../wip/libxcb

.include "../../wip/xcb-proto/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.endif # LIBXCB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxcb
