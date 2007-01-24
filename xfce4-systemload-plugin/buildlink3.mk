# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/01/24 08:25:44 marttikuparinen Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_SYSTEMLOAD_PLUGIN_BUILDLINK3_MK:=	${XFCE4_SYSTEMLOAD_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-systemload-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-systemload-plugin}
BUILDLINK_PACKAGES+=	xfce4-systemload-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-systemload-plugin

.if ${XFCE4_SYSTEMLOAD_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-systemload-plugin+=	xfce4-systemload-plugin>=0.4.2
BUILDLINK_PKGSRCDIR.xfce4-systemload-plugin?=	../../wip/xfce4-systemload-plugin
.endif	# XFCE4_SYSTEMLOAD_PLUGIN_BUILDLINK3_MK

.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
