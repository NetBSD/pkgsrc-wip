# $NetBSD: Makefile,v 1.2 2004/01/03 22:34:38 mpasternak Exp $
#

DISTNAME=		${MING_DISTNAME}
PKGNAME=		${PYPKGPREFIX}-${MING_PKGNAME}
CATEGORIES=		graphics
MASTER_SITES=		${MING_MASTER_SITES}
EXTRACT_SUFX=		${MING_EXTRACT_SUFX}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://ming.sourceforge.net/
COMMENT=		Python bindings for Ming library

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes

ALL_TARGET=		mingcmodule.so
REALSRC=		${WRKSRC}/py_ext

do-build:
	cd ${REALSRC} && ${MAKE} PYINC=${PREFIX}/${PYINC} \
		PYLIB=${PREFIX}/${PYLIB} PYSITELIB=${PREFIX}/${PYSITELIB} \
		PREFIX=${PREFIX} RPATH_FLAG=${RPATH_FLAG} ${ALL_TARGET}

do-install:
	cd ${REALSRC} && ${MAKE} PYINC=${PREFIX}/${PYINC} \
		PYLIB=${PREFIX}/${PYLIB} PYSITELIB=${PREFIX}/${PYSITELIB} \
		PREFIX=${PREFIX} RPATH_FLAG=${RPATH_FLAG} install

.include "../../wip/ming/buildlink2.mk"
.include "../../wip/ming/Makefile.common"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
