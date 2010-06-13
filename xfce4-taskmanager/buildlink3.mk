# $NetBSD: buildlink3.mk,v 1.7 2010/06/13 22:47:21 thomasklausner Exp $

BUILDLINK_TREE+=	xfce4-taskmanager

.if !defined(XFCE4_TASKMANAGER_BUILDLINK3_MK)
XFCE4_TASKMANAGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-taskmanager+=	xfce4-taskmanager>=0.3.2
BUILDLINK_ABI_DEPENDS.xfce4-taskmanager?=	xfce4-taskmanager>=0.3.2nb1
BUILDLINK_PKGSRCDIR.xfce4-taskmanager?=	../../wip/xfce4-taskmanager

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_TASKMANAGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-taskmanager
