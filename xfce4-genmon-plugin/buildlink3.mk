# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/10/26 06:32:49 dhowland Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_GENMON_PLUGIN_BUILDLINK3_MK:=	${XFCE4_GENMON_PLUGIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-genmon-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-genmon-plugin}
BUILDLINK_PACKAGES+=	xfce4-genmon-plugin

.if !empty(XFCE4_GENMON_PLUGIN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-genmon-plugin+=	xfce4-genmon-plugin>=1.1
BUILDLINK_PKGSRCDIR.xfce4-genmon-plugin?=	../../sysutils/xfce4-genmon-plugin
.endif	# XFCE4_GENMON_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
