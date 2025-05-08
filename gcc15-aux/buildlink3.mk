# $NetBSD: buildlink3.mk,v 1.1 2025/04/27 12:00:00 dkazankov Exp $

BUILDLINK_TREE+=	gcc15-aux

.if !defined(GCC15_AUX_BUILDLINK3_MK)
GCC15_AUX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc15-aux+=	gcc15-aux>=15
BUILDLINK_ABI_DEPENDS.gcc15-aux+=	gcc15-aux>=15.1
BUILDLINK_PKGSRCDIR.gcc15-aux=		../../wip/gcc15-aux
BUILDLINK_DEPMETHOD.gcc15-aux?=	build

PREPEND_PATH+=	${BUILDLINK_DIR}/gcc15-aux/bin

GNU_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}

ADALIB_PREFIX=	gcc15-aux/lib/gcc/${GNU_TARGET_MACHINE}/15.1.0

BUILDLINK_FILES.gcc15-aux+=	gcc15-aux/${GNU_TARGET_MACHINE}/lib/*

BUILDLINK_INCDIRS.gcc15-aux+=	gcc15-aux/include
BUILDLINK_INCDIRS.gcc15-aux+=	${ADALIB_PREFIX}/include
BUILDLINK_INCDIRS.gcc15-aux+=	${ADALIB_PREFIX}/include-fixed
BUILDLINK_INCDIRS.gcc15-aux+=	${ADALIB_PREFIX}/plugin/include
BUILDLINK_INCDIRS.gcc15-aux+=	${ADALIB_PREFIX}/adainclude

BUILDLINK_LIBDIRS.gcc15-aux+=	gcc15-aux/lib
BUILDLINK_LIBDIRS.gcc15-aux+=	${ADALIB_PREFIX}
BUILDLINK_LIBDIRS.gcc15-aux+=	${ADALIB_PREFIX}/adalib
BUILDLINK_LIBDIRS.gcc15-aux+=	gcc15-aux/${GNU_TARGET_MACHINE}/lib

BUILDLINK_CONTENTS_FILTER.gcc15-aux=	${EGREP} \
					'(bin/.*|include/.*|lib/.*|libexec/.*|${GNU_TARGET_MACHINE}/lib/.*)'

pkgbase := gcc15-aux
.include "../../mk/pkg-build-options.mk"
.endif

BUILDLINK_TREE+=	-gcc15-aux
