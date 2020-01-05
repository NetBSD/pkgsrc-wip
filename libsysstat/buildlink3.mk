# $NetBSD$

BUILDLINK_TREE+=	libsysstat

.if !defined(LIBSYSSTAT_BUILDLINK3_MK)
LIBSYSSTAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsysstat+=	libsysstat>=0.4.2
BUILDLINK_PKGSRCDIR.libsysstat?=	../../wip/libsysstat

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBSYSSTAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsysstat
