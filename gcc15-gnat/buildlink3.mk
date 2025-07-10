# $NetBSD: buildlink3.mk,v 1.1 2025/04/27 12:00:00 dkazankov Exp $

BUILDLINK_TREE+=	gcc15-gnat

.if !defined(GCC15_GNAT_BUILDLINK3_MK)
GCC15_GNAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc15-gnat+=	gcc15-gnat>=15.1.0
#BUILDLINK_ABI_DEPENDS.gcc15-gnat+=	gcc15-gnat>=15.1.0
BUILDLINK_PKGSRCDIR.gcc15-gnat?=	../../wip/gcc15-gnat
BUILDLINK_DEPMETHOD.gcc15-gnat?=	build

PREPEND_PATH+=	${BUILDLINK_DIR}/gcc15-gnat/bin

ADALIB_PREFIX=	gcc15-gnat/lib/gcc/${MACHINE_GNU_PLATFORM}/15.1.0

BUILDLINK_INCDIRS.gcc15-gnat+=	${ADALIB_PREFIX}/include
BUILDLINK_INCDIRS.gcc15-gnat+=	${ADALIB_PREFIX}/adainclude

BUILDLINK_LIBDIRS.gcc15-gnat+=	${ADALIB_PREFIX}
BUILDLINK_LIBDIRS.gcc15-gnat+=	${ADALIB_PREFIX}/adalib

BUILDLINK_RPATHDIRS.gcc15-gnat+=	${ADALIB_PREFIX}
BUILDLINK_RPATHDIRS.gcc15-gnat+=	${ADALIB_PREFIX}/adalib
BUILDLINK_RPATHDIRS.gcc15-gnat+=	gcc15-gnat/${MACHINE_GNU_PLATFORM}/lib

BUILDLINK_CONTENTS_FILTER.gcc15-gnat=	${EGREP} \
					'(bin/.*|include/.*|lib/.*|libexec/.*|${MACHINE_GNU_PLATFORM}/lib/.*)'

pkgbase := gcc15-gnat
.include "../../mk/pkg-build-options.mk"
.endif

BUILDLINK_TREE+=	-gcc15-gnat
