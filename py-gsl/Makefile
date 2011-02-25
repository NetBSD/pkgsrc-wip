# $NetBSD: Makefile,v 1.2 2011/02/25 09:47:48 thomasklausner Exp $
#

DISTNAME=	pygsl-0.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pygsl/pygsl/pygsl-0.9.5/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pygsl.sourceforge.net/
COMMENT=	Python interface for the GNU scientific library
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 27 26 25 24 23 22 20
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_test.py

INSTALLATION_DIRS=	share/doc/py-gsl/ref

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/html/ref/* ${DESTDIR}${PREFIX}/share/doc/py-gsl/ref

.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.gsl+=		gsl>=1.4
.include "../../math/gsl/buildlink3.mk"
# furur replace py-Numeric; py-numarray by py-numpy
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
