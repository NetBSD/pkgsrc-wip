# $NetBSD: buildlink3.mk,v 1.0 2024/07/06 11:00:00 dkazankov Exp $

BUILDLINK_TREE+=	gcc14-gnat

.if !defined(GCC14_GNAT_BUILDLINK3_MK)
GCC14_GNAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc14-gnat+=	gcc14-gnat>=14
BUILDLINK_ABI_DEPENDS.gcc14-gnat+=	gcc14-gnat>=14.1
BUILDLINK_PKGSRCDIR.gcc14-gnat=		../../wip/gcc14-gnat
BUILDLINK_DEPMETHOD.gcc14-gnat?=	build

GNU_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}

ADALIB_PREFIX=	gcc14-gnat/lib/gcc/${GNU_TARGET_MACHINE}/14.2.0

BUILDLINK_FILES.gcc14-gnat+=	${ADALIB_PREFIX}/adalib/*.ali

BUILDLINK_INCDIRS.gcc14-gnat+=	gcc14-gnat/include ${ADALIB_PREFIX}/adainclude
BUILDLINK_LIBDIRS.gcc14-gnat+=	gcc14-gnat/lib ${ADALIB_PREFIX}/adalib

pkgbase := gcc14-gnat
.include "../../mk/pkg-build-options.mk"
.endif

BUILDLINK_TREE+=	-gcc14-gnat
