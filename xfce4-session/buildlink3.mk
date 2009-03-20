# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:43:54 jsonn Exp $

BUILDLINK_TREE+=	xfce4-session

.if !defined(XFCE4_SESSION_BUILDLINK3_MK)
XFCE4_SESSION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-session+=	xfce4-session>=4.4.1
BUILDLINK_PKGSRCDIR.xfce4-session?=	../../wip/xfce4-session

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_SESSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-session
