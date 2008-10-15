# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/10/15 20:30:10 hoka_adam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXFCE4MENU_BUILDLINK3_MK:=	${LIBXFCE4MENU_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libxfce4menu
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxfce4menu}
BUILDLINK_PACKAGES+=	libxfce4menu
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libxfce4menu

.if ${LIBXFCE4MENU_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libxfce4menu+=	libxfce4menu>=4.5.91
BUILDLINK_PKGSRCDIR.libxfce4menu?=	../../wip/libxfce4menu
.endif	# LIBXFCE4MENU_BUILDLINK3_MK

.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
