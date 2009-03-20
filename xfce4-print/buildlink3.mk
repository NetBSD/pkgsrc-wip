# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:43:54 jsonn Exp $

BUILDLINK_TREE+=	xfce4-print

.if !defined(XFCE4_PRINT_BUILDLINK3_MK)
XFCE4_PRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-print+=	xfce4-print>=4.4.1
BUILDLINK_ABI_DEPENDS.xfce4-print?=	xfce4-print>=4.4.1
BUILDLINK_PKGSRCDIR.xfce4-print?=	../../wip/xfce4-print

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/a2ps/buildlink3.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

pkgbase := xfce4-print
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.xfce4-print:Mcups)
.  include "../../print/cups/buildlink3.mk"
.endif
.endif # XFCE4_PRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-print
