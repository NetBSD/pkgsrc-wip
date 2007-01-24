# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/01/24 08:22:28 marttikuparinen Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_CPUGRAPH_PLUGIN_BUILDLINK3_MK:=	${XFCE4_CPUGRAPH_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-cpugraph-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-cpugraph-plugin}
BUILDLINK_PACKAGES+=	xfce4-cpugraph-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-cpugraph-plugin

.if ${XFCE4_CPUGRAPH_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-cpugraph-plugin+=	xfce4-cpugraph-plugin>=0.3.0
BUILDLINK_PKGSRCDIR.xfce4-cpugraph-plugin?=	../../wip/xfce4-cpugraph-plugin
.endif	# XFCE4_CPUGRAPH_PLUGIN_BUILDLINK3_MK

.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
