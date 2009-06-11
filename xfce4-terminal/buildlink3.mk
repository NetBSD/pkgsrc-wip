# $NetBSD: buildlink3.mk,v 1.7 2009/06/11 08:10:32 thomasklausner Exp $

BUILDLINK_TREE+=	xfce4-terminal

.if !defined(XFCE4_TERMINAL_BUILDLINK3_MK)
XFCE4_TERMINAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-terminal+=	xfce4-terminal>=0.2.6
BUILDLINK_ABI_DEPENDS.xfce4-terminal?=	xfce4-terminal>=0.2.6nb2
BUILDLINK_PKGSRCDIR.xfce4-terminal?=	../../wip/xfce4-terminal

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-exo/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_TERMINAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-terminal
