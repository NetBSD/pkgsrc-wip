# $NetBSD: Makefile,v 1.4 2014/05/09 07:38:48 thomasklausner Exp $

VERSION=	0.21
DISTNAME=	PyLapack
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//S/L/l/}-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	http://kochanski.org/gpk/misc/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://kochanski.org/gpk/misc/PyLapack.html
COMMENT=	PyLapack is a python interface to LAPACK
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	fortran77
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-Numeric

INSTALLATION_DIRS=	share/doc/py-lapack

post-install:
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL  ${DESTDIR}${PREFIX}/share/doc/py-lapack

.include "../../lang/python/extension.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
