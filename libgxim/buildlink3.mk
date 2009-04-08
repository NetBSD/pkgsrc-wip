# $NetBSD: buildlink3.mk,v 1.2 2009/04/08 14:52:50 jihbed Exp $

BUILDLINK_TREE+=	libgxim

.if !defined(LIBGXIM_BUILDLINK3_MK)
LIBGXIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgxim+=	libgxim>=0.3.3
BUILDLINK_PKGSRCDIR.libgxim?=	../../wip/libgxim

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

.endif	# LIBGXIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgxim
