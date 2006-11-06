# $NetBSD: buildlink3.mk,v 1.3 2006/11/06 11:00:26 marttikuparinen Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_MCS_MANAGER_BUILDLINK3_MK:=	${XFCE4_MCS_MANAGER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-mcs-manager
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-mcs-manager}
BUILDLINK_PACKAGES+=	xfce4-mcs-manager
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-mcs-manager

.if ${XFCE4_MCS_MANAGER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-mcs-manager+=	xfce4-mcs-manager>=4.3.99.2
BUILDLINK_PKGSRCDIR.xfce4-mcs-manager?=	../../wip/xfce4-mcs-manager
.endif	# XFCE4_MCS_MANAGER_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/libxfce4gui/buildlink3.mk"
.include "../../wip/libxfce4mcs/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
