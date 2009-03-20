# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:43:53 jsonn Exp $

BUILDLINK_TREE+=	xfce4-exo

.if !defined(XFCE4_EXO_BUILDLINK3_MK)
XFCE4_EXO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-exo+=	xfce4-exo>=0.3.2
BUILDLINK_PKGSRCDIR.xfce4-exo?=	../../wip/xfce4-exo

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/xfce4-mcs-plugins/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_EXO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-exo
