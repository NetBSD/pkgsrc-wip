# $NetBSD: buildlink3.mk,v 1.13 2011/07/02 20:11:49 reinoudz70 Exp $

BUILDLINK_TREE+=	xfce4-panel

.if !defined(XFCE4_PANEL_BUILDLINK3_MK)
XFCE4_PANEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-panel+=	xfce4-panel>=4.8.5
BUILDLINK_ABI_DEPENDS.xfce4-panel?=	xfce4-panel>=4.8.5
BUILDLINK_PKGSRCDIR.xfce4-panel?=	../../wip/xfce4-panel

.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/libxfce4ui/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.endif # XFCE4_PANEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-panel
