# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:43:53 jsonn Exp $

BUILDLINK_TREE+=	xfce4-gtk2-engine

.if !defined(XFCE4_GTK2_ENGINE_BUILDLINK3_MK)
XFCE4_GTK2_ENGINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-gtk2-engine+=	xfce4-gtk2-engine>=2.4.1
BUILDLINK_PKGSRCDIR.xfce4-gtk2-engine?=	../../wip/xfce4-gtk2-engine

.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_GTK2_ENGINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-gtk2-engine
