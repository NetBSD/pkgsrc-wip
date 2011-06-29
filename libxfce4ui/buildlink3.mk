# $NetBSD: buildlink3.mk,v 1.2 2011/06/29 14:20:28 reinoudz70 Exp $

BUILDLINK_TREE+=	libxfce4ui

.if !defined(LIBXFCE4UI_BUILDLINK3_MK)
LIBXFCE4UI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4ui+=	libxfce4ui>=4.8.0
BUILDLINK_PKGSRCDIR.libxfce4ui?=	../../wip/libxfce4ui

.include "../../wip/xfconf/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.endif # LIBXFCE4UI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4ui
