# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/12 05:49:54 blef Exp $
#
# This Makefile fragment is included by packages that use libdvbpsi.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBDVBPSI_BUILDLINK2_MK)
LIBDVBPSI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libdvbpsi
BUILDLINK_DEPENDS.libdvbpsi?=		libdvbpsi>=0.1.3
BUILDLINK_PKGSRCDIR.libdvbpsi?=		../../wip/libdvbpsi

EVAL_PREFIX+=	BUILDLINK_PREFIX.libdvbpsi=libdvbpsi
BUILDLINK_PREFIX.libdvbpsi_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/demux.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/descriptor.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_02.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_03.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_04.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_05.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_06.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_07.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_08.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_09.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_0a.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_0b.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_0c.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_0d.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_0e.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_0f.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_42.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_47.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dr_48.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/dvbpsi.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/pat.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/pmt.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/psi.h
BUILDLINK_FILES.libdvbpsi+=	include/dvbpsi/sdt.h
BUILDLINK_FILES.libdvbpsi+=	lib/libdvbpsi.*

BUILDLINK_TARGETS+=	libdvbpsi-buildlink

libdvbpsi-buildlink: _BUILDLINK_USE

.endif	# LIBDVBPSI_BUILDLINK2_MK
