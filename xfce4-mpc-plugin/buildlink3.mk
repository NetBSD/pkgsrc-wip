# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/04/17 05:32:16 marttikuparinen Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_MPC_PLUGIN_BUILDLINK3_MK:=	${XFCE4_MPC_PLUGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-mpc-plugin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-mpc-plugin}
BUILDLINK_PACKAGES+=	xfce4-mpc-plugin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-mpc-plugin

.if ${XFCE4_MPC_PLUGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-mpc-plugin+=	xfce4-mpc-plugin>=0.3.1
BUILDLINK_PKGSRCDIR.xfce4-mpc-plugin?=	../../wip/xfce4-mpc-plugin
.endif	# XFCE4_MPC_PLUGIN_BUILDLINK3_MK

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
