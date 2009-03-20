# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:43:53 jsonn Exp $

BUILDLINK_TREE+=	xfce4-icon-theme

.if !defined(XFCE4_ICON_THEME_BUILDLINK3_MK)
XFCE4_ICON_THEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-icon-theme+=	xfce4-icon-theme>=4.4.1
BUILDLINK_PKGSRCDIR.xfce4-icon-theme?=	../../wip/xfce4-icon-theme

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_ICON_THEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-icon-theme
