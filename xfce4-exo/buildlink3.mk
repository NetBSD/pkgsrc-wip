# $NetBSD: buildlink3.mk,v 1.6 2007/01/23 08:00:35 marttikuparinen Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_EXO_BUILDLINK3_MK:=	${XFCE4_EXO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-exo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-exo}
BUILDLINK_PACKAGES+=	xfce4-exo
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-exo

.if ${XFCE4_EXO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-exo+=	xfce4-exo>=0.3.2
BUILDLINK_PKGSRCDIR.xfce4-exo?=	../../wip/xfce4-exo
.endif	# XFCE4_EXO_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
