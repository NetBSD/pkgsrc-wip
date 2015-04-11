# $NetBSD: buildlink3.mk,v 1.1 2015/04/11 14:59:45 krytarowski Exp $

BUILDLINK_TREE+=	libsysstat

.if !defined(LIBSYSSTAT_BUILDLINK3_MK)
LIBSYSSTAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsysstat+=	libsysstat>=0.3.0
BUILDLINK_PKGSRCDIR.libsysstat?=	../../wip/libsysstat

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBSYSSTAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsysstat
