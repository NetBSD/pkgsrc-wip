# $NetBSD: buildlink3.mk,v 1.3 2006/11/06 11:00:27 marttikuparinen Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_SESSION_BUILDLINK3_MK:=	${XFCE4_SESSION_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-session
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-session}
BUILDLINK_PACKAGES+=	xfce4-session
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-session

.if ${XFCE4_SESSION_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-session+=	xfce4-session>=4.3.99.2
BUILDLINK_PKGSRCDIR.xfce4-session?=	../../wip/xfce4-session
.endif	# XFCE4_SESSION_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
