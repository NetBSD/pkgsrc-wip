# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:43:53 jsonn Exp $

BUILDLINK_TREE+=	xfce4

.if !defined(XFCE4_BUILDLINK3_MK)
XFCE4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4+=	xfce4>=4.4.1
BUILDLINK_ABI_DEPENDS.xfce4?=	xfce4>=4.4.1nb2
BUILDLINK_PKGSRCDIR.xfce4?=	../../wip/xfce4

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
.endif # XFCE4_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4
