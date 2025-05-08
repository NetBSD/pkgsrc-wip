# $NetBSD: buildlink3.mk,v 1.1 2025/04/27 12:00:00 dkazankov Exp $

BUILDLINK_TREE+=	gcc15-gnat-libs

.if !defined(GCC15_GNAT_LIBS_BUILDLINK3_MK)
GCC15_GNAT_LIBS_BUILDLINK3_MK:=

.if !empty(USE_PKGSRC_GCC_RUNTIME:M[Yy][Ee][Ss])
BUILDLINK_API_DEPENDS.gcc15-gnat-libs+=	gcc15-gnat-libs>=15.1.0
.else
BUILDLINK_API_DEPENDS.gcc15-gnat-libs+=	{gcc15-gnat,gcc15-gnat-libs}>=15.1.0
.endif
BUILDLINK_PKGSRCDIR.gcc15-gnat-libs=	../../wip/gcc15-gnat-libs
BUILDLINK_DEPMETHOD.gcc15-gnat-libs?=	full

GCC_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}

TARGET_LIBDIR.gcc15-gnat-libs=	${PREFIX}/gcc15-gnat/${GCC_TARGET_MACHINE}/lib

BUILDLINK_PASSTHRU_DIRS+=	${TARGET_LIBDIR.gcc15-gnat-libs}

BUILDLINK_FILES.gcc15-gnat-libs=	#empty
BUILDLINK_AUTO_VARS.gcc15-gnat-libs=	no
BUILDLINK_AUTO_DIRS.gcc15-gnat-libs=	no

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif # GCC15_GNAT_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc15-gnat-libs
