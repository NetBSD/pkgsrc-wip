# $NetBSD: buildaddon.mk,v 1.3 2004/02/27 03:20:08 minskim Exp $

.include "../../wip/gcc3-c-devel/Makefile.common"

pre-build:
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} tconfig.h)
	${LN} -sf ${GCC_PREFIX}/lib/libiberty.a ${WRKSRC}/libiberty
	${LN} -sf ${GCC_PREFIX}/bin/gcc ${WRKSRC}/gcc/xgcc

BUILDLINK_DEPENDS.gcc34c?=	gcc3${GCC3_PKGMODIF}-c-3.4-devel
BUILDLINK_PKGSRCDIR.gcc34c?=	../../wip/gcc3-c-devel

BUILDLINK_PREFIX.gcc34c=	${LOCALBASE}

BUILDLINK_PACKAGES+=	gcc34c

BUILDLINK_FILES.gcc34c+=	${GCC_ARCHSUBDIR}/libgcc.a
BUILDLINK_FILES.gcc34c+=	${GCC_ARCHSUBDIR}/libgcc_eh.a
BUILDLINK_FILES.gcc34c+=	${GCC_ARCHSUBDIR#${GCC_VERSION}}/libgcc_s.so
BUILDLINK_FILES.gcc34c+=	${GCC_ARCHSUBDIR#${GCC_VERSION}}/libgcc_s.so.1

BUILDLINK_TARGETS+=		gcc34c-buildlink

gcc34c-buildlink: _BUILDLINK_USE
