# $NetBSD: buildlink3.mk,v 1.2 2006/09/04 08:54:04 marttikuparinen Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_MCS_PLUGINS_BUILDLINK3_MK:=	${XFCE4_MCS_PLUGINS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-mcs-plugins
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-mcs-plugins}
BUILDLINK_PACKAGES+=	xfce4-mcs-plugins
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-mcs-plugins

.if ${XFCE4_MCS_PLUGINS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-mcs-plugins+=	xfce4-mcs-plugins>=4.3.99.1
BUILDLINK_PKGSRCDIR.xfce4-mcs-plugins?=	../../wip/xfce4-mcs-plugins
.endif	# XFCE4_MCS_PLUGINS_BUILDLINK3_MK

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-mcs-manager/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
