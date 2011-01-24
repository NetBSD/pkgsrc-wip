# $NetBSD: Makefile,v 1.1.1.1 2011/01/24 09:18:14 jihbed Exp $
#

VERSION=	0.21
DISTNAME=	PyLapack
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//S/L/l/}-${VERSION}
CATEGORIES=	math python
MASTER_SITES=	http://kochanski.org/gpk/misc/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://kochanski.org/gpk/misc/PyLapack.html
COMMENT=	PyLapack is a python interface to LAPACK
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES= fortran77
PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	share/doc/py-lapack

post-install:
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL  ${DESTDIR}${PREFIX}/share/doc/py-lapack

.include "../../lang/python/extension.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
