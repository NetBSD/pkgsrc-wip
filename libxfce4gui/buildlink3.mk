# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:43:49 jsonn Exp $

BUILDLINK_TREE+=	libxfce4gui

.if !defined(LIBXFCE4GUI_BUILDLINK3_MK)
LIBXFCE4GUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4gui+=	libxfce4gui>=4.5.91
BUILDLINK_PKGSRCDIR.libxfce4gui?=	../../wip/libxfce4gui

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # LIBXFCE4GUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4gui
