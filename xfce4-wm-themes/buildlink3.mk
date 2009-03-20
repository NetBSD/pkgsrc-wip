# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:43:54 jsonn Exp $

BUILDLINK_TREE+=	xfce4-wm-themes

.if !defined(XFCE4_WM_THEMES_BUILDLINK3_MK)
XFCE4_WM_THEMES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-wm-themes+=	xfce4-wm-themes>=4.4.1
BUILDLINK_PKGSRCDIR.xfce4-wm-themes?=	../../wip/xfce4-wm-themes

.include "../../wip/xfce4-wm/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_WM_THEMES_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-wm-themes
