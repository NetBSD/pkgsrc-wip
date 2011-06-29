# $NetBSD: buildlink3.mk,v 1.9 2011/06/29 11:22:04 reinoudz70 Exp $

BUILDLINK_TREE+=	xfce4-exo

.if !defined(XFCE4_EXO_BUILDLINK3_MK)
XFCE4_EXO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-exo+=	xfce4-exo>=0.3.100
BUILDLINK_ABI_DEPENDS.xfce4-exo?=	xfce4-exo>=0.3.101nb6
BUILDLINK_PKGSRCDIR.xfce4-exo?=	../../wip/xfce4-exo

pkgbase := xfce4-exo
.include "../../mk/pkg-build-options.mk"

#.if !empty(PKG_BUILD_OPTIONS.xfce4-exo:Mhal)
#.include "../../sysutils/hal/buildlink3.mk"
#.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.endif # XFCE4_EXO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-exo
