# $NetBSD: buildlink3.mk,v 1.4 2006/07/14 11:01:36 thomasklausner Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_TASKMANAGER_BUILDLINK3_MK:=	${XFCE4_TASKMANAGER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-taskmanager
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-taskmanager}
BUILDLINK_PACKAGES+=	xfce4-taskmanager
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-taskmanager

.if ${XFCE4_TASKMANAGER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-taskmanager+=	xfce4-taskmanager>=0.3.1nb1
BUILDLINK_PKGSRCDIR.xfce4-taskmanager?=	../../wip/xfce4-taskmanager
.endif	# XFCE4_TASKMANAGER_BUILDLINK3_MK

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
