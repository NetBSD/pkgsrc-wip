# $NetBSD: buildlink3.mk,v 1.8 2008/10/15 20:27:18 hoka_adam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXFCE4GUI_BUILDLINK3_MK:=	${LIBXFCE4GUI_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libxfce4gui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxfce4gui}
BUILDLINK_PACKAGES+=	libxfce4gui
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libxfce4gui

.if ${LIBXFCE4GUI_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libxfce4gui+=	libxfce4gui>=4.5.91
BUILDLINK_PKGSRCDIR.libxfce4gui?=	../../wip/libxfce4gui
.endif	# LIBXFCE4GUI_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
