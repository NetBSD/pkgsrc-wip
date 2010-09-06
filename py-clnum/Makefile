# $NetBSD: Makefile,v 1.1.1.1 2010/09/06 13:49:09 jihbed Exp $
#

DISTNAME=	clnum-1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/c/clnum/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/c/clnum/
COMMENT=	Rational and arbitrary precision floating point numbers
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	share/doc/py-clnum

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test_clnum.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/clnumManual.html ${DESTDIR}${PREFIX}/share/doc/py-clnum

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/cln/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
