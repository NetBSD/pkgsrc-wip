# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:43:49 jsonn Exp $

BUILDLINK_TREE+=	libxfce4util

.if !defined(LIBXFCE4UTIL_BUILDLINK3_MK)
LIBXFCE4UTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4util+=	libxfce4util>=4.5.91
BUILDLINK_PKGSRCDIR.libxfce4util?=	../../wip/libxfce4util

.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # LIBXFCE4UTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4util
