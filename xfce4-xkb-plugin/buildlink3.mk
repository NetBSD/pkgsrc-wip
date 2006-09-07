# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/09/07 07:53:11 marttikuparinen Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_XKB_PLUGIN_BUILDLINK3_MK:=	${XFCE4_XKB_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-xkb-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-xkb-plugin}
BUILDLINK_PACKAGES+=	xfce4-xkb-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-xkb-plugin

.if ${XFCE4_XKB_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-xkb-plugin+=	xfce4-xkb-plugin>=0.4.1
BUILDLINK_PKGSRCDIR.xfce4-xkb-plugin?=	../../wip/xfce4-xkb-plugin
.endif	# XFCE4_XKB_PLUGIN_BUILDLINK3_MK

.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
