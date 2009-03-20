# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:43:49 jsonn Exp $

BUILDLINK_TREE+=	libxfce4mcs

.if !defined(LIBXFCE4MCS_BUILDLINK3_MK)
LIBXFCE4MCS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4mcs+=	libxfce4mcs>=4.4.1
BUILDLINK_PKGSRCDIR.libxfce4mcs?=	../../wip/libxfce4mcs

.include "../../x11/startup-notification/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../wip/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # LIBXFCE4MCS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4mcs
