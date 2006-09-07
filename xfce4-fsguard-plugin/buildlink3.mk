# $NetBSD: buildlink3.mk,v 1.3 2006/09/07 08:27:47 marttikuparinen Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_FSGUARD_PLUGIN_BUILDLINK3_MK:=	${XFCE4_FSGUARD_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-fsguard-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-fsguard-plugin}
BUILDLINK_PACKAGES+=	xfce4-fsguard-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-fsguard-plugin

.if ${XFCE4_FSGUARD_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-fsguard-plugin+=	xfce4-fsguard-plugin>=0.3.0
BUILDLINK_PKGSRCDIR.xfce4-fsguard-plugin?=	../../wip/xfce4-fsguard-plugin
.endif	# XFCE4_FSGUARD_PLUGIN_BUILDLINK3_MK

.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
