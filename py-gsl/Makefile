# $NetBSD: Makefile,v 1.7 2014/05/09 07:38:47 thomasklausner Exp $

DISTNAME=	pygsl-0.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pygsl/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pygsl.sourceforge.net/
COMMENT=	Python interface for the GNU scientific library
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-Numeric, py-numarray

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_test.py

INSTALLATION_DIRS=	share/doc/py-gsl/ref

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/html/ref/* ${DESTDIR}${PREFIX}/share/doc/py-gsl/ref

.include "../../lang/python/distutils.mk"
BUILDLINK_API_DEPENDS.gsl+=		gsl>=1.9
.include "../../math/gsl/buildlink3.mk"
# furur replace py-Numeric; py-numarray by py-numpy
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
