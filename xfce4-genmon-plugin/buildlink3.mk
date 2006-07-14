# $NetBSD: buildlink3.mk,v 1.4 2006/07/14 10:59:42 thomasklausner Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_GENMON_PLUGIN_BUILDLINK3_MK:=	${XFCE4_GENMON_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-genmon-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-genmon-plugin}
BUILDLINK_PACKAGES+=	xfce4-genmon-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-genmon-plugin

.if ${XFCE4_GENMON_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-genmon-plugin+=	xfce4-genmon-plugin>=1.1
BUILDLINK_PKGSRCDIR.xfce4-genmon-plugin?=	../../wip/xfce4-genmon-plugin
.endif	# XFCE4_GENMON_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
