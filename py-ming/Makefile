# $NetBSD: Makefile,v 1.1.1.1 2003/11/27 00:56:20 mpasternak Exp $
#

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
COMMENT=	Python bindings for Ming library

USE_BUILDLINK2=	yes
PY_PATCHPLIST=	yes

ALL_TARGET=	mingcmodule.so
REALSRC=	${WRKSRC}/py_ext

do-build:
	cd ${REALSRC} && ${MAKE} PYINC=${PREFIX}/${PYINC} \
		PYLIB=${PREFIX}/${PYLIB} PYSITELIB=${PREFIX}/${PYSITELIB} \
		PREFIX=${PREFIX} RPATH_FLAG=${RPATH_FLAG} ${ALL_TARGET}

do-install:
	cd ${REALSRC} && ${MAKE} PYINC=${PREFIX}/${PYINC} \
		PYLIB=${PREFIX}/${PYLIB} PYSITELIB=${PREFIX}/${PYSITELIB} \
		PREFIX=${PREFIX} RPATH_FLAG=${RPATH_FLAG} install

.include "../../wip/ming/Makefile.common"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
