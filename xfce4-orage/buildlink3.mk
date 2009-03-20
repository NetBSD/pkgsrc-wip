# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:43:54 jsonn Exp $

BUILDLINK_TREE+=	xfce4-orage

.if !defined(XFCE4_ORAGE_BUILDLINK3_MK)
XFCE4_ORAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-orage+=	xfce4-orage>=4.4.1
BUILDLINK_PKGSRCDIR.xfce4-orage?=	../../wip/xfce4-orage

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_ORAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-orage
