# $NetBSD: buildlink3.mk,v 1.5 2007/01/23 08:00:40 marttikuparinen Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_TERMINAL_BUILDLINK3_MK:=	${XFCE4_TERMINAL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-terminal
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-terminal}
BUILDLINK_PACKAGES+=	xfce4-terminal
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-terminal

.if ${XFCE4_TERMINAL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-terminal+=	xfce4-terminal>=0.2.6
BUILDLINK_PKGSRCDIR.xfce4-terminal?=	../../wip/xfce4-terminal
.endif	# XFCE4_TERMINAL_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-exo/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
