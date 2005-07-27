# $NetBSD: Makefile,v 1.7 2005/07/27 16:28:33 thomasklausner Exp $
#

DISTNAME=		${MING_DISTNAME}
PKGNAME=		${PYPKGPREFIX}-${MING_PKGNAME}
CATEGORIES=		graphics
MASTER_SITES=		${MING_MASTER_SITES}
EXTRACT_SUFX=		${MING_EXTRACT_SUFX}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ming.sourceforge.net/
COMMENT=		Python bindings for Ming library

PY_PATCHPLIST=		yes

BUILD_TARGET=		mingcmodule.so
REALSRC=		${WRKSRC}/py_ext

do-build:
	cd ${REALSRC} && ${MAKE} PYINC=${PREFIX}/${PYINC} \
		PYLIB=${PREFIX}/${PYLIB} PYSITELIB=${PREFIX}/${PYSITELIB} \
		PREFIX=${PREFIX} COMPILER_RPATH_FLAG=${COMPILER_RPATH_FLAG} \
		${BUILD_TARGET}

do-install:
	cd ${REALSRC} && ${MAKE} PYINC=${PREFIX}/${PYINC} \
		PYLIB=${PREFIX}/${PYLIB} PYSITELIB=${PREFIX}/${PYSITELIB} \
		PREFIX=${PREFIX} COMPILER_RPATH_FLAG=${COMPILER_RPATH_FLAG}
		${INSTALL_TARGET}

.include "../../wip/ming/buildlink3.mk"
.include "../../wip/ming/Makefile.common"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
