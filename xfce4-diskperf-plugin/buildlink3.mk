# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/01/24 08:23:47 marttikuparinen Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_DISKPERF_PLUGIN_BUILDLINK3_MK:=	${XFCE4_DISKPERF_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-diskperf-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-diskperf-plugin}
BUILDLINK_PACKAGES+=	xfce4-diskperf-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-diskperf-plugin

.if ${XFCE4_DISKPERF_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-diskperf-plugin+=	xfce4-diskperf-plugin>=2.1.0
BUILDLINK_PKGSRCDIR.xfce4-diskperf-plugin?=	../../wip/xfce4-diskperf-plugin
.endif	# XFCE4_DISKPERF_PLUGIN_BUILDLINK3_MK

.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
