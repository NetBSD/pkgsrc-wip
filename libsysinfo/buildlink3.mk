# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.19.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_PLATFORM:MFreeBSD-*-*}

BUILDLINK_TREE+=	libsysinfo

.if !defined(LIBSYSINFO_BUILDLINK3_MK)
LIBSYSINFO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libsysinfo?=	build

BUILDLINK_API_DEPENDS.libsysinfo+=	libsysinfo>=0.0.3
BUILDLINK_PKGSRCDIR.libsysinfo?=	../../wip/libsysinfo
.endif	# LIBSYSINFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsysinfo

.endif
