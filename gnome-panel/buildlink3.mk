# $NetBSD: buildlink3.mk,v 1.71 2015/04/25 14:25:04 tnn Exp $

BUILDLINK_TREE+=	gnome-panel

.if !defined(GNOME_PANEL_BUILDLINK3_MK)
GNOME_PANEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-panel+=	gnome-panel>=3.16.1
BUILDLINK_PKGSRCDIR.gnome-panel?=	../../wip/gnome-panel

pkgbase:= gnome-panel
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gnome-panel:Mevolution)
.include "../../wip/evolution-data-server/buildlink3.mk"
.endif

#.include "../../net/libgdata/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
#.include "../../devel/libgnome/buildlink3.mk"
#.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # GNOME_PANEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-panel
