# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:49 jsonn Exp $

BUILDLINK_TREE+=	libxfce4menu

.if !defined(LIBXFCE4MENU_BUILDLINK3_MK)
LIBXFCE4MENU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4menu+=	libxfce4menu>=4.5.91
BUILDLINK_PKGSRCDIR.libxfce4menu?=	../../wip/libxfce4menu

.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # LIBXFCE4MENU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4menu
