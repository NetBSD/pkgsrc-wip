# $NetBSD: buildlink3.mk,v 1.3 2006/11/06 11:00:25 marttikuparinen Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XFCE4_BUILDLINK3_MK:=	${XFCE4_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4}
BUILDLINK_PACKAGES+=	xfce4
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4

.if ${XFCE4_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4+=	xfce4>=4.3.99.2
BUILDLINK_PKGSRCDIR.xfce4?=	../../wip/xfce4
.endif	# XFCE4_BUILDLINK3_MK

.include "../../wip/xfce4-mixer/buildlink3.mk"
.include "../../wip/xfce4-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-print/buildlink3.mk"
.include "../../wip/xfce4-appfinder/buildlink3.mk"
.include "../../wip/xfce4-xarchiver/buildlink3.mk"
.include "../../wip/xfce4-orage/buildlink3.mk"
.include "../../wip/xfce4-wm/buildlink3.mk"
.include "../../wip/xfce4-wm-themes/buildlink3.mk"
.include "../../wip/xfce4-desktop/buildlink3.mk"
.include "../../wip/xfce4-gtk2-engine/buildlink3.mk"
.include "../../wip/xfce4-mousepad/buildlink3.mk"
.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../wip/xfce4-session/buildlink3.mk"
.include "../../wip/xfce4-terminal/buildlink3.mk"
.include "../../wip/xfce4-utils/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
