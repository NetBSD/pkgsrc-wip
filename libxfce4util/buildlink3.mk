# $NetBSD: buildlink3.mk,v 1.11 2011/06/29 13:29:27 reinoudz70 Exp $

BUILDLINK_TREE+=	libxfce4util

.if !defined(LIBXFCE4UTIL_BUILDLINK3_MK)
LIBXFCE4UTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxfce4util+=	libxfce4util>=4.6.0
BUILDLINK_ABI_DEPENDS.libxfce4util?=	libxfce4util>=4.6.1nb4
BUILDLINK_PKGSRCDIR.libxfce4util?=	../../wip/libxfce4util

.include "../../devel/glib2/buildlink3.mk"
.endif # LIBXFCE4UTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxfce4util
