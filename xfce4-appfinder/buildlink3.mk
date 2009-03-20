# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:43:53 jsonn Exp $

BUILDLINK_TREE+=	xfce4-appfinder

.if !defined(XFCE4_APPFINDER_BUILDLINK3_MK)
XFCE4_APPFINDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-appfinder+=	xfce4-appfinder>=4.4.1
BUILDLINK_PKGSRCDIR.xfce4-appfinder?=	../../wip/xfce4-appfinder

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/libxfce4gui/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_APPFINDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-appfinder
