# $NetBSD: buildlink3.mk,v 1.1 2025/04/27 12:00:00 dkazankov Exp $

BUILDLINK_TREE+=	gcc15-gnat

.if !defined(GCC15_GNAT_BUILDLINK3_MK)
GCC15_GNAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc15-gnat+=	gcc15-gnat>=15
BUILDLINK_ABI_DEPENDS.gcc15-gnat+=	gcc15-gnat>=15.1
BUILDLINK_PKGSRCDIR.gcc15-gnat=		../../wip/gcc15-gnat
BUILDLINK_DEPMETHOD.gcc15-gnat?=	build

PREPEND_PATH+=	${BUILDLINK_DIR}/gcc15-gnat/bin

GNU_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}

ADALIB_PREFIX=	gcc15-gnat/lib/gcc/${GNU_TARGET_MACHINE}/15.1.0

BUILDLINK_FILES.gcc15-gnat+=	gcc15-gnat/${GNU_TARGET_MACHINE}/lib/*

BUILDLINK_INCDIRS.gcc15-gnat+=	gcc15-gnat/include
BUILDLINK_INCDIRS.gcc15-gnat+=	${ADALIB_PREFIX}/include
BUILDLINK_INCDIRS.gcc15-gnat+=	${ADALIB_PREFIX}/include-fixed
BUILDLINK_INCDIRS.gcc15-gnat+=	${ADALIB_PREFIX}/plugin/include
BUILDLINK_INCDIRS.gcc15-gnat+=	${ADALIB_PREFIX}/adainclude

BUILDLINK_LIBDIRS.gcc15-gnat+=	gcc15-gnat/lib
BUILDLINK_LIBDIRS.gcc15-gnat+=	${ADALIB_PREFIX}
BUILDLINK_LIBDIRS.gcc15-gnat+=	${ADALIB_PREFIX}/adalib
BUILDLINK_LIBDIRS.gcc15-gnat+=	gcc15-gnat/${GNU_TARGET_MACHINE}/lib

BUILDLINK_CONTENTS_FILTER.gcc15-gnat=	${EGREP} \
					'(bin/.*|include/.*|lib/.*|libexec/.*|${GNU_TARGET_MACHINE}/lib/.*)'

pkgbase := gcc15-gnat
.include "../../mk/pkg-build-options.mk"
.endif

BUILDLINK_TREE+=	-gcc15-gnat
